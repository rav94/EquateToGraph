#ifndef COSINE_GUI_H
#define COSINE_GUI_H

#include <QDialog>

namespace Ui
{
    class cosine_gui;
}

class cosine_gui : public QDialog
{
    Q_OBJECT

public:
    explicit cosine_gui(QWidget *parent = 0);
    ~cosine_gui();

private:
    Ui::cosine_gui *ui;
};

#endif // COSINE_GUI_H
