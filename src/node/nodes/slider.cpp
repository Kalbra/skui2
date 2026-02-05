#include "slider.h"

Slider::Slider(QObject *parent)
    : Visual{parent}
{
    config();
    setInterfaces({Interface(QVariant(0), InterfaceDirection::Output, "value")});
}

QWidget *Slider::paintWidget(VisualContainer *visual_container)
{
    //Create a slider in the panel for this node.
    QSlider *slider = new QSlider(visual_container);
    slider->setOrientation(Qt::Horizontal);
<<<<<<< HEAD
=======
    //slider->setFixedSize(200, 30);
>>>>>>> f6f6ac898a1457f9f4378ef833cadc560b34b075
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setValue(50);
    slider->show();
    connect(slider, &QSlider::valueChanged, this, &Slider::onSliderValueChanged);
    return slider;
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