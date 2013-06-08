#include "taskdialog.h"
#include "ui_taskdialog.h"
#include <QDebug>

using Types::Task;

TaskDialog::TaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);
}

TaskDialog::~TaskDialog()
{
    delete ui;
}

void TaskDialog::setTask(Task task)
{
    ui->taskTable->setTask(task);
    ui->taskNum->setValue(task.taskNumber);
}

Task TaskDialog::getTask()
{
    Task task;
    task.taskNumber=ui->taskNum->value();
    task.steps=ui->taskTable->getSteps();
    return task;
}
