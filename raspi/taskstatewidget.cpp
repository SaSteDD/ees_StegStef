#include "taskstatewidget.h"
#include <QVBoxLayout>
#include <QEvent>
#include <QFont>
#include <QDebug>

TaskStateWidget::TaskStateWidget(QWidget *parent) :
    QWidget(parent),
    stepNum(0)
{

    QVBoxLayout* layout=new QVBoxLayout();
        setLayout(layout);
    trackView=new TrackView();
    stepLabel=new QLabel("");

    layout->addWidget(stepLabel);
    layout->addWidget(trackView);

    stepLabel->setStyleSheet("font: 16pt \"Arial Black\";");
    qDebug() << stepLabel->text();
}

void TaskStateWidget::setTaskState(Types::NxtState state)
{
    trackView->setTrackPosition(state.section);
    if(stepNum > 0) stepLabel->setText(QString("Schritt: %1").arg(state.stepNum.num));
    else stepLabel->setText("-");
    stepNum=state.stepNum.num;
}

void TaskStateWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    if(e->type() == QEvent::EnabledChange)
    {
        if(!isEnabled())
        {
            trackView->setTrackPosition(Types::unknown);
            stepLabel->setText("");
        } else if(stepNum>=1){
            stepLabel->setText(QString("Schritt: %1").arg(stepNum));
        } else {
            stepLabel->setText("...");
        }
    }
}
