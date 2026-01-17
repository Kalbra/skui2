#ifndef NodeEditorScene_H
#define NodeEditorScene_H

#include <QGraphicsScene>

#include "node_graphicsitem.h"

class NodeEditorScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit NodeEditorScene(QObject *parent = nullptr);

    void addNode(Node *);

private:
    void createNodeGraphicsItem(Node *);

    QList<Node *> m_nodes;
    int m_debug_x;
};

#endif // NodeEditorScene_H