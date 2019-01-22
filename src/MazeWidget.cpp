#include "MazeWidget.h"
#include "Colorizer.h"

#include <QColor>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>
#include <cmath>

MazeWidget::MazeWidget(std::shared_ptr<Maker> maker) : maker_(maker) {
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

void MazeWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);

  if (!maker_)
    return;
  const auto &grid = maker_->grid();

  const auto vsize = int(window()->height()) / grid.h();
  const auto hsize = int(window()->width()) / grid.w();

  cellSize = std::min(hsize, vsize);

  QVector<QLineF> lines;
  for (const auto &c : grid.getCells()) {
    qreal x1 = c.x() * cellSize;
    qreal y1 = c.y() * cellSize;
    qreal x2 = x1 + cellSize;
    qreal y2 = y1 + cellSize;

    auto color = colorizer_->getColorForCell(c.idx());
    if (c.idx() == clickIdx) {
      color = QColor::fromHsv(30, 200, 200);
    }
    painter.fillRect(x1, y1, cellSize, cellSize, color);

    if (c.N < 0)
      lines << QLineF(x1, y1, x2, y1);
    if (c.W < 0)
      lines << QLineF(x1, y1, x1, y2);
    if (!grid.linked(c.idx(), c.E))
      lines << QLineF(x2, y1, x2, y2);
    if (!grid.linked(c.idx(), c.S))
      lines << QLineF(x1, y2, x2, y2);
  }
  painter.drawLines(lines);
}

void MazeWidget::mousePressEvent(QMouseEvent *event) {
  click = event->pos();
  if (maker_) {
    const auto &grid = maker_->grid();
    auto x = std::floor(click.x() / cellSize);
    auto y = std::floor(click.y() / cellSize);
    clickIdx = y * grid.w() + x;
    qDebug() << x << ", " << y << " => " << clickIdx;
  }
  repaint();
}

int MazeWidget::getClicked() { return clickIdx; }
