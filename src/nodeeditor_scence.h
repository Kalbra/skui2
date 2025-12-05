#ifndef NODEEDITORSCENCE_H
#define NODEEDITORSCENCE_H

#include <QGraphicsScene>

class NodeEditorScence : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit NodeEditorScence(QObject *parent = nullptr);
};

#endif // NODEEDITORSCENCE_H