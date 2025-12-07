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
        Node *node = new Node(this);
        m_nodeeditor->addNode(node);
        Test *test = new Test(m_panel, visual_uid_count, node);
        connect(test->resize_bounding_box,
                &ResizeBoundingBox::changedDelta,
                m_panel,
                &Panel::changeGeometryForSelected);
        container.ptr = test;
        visual_uid_count++;
    } else if (type == VisualType::Slider) {
        Node *node = new Node(this);
        m_nodeeditor->addNode(node);
        Slider *slider = new Slider(m_panel, visual_uid_count, node);
        connect(slider->resize_bounding_box,
                &ResizeBoundingBox::changedDelta,
                m_panel,
                &Panel::changeGeometryForSelected);
        container.ptr = slider;
        visual_uid_count++;
    } else {
        container.ptr = nullptr;
    }

    return static_cast<Visual *>(container.ptr);
}
