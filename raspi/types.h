#ifndef TYPES_H
#define TYPES_H
#include <QList>
#include <QStringList>
#include <QMetaType>

namespace Types{

    /*
     *To split 32bit-int into chars
     */
    typedef union {
        struct{
            unsigned char byte0;
            unsigned char byte1;
            unsigned char byte2;
            unsigned char byte3;
        };
        int num;
    } StepNumType;


    /*
     *The order of this corresponds with the order of StepTypes(!).
     *There are other (less efficient) Methods to achieve this, but this will work.
     */
    typedef enum {
        Bohren,
        Drehen,
        Fraesen
    } StationType;


    /*
     *The same goes for the the TrackPostions
     */
    typedef enum {
        parkingSpace,
        mark6,
        parkingSpaceTSection,
        longLane,
        mark1,
        station1,
        station1to2,
        mark2,
        station2,
        station2to3,
        mark3,
        station3,
        station3to4,
        mark4,
        station4,
        station4ToParkingSpace,
        mark5,
        unknown
    } TrackSection;

    typedef struct {
        TrackSection section;
        StepNumType stepNum;
    } NxtState;

    /*
     *Each Task has a number and a variable number of TaskSteps
     */
    typedef struct{
        StationType type;

        unsigned int quality;

        unsigned int time;

    } TaskStep;

    typedef struct{
        unsigned int taskNumber;
        QList<TaskStep> steps;
    } Task;



    /*
     *struct to describe a Bluetooth-Device
     */
    typedef struct{
        QString name;
        QString mac;
    } BtDevice;

    /*
     *A Station uis characteried by its type and its quality
     */
    typedef struct{
        StationType type;
        int quality;
    } StationPar;

    typedef struct{
        StationPar station1;
        StationPar station2;
        StationPar station3;
        StationPar station4;
    } StationSetup;
}

Q_DECLARE_METATYPE(Types::StationType)


Q_DECLARE_METATYPE(Types::BtDevice)
Q_DECLARE_METATYPE(QList<Types::BtDevice>)

#endif // TYPES_H
