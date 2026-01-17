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

Visual *Document::createVisual(VisualType type)
{
    VisualContainer container;
    container.type = type;

    if (type == VisualType::Test) {
        Label *label = new Label(this);
        label->setPanel(m_panel);
        label->setNodeEditor(m_nodeeditor);
        m_nodeeditor->addNode(label);

        connect(label->getVisual()->resize_bounding_box,
                &ResizeBoundingBox::changedDelta,
                m_panel,
                &Panel::changeGeometryForSelected);
        container.ptr = label->getVisual();
        visual_uid_count++;
    } else if (type == VisualType::Slider) {
        Slider *slider = new Slider(this);
        slider->setPanel(m_panel);
        slider->setNodeEditor(m_nodeeditor);
        m_nodeeditor->addNode(slider);

        connect(slider->getVisual()->resize_bounding_box,
                &ResizeBoundingBox::changedDelta,
                m_panel,
                &Panel::changeGeometryForSelected);

        container.ptr = slider->getVisual();
        visual_uid_count++;
    } else {
        container.ptr = nullptr;
    }

    return static_cast<Visual *>(container.ptr);
}
