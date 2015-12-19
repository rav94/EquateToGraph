#include "about_gui.h"
#include "ui_about_gui.h"

about_gui::about_gui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about_gui)
{
    ui->setupUi(this);
}

about_gui::~about_gui()
{
    delete ui;
}
