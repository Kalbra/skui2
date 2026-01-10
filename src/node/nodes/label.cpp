#include "label.h"

Label::Label(QObject *parent)
    : Node{parent}
{
    setProperty("name", "Label");
    Interface text_interface = Interface(QVariant(0), InterfaceDirection::Input, "text");

    setInterfaces({text_interface});
    getInterface("text")->setCallback([this]() { setText(); });
}

void Label::paintVisual(Visual *visual)
{
    visual->setGeometry(QRect(100, 100, 200, 50));
    visual->setMinimumSize(QSize(200, 50));
    visual->setMouseTracking(true);

    //Create a label in the panel for this node.
    m_label = new QLabel("Label Text", visual);
    m_label->setGeometry(10, 10, 180, 30);
    m_label->show();
    qDebug() << "Label created";
}

void Label::setText()
{
    Interface *text_interface = getInterface("text");
    if (text_interface && m_label) {
        m_label->setText(text_interface->toString());
    }
}