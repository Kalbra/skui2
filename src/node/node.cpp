#include "node.h"

Node::Node(QObject *parent)
    : QObject{parent}
{}

void Node::setPanel(QWidget *panel_widget)
{
    m_panel = panel_widget;

    Visual *visual = new Visual(m_panel, 0);
    m_visual = visual;
    paintVisual(visual);
}

Interface *Node::getInterface(const QString &identifier)
{
    for (Interface &interface : m_interfaces) {
        if (interface.getIdentifier() == identifier) {
            return &interface;
        }
    }

    return nullptr;  // No interface found with the given identifier
}