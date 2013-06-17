#ifndef TRACKVIEW_H
#define TRACKVIEW_H

#include <QLabel>
#include "types.h"
class TrackView : public QLabel
{
    Q_OBJECT
public:
    explicit TrackView(QWidget *parent = 0);
    
public slots:
    void setTrackPosition(Types::TrackSection section);
private:
    int currentSection;
    QPixmap activePic, inActivePic;
    void setActivePic();
    
};

#endif // TRACKVIEW_H
