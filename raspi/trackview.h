#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QLabel>
#include "types.h"

/*
 *Widget for showing a picture for visualizing the current track position
 */
class TrackView : public QLabel
{
    Q_OBJECT
public:
    explicit TrackView(QWidget *parent = 0);
    
public:

    /*
     *Set the current position
     */
    void setTrackPosition(Types::TrackSection section);
private:
    int currentSection;//current section casted to int
    QPixmap activePic, inActivePic; //pics for active and inactive state of the  widget
    void setActivePic();
};

#endif // TRACKVIEW_H
