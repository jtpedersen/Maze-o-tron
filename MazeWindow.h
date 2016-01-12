#ifndef MAZEWINDOW_H_
#define MAZEWINDOW_H_

#include <QtWidgets>

class MazeWindow : public QMainWindow
{
  Q_OBJECT
 public:
  MazeWindow();

 private:

  void init();
  void createActions();
  void setupToolBar();

  void createMaze();
  
  QGraphicsScene *scene; 
  QGraphicsView *view;
  QToolBar *toolbar;

  QAction *newMaze;
  
  class Grid *grid;
};

#endif /* !MAZEWINDOW_H_ */
