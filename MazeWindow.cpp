#include "MazeWindow.h"

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
  QObject::connect(newMaze, &QAction::triggered, [this] { this->scene->addText("Hello, world!");});
}

void MazeWindow::setupToolBar() {
  toolbar = addToolBar(tr("Mazes"));
  toolbar->addAction(newMaze);
}
