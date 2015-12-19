#include "quadritic_gui.h"
#include "ui_quadritic_gui.h"
#include "main_gui/quadritic_gui.h"

#include <QFileDialog>
#include <QImageWriter>
#include <QMessageBox>
#include <QtMath>


quadritic_gui::quadritic_gui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::quadritic_gui)
{
    ui->setupUi(this);

    image = new SaveImage();

    //slot for draw button Draw Gaph
    QObject::connect(ui->btn_graphDraw, SIGNAL(clicked(bool)), this, SLOT(viewGraph()));
}

quadritic_gui::~quadritic_gui()
{   
    delete ui;
}


//get set methods decleration
double quadritic_gui::xValue() const
{
    return m_xValue;
}

void quadritic_gui::setXValue(double xValue)
{
    m_xValue = xValue;
}


double quadritic_gui::cValue() const
{
    return m_cValue;
}

void quadritic_gui::setCValue(double cValue)
{
    m_cValue = cValue;
}

double quadritic_gui::bValue() const
{
    return m_bValue;
}

void quadritic_gui::setBValue(double bValue)
{
    m_bValue = bValue;
}

double quadritic_gui::aValue() const
{
    return m_aValue;
}

void quadritic_gui::setAValue(double aValue)
{
    m_aValue = aValue;
}

//private methods declaration
void quadritic_gui::setUiElements()
{
    //method decleration for intiating linking ui elements with setters of member variables
    setAValue(ui->line_aValue->text().toDouble());
    setBValue(ui->line_bvalue->text().toDouble());
    setCValue(ui->lineCValue->text().toDouble());
    setXValue(calcualteAxisofSym());
}

void quadritic_gui::SaveAsImage()
{
    QString fileName= QFileDialog::getSaveFileName(this, "Save Image", QCoreApplication::applicationDirPath(), "BMP Files (.bmp);;JPEG (.JPEG);;PNG (*.png)" );
           if (!fileName.isNull())
           {

                    QPixmap pixMap = ui->customPlot->grab();
                    pixMap.save(fileName);
           }
}

double quadritic_gui::calcualteAxisofSym()
{
    double axisOfSymValue = - (bValue() / (2 * aValue()) );

    return axisOfSymValue;
}

double quadritic_gui::calculateYValue()
{
    double yValue = (aValue() *  qPow(xValue(),2)) + (bValue() * xValue()) + cValue();

    return yValue;
}

double quadritic_gui::calculateDelta()
{
    double deltaValue = (qPow(bValue(),2)) - (4 * aValue() * cValue());

    return deltaValue;
}


//event-driven methods
void quadritic_gui::on_btn_axisOfSym_clicked()
{
    if(ui->line_aValue->text().trimmed().length() == 0 | ui->line_bvalue->text().trimmed().length() == 0 |
            ui->lineCValue->text().trimmed().length() == 0)
    {
        QMessageBox msgBox;
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/title_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        msgBox.setWindowIcon(icon);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Please do fill all the constant values to proceed.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }

    else
    {
        setUiElements();

        double axisOfSymmetry = calcualteAxisofSym();

        QVariant value = axisOfSymmetry;

        ui->text_quadOutput->setText("The axis of symmetry of this function is equal to " + value.toString());
    }
}

void quadritic_gui::on_btn_discValue_clicked()
{

    if(ui->line_aValue->text().trimmed().length() == 0 | ui->line_bvalue->text().trimmed().length() == 0 |
            ui->lineCValue->text().trimmed().length() == 0)
    {
        QMessageBox msgBox;
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/title_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        msgBox.setWindowIcon(icon);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Please do fill all the constant values to proceed.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }

    else
    {
        setUiElements();

        double deltaValue = calculateDelta();

        QVariant value = deltaValue;

        ui->text_quadOutput->setText("The value of Discriminant of this function is equal to " + value.toString());
    }
}



void quadritic_gui::on_btn_funcDetail_clicked()
{
    setUiElements();

    if(ui->line_aValue->text().trimmed().length() == 0 | ui->line_bvalue->text().trimmed().length() == 0 |
            ui->lineCValue->text().trimmed().length() == 0)
    {
        QMessageBox msgBox;
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/title_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        msgBox.setWindowIcon(icon);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Please do fill all the constant values to proceed.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }

    else
    {

        double yValue = calculateYValue();
        double deltaValue = calculateDelta();

        QVariant value1 = yValue;
        QVariant value2 = deltaValue;
//            QVariant valueOfa = aValue;
//            QVariant valueOfb = bValue;
//            QVariant valueOfc = cValue;

        if(ui->line_aValue->text().toDouble() >= 0.0) //bug in getting aValue
        {

            if(value2 < 0)
            {
               ui->text_quadOutput->setText("Since the value of constant a is positive, the graph of this function will "
                                                 "take maximum value. "
                                                 "There will be no real roots for this function. "
                                                 "The value of y is " +
                                                  value1.toString());
            }

            else if(value2 == 0)
            {
               ui->text_quadOutput->setText("Since the value of constant a is positive, the graph of this function will "
                                                 "take maximum value. "
                                                 "There will be one real root for this function. "
                                                 "The value of y is " +
                                                 value1.toString());
            }
            else
            {
              ui->text_quadOutput->setText("Since the value of constant a is positive, the graph of this function will "
                                                 "take maximum value. "
                                                 "There will be two real roots for this function. The value of y is " +
                                                 value1.toString());
            }

        }

        else
        {

            if(value2 < 0)
            {
               ui->text_quadOutput->setText("Since the value of constant a is negative, the graph of this function will "
                                                 "take minimum value. "
                                                 "There will be no real roots for this function. The value of y will be " +
                                                 value1.toString());
            }

            else if(value2 == 0)
            {
               ui->text_quadOutput->setText("Since the value of constant a is positive, the graph of this function will "
                                                 "take minimum value. "
                                                 "There will be one real root for this function. The value of y will be " +
                                                 value1.toString());
            }

            else
            {
               ui->text_quadOutput->setText("Since the value of constant a is positive, the graph of this function will "
                                                 "take minimum value. "
                                                 "There will be two real roots for this function. The value of y will be " +
                                                 value1.toString());
            }
         }
    }

}


void quadritic_gui::makePlot()
{
    setUiElements();
    QVector<double> x(100000), y(100000); // initialize with entries 0..100000
    for (int i=0; i<100000; ++i)
    {
        x[i] =  (i-90000)/5;
        y[i] =  (aValue()*qPow(x[i],2)) + bValue()*x[i] + cValue();
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


void quadritic_gui::on_btn_graphDraw_clicked()
{
    if(ui->line_aValue->text().trimmed().length() == 0 | ui->line_bvalue->text().trimmed().length() == 0 |
            ui->lineCValue->text().trimmed().length() == 0)
    {
        QMessageBox msgBox;
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/title_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        msgBox.setWindowIcon(icon);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Please do fill all the constant values to proceed.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
        makePlot();
    }

}

void quadritic_gui::on_btn_saveImage_clicked()
{
    SaveAsImage();
}
