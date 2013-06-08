#include "stepdialog.h"
#include "ui_stepdialog.h"
#include <QDebug>

using Types::TaskStep;
using Types::StationType;

StepDialog::StepDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StepDialog)
{
    ui->setupUi(this);
}

StepDialog::~StepDialog()
{
    delete ui;
}

TaskStep StepDialog::getStep()
{
    TaskStep step={StationType::Bohren,0,0};
    step.quality=ui->QualitySlider->value();
    step.time=ui->timeBox->value();
    if(ui->TypeBox->currentText() == trUtf8("Bohren")){
        step.type=StationType::Bohren;
    } else if(ui->TypeBox->currentText() == trUtf8("Drehen")) {
        step.type=StationType::Drehen;
    } else  {
        step.type=StationType::Fraesen;
    }

    qDebug() << "New Step: " << ui->TypeBox->currentText() <<"(" << step.type << ") " << step.quality << step.time << "s";
    return step;
}
