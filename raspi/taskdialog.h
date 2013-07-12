#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include "types.h"

namespace Ui {
class TaskDialog;
}

/*
 *DIalog for editing a Task
 */
class TaskDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TaskDialog(QWidget *parent = 0);

    /*
     *runs the step dialog
     */
    void setTask(Types::Task task);

    /*
     *returns the edited task
     */
    Types::Task getTask();
    ~TaskDialog();    
    
private:
    Ui::TaskDialog *ui;//ui handle
};

#endif // TASKDIALOG_H
