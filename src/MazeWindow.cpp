#include "MazeWindow.h"

#include <Grid.h>
#include <Cell.h>
#include <BinTreeMaker.h>
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

void MazeWindow::drawMaze(const Grid& grid) {
  qreal cellSize = 5.0;
  
  for(const auto&c :grid.getCells()) {
    qreal x1 = c.x() * cellSize;
    qreal y1 = c.y() * cellSize;
    qreal x2 = x1 + cellSize;
    qreal y2 = y1 + cellSize;

    if (c.N < 0)
      scene->addLine(x1,y1, x2,y1);
    if (c.W < 0)
      scene->addLine(x1,y1, x1,y2);
    if ( ! c.linked(c.E))
      scene->addLine(x2,y1, x2,y2);
    if ( ! c.linked(c.S))
      scene->addLine(x1,y2, x2,y2);

  }
}

void MazeWindow::createMaze() {
  Grid grid(200,200);
  BinTreeMaker maker(grid);
  while(!maker.isDone()) {
    maker.step();
  }
  drawMaze(maker.getGrid());
}
