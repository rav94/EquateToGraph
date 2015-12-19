#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Qt Libraries
#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_actionExit_triggered();

    void on_actionLinear_triggered();

    void on_actionQuadritic_triggered();

    void on_actionCubic_triggered();

    void on_actionSine_triggered();

    void on_actionCosine_triggered();

    void on_actionTan_triggered();

    void on_actionAbout_EquateToGraph_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionHelp_triggered();

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
