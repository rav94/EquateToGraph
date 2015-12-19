#include "mainwindow.h"
#include "ui_mainwindow.h"

//Qt Libraries
#include <QKeyEvent>
#include <QDesktopServices>
#include <QMessageBox>

//main_gui header files
#include "main_gui/linear_gui.h"
#include "main_gui/quadritic_gui.h"
#include "main_gui/cubic_gui.h"

#include "main_gui/about_gui.h"

#include "main_gui/help_gui.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose); //Memory Management

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionLinear_triggered()
{
    //Based on Modal Approach
    linear_gui linear;
    linear.setModal(true);
    linear.exec();
}

void MainWindow::on_actionQuadritic_triggered()
{
    //Based on Modal Approach
    quadritic_gui quadritic;
    quadritic.setModal(true);
    quadritic.exec();
}

void MainWindow::on_actionCubic_triggered()
{
    //Based on Modal Approach
    cubic_gui cubic;
    cubic.setModal(true);
    cubic.exec();
}

void MainWindow::on_actionAbout_EquateToGraph_triggered()
{
    //Based on Modal Approach
    about_gui about;
    about.setModal(true);
    about.exec();
}

void MainWindow::on_actionHelp_triggered()
{
    //Based on Modal Approach
    help_gui help;
    help.setModal(true);
    help.exec();
}
