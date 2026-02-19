#include "document.h"

Document::Document(QObject *parent, Panel *panel, NodeEditor *nodeeditor)
    : QObject{parent}
    , m_panel(panel)
    , m_nodeeditor(nodeeditor)
{}

Document::~Document() {}

QJsonObject Document::save()
{
    return QJsonObject();
}

void Document::load(QJsonObject content)
{
    return;
}

void Document::createVisual(VisualType type)
{
    if (type == VisualType::Test) {
        Label *label = new Label(this);
        label->setPanel(m_panel, QPoint(200, 200));
        m_nodeeditor->addNode(label);
    } else if (type == VisualType::Slider) {
        Slider *slider = new Slider(this);
        slider->setPanel(m_panel, QPoint(400, 200));
        m_nodeeditor->addNode(slider);
    }
}
