#include "MazeWindow.h"
#include "Colorizer.h"

#include "UniDijkstra.h"

#include <Cell.h>
#include <Grid.h>
#include <util.h>

#include "MakerFactory.h"

#include <chrono>
#include <iostream>
#include <iterator>

using Clock = std::chrono::high_resolution_clock;

MazeWindow::MazeWindow() {
  init();
  createActions();
  setupToolBar();
  resize(900, 800);
}

void MazeWindow::init() {
  algorithmSelector = new QComboBox(this);
  mazeWidget = new MazeWidget(nullptr);
  steps = new QLabel(this);
  setCentralWidget(mazeWidget);
}

void MazeWindow::createActions() {
  newMaze = new QAction(QIcon(":/maze"), tr("&New"), this);
  newMaze->setShortcuts(QKeySequence::New);
  newMaze->setStatusTip(tr("Create a new Maze"));

  playAction = new QAction(QIcon(":/play"), tr("&Play"), this);
  playAction->setStatusTip(tr("Start construction"));

  pauseAction = new QAction(QIcon(":/pause"), tr("&Pause"), this);
  pauseAction->setStatusTip(tr("pause construction"));

  stepAction = new QAction(QIcon(":/step"), tr("&Step"), this);
  stepAction->setStatusTip(tr("step construction"));

  algorithmSelector->addItem(tr("BinaryTree"));
  algorithmSelector->addItem(tr("SideWinder"));
  algorithmSelector->addItem(tr("RecursiveBacktracker"));
  algorithmSelector->addItem(tr("Prims"));

  dimensionSetter = new QSpinBox(this);
  dimensionSetter->setMinimum(2);
  dimensionSetter->setMaximum(1000);
  dimensionSetter->setValue(20);

  QObject::connect(newMaze, &QAction::triggered,
                   [this] { this->createMaze(); });

  QObject::connect(stepAction, &QAction::triggered, [this] {
    while (maker && !maker->isDone()) {
      maker->step();
      stepCount++;
    }
    steps->setNum(stepCount);
    mazeWidget->repaint();
  });

  QObject::connect(playAction, &QAction::triggered, [this] { tick(); });
}

void MazeWindow::tick() {
  if (!maker || maker->isDone())
    return;
  static QMutex mutex;
  QMutexLocker locker(&mutex);
  maker->step();
  mazeWidget->update();
  stepCount++;
  steps->setNum(stepCount);
  QTimer::singleShot(20, [this]() { this->tick(); });
}

void MazeWindow::setupToolBar() {
  toolbar = addToolBar(tr("Mazes"));
  toolbar->addWidget(dimensionSetter);
  toolbar->addAction(newMaze);
  toolbar->addAction(stepAction);
  toolbar->addAction(playAction);
  toolbar->addWidget(algorithmSelector);
  toolbar->addSeparator();
  toolbar->addWidget(new QLabel("Steps: "));
  toolbar->addWidget(steps);

  auto dijkstra = new QAction(tr("&dijkstra"), this);
  dijkstra->setStatusTip(tr("Dijstra construction"));
  connect(dijkstra, &QAction::triggered, [this] { showDijkstra(); });
  toolbar->addAction(dijkstra);
}

void MazeWindow::showDijkstra() {
  auto tmp =
      std::make_shared<UniDijkstra>(std::max(0, mazeWidget->getClicked()));
  auto colorizer = std::make_shared<DijkstraColorizer>(tmp);

  tmp->setGrid(maker->grid());

  auto start = Clock::now();
  while (!tmp->isDone())
    tmp->step();
  auto dur = Clock::now() - start;
  std::cout
      << "It took "
      << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
      << "ms" << std::endl;

  mazeWidget->setMaker(tmp);
  mazeWidget->setColorizer(colorizer);
  mazeWidget->repaint();
}

void MazeWindow::createMaze() {

  auto selected = algorithmSelector->currentText();
  auto factory = MakerFactory::byName(selected);

  maker = factory->maker();

  int w, h;
  w = h = dimensionSetter->value();
  stepCount = 0;
  maker->setGrid(Grid(w, h));
  mazeWidget->setMaker(maker);
  mazeWidget->setColorizer(factory->colorizer());
  mazeWidget->repaint();
}
