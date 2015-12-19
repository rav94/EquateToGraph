#ifndef LINEAR_GUI_H
#define LINEAR_GUI_H

#include <QDialog>

#include "saveimage.h"


namespace Ui
{
    class linear_gui;
}

//Inherits SetValue
class linear_gui : public QDialog
{
    Q_OBJECT

public:
    explicit linear_gui(QWidget *parent = 0);
    ~linear_gui();

    //getter and setter methods for m_yValue
    double yValue() const;
    void setYValue(double yValue);

    //getter and setter methods for m_xValue
    double xValue() const;
    void setXValue(double xValue);

    //getter and setter methods for m_cValue
    double cValue() const;
    void setCValue(double cValue);

private slots:

    void on_btn_gradientValve_clicked();

    void on_btn_funcDetail_clicked();

    void on_btn_graphDraw_clicked();

    void makePlot();

private:
    Ui::linear_gui *ui;

    double calculateGradient();

    void setUiElements();

    //member vriables for linear_gui
    double m_yValue;
    double m_xValue;
    double m_cValue;

};

#endif // LINEAR_GUI_H
