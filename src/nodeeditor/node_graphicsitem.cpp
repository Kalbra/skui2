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

    m_font = painter->font();
    m_font.setBold(true);
    m_font.setPixelSize(FONT_SIZE);
    painter->setFont(m_font);

    drawOuterFrame(painter);
    drawPads(painter);
}

void NodeGraphicsItem::drawOuterFrame(QPainter *painter)
{
    QRect node_name_bounding = QFontMetrics(m_font).boundingRect(
        m_node->property("name").toString());

    m_rect_width = node_name_bounding.width() + BOX_WIDTH * 2 + BOX_MARGIN.right() * 2;
    painter->drawRect(PAD_SPACING, 0, m_rect_width, 200);
    painter->drawText(BOX_MARGIN.left() + BOX_WIDTH + PAD_SPACING,
                      BOX_MARGIN.top() - node_name_bounding.y(),
                      m_node->property("name").toString());
}

void NodeGraphicsItem::drawPads(QPainter *painter)
{
    int left_y_offset = PAD_SPACING;
    int right_y_offset = PAD_SPACING;
    for (const Interface &interface : m_node->getInterfaces()) {
        if (interface.getDirection() == InterfaceDirection::Input) {
            painter->drawRect(0, left_y_offset, PAD_SIZE, PAD_SIZE);
            left_y_offset += PAD_SPACING;
        } else if (interface.getDirection() == InterfaceDirection::Output) {
            painter->drawRect(m_rect_width + BOX_WIDTH * 2 + PAD_SIZE,
                              right_y_offset,
                              PAD_SIZE,
                              PAD_SIZE);
            right_y_offset += PAD_SPACING;
        }
    }
}

QRectF NodeGraphicsItem::boundingRect() const
{
    return QRectF(0, 0, 800, 800);
}