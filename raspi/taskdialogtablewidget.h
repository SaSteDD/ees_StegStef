#ifndef TASKDIALOGTABLEWIDGET_H
#define TASKDIALOGTABLEWIDGET_H

#include <QTableWidget>
#include <QList>
#include "types.h"

class TaskDialogTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit TaskDialogTableWidget(QWidget *parent = 0);
    QList<Types::TaskStep> getSteps();
    void setTask(Types::Task task);
    
private slots:
    void moveCurrentRowUp();
    void moveCurrentRowDown();
    void addRow();
    void removeRow();
private:
    void addStep(Types::TaskStep step);
};

#endif // TASKDIALOGTABLEWIDGET_H
