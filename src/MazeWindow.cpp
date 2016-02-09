#include "MazeWindow.h"
#include "Colorizer.h"

#include <Grid.h>
#include <Cell.h>
#include <BinTreeMaker.h>
#include <SideWinderMaker.h>
#include <RecursiveBacktrackerMaker.h>
#include <PrimMaker.h>
#include <util.h>

#include <iterator>
#include <iostream>

MazeWindow::MazeWindow() {
  init();
  createActions();
  setupToolBar();
  resize(1000,800);
}

void MazeWindow::init() {
  scene = new QGraphicsScene(this);
  view = new QGraphicsView(scene);
  algorithmSelector = new QComboBox(this);
  view->show();
  setCentralWidget(view);
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
  dimensionSetter->setMaximum(100);
  dimensionSetter->setValue(20);

  QObject::connect(newMaze, &QAction::triggered, [this] { this->createMaze();});

  QObject::connect(stepAction, &QAction::triggered, [this] { 
      if(maker && !maker->isDone()) {
	maker->step();
	drawMaze(maker->getGrid());
      }});

  QObject::connect(playAction, &QAction::triggered, [this] { 
      tick();
    });
}

void MazeWindow::tick() {
  if (!maker || maker->isDone()) return;
  maker->step();
  drawMaze(maker->getGrid());
  QTimer::singleShot(200, [this] () { this->tick();});
}

void MazeWindow::setupToolBar() {
  toolbar = addToolBar(tr("Mazes"));
  toolbar->addWidget(dimensionSetter);
  toolbar->addAction(newMaze);
  toolbar->addAction(stepAction);
  toolbar->addAction(playAction);
  toolbar->addWidget(algorithmSelector);
}

void MazeWindow::drawMaze(const Grid& grid) {
  Q_ASSERT(colorizer);
  scene->clear();
  qreal cellSize = 35;

  QPen border(QColor(0,0,0));
  for(const auto&c :grid.getCells()) {
    qreal x1 = c.x() * cellSize;
    qreal y1 = c.y() * cellSize;
    qreal x2 = x1 + cellSize;
    qreal y2 = y1 + cellSize;

    auto color = colorizer->getColorForCell(c.idx());
    QBrush brush(color);
    QPen pen(color);
    int rs = cellSize - 2 * border.width();
    scene->addRect(x1+border.width(),y1+border.width(),rs,rs,pen,brush);
    
    if (c.N < 0)
      scene->addLine(x1,y1, x2,y1, border);
    if (c.W < 0)
      scene->addLine(x1,y1, x1,y2, border);
    if ( ! c.linked(c.E))
      scene->addLine(x2,y1, x2,y2, border);
    if ( ! c.linked(c.S))
      scene->addLine(x1,y2, x2,y2, border);

  }
}

void MazeWindow::createMaze() {
  int w,h;
  w = h = dimensionSetter->value();
  auto selected = algorithmSelector->currentText();
  if (selected == tr("BinaryTree")) {
    maker = std::make_unique<BinTreeMaker>(Grid(w,h));
    colorizer = std::make_unique<SimpleColorizer>(maker.get());
  } else if (selected == tr("SideWinder")) {
    maker = std::make_unique<SideWinderMaker>(Grid(w,h));
    colorizer = std::make_unique<SimpleColorizer>(maker.get());
  } else if (selected == tr("RecursiveBacktracker")) {
    maker = std::make_unique<RecursiveBacktrackerMaker>(Grid(w,h));
    auto* ptr = static_cast<RecursiveBacktrackerMaker*>(maker.get());
    colorizer = std::make_unique<RecursiveBacktrackerColorizer>(ptr);
  } else if (selected == tr("Prims")) {
    maker = std::make_unique<PrimMaker>(Grid(w,h));
    colorizer = std::make_unique<SimpleColorizer>(maker.get());
  } else {
    Q_ASSERT(false);
  }
  drawMaze(maker->getGrid());
}
