#ifndef SONG_H
#define SONG_H

#include "unit.h"


class Song : public Unit
{
public:
    Song();
    Song(QString, QString, QString, int, int, QString);
    Song(const Song&);
    Song (Song&&);

    QString getAlbum() const;
    void setAlbum(QString&);

    void play() override;
    void pause() override;
    void forward() override;
    void back() override;
private:
    QString albumTitle;
    QMediaPlayer *player = new QMediaPlayer();
};

#endif // SONG_H
