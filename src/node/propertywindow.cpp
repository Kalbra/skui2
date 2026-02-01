#include "propertywindow.h"

PropertyWindow::PropertyWindow(QWidget* parent, QObject* object)
    : QWidget{parent, Qt::Window}
{
    if (!object)
        return;

    QFormLayout* layout = new QFormLayout(this);

    const QMetaObject* meta = object->metaObject();
    for (int i = 0; i < meta->propertyCount(); ++i) {
        QMetaProperty prop = meta->property(i);
        QString name = prop.name();
        QVariant value = object->property(name.toLatin1());
        QLabel* nameLabel = new QLabel(name);
        QLabel* valueLabel = new QLabel(value.toString());
        layout->addRow(nameLabel, valueLabel);
    }

    setLayout(layout);
    setWindowTitle("Properties of " + object->objectName());
}
