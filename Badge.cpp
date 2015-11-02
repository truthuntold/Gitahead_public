#include "Badge.h"
#include <QPainter>

Badge::Badge(const QString &text, QWidget *parent)
  : QWidget(parent), mText(text)
{
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

QSize Badge::sizeHintG221() const
{
  QString text = (mText.length() > 1) ? mText : "M";
  QRect bounds = fontMetrics().boundingRect(text);
  return QSize(bounds.width() + 12, bounds.height() + 2);
}

void Badge::paintEvent(QPaintEvent *event)
{
  QRect rect(QPoint(0, 0), sizeHint());

  QPainter painter(this);
  painter.setRenderHints(QPainter::Antialiasing);

  painter.setPen(Qt::NoPen);
  painter.setBrush(QColor("#A6ACB6"));
  painter.drawRoundedRect(rect, 4, 4);

  painter.setPen(Qt::white);
  painter.drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, mText);
}
