#include "MazeWindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
 
  //Q_INIT_RESOURCE(application);

  QApplication app(argc, argv);
  app.setOrganizationName("aMaze");
  app.setApplicationName("maze-o-tron");
  MazeWindow mazeWin;
  mazeWin.show();
  return app.exec();
}
