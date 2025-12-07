#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QJsonObject>
#include <QObject>

#include "panel.h"
#include "visual.h"
#include "visuals/test.h"

class Document : QObject
{
    Q_OBJECT

public:
    Document(QObject *, Panel *);
    ~Document();

    QJsonObject save();
    void load(QJsonObject);

    Visual *createVisual(VisualType type);

    DisplayMode display_mode = DisplayMode::Run;

private:
    unsigned int visual_uid_count = 0;
    QList<VisualContainer> visuals;

    Panel *m_panel;
};

#endif // DOCUMENT_H
