#include "trackview.h"
#include <QDebug>
#include "types.h"

TrackView::TrackView(QWidget *parent) :
    QLabel(parent),
    currentSection(0),
    inActivePic(":/streckenPics/fahrplan_nxt.svg")
{
    setActivePic();
    setPixmap(inActivePic);
}

void TrackView::setTrackPosition(Types::TrackSection section)
{
    currentSection=section;
    setActivePic();
    setPixmap(activePic);
}

void TrackView::setActivePic()
{
    qDebug() << "Trackview: " << currentSection;
    switch(currentSection)
    {
    case(Types::parkingSpace):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_homePark.svg");
        break;
    case(Types::parkingSpaceTSection):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_homeTCrossing.svg");
        break;
    case(Types::longLane):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_homebs0.svg");
        break;
    case(Types::station1):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_bs0.svg");
        break;
    case(Types::station2):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_bs1.svg");
        break;
    case(Types::station3):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_bs2.svg");
        break;
    case(Types::station4):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_bs3.svg");
        break;
    case(Types::station1to2):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_bs01.svg");
        break;
    case(Types::station2to3):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_bs12.svg");
        break;
    case(Types::station3to4):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_bs23.svg");
        break;
    case(Types::station4ToParkingSpace):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_bs3home.svg");
        break;
    case(Types::mark1):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_mark0.svg");
        break;
    case(Types::mark2):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_mark1.svg");
        break;
    case(Types::mark3):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_mark2.svg");
        break;
    case(Types::mark4):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_mark3.svg");
        break;
    case(Types::mark6):
        activePic=QPixmap(":/streckenPics/fahrplan_nxt_mark5.svg");
        break;
    case(Types::unknown):
        activePic=inActivePic;
    default:
        activePic=inActivePic;
    }
}
