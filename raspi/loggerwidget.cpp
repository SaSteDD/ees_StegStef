#include "loggerwidget.h"
#include <QTime>
#include <QDebug>
#include <QContextMenuEvent>
#include <QMenu>

LoggerWidget::LoggerWidget(QWidget *parent) :
    QTextEdit(parent),
    clearAllAction(new QAction(trUtf8("Log löschen"),this))
{
    cursor=QTextCursor(document());
    bf=cursor.blockFormat();
    setReadOnly(true);
    QFont f=font();
    f.setStyleHint(QFont::Monospace);
    f.setFamily("Courier New");
    f.setPointSize(logTextPointSize);
    setFont(f);

    clearAllAction->setShortcut(QKeySequence("Ctrl+d"));

    connect(clearAllAction,SIGNAL(triggered()),this,SLOT(clear()));
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

void LoggerWidget::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu* menu=createStandardContextMenu(e->pos());
    menu->addAction(clearAllAction);
    menu->popup(mapToGlobal(e->pos()));
    if(this->toPlainText().isEmpty()) clearAllAction->setDisabled(true);
    else clearAllAction->setDisabled(false);
}

const QBrush LoggerWidget::appCol=QBrush(QColor("#FCFCA8"));
const QBrush LoggerWidget::nxtCol=QBrush(QColor("#99FF99"));
const QBrush LoggerWidget::raspiCol=QBrush(QColor("#99FFFF"));

const int LoggerWidget::logTextPointSize=11;
