#ifndef PANEL_H
#define PANEL_H

#include <QChildEvent>
#include <QGuiApplication>
#include <QLoggingCategory>
#include <QMouseEvent>
#include <QRubberBand>
#include <QWidget>

#include "skuievent.h"
#include "visual.h"

enum class AlignDirection { Top, Right, Bottom, Left, Horizontal, Vertical };

const int MAX_MOUSE_WIGGLE_TOLERANCE = 5; // px of size

class Panel : public QWidget
{
    Q_OBJECT
public:
    explicit Panel(QWidget *parent = nullptr);

protected:
    void mousePressChanged(QMouseEvent *);
    void mousePositionChanged(QMouseEvent *);
    void mouseReleaseChanged(QMouseEvent *);

    bool event(QEvent *) override;

public:
    void addVisual(Visual *);

public slots:
    void setMode(DisplayMode);
    void triggeredAlign(AlignDirection);
    void changeGeometryForSelected(DragDirection, QPointF);

private:
    QPoint origin;
    QPointF last_global_position;
    bool mouse_pressed = false;
    QRubberBand *rubber_band;
    DisplayMode display_mode;
    QList<Visual *> selected_visuals;

    void select(Visual *);
    void deselectAll();
    QList<Visual *> visualChildIn(QRect);
    Visual *visualChildAt(QPoint);
    bool inMouseWiggleTolerance(QSize);
    void selectSingle(QPoint);
    void selectMultiple(QList<Visual *>);
    void alignVisualToBoundingBox(AlignDirection, Visual *, QRect);
    QRect calculateMinimumBoundingBox(const QList<Visual *> &);
};

#endif // PANEL_H
