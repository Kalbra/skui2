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
    explicit Node(QObject *parent)
        : QObject{parent} {};

    Q_PROPERTY(QString name MEMBER m_name)

    void setInterfaces(const QList<Interface> &interfaces)
    {
        m_interfaces = interfaces;
    }
    const QList<Interface> &getInterfaces() { return m_interfaces; }

virtual void valueChange(const Interface &) ;

signals:
    void changedInterfaceValue(const Interface &);

private:
    QString m_name;

    QList<Interface> m_interfaces;
};

#endif // NODE_H