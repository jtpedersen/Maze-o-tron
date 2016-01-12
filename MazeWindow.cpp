#include "MazeWindow.h"
#include "Grid.h"
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
  grid = new Grid(20,20);
  
  auto NW = [] (const Cell& c) {
    std::vector<Cell*> ls;
    Cell *ns[] = { c.N, c.E};
    for (auto n : ns) {
      if (n) {
	ls.push_back(n);
      }
      return ls;
    }
  };

  for (auto c: grid->cells) {
    auto nws = NW(c);
    if (nws.size() < 1)
      continue;
    auto linkTo = *select_randomly(begin(nws), end(nws));
    std::cout << "link" << c << " --- " << *linkTo << std::endl;
    c.link(linkTo);
  }
  
  std::cout << *grid << std::endl;

}
