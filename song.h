#ifndef SONG_H
#define SONG_H

#include "unit.h"


class Song : public Unit
{
public:
    Song();
    Song(std::string, std::string, std::string, int, int, std::string);
    Song(const Song&);
    Song (Song&&);

    std::string getAlbum() const;
    void setAlbum(std::string&);

    void play() override;
    void pause() override;
    void forward() override;
    void back() override;
private:
    std::string albumTitle;
    QMediaPlayer *player = new QMediaPlayer();
};

#endif // SONG_H
