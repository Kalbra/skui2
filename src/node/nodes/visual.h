#ifndef VISUAL_H
#define VISUAL_H

#include <QLoggingCategory>

#include "../../panel/visual_container.h"
#include "../node.h"

class Visual : public Node
{
    Q_OBJECT

public:
    explicit Visual(QObject *parent = nullptr);
    virtual ~Visual() {};

    void setPanel(QWidget *panel_widget, QPoint position = QPoint(0, 0));
    void setPanelPosition(QPoint);
    virtual QWidget *paintWidget(VisualContainer *parent);

protected:
    /** @brief Set various configurations
     * 
     * This method sets the object name of instance.
     * It contains the class name and an instance counter.
     * The method also logs the creation of the object.
     */
    void config();

private:
    VisualContainer *m_visual_container = nullptr;
    QWidget *m_visual_widget = nullptr;
    static QMap<QString, int> instance_counter;
};

#endif // VISUAL_H