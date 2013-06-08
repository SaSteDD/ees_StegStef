#ifndef STEPDIALOG_H
#define STEPDIALOG_H

#include <QDialog>
#include "types.h"

namespace Ui {
class StepDialog;
}

class StepDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit StepDialog(QWidget *parent = 0);
    Types::TaskStep getStep();
    ~StepDialog();
    
private:
    Ui::StepDialog *ui;
};

#endif // STEPDIALOG_H
