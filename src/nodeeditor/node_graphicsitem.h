#ifndef NODE_GRAPHICSITEM_H
#define NODE_GRAPHICSITEM_H

#include <QFontMetrics>
#include <QGraphicsItem>
#include <QMargins>
#include <QPainter>
#include <QPen>
#include <QPointF>

const QMargins BOX_MARGIN(7, 7, 7, 7);
const int BOX_WIDTH = 4;
const int FONT_SIZE = 20;

class NodeGraphicsItem : public QGraphicsItem
{
public:
    explicit NodeGraphicsItem(QGraphicsItem *parent = nullptr);

    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) override;
    QRectF boundingRect() const override;

private:
    QString m_node_name;
};

#endif // NODE_GRAPHICSITEM_H