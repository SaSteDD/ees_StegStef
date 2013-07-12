#ifndef TASKDIALOGTABLEWIDGET_H
#define TASKDIALOGTABLEWIDGET_H

#include <QTableWidget>
#include <QList>
#include "types.h"

/*
 *The Task Dialog uses this widget for displaying the task steps
 */
class TaskDialogTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit TaskDialogTableWidget(QWidget *parent = 0);

    /*
     *returns the widgets steps
     */
    QList<Types::TaskStep> getSteps();

    /*
     *fills the widget with a task steps
     */
    void setTask(Types::Task task);
    
private slots:

    /*
     *Functions for manipulating the step order
     */
    void moveCurrentRowUp();
    void moveCurrentRowDown();

    /*
     *Add/delete steps (currently selected row)
     */
    void addRow();//run the step dialog
    void removeRow();
private:
    void addStep(Types::TaskStep step); //gets called after step dialog is done
};

#endif // TASKDIALOGTABLEWIDGET_H
