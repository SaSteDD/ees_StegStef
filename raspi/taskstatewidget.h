#ifndef TASKSTATEWIDGET_H
#define TASKSTATEWIDGET_H

#include <QWidget>
#include <QLabel>
#include "trackview.h"
#include "types.h"

class TaskStateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TaskStateWidget(QWidget *parent = 0);
    
public slots:
    void setTaskState(Types::NxtState state);

private:
    void changeEvent(QEvent *);

    TrackView* trackView;
    QLabel *stepLabel;
    int stepNum;
};

#endif // TASKSTATEWIDGET_H
