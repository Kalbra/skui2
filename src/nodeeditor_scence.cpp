#include "nodeeditor_scence.h"

NodeEditorScence::NodeEditorScence(QObject *parent)
    : QGraphicsScene{parent}
{
    setBackgroundBrush(Qt::white);
    addRect(QRect(100, 1000, 200, 200), QPen(), QBrush(Qt::blue));
}
