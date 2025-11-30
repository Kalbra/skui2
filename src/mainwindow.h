#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QMainWindow>

#include "document.h"
#include "panel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct VisualMenuAction
{
    QString name;
    VisualType type;
};

struct AlignTool
{
    QString tool_tip;
    AlignDirection direction;
    QIcon icon;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Document *focus_document;

signals:
    void modeChanged(DisplayMode);

private slots:
    void on_mode_changed_button_clicked();

private:
    Ui::MainWindow *ui;

    Panel *panel;

    void loadInsertVisualMenu();
    void loadAlignTools();
    const QIcon loadIcon(const QString &);
};
#endif // MAINWINDOW_H
