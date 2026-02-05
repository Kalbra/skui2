#ifndef PROPERTYWINDOW_H
#define PROPERTYWINDOW_H

#include <QFormLayout>
#include <QLabel>
#include <QMetaProperty>
#include <QWidget>
#include <QScrollArea>

class PropertyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PropertyWindow(QWidget *parent, QObject *object);
signals:
};

#endif // PROPERTYWINDOW_H
