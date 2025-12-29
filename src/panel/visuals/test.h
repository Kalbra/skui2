#ifndef TEST_H
#define TEST_H

#include <QLabel>

#include "../visual.h"
#include "../node/node.h"

class Test : public Visual
{
    Q_OBJECT
public:
    explicit Test(QWidget *panel = nullptr, unsigned int uid = 0, Node *node = nullptr);
};

#endif // TEST_H
