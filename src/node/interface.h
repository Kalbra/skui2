#ifndef INTERFACE_H
#define INTERFACE_H

#include <QVariant>

enum class InterfaceDirection { Output, Input };

class Interface : public QVariant
{
public:
    Interface(QVariant &, InterfaceDirection, const QString &);

    const QString &getIdentifier() { return m_identifier; };

    void update();

    bool routeTo(Interface *);

private:
    void updateRoutedInterfaces();

    const QString m_identifier;
    InterfaceDirection m_interface_direction;
    QList<Interface *> m_routed_interfaces;
};

#endif // INTERFACE_H
