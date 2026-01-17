#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

#include "../node.h"

class Label : public Node
{
    Q_OBJECT

public:
    explicit Label(QObject *parent = nullptr);

private:
    void paintVisual(Visual *panel) override;
    void setText();

    QLabel *m_label;
};

#endif // LABEL_H