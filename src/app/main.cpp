#include "mainwindow.h"
#include "skui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qSetMessagePattern("%{time yyyy-MM-dd hh:mm:ss,zzz} [%{type}] %{category}: %{message}");

    Skui skui(argc, argv);
    MainWindow main_window;
    main_window.show();
    return skui.exec();
}
