#ifndef NODE_H
#define NODE_H

#include <QHash>
#include <QObject>
#include <QVariant>

class Interface : QVariant
{
public:
    void setIdentifier(const QString &identifier) { m_identifier = identifier; }
    const QString &getIdentifier() { return m_identifier; };

private:
    QString m_identifier;
};

class Node : public QObject
{
    Q_OBJECT

public:
    explicit Node(QObject *parent)
        : QObject{parent} {};

    Q_PROPERTY(QString name MEMBER m_name)

    void setOutputInterfaces(const QList<Interface> &output_interfaces)
    {
        m_output_interfaces = output_interfaces;
    }
    const QList<Interface> &getOutputInterfaces() { return m_output_interfaces; }

    void getInputInterfaces(const QList<Interface> &input_interfaces)
    {
        m_input_interfaces = input_interfaces;
    }
    const QList<Interface> &getInputInterfaces() { return m_input_interfaces; }

public slots:
    virtual void valueChange(const Interface &) {};

signals:
    void changedInterfaceValue(const Interface &);

private:
    QString m_name;

    QList<Interface> m_output_interfaces;
    QList<Interface> m_input_interfaces;
};

#endif // NODE_H