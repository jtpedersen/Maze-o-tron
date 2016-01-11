#ifndef MAZEWINDOW_H_
#define MAZEWINDOW_H_

#include <QtWidgets>

class MazeWindow : public QMainWindow
{
  Q_OBJECT
 public:
  MazeWindow();

  /* private slots: */

 private:
  void init();
  void createActions();
  void setupToolBar();
  
  QGraphicsScene *scene; 
  QGraphicsView *view;
  QToolBar *toolbar;


  QAction *newMaze;
};

#endif /* !MAZEWINDOW_H_ */
