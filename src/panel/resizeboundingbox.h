#ifndef RESIZEBOUNDINGBOX_H
#define RESIZEBOUNDINGBOX_H

#include <QCursor>
#include <QMargins>
#include <QMouseEvent>
#include <QPainter>
#include <QWidget>

const int OUTER_HITBOX_SIZE = 10;
const QMargins WIDGET_MARGIN(20, 20, 20, 20);
const QMargins CENTER_HITBOX_MARGIN(15, 15, 15, 15);

enum class DragDirection {
    NorthWest,
    North,
    NorthEast,
    East,
    SouthEast,
    South,
    SouthWest,
    West,
    Center,
    None,
};

class ResizeBoundingBox : public QWidget
{
    Q_OBJECT
public:
    explicit ResizeBoundingBox(QWidget *parent = nullptr);

    void setBoxGeometry(QRect);
    void setBoxMinimumSize(QSize);

protected:
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;

    void paintEvent(QPaintEvent *) override;

signals:
    void changedGeometry(QRect);
    void changedDelta(DragDirection, QPointF);

private:
    QRect box_geometry;

    QRect mapRectFromParent(QRect);
    static QRect squareByCenter(QPoint, int);
    QMap<DragDirection, QPoint> outerHitboxPositions();
    QMap<DragDirection, QRect> hitboxes();
    DragDirection containesHitbox(QPoint);
    void setHoverCursor(DragDirection);

    DragDirection active_direction = DragDirection::None;
    bool mouse_pressed = false;

    QPointF last_global_position;
    QRect last_geometry;
};

#endif // RESIZEBOUNDINGBOX_H
