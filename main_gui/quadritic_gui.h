#ifndef QUADRITIC_GUI_H
#define QUADRITIC_GUI_H

#include <QDialog>

#include "saveimage.h"

namespace Ui
{
    class quadritic_gui;
}

//Inherits SetValue
class quadritic_gui : public QDialog
{
    Q_OBJECT

public:
    explicit quadritic_gui(QWidget *parent = 0);
    ~quadritic_gui();

    //getter and setter methods for m_aValue
    double aValue() const;
    void setAValue(double aValue);

    //getter and setter methods for m_bValue
    double bValue() const;
    void setBValue(double bValue);

    //getter and setter methods for m_cValue
    double cValue() const;
    void setCValue(double cValue);

    //getter and setter methods for m_xValue
    double xValue() const;
    void setXValue(double xValue);


private slots:

    void on_btn_axisOfSym_clicked();

    void on_btn_discValue_clicked();

    void on_btn_funcDetail_clicked();

    void makePlot();

    void on_btn_graphDraw_clicked();

    void on_btn_saveImage_clicked();

private:
    Ui::quadritic_gui *ui;

    SaveImage *image;

    //method for delta calculation
    double calculateDelta();

    //method for axis of symmetry calculation
    double calcualteAxisofSym();

    //method for calculating the value of y
    double calculateYValue();

    //method to connect member variables with UI Elements
    void setUiElements();

    void SaveAsImage();

    //member vriables for quadritic_gui
    double m_aValue;
    double m_bValue;
    double m_cValue;
    double m_xValue;

};

#endif // QUADRITIC_GUI_H
