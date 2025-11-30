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

#include "interfacehandler.h"
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
    explicit Visual(QWidget *parent = nullptr, unsigned int uid = 0);
    virtual ~Visual() {};

    void remove();
    void setGeometry(QRect);

    ResizeBoundingBox *resize_bounding_box;

public slots:
    void setMode(DisplayMode);
    void changeGeometry(QRect);
    void changeGeometryByDelta(DragDirection, QPointF);

protected:
    QString info_name = "Base Class";
    QString info_class_name = "Visual";
    QString info_description = "This class is the base for every visual. If you can see this, the "
                               "base class is called without a child.";

    void setMinimumSize(QSize);
    void makeInterface(InterfaceInfo, InterfaceDirection);

    bool checkForParentHandling(QEvent *);

private:
    int uid;

    void logInitiation();

    DisplayMode m_display_mode = DisplayMode::Run;
    QPointF last_global_position;

    void enableSizeGrip();
    void disableSizeGrip();
};

#endif // VISUAL_H
