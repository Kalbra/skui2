#include "slider.h"

Slider::Slider(QObject *parent)
    : Node{parent}
{
    setInterfaces({Interface(QVariant(0), InterfaceDirection::Output, "value")});
    setProperty("name", "Slider");
}

void Slider::paintVisual(Visual *visual)
{
    visual->setGeometry(QRect(200, 200, 400, 100));
    visual->setMinimumSize(QSize(400, 100));
    visual->setMouseTracking(true);

    //Create a slider in the panel for this node.
    QSlider *slider = new QSlider(visual);
    slider->setOrientation(Qt::Horizontal);
    slider->setGeometry(10, 10, 200, 30);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setValue(50);
    slider->show();
    qDebug() << "Slider created";
    connect(slider, &QSlider::valueChanged, this, &Slider::onSliderValueChanged);
}

void Slider::onSliderValueChanged(int value)
{
    Interface *value_interface = getInterface("value");
    if (value_interface) {
        qDebug() << "Slider value changed to:" << value;
        value_interface->setValue(QVariant(value));

        value_interface->update();
    }
}