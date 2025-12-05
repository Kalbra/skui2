#ifndef NODEEDITORVIEWPORT_H
#define NODEEDITORVIEWPORT_H

#include <QGraphicsView>

#include "nodeeditor_scence.h"

class NodeEditorViewPort : public QGraphicsView
{
    Q_OBJECT
public:
    explicit NodeEditorViewPort(QWidget *parent = nullptr);
};

#endif // NODEEDITORVIEWPORT_H