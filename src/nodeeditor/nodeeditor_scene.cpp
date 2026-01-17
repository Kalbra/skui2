#include "nodeeditor_scene.h"

NodeEditorScene::NodeEditorScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setBackgroundBrush(Qt::white);

    //NodeGraphicsItem *node = new NodeGraphicsItem();
    //node->setPos(100, 100);

    //addItem(node);
    //addRect(QRect(100, 1000, 200, 200), QPen(), QBrush(Qt::blue));
}

void NodeEditorScene::addNode(Node *node)
{
    m_nodes.append(node);
    m_debug_x = m_debug_x + 300;
    NodeGraphicsItem *node_graphicitem = new NodeGraphicsItem(nullptr, node);
    node_graphicitem->setPos(m_debug_x, 100);
    addItem(node_graphicitem);
}