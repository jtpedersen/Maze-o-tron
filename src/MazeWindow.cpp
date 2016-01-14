#include "MazeWindow.h"
#include "Grid.h"
#include "BinTreeMaker.h"
#include "util.h"

#include <iterator>
#include <iostream>

MazeWindow::MazeWindow() {
  init();
  createActions();
  setupToolBar();
}

void MazeWindow::init() {
  scene = new QGraphicsScene(this);
  view = new QGraphicsView(scene);
  view->show();
  setCentralWidget(view);

}

void MazeWindow::createActions() {
  newMaze = new QAction(QIcon(":/maze"), tr("&New"), this);
  newMaze->setShortcuts(QKeySequence::New);
  newMaze->setStatusTip(tr("Create a new Maze"));
  QObject::connect(newMaze, &QAction::triggered, [this] { this->createMaze();});
}

void MazeWindow::setupToolBar() {
  toolbar = addToolBar(tr("Mazes"));
  toolbar->addAction(newMaze);
}

void MazeWindow::createMaze() {
  Grid grid(20,20);
  BinTreeMaker maker(grid);
  while(!maker.isDone()) {
    maker.step();
    std::cout << maker.getGrid() << std::endl;
  }

}
