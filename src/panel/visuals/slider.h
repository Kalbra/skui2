#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>

#include "../node/node.h"
#include "../visual.h"

class Slider : public Visual
{
    Q_OBJECT
public:
    explicit Slider(QWidget *parent = nullptr, unsigned int uid = 0, Node *node = nullptr);

protected:
    bool eventFilter(QObject *, QEvent *) override;

private:
    QSlider *m_slider;
};

#endif // SLIDER_H
