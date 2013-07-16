#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QMessageBox>
#include "types.h"
#include "nxtcommunicator.h"
#include "btwahldialog.h"
#include "taskdialog.h"

namespace Ui {
class MainWindow;
}
/*
 *Main Application class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    /*
     *open the Dialog for editing the task
     */
    void runTaskSetup();

    /*
     *open Bluetooth Dialog
     */
    void runBtSetup();

    /*
     *Open/Close Bluetooth connection
     *
     *These slots are used by the actions in the menu bar
     */
    void openBtConnection();
    void closeBtConnection();

    /*
     *Slot to notify the UI the task was finished
     */
    void taskFinished(bool success);

    /*
     *Send Task to NXT
     */
    void startTask();

private:
    /*
     *We switch the label as  soon as we try to connect to the device
     */
    void switchConnectionStatusLabel(bool status);

    Ui::MainWindow *ui; //ui handler
    Types::Task task; //Task returned by the Task menu
    Types::BtDevice btDevice; //selected Bt device => This is initialized from a setting saved by earlier uses of the application
    NxtCommunicator nxtCom; //nxt communication object
    BtDeviceDialog* btDialog; //since we want to keep the Bluetooth dialog's state after it is closed, we don't delete it after it is closed
    TaskDialog* taskDialog; //see above
    QLabel* statusBarConnectionStateLabel; //the bluottoh icon in the application's statusbar
    QMessageBox msgBox;// MessageBox for showing the Task success /error Message
};

#endif // MAINWINDOW_H
