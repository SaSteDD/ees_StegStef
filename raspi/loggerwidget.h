#ifndef LOGGERWIDGET_H
#define LOGGERWIDGET_H

#include <QTextEdit>
#include <QTextDocument>
#include <QBrush>

/*
 *Central Logging Widget
 *This Widget will log Messages with a color coded Background, and also output all received messages
 *to StdOut via qDebug()
 */
class LoggerWidget : public QTextEdit
{
    Q_OBJECT
public:
    explicit LoggerWidget(QWidget *parent = 0);
    
signals:

public slots:
    /*
     *There are 3 possible type sof messages
     *..from NXT
     *..from RasPi (=== machine that is running this app)
     *..App Message: Mostly messages concernig the Bluetoot connection
     */
    void addNxtMessage(QString msg);
    void addRaspiMessage(QString msg);
    void addAppMessage(QString msg);
private:
    /*
     *An Action to delete this widget's content  was added
     */
    void contextMenuEvent(QContextMenuEvent *e);
    /*
     *Color Defs for the Log Background, and Log Font
     */
    const static QBrush nxtCol, raspiCol, appCol;
    const static int logTextPointSize;
    /*
     *The 3 slots for our message types are actually just wrappers for this
     *Function
     */
    void printColoredMessage(QString msg, QBrush col);
    QTextCursor cursor;
    QTextBlockFormat bf;
    QAction* clearAllAction;
};

#endif // LOGGERWIDGET_H
