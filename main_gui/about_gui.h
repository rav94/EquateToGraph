#ifndef ABOUT_GUI_H
#define ABOUT_GUI_H

#include <QDialog>

namespace Ui
{
    class about_gui;
}

class about_gui : public QDialog
{
    Q_OBJECT

public:
    explicit about_gui(QWidget *parent = 0);
    ~about_gui();

private:
    Ui::about_gui *ui;

};

#endif // ABOUT_GUI_H
