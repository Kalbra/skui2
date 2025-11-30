#include "mainwindow.h"
#include "ui_mainwindow.h"

Q_DECLARE_LOGGING_CATEGORY(gui)
Q_LOGGING_CATEGORY(gui, "GUI")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    panel = new Panel(ui->centralwidget);

    ui->centralwidget->layout()->addWidget(panel);

    focus_document = new Document(panel);

    loadInsertVisualMenu();

    loadAlignTools();

    connect(this, &MainWindow::modeChanged, panel, &Panel::setMode);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadInsertVisualMenu()
{
    const VisualMenuAction wrapped_actions[] = {{"Test", VisualType::Test},
                                                {"Slider", VisualType::Slider}};

    for (const VisualMenuAction &wraped_action : wrapped_actions) {
        QAction *menu_insert_action = new QAction(wraped_action.name);
        connect(menu_insert_action, &QAction::triggered, this, [this, wraped_action] {
            Visual *visual = focus_document->createVisual(wraped_action.type);
            connect(this, &MainWindow::modeChanged, visual, &Visual::setMode);
        });

        menu_insert_action->setText(wraped_action.name);
        ui->menuInsertVisual->addAction(menu_insert_action);
    }
}

const QIcon MainWindow::loadIcon(const QString &identifier)
{
    return QIcon("./assets/breeze_icon/" + identifier);
}

void MainWindow::loadAlignTools()
{
    const AlignTool align_tools[]
        = {{"Align Top", AlignDirection::Top, QIcon(":/icons/align-vertical-top.svg")},
           {"Align Right", AlignDirection::Right, QIcon(":/icons/align-horizontal-right.svg")},
           {"Align Bottom", AlignDirection::Bottom, QIcon(":/icons/align-vertical-bottom.svg")},
           {"Align Left", AlignDirection::Left, QIcon(":/icons/align-horizontal-left.svg")},
           {"Align Horizontal",
            AlignDirection::Horizontal,
            QIcon(":/icons/align-horizontal-center.svg")},
           {"Align Vertical", AlignDirection::Vertical, QIcon(":/icons/align-vertical-center.svg")}};

    for (const AlignTool &align_tool : align_tools) {
        QPushButton *align_button = new QPushButton(this);
        ui->align->addWidget(align_button);

        align_button->setIcon(align_tool.icon);
        align_button->setToolTip(align_tool.tool_tip);

        connect(align_button, &QPushButton::clicked, this, [this, align_tool] {
            panel->triggeredAlign(align_tool.direction);
        });
    }
}

void MainWindow::on_mode_changed_button_clicked()
{
    if (focus_document->display_mode == DisplayMode::Run) {
        focus_document->display_mode = DisplayMode::Edit;
        ui->mode_changed_button->setText("Run Mode");
        qInfo(gui) << "Display mode changed to Edit";
    } else {
        focus_document->display_mode = DisplayMode::Run;
        ui->mode_changed_button->setText("Edit Mode");
        qInfo(gui) << "Display mode to Run";
    }
    emit modeChanged(focus_document->display_mode);
}
