#ifndef MAZEWIDGET_H_
#define MAZEWIDGET_H_
#include <Maker.h>
#include "Colorizer.h"

#include <QWidget>
#include <memory>


class MazeWidget : public QWidget {
  Q_OBJECT
 public:
  MazeWidget(std::shared_ptr<Maker> maker);
  void setMaker(std::shared_ptr<Maker> maker);
  void setColorizer(std::shared_ptr<Colorizer> colorizer);
 protected:
  virtual void paintEvent(QPaintEvent * event) override;

private:
  std::shared_ptr<Maker> maker_;
  std::shared_ptr<Colorizer> colorizer_;
};

#endif /* !MAZEWIDGET_H_ */
