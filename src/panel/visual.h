#ifndef VISUAL_H
#define VISUAL_H

#include <QDebug>
#include <QLayout>
#include <QLoggingCategory>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QPoint>
#include <QResizeEvent>
#include <QSizeGrip>
#include <QString>
#include <QWidget>

#include "resizeboundingbox.h"

enum class DisplayMode { Run, Edit };

enum class VisualType { Parent, Test, Slider };

const QEvent::Type PANEL_HANDLED_ON_EDIT_MODE[] = {QEvent::MouseButtonPress,
                                                   QEvent::MouseButtonRelease,
                                                   QEvent::MouseMove};

struct VisualContainer
{
    void *ptr;
    VisualType type;
};

class Visual : public QWidget
{
    Q_OBJECT

public:
    explicit Visual(QWidget *panel = nullptr, unsigned int uid = 0);
    virtual ~Visual() {};

    void remove();
    void setGeometry(QRect);

    ResizeBoundingBox *resize_bounding_box;

public slots:
    void setMode(DisplayMode);
    void changeGeometry(QRect);
    void changeGeometryByDelta(DragDirection, QPointF);
    void setMinimumSize(QSize);

protected:
    bool checkForParentHandling(QEvent *);

private:
    int m_uid;

    void logInitiation();

    DisplayMode m_display_mode = DisplayMode::Run;
    QPointF last_global_position;

    void enableSizeGrip();
    void disableSizeGrip();
};

#endif // VISUAL_H
