#include "interface.h"

Interface::Interface(QVariant &value, InterfaceDirection interface_direction, QString &identifier)
    : QVariant{value}
    , m_interface_direction(interface_direction)
    , m_identifier(identifier)
{}

bool Interface::routeTo(Interface *target_interface)
{
    if (m_interface_direction == InterfaceDirection::Input) {
        return false; // Failed: Routing is done by output interfaces
    }
    if (this->type() != target_interface->type()) {
        return false; // Failed: Interfaces not same type
    }

    m_routed_interfaces.append(target_interface);
    target_interface->m_routed_interfaces.append(this);
}

void Interface::update()
{
    // Output Interfaces recive their update by the node after the value in the variant has changed.
    // Input Interfaces do not see the node of the output interfaces.
    // Therefore the Output Interface sends an update function call to the routed / connected input node.
    if (m_interface_direction == InterfaceDirection::Output) {
        updateRoutedInterfaces();
    }
}

void Interface::updateRoutedInterfaces()
{
    for (Interface *routed_interface : m_routed_interfaces) {
        routed_interface->update();
    }
}