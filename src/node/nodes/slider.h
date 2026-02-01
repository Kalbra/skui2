#ifndef SLIDER_H
#define SLIDER_H

#include <QDebug>
#include <QSlider>

#include "visual.h"

class Slider : public Visual
{
    Q_OBJECT
public:
    explicit Slider(QObject *parent = nullptr);

private slots:
    void onSliderValueChanged(int value);

private:
    QWidget *paintWidget(VisualContainer *) override;
};

#endif // SLIDER_H