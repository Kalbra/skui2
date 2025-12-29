#include "node_graphicsitem.h"

NodeGraphicsItem::NodeGraphicsItem(QGraphicsItem *parent, Node *node)
    : QGraphicsItem{parent}
    , m_node(node)
{}

void NodeGraphicsItem::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget)
{
    QPen pen(QColorConstants::DarkRed, BOX_WIDTH);
    painter->setPen(pen);

    QFont font = painter->font();
    font.setBold(true);
    font.setPixelSize(FONT_SIZE);
    painter->setFont(font);
    QRect node_name_bounding = QFontMetrics(font).boundingRect(m_node->property("name").toString());

    int rect_width = node_name_bounding.width() + BOX_WIDTH * 2 + BOX_MARGIN.right() * 2;
    painter->drawRect(0, 0, rect_width, 200);
    painter->drawText(BOX_MARGIN.left() + BOX_WIDTH,
                      BOX_MARGIN.top() - node_name_bounding.y(),
                      m_node->property("name").toString());
}

QRectF NodeGraphicsItem::boundingRect() const
{
    return QRectF(0, 0, 800, 800);
}