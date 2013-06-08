#include "loggerwidget.h"
#include <QTime>
#include <QDebug>

LoggerWidget::LoggerWidget(QWidget *parent) :
    QTextEdit(parent)
{
    cursor=QTextCursor(document());
    bf=cursor.blockFormat();
    setReadOnly(true);
    QFont f=font();
    f.setStyleHint(QFont::Monospace);
    f.setFamily("Courier New");
    f.setPointSize(logTextPointSize);
    setFont(f);

}

void LoggerWidget::addAppMessage(QString msg)
{
    printColoredMessage(QTime::currentTime().toString("hh:mm:ss") + " [App  ] " + msg, appCol);
}

void LoggerWidget::addNxtMessage(QString msg)
{

    printColoredMessage(QTime::currentTime().toString("hh:mm:ss") + " [NXT  ] " + msg, nxtCol);
}

void LoggerWidget::addRaspiMessage(QString msg)
{
    printColoredMessage(QTime::currentTime().toString("hh:mm:ss") + " [RasPi] " + msg, raspiCol);
}

void LoggerWidget::printColoredMessage(QString msg, QBrush col)
{
    qDebug() << msg;
    bf.setBackground(col);
    cursor.movePosition(QTextCursor::End);
    cursor.insertBlock(bf);
    cursor.insertText(msg);
    textCursor().movePosition(QTextCursor::End);
    ensureCursorVisible();
}

const QBrush LoggerWidget::appCol=QBrush(QColor("#FCFCA8"));
const QBrush LoggerWidget::nxtCol=QBrush(QColor("#99FF99"));
const QBrush LoggerWidget::raspiCol=QBrush(QColor("#99FFFF"));

const int LoggerWidget::logTextPointSize=11;
