#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include "types.h"

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TaskDialog(QWidget *parent = 0);
    void setTask(Types::Task task);
    Types::Task getTask();
    ~TaskDialog();    
    
private:
    Ui::TaskDialog *ui;
};

#endif // TASKDIALOG_H
