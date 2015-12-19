#ifndef CUBIC_GUI_H
#define CUBIC_GUI_H

#include <QDialog>

#include "saveimage.h"

namespace Ui
{
    class cubic_gui;
}

class cubic_gui : public QDialog
{
    Q_OBJECT

public:
    explicit cubic_gui(QWidget *parent = 0);
    ~cubic_gui();

    double aValue() const;
    void setAValue(double aValue);

    double bValue() const;
    void setBValue(double bValue);

    double cValue() const;
    void setCValue(double cValue);

    double dValue() const;
    void setDValue(double dValue);

private slots:

    void on_btn_discriminant_clicked();

    void on_btn_funcDetails_clicked();

    void on_btn_CValue_clicked();

    void makePlot();

    void on_btn_drawGraph_clicked();

private:
    Ui::cubic_gui *ui;

    double calculateDeltaZero();

    double calculateDeltaOne();

    double calculateDiscriminant();

    double calculateCValue();

    void settingUiElements();

    double m_aValue;
    double m_bValue;
    double m_cValue;
    double m_dValue;
};

#endif // CUBIC_GUI_H
