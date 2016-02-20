#include "MazeWidget.h"
#include "Colorizer.h"

#include <QColor>
#include <QPainter>


MazeWidget::MazeWidget(std::shared_ptr<Maker> maker) 
  : maker_(maker)
{
  colorizer_ = std::make_shared<UniformColorizer>();
}

void MazeWidget::setMaker(std::shared_ptr<Maker> maker) {
  maker_ = maker;
  update();
}

void MazeWidget::setColorizer(std::shared_ptr<Colorizer> colorizer) {
  colorizer_ = colorizer;
  update();
}

void MazeWidget::paintEvent(QPaintEvent * event) {
  if (!maker_) return;
  const auto& grid = maker_->grid();
  qreal cellSize = 35;
  QPainter painter(this);

  // background
  for(const auto&c :grid.getCells()) {
    qreal x1 = c.x() * cellSize;
    qreal y1 = c.y() * cellSize;
    qreal x2 = x1 + cellSize;
    qreal y2 = y1 + cellSize;

    auto color = colorizer_->getColorForCell(c.idx());
    painter.fillRect(x1,y1,cellSize,cellSize, color);
  }
  
  QPen border(QColor(0,0,0));
  for(const auto&c :grid.getCells()) {
    qreal x1 = c.x() * cellSize;
    qreal y1 = c.y() * cellSize;
    qreal x2 = x1 + cellSize;
    qreal y2 = y1 + cellSize;

    if (c.N < 0)
      painter.drawLine(x1,y1, x2,y1);
    if (c.W < 0)
      painter.drawLine(x1,y1, x1,y2);
    if ( ! grid.linked(c.idx(), c.E))
      painter.drawLine(x2,y1, x2,y2);
    if ( ! grid.linked(c.idx(), c.S))
      painter.drawLine(x1,y2, x2,y2);

  }

  
}
  
