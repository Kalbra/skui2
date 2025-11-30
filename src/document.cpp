#include "document.h"

#include "visuals/slider.h"
#include "visuals/test.h"

Document::Document(Panel *panel)
{
    this->panel = panel;
}

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
        Test *test = new Test(panel, visual_uid_count);
        connect(test->resize_bounding_box,
                &ResizeBoundingBox::changedDelta,
                panel,
                &Panel::changeGeometryForSelected);
        container.ptr = test;
        visual_uid_count++;
    } else if (type == VisualType::Slider) {
        Slider *slider = new Slider(panel, visual_uid_count);
        connect(slider->resize_bounding_box,
                &ResizeBoundingBox::changedDelta,
                panel,
                &Panel::changeGeometryForSelected);
        container.ptr = slider;
        visual_uid_count++;
    } else {
        container.ptr = nullptr;
    }

    return static_cast<Visual *>(container.ptr);
}
