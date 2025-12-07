#include "nodeeditor.h"

NodeEditor::NodeEditor(QWidget *parent)
    : QGraphicsView{parent}
{
    m_scene = new NodeEditorScene(parent);
    setScene(m_scene);
    setSceneRect(0, 0, 1000, 1000);
    centerOn(0, 0);

    //setDragMode(DragMode::ScrollHandDrag);
    setResizeAnchor(ViewportAnchor::AnchorUnderMouse);
}

void NodeEditor::addNode(Node *node)
{
    m_scene->addNode(node);
}