#ifndef NODE_H
#define NODE_H

#include <QHash>
#include <QObject>
#include <QVariant>

#include "interface.h"

class Node : public QObject
{
    Q_OBJECT

public:
    explicit Node(QObject *parent);

    Q_PROPERTY(QString name MEMBER m_name)

    void setInterfaces(const QList<Interface> &interfaces) { m_interfaces = interfaces; }
    QList<Interface> &getInterfaces() { return m_interfaces; }
    Interface *getInterface(const QString &identifier);

signals:
    void changedInterfaceValue(const Interface &);

private:
    QString m_name;
    QWidget *m_nodeeditor = nullptr;

    QList<Interface> m_interfaces;
};

#endif // NODE_H