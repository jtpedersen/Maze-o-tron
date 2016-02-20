#ifndef MAZEWINDOW_H_
#define MAZEWINDOW_H_

#include "Colorizer.h"
#include "Maker.h"
#include "MazeWidget.h"

#include <QtWidgets>
#include <memory>

class Grid;

class MazeWindow : public QMainWindow
{
  Q_OBJECT
 public:
  MazeWindow();

 private:

  void init();
  void createActions();
  void setupToolBar();
  
  // create a grid to build a maze on
  void createMaze();
  //take a step, trigger new step later
  void tick();
  
  QToolBar *toolbar = nullptr;

  QAction *newMaze = nullptr;
  QAction *playAction = nullptr;
  QAction *pauseAction = nullptr;
  QAction *stepAction = nullptr;
  QAction *stopAction = nullptr;

  QComboBox *algorithmSelector = nullptr;
  QSpinBox *dimensionSetter = nullptr;

  std::shared_ptr<Maker> maker;

  MazeWidget *mazeWidget = nullptr;
};

#endif /* !MAZEWINDOW_H_ */
