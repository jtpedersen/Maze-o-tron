#ifndef MAZEWINDOW_H_
#define MAZEWINDOW_H_

#include <QtWidgets>
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

  void createMaze();
  
  QGraphicsScene *scene; 
  QGraphicsView *view;
  QToolBar *toolbar;

  QAction *newMaze;
  
};

#endif /* !MAZEWINDOW_H_ */
