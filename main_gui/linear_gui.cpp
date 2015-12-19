#include "linear_gui.h"
#include "ui_linear_gui.h"

#include <QMessageBox>
#include <QtMath>



linear_gui::linear_gui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::linear_gui)
{
    ui->setupUi(this);

    //slot for draw button Draw Gaph
    QObject::connect(ui->btn_graphDraw, SIGNAL(clicked(bool)), this, SLOT(viewGraph()));
}

linear_gui::~linear_gui()
{
    delete ui;

}

//get set methods decleration
double linear_gui::yValue() const
{
    return m_yValue;
}

void linear_gui::setYValue(double yValue)
{  
    m_yValue = yValue;
}

double linear_gui::xValue() const
{
    return m_xValue;
}

void linear_gui::setXValue(double xValue)
{
    m_xValue = xValue;
}

double linear_gui::cValue() const
{
    return m_cValue;
}

void linear_gui::setCValue(double cValue)
{
    m_cValue = cValue;
}

//private methods decleration
double linear_gui::calculateGradient()
{

    if(ui->line_cValue->text().trimmed().length() == 0)
    {
        double gradient = yValue() / xValue() ;
        return gradient;
    }
    else
    {
        double gradient =  ( yValue() / xValue() )  - cValue();
        return gradient;
    }

}

void linear_gui::setUiElements()
{
    //method decleration for intiating linking ui elements with setters of member variables
    setXValue(ui->line_xValue->text().toDouble());
    setYValue(ui->line_yValue->text().toDouble());
    setCValue(ui->line_cValue->text().toDouble());
}


//event-driven methods
void linear_gui::on_btn_gradientValve_clicked()
{
    if(ui->line_xValue->text().trimmed().length() == 0 | ui->line_yValue->text().trimmed().length() == 0)
    {
        QMessageBox msgBox;
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/title_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        msgBox.setWindowIcon(icon);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Please do fill y and x values to proceed.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
        setUiElements();

        double gradientValue = calculateGradient();

        QVariant value = gradientValue;

        ui->txt_linear_out->setText("The gradient value of this function is equal to " + value.toString());
    }
}


void linear_gui::on_btn_funcDetail_clicked()
{

    if(ui->line_xValue->text().trimmed().length() == 0 | ui->line_yValue->text().trimmed().length() == 0)
    {
        QMessageBox msgBox;
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/title_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        msgBox.setWindowIcon(icon);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Please do fill y and x values to proceed.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
        if(ui->line_cValue->text().trimmed().length() == 0)
        {
            ui->txt_linear_out->setText("Since the value of c is taking a Zero(0), the equation will be in the form of y = mx");
        }
        else
        {
            ui->txt_linear_out->setText("Since the value of c is taking a value, the equation will be in the form of y = mx + c ");
        }
    }

}

void linear_gui::makePlot()
{
   setUiElements();
   QVector<double> x(100000), y(100000); // initialize with entries 0..100000
   for (int i=0; i<100000; ++i)
   {
       x[i] =  (i-90000)/5;
       y[i] =  calculateGradient()*x[i] + cValue();
   }
   // create graph and assign data to it:
   ui->customPlot->addGraph();
   ui->customPlot->graph(0)->setData(x, y);
   // give the axes some labels:
   ui->customPlot->xAxis->setLabel("x");
   ui->customPlot->yAxis->setLabel("y");
   // set axes ranges, so we see all data:
   ui->customPlot->xAxis->setRange(-20, 20);
   ui->customPlot->yAxis->setRange(-20, 20);
   ui->customPlot->replot();
}


void linear_gui::on_btn_graphDraw_clicked()
{
    if(ui->line_xValue->text().trimmed().length() == 0 | ui->line_yValue->text().trimmed().length() == 0)
    {
        QMessageBox msgBox;
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/title_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        msgBox.setWindowIcon(icon);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Please do fill y and x values to proceed.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
        makePlot();
    }
}
