#include "slider.h"

Slider::Slider(QWidget *parent, unsigned int uid, Node *node)
    : Visual(parent, uid, node)
{
    setGeometry(QRect(200, 200, 400, 100));
    setMinimumSize(QSize(400, 100));
    setMouseTracking(true);

    info_name = "Slider Class";
    info_class_name = "Slider";
    info_description = "Basic Slider.";

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(QRect(0, 0, 400, 100));
    m_slider->installEventFilter(this);
    m_slider->setMouseTracking(true);
    m_slider->setMinimum(0);
    m_slider->setMaximum(100);
    m_slider->show();

    int value = 1;
}

bool Slider::eventFilter(QObject *object, QEvent *event)
{
    if (object == m_slider) {
        //return Visual::checkForParentHandling(event);
    }
    return QWidget::eventFilter(object, event);
}
