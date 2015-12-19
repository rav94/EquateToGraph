#ifndef HELP_GUI_H
#define HELP_GUI_H

#include <QDialog>

namespace Ui
{
    class help_gui;
}

class help_gui : public QDialog
{
    Q_OBJECT

public:
    explicit help_gui(QWidget *parent = 0);
    ~help_gui();

private:
    Ui::help_gui *ui;
};

#endif // HELP_GUI_H
