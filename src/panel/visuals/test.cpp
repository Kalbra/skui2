#include "test.h"

Test::Test(QWidget *panel, unsigned int uid)
    : Visual(panel, uid)
{
    setGeometry(QRect(200, 200, 200, 200));
    setMinimumSize(QSize(200, 200));

    qDebug() << geometry();

    QLabel *button = new QLabel("TEST", this);
    button->show();

    qDebug() << geometry();
}
