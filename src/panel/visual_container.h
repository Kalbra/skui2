#ifndef VISUAL_CONTAINER_H
#define VISUAL_CONTAINER_H

#include <QChildEvent>
#include <QLayout>
#include <QWidget>

class VisualContainer : public QWidget
{
    Q_OBJECT
public:
    explicit VisualContainer(QWidget *parent = nullptr);

protected:
    void childEvent(QChildEvent *) override;
};

#endif // VISUAL_CONTAINER_H