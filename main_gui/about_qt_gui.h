#ifndef ABOUT_QT_GUI_H
#define ABOUT_QT_GUI_H

#include <QDialog>

namespace Ui
{
    class about_qt_gui;
}

class about_qt_gui : public QDialog
{
    Q_OBJECT

public:
    explicit about_qt_gui(QWidget *parent = 0);
    ~about_qt_gui();

private:
    Ui::about_qt_gui *ui;
};

#endif // ABOUT_QT_GUI_H
