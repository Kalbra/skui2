#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

#include "visual.h"

class Label : public Visual
{
    Q_OBJECT

public:
    explicit Label(QObject *parent = nullptr);

private:
    QWidget *paintWidget(VisualContainer *) override;
    void setText();

    QLabel *m_label;
};

#endif // LABEL_H