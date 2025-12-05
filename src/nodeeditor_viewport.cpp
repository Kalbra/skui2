#include "nodeeditor_viewport.h"

NodeEditorViewPort::NodeEditorViewPort(QWidget *parent)
    : QGraphicsView{parent}
{
    setScene(new NodeEditorScence(parent));

    //setDragMode(DragMode::ScrollHandDrag);
    setResizeAnchor(ViewportAnchor::AnchorUnderMouse);
}