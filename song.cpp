#include "song.h"


Song::Song()
{
    title = albumTitle = artist = "untitled";
    duration = 0;
    year = QDate::currentDate().year();
    path = "";
}

Song::Song(std::string _title, std::string _albumTitle, std::string _artist,
           int _duration, int _year, std::string _path)
{
    title = _title;
    albumTitle = _albumTitle;
    artist = _artist;
    duration = _duration;
    year = _year;
    path = _path;
    //player->setMedia(QUrl::fromLocalFile(path));
    //player->setVolume(50);
}

Song::Song(const Song &other)
{
    title = other.getTitle();
    albumTitle = other.getAlbum();
    artist = other.getArtist();
    duration = other.getDuration();
    year = other.getYear();
    path = other.getPath();
    //player->setMedia(QUrl::fromLocalFile(path));
    //player->setVolume(50);
}

Song::Song(Song &&other)
{
    title = other.getTitle();
    albumTitle = other.getAlbum();
    artist = other.getArtist();
    duration = other.getDuration();
    year = other.getYear();
    path = other.getPath();
    //player->setMedia(QUrl::fromLocalFile(path));
    //player->setVolume(50);
}

std::string Song::getAlbum() const
{
    return albumTitle;
}

void Song::setAlbum(std::string &_albumTitle)
{
    albumTitle = _albumTitle;
}

void Song::play()
{
    player->play();
}

void Song::pause()
{
    player->pause();
}
void Song::forward()
{
    return;
}
void Song::back()
{
    return;
}
