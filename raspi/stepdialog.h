#ifndef STEPDIALOG_H
#define STEPDIALOG_H

#include <QDialog>
#include "types.h"

namespace Ui {
class StepDialog;
}

/*
 *Dialog for editing a single step of a Task
 */
class StepDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit StepDialog(QWidget *parent = 0);

    /*
     *Returns the edited Step
     */
    Types::TaskStep getStep();
    ~StepDialog();
    
private:
    Ui::StepDialog *ui;//ui handle
};

#endif // STEPDIALOG_H
