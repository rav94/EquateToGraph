#include "cubic_gui.h"
#include "ui_cubic_gui.h"

#include <QMessageBox>
#include <QtMath>

cubic_gui::cubic_gui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cubic_gui)
{
    ui->setupUi(this);

    //slot for draw button Draw Gaph
    QObject::connect(ui->btn_drawGraph, SIGNAL(clicked(bool)), this, SLOT(viewGraph()));
}

cubic_gui::~cubic_gui()
{
    delete ui;
}

//get set methods decleration
double cubic_gui::aValue() const
{
    return m_aValue;
}

void cubic_gui::setAValue(double aValue)
{
    m_aValue = aValue;
}

double cubic_gui::bValue() const
{
    return m_bValue;
}

void cubic_gui::setBValue(double bValue)
{
    m_bValue = bValue;
}

double cubic_gui::cValue() const
{
    return m_cValue;
}

void cubic_gui::setCValue(double cValue)
{
    m_cValue = cValue;
}

double cubic_gui::dValue() const
{
    return m_dValue;
}

void cubic_gui::setDValue(double dValue)
{
    m_dValue = dValue;
}

//private method decleration
void cubic_gui::settingUiElements()
{
    //method decleration for intiating linking ui elements with setters of member variables
    setAValue(ui->line_aValue->text().toDouble());
    setBValue(ui->line_bValue->text().toDouble());
    setCValue(ui->line_cValue->text().toDouble());
    setDValue(ui->line_dValue->text().toDouble());
}


double cubic_gui::calculateDeltaZero()
{
    double deltaZero = (qPow(bValue(),2)) - 3 * aValue() * cValue();

    return deltaZero;
}

double cubic_gui::calculateDeltaOne()
{
    double deltaOne = (2 * qPow(bValue(),3)) - (9 * aValue() * bValue() * cValue()) +
            (27 * qPow(aValue(),2) * dValue());

    return deltaOne;
}

double cubic_gui::calculateDiscriminant()
{
    double discriminant = ((qPow(calculateDeltaOne(),2)) - (4 - (qPow(calculateDeltaZero(),3)))) / (-27 * aValue() * aValue());

    return discriminant;
}

double cubic_gui::calculateCValue()
{
    double sqr = 0.3333; // 1/3 Simplified - For calculating roots
    double value = qPow(qSqrt((qPow(calculateDeltaOne(),2) - 4 * qPow(calculateDeltaZero(),3)) + calculateDeltaOne())/2,0.33);

    return value;
}


//event-driven methods decleration
void cubic_gui::on_btn_discriminant_clicked()
{
    if(ui->line_aValue->text().trimmed().length() == 0 | ui->line_bValue->text().trimmed().length() == 0 |
                ui->line_cValue->text().trimmed().length() == 0 |  ui->line_dValue->text().trimmed().length() == 0 )
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
        settingUiElements();

        double discriminantValue = calculateDiscriminant();

        QVariant value = discriminantValue;

        //truncate final value to avoid decimals in funcDetails_clicked()
        ui->txt_cubic_out->setText("The value of the discriminant of this function is equal to " + value.toString());

    }

}

void cubic_gui::on_btn_funcDetails_clicked()
{

    if(ui->line_aValue->text().trimmed().length() == 0 | ui->line_bValue->text().trimmed().length() == 0 |
                ui->line_cValue->text().trimmed().length() == 0 |  ui->line_dValue->text().trimmed().length() == 0 )
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

        QVariant value = calculateDiscriminant();
        QVariant value1 = calculateCValue();

        //value from calcualteDiscriment() converted to an int value
        int valueToTest = value.toInt();


        if(valueToTest > 0)
        {
            ui->txt_cubic_out->setText("The equation has three real solutions. Find roots by substituting the value of y = " + value1.toString());
        }
        else if(valueToTest == 0 )
        {
            ui->txt_cubic_out->setText("The equation has either one or two real solutions. Find roots by substituting the value of y = " + value1.toString());
        }
        else {
           ui->txt_cubic_out->setText("The equation has only one solution. Find roots by substituting the value of y = " + value1.toString());
        }
    }

}


void cubic_gui::on_btn_CValue_clicked()
{
    if(ui->line_aValue->text().trimmed().length() == 0 | ui->line_bValue->text().trimmed().length() == 0 |
                ui->line_cValue->text().trimmed().length() == 0 |  ui->line_dValue->text().trimmed().length() == 0 )
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
        settingUiElements();

        double CValue = calculateCValue();

        QVariant value = CValue;

        ui->txt_cubic_out->setText("Value of C can be subsituted for y and the equation can then be solved to obtain values of x, which are roots. The C Value = "
                               + value.toString());
    }

}

void cubic_gui::makePlot()
{
    settingUiElements();
    QVector<double> x(100000), y(100000); // initialize with entries 0..100000
    for (int i=0; i<100000; ++i)
    {
        x[i] =  (i-90000)/5;
        y[i] =  (aValue()*qPow(x[i],3)) + (bValue()*qPow(x[i],2)) + cValue()*x[i] + dValue();
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

void cubic_gui::on_btn_drawGraph_clicked()
{
    if(ui->line_aValue->text().trimmed().length() == 0 | ui->line_bValue->text().trimmed().length() == 0 |
                ui->line_cValue->text().trimmed().length() == 0 |  ui->line_dValue->text().trimmed().length() == 0 )
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
