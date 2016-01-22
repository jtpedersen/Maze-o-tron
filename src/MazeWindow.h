#ifndef MAZEWINDOW_H_
#define MAZEWINDOW_H_

#include <QtWidgets>
#include <memory>

#include "BinTreeMaker.h"

class Grid;



class MazeWindow : public QMainWindow
{
  Q_OBJECT
 public:
  MazeWindow();

  void drawMaze(const Grid& grid);

 private:

  void init();
  void createActions();
  void setupToolBar();
  
  // create a grid to build a maze on
  void createMaze();
  //take a step
  
  QGraphicsScene *scene = nullptr;
  QGraphicsView *view = nullptr;
  QToolBar *toolbar = nullptr;

  QAction *newMaze = nullptr;
  QAction *playAction = nullptr;
  QAction *pauseAction = nullptr;
  QAction *stepAction = nullptr;
  QAction *stopAction = nullptr;
  
  std::unique_ptr<Maker> maker;



};

#endif /* !MAZEWINDOW_H_ */
