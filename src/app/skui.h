#ifndef SKUI_H
#define SKUI_H

#include <QApplication>
#include <QDebug>
#include <QEvent>

class Skui : public QApplication
{
public:
    explicit Skui(int &, char **);

    bool notify(QObject *, QEvent *) override;
};

#endif // SKUI_H
