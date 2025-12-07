#ifndef NodeEditor_H
#define NodeEditor_H

#include <QGraphicsView>

#include "node.h"
#include "nodeeditor_scene.h"

class NodeEditor : public QGraphicsView
{
    Q_OBJECT
public:
    explicit NodeEditor(QWidget *parent = nullptr);

    void addNode(Node *);

private:
    NodeEditorScene *m_scene;
};

#endif // NodeEditor_H