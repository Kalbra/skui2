#ifndef SLIDER_H
#define SLIDER_H

#include <QDebug>
#include <QSlider>

#include "../node.h"

class Slider : public Node
{
    Q_OBJECT
public:
    explicit Slider(QObject *parent = nullptr);

private slots:
    void onSliderValueChanged(int value);

private:
    void paintVisual(Visual *panel) override;
};

#endif // SLIDER_H