#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QJsonObject>
#include <QObject>

#include "nodeeditor.h"
#include "nodes/label.h"
#include "nodes/slider.h"
#include "panel.h"
#include "visual.h"
#include "visuals/test.h"

class Document : QObject
{
    Q_OBJECT

public:
    Document(QObject *, Panel *, NodeEditor *);
    ~Document();

    QJsonObject save();
    void load(QJsonObject);

    Visual *createVisual(VisualType type);

    DisplayMode display_mode = DisplayMode::Run;

private:
    unsigned int visual_uid_count = 0;
    QList<VisualContainer> visuals;

    Panel *m_panel;
    NodeEditor *m_nodeeditor;
};

#endif // DOCUMENT_H
