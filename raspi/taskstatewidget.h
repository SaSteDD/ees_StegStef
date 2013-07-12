#ifndef TASKSTATEWIDGET_H
#define TASKSTATEWIDGET_H

#include <QWidget>
#include <QLabel>
#include "trackview.h"
#include "types.h"

/*
 *Widget  for visualizing the state the nxt sent us
 */
class TaskStateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TaskStateWidget(QWidget *parent = 0);
    
public slots:

    /*
     *Set the task state
     */
    void setTaskState(Types::NxtState state);

private:

    /*
     *This checks if the widget is disabled and changes the background image accordingly
     */
    void changeEvent(QEvent *);

    TrackView* trackView; //the actual widget showing the state picture
    QLabel *stepLabel;//label showing the number of the current step
    int stepNum; //current step number
};

#endif // TASKSTATEWIDGET_H
