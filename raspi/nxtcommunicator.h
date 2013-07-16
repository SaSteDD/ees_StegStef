#ifndef NXTCOMMUNICATOR_H
#define NXTCOMMUNICATOR_H

#include <QObject>
#include <QProcess>
#include "types.h"
#include <QTimer>
#include <QPair>

/*
 *-Send/Read Messages to/from  the NXT
 *-Establish Bluetooth connection
 */
class NxtCommunicator : public QObject
{
    Q_OBJECT
public:
     explicit NxtCommunicator(QObject *parent = 0);

    /*
     *Try to connect to BT device
     *
     *this starts the rfcomm proccess with superuser rights
     *
     *device - device we want to connect to
     */
    void openConnection(Types::BtDevice device);

signals:
    /*
     *Messages we send, formatted in a human readable way
     */
    void appLogMessage(QString);
    void nxtLogMessage(QString);
    void raspiLogMessage(QString);

    /*
     *This is for sending any new States we receive from the NXT (Mainwindow connects this to the Trackview widget)
     */
    void nxtStateChanged(Types::NxtState);

    /*
     *true on success
     *false on error
     */
    void taskFinished(bool);

    /*
     *connection closed/opened
     */
    void connectionClosed();
    void connectionOpened();

    /*
     *true on connect
     *false on disconnect
     */
    void connectionStateChanged(bool);

public slots:
    /*
     *The abort-character will be sent the next the main Communication loop is executed
     */
    void sendNxtPauseResume();

    /*
     *Sends Task Data
     */
    void sendTaskData(const Types::Task& task, const Types::StationSetup& stationSetup);

    /*
     *This imediately closes the Bluetooth connection by closing tho rfcomm proccess
     */
    void closeConnection();

private slots:
    /*
     *These slots are used for interacting with the rfcomm process
     */
    void rfcommDeviceClosed(int,QProcess::ExitStatus);
    void rfcommProcReadStdErr();
    void rfcommProcReadStdOut();

    /*
     *Check if RFCOMM connection was established
     *else we try again a little later automatically
     *
     *This could run in an endless loop as long as rfcomm process is running
     *=>user can stop this by runnig disconnect action, which closes rfcomm proccess
     */
    void tryBtConnect();

    /*
     *This is the main loop which gets called periodically as long as the connection is open
     *
     *we try to read one char from the rfcomm device, determine the message and then run
     *the appropiate handler function
     */
    void mainCommunicationLoop();

private:
    /*
     *This is a helper function we use when constructing the log messages
     */
    static inline QString chToHexString(const char ch);

    /*
     *
     *Select a working command of the list of graphical sudo commands
     */
    QString getGraphicalSudoCommand();

    /*
     *Read output from the rfcomm process
     */
    QString readDataFromProc();

    /*
     *When a Task was finished we show a notification Dialog (with appropiate success/ error message)
     *
     *success = true on success
     */
    void runTaskFinished(bool success);

    /*
     *returns true on success
     */
    bool readChar(char* ch);

    /*
     *only returns true if EXACTLY len chars could be read
     *else we close the connection
     *
     *This works because massages are being sent complete at a time (with no pause between the chars).
     *The rfcomm API is configured to use an inter character timer, which ensures we receive the wholo message and
     *needn't worry about chunked messages
    */
    bool readChars(char *ch, int len);


    /*
     *returns true on success
     */
    bool sendChar(char ch , QString str);

    /*
     *Read State Data NXT sends
     *Format for NXT-Message:
     *      [StateChar]  [state (0-15)] [  StepNr   ]
     *Nr:        1              2          3 4 5 6
     */
    void readStateData();

    /*
     *Format: (we expect sizeof(int) to be 4 -> 32bit integers
     *     t [Nr] [Steps n(int32_t little endian)] {[Type (0-2)][Quality (1-4)][time (3-20)]}*n
     *BNr: 1  2      3 4 5 6                            i*3+7         i*3+8        i*3+9
     *Example:
     * t  0x02 0x0002 0x01 0x04 0xA0   0x00  0x03 0x09   T
     *    (Nr) (Steps)  (Ty) (Qu) (Tim)  (Ty)  (Qu) (Tim)
     */
    void writeTaskData();

    /*
     *Send Data for requested stations
     *Format for Message of nxt(Receive):
     *     [qualityChar]  [Station-Nr (1-4)]
     *BNr.      1                 2
     *
     *Example:  q                  1
     *
     *Format for Message of RasPi (send):
     *     [qualityChar] [StationType]  [Quality]
     *
     *BNr:           1           2              3
     *Example:       q           2              4
     */
    void sendStationData();

    QProcess rfCommProcess;//process for opening the rfcomm connection
    bool isRunning;//just to make sure we don't send anything until we connected to the rfcomm device
    bool sendNxtPauseChar, writeTask;//when  a pause message or Task message was requested, we set these to true and send the messages at the appropriate time in the communcation loop
    QTimer timer;//timer for the communication loop

    const static int waitTimeMs;//timer interval for timer
    /*
     *rfcomm can only be executed by root.
     *This is is a list of graphical versions of "sudo"
     *if one of these commands exists, it will be used to execute rfcomm
     */
    const static QStringList graphicalSudoCommands;

    Types::Task task;//the Task to be sent
    Types::StationSetup stationSetup;//the current stationsetup

    /*
     *The MessageBox we open, after the task has finished expects a SLOT.
     *So here it is ;)
     */
private slots:
    void dummySlot();
};
#endif // NXTCOMMUNICATOR_H
