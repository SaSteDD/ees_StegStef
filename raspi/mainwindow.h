#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include "types.h"
#include "nxtcommunicator.h"
#include "btwahldialog.h"
#include "taskdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void runTaskSetup();
    void runBtSetup();
    void openBtConnection();
    void closeBtConnection();
    void taskFinished();
    void startTask();

private:
    void switchConnectionStatusLabel(bool status);

    Ui::MainWindow *ui;
    Types::Task task;
    Types::BtDevice btDevice;
    NxtCommunicator nxtCom;
    QTimer tim;
    BtDeviceDialog* btDialog;
    TaskDialog* taskDialog;
    QLabel* statusBarConnectionStateLabel;
};

#endif // MAINWINDOW_H
