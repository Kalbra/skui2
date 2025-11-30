#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QJsonObject>
#include <QObject>

#include "panel.h"
#include "visual.h"
#include "visuals/test.h"

#include "outbound.h"

class Document : QObject
{
    Q_OBJECT

public:
    Document(Panel *);
    ~Document();

    QJsonObject save();
    void load(QJsonObject);

    Visual *createVisual(VisualType type);

    DisplayMode display_mode = DisplayMode::Run;

private:
    unsigned int visual_uid_count = 0;
    QList<VisualContainer> visuals;
    QList<Outbound> outbounds;

    Panel *panel;
};

#endif // DOCUMENT_H
