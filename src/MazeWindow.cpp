#include "MazeWindow.h"
#include "Colorizer.h"

#include <Grid.h>
#include <Cell.h>
#include <util.h>

#include "MakerFactory.h"

#include <iterator>
#include <iostream>

MazeWindow::MazeWindow() {
  init();
  createActions();
  setupToolBar();
  resize(1000,800);
}

void MazeWindow::init() {
  algorithmSelector = new QComboBox(this);
  mazeWidget = new MazeWidget(nullptr);
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
  dimensionSetter->setMaximum(200);
  dimensionSetter->setValue(20);

  QObject::connect(newMaze, &QAction::triggered, [this] { this->createMaze();});

  QObject::connect(stepAction, &QAction::triggered, [this] { 
      while(maker && !maker->isDone()) {
	maker->step();
      }
      mazeWidget->repaint();
    });

  QObject::connect(playAction, &QAction::triggered, [this] { 
      tick();
    });
}

void MazeWindow::tick() {
  if (!maker || maker->isDone()) return;
  // TODO: mutex
  maker->step();
  mazeWidget->update();
  QTimer::singleShot(20, [this] () { this->tick();});
}

void MazeWindow::setupToolBar() {
  toolbar = addToolBar(tr("Mazes"));
  toolbar->addWidget(dimensionSetter);
  toolbar->addAction(newMaze);
  toolbar->addAction(stepAction);
  toolbar->addAction(playAction);
  toolbar->addWidget(algorithmSelector);
}

void MazeWindow::createMaze() {
  
  auto selected = algorithmSelector->currentText();
  auto factory = MakerFactory::byName(selected);
  
  maker = factory->maker();

  int w,h;
  w = h = dimensionSetter->value();
  maker->setGrid(Grid(w,h));
  mazeWidget->setMaker(maker);
  mazeWidget->setColorizer(factory->colorizer());
  mazeWidget->repaint();
}

