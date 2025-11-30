#include "visual.h"

Q_DECLARE_LOGGING_CATEGORY(visual)
Q_LOGGING_CATEGORY(visual, "VISUAL")

Visual::Visual(QWidget *panel, unsigned int uid)
    : QWidget(panel)
{
    this->uid = uid;
    setMouseTracking(true);

    resize_bounding_box = new ResizeBoundingBox(panel);
    //resize_bounding_box->show();

    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet("background-color: lightblue; border: 1px solid blue;");
    show();
}

void Visual::setGeometry(QRect geometry)
{
    resize_bounding_box->setBoxGeometry(geometry);
    QWidget::setGeometry(geometry);
    qInfo(visual) << "Changed geometry: " << geometry;
}

void Visual::setMode(DisplayMode display_mode)
{
    m_display_mode = display_mode;
}

void Visual::setMinimumSize(QSize size)
{
    resize_bounding_box->setBoxMinimumSize(size);
    QWidget::setMinimumSize(size);
}

void Visual::changeGeometry(QRect geometry)
{
    QWidget::setGeometry(geometry);
}

void Visual::changeGeometryByDelta(DragDirection active_direction, QPointF delta)
{
    int initial_x = geometry().x();
    int initial_y = geometry().y();
    int initial_w = geometry().width();
    int initial_h = geometry().height();

    int new_x = initial_x;
    int new_y = initial_y;
    int new_w = initial_w;
    int new_h = initial_h;

    switch (active_direction) {
    case DragDirection::North: // Fixed: Bottom
        new_y = initial_y + delta.y();
        new_h = initial_h - delta.y();
        break;
    case DragDirection::NorthEast: // Fixed: BottomLeft
        new_y = initial_y + delta.y();
        new_w = initial_w + delta.x();
        new_h = initial_h - delta.y();
        break;
    case DragDirection::East: // Fixed: Left
        new_w = initial_w + delta.x();
        break;
    case DragDirection::SouthEast: // Fixed: TopLeft
        new_w = initial_w + delta.x();
        new_h = initial_h + delta.y();
        break;
    case DragDirection::South: // Fixed: Top
        new_h = initial_h + delta.y();
        break;
    case DragDirection::SouthWest: // Fixed: TopRight
        new_x = initial_x + delta.x();
        new_w = initial_w - delta.x();
        new_h = initial_h + delta.y();
        break;
    case DragDirection::West: // Fixed: Right
        new_x = initial_x + delta.x();
        new_w = initial_w - delta.x();
        break;
    case DragDirection::NorthWest: // Fixed: BottomRight
        new_x = initial_x + delta.x();
        new_y = initial_y + delta.y();
        new_w = initial_w - delta.x();
        new_h = initial_h - delta.y();
        break;
    case DragDirection::Center:
        new_x = initial_x + delta.x();
        new_y = initial_y + delta.y();
        break;
    default: // DrageDirection::None
        break;
    }

    if (new_w < minimumWidth()) {
        new_w = initial_w;
        new_x = initial_x;
    }
    if (new_h < minimumHeight()) {
        new_h = initial_h;
        new_y = initial_y;
    }

    QRect new_geometry(new_x, new_y, new_w, new_h);

    resize_bounding_box->setBoxGeometry(new_geometry);
    QWidget::setGeometry(new_geometry);
}

void Visual::logInitiation()
{
    qInfo(visual) << QString("Initiated '%1'(%2) at 0x%3")
                         .arg(info_class_name)
                         .arg(QString::number(uid))
                         .arg(reinterpret_cast<quintptr>(this), QT_POINTER_SIZE * 2, 16, QChar('0'));
}

// In Edit Mode all events in PANEL_HANDLED_ON_EDIT_MODE need to get handled by the Panel
// This could be a mouse event. The Panels needs the mouse event to handle the draging or resizing
// of the Visual. This only works if EVERY child widget ignores the given events.
bool Visual::checkForParentHandling(QEvent *event)
{
    if (m_display_mode != DisplayMode::Edit) {
        //qDebug() << event;
        return QWidget::event(event);
    }

    for (QEvent::Type panel_handled : PANEL_HANDLED_ON_EDIT_MODE) {
        if (event->type() == panel_handled) {
            return false;
        }
    }

    return QWidget::event(event);
}
