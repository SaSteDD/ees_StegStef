#ifndef LOGGERWIDGET_H
#define LOGGERWIDGET_H

#include <QTextEdit>
#include <QTextDocument>
#include <QBrush>

class LoggerWidget : public QTextEdit
{
    Q_OBJECT
public:
    explicit LoggerWidget(QWidget *parent = 0);
    
signals:

public slots:
    void addNxtMessage(QString msg);
    void addRaspiMessage(QString msg);
    void addAppMessage(QString msg);
private:
    void contextMenuEvent(QContextMenuEvent *e);
    const static QBrush nxtCol, raspiCol, appCol;
    const static int logTextPointSize;
    void printColoredMessage(QString msg, QBrush col);
    QTextCursor cursor;
    QTextBlockFormat bf;
    QAction* clearAllAction;

};

#endif // LOGGERWIDGET_H
