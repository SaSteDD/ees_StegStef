#include "taskdialogtablewidget.h"
#include "stepdialog.h"
#include <QDebug>
#include "types.h"

using Types::TaskStep;
using Types::StationType;

Q_DECLARE_METATYPE(TaskStep)

TaskDialogTableWidget::TaskDialogTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    setSelectionBehavior(QAbstractItemView::SelectRows);
}

void TaskDialogTableWidget::moveCurrentRowUp()
{
    int row = currentRow();
    QTableWidgetItem* selection=currentItem();
    QTableWidgetItem* items[3];

    if(row != 0)
    {
        for(int i=0; i<3; i++)
        {
          items[i]=takeItem(row,i);
          setItem(row,i,takeItem(row-1,i));
          setItem(row-1,i,items[i]);
          setCurrentItem(selection);
        }

    }
}

void TaskDialogTableWidget::moveCurrentRowDown()
{
    int row = currentRow();
    QTableWidgetItem* selection=currentItem();
    QTableWidgetItem* items[3];

    if (row != (rowCount()-1))
    {
        for(int i=0; i<3; i++)
        {
          items[i]=takeItem(row,i);
          setItem(row,i,takeItem(row+1,i));
          setItem(row+1,i,items[i]);
          setCurrentItem(selection);
        }
    }
}

void TaskDialogTableWidget::addRow()
{
    //Run the Step Dialog
    StepDialog* stepDialog=new StepDialog(this);
    if( stepDialog->exec() == QDialog::Accepted)
    {
        addStep(stepDialog->getStep());
    }
}

void TaskDialogTableWidget::addStep(TaskStep step)
{
    //insert the Items
    int row=this->currentRow();
    insertRow(++row);
    if(row==0) setCurrentCell(0,0); //at creation Time nothing will be selected, removng this, will reverse the task steps!!!

    QTableWidgetItem *newItem=new QTableWidgetItem("");//Station Type
    newItem->setData(Qt::UserRole,QVariant::fromValue<TaskStep>(step)); //one item remembers Step, this makes exporting of tasks easier
    newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    if(step.type == StationType::Bohren)
    {
        newItem->setText(trUtf8("Bohren"));
    } else if(step.type == StationType::Drehen)
    {
        newItem->setText(trUtf8("Drehen"));
    } else {
        newItem->setText(trUtf8("Fräsen"));
    }
   setItem(row,0,newItem);

   //quality
   newItem=new QTableWidgetItem("");
   newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
   newItem->setText(QString::number(step.quality));
   setItem(row,1,newItem);

   //time
   newItem=new QTableWidgetItem("");
   newItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
   newItem->setText(QString::number(step.time) + "s");
   setItem(row,2,newItem);
}

void TaskDialogTableWidget::removeRow()
{

    int row = currentRow();
    int column = currentColumn();
    QTableWidget::removeRow(row);
    if(row != 0) row -= 1;
        setCurrentCell(row,column,QItemSelectionModel::Select);
}

void TaskDialogTableWidget::setTask(Types::Task task)
{
    while(rowCount()>0)
    {
        QTableWidget::removeRow(0);
    }

    foreach (TaskStep step, task.steps) {
        addStep(step);
    }
}

QList<TaskStep> TaskDialogTableWidget::getSteps()
{
    QList<TaskStep> steps;

    for(int i=0; i<rowCount(); i++)
    {
        steps.append(item(i,0)->data(Qt::UserRole).value<TaskStep>());
    }
    return steps;
}
