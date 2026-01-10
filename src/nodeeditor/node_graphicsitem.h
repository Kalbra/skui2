#ifndef NODE_GRAPHICSITEM_H
#define NODE_GRAPHICSITEM_H

#include <QFontMetrics>
#include <QGraphicsItem>
#include <QMargins>
#include <QPainter>
#include <QPen>
#include <QPointF>

#include "../node/node.h"

const QMargins BOX_MARGIN(7, 7, 7, 7);
const int BOX_WIDTH = 4;
const int FONT_SIZE = 20;
const int PAD_SIZE = 5;
const int PAD_SPACING = 10;

class NodeGraphicsItem : public QGraphicsItem
{
public:
    explicit NodeGraphicsItem(QGraphicsItem *parent = nullptr, Node *node = nullptr);

    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) override;
    QRectF boundingRect() const override;

private:
    void drawOuterFrame(QPainter *painter);
    void drawPads(QPainter *painter);

    Node *m_node;
    QFont m_font;
    int m_rect_width;
};

#endif // NODE_GRAPHICSITEM_H