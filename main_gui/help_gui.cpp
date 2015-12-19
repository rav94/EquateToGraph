#include "help_gui.h"
#include "ui_help_gui.h"

help_gui::help_gui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_gui)
{
    ui->setupUi(this);
}

help_gui::~help_gui()
{
    delete ui;
}
