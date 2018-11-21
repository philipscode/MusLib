#include "song.h"


Song::Song()
{
    title_ = albumTitle_ = artist_ = "untitled";
    year_ = QDate::currentDate().year();
    path_ = "";
}

Song::Song(std::string title, std::string albumTitle, std::string artist,
           std::string path, int year)
{
    title_ = title;
    albumTitle_ = albumTitle;
    artist_ = artist;
    path_ = path;
    year_ = year;
    //player->setMedia(QUrl::fromLocalFile(path));
    //player->setVolume(50);
}

Song::Song(const Song &other)
{
    title_ = other.getTitle();
    albumTitle_ = other.getAlbum();
    artist_ = other.getArtist();
    path_ = other.getPath();
    year_ = other.getYear();
    //player->setMedia(QUrl::fromLocalFile(path));
    //player->setVolume(50);
}

Song::Song(Song &&other)
{
    title_ = other.getTitle();
    albumTitle_ = other.getAlbum();
    artist_ = other.getArtist();
    path_ = other.getPath();
    year_ = other.getYear();
    //player->setMedia(QUrl::fromLocalFile(path));
    //player->setVolume(50);
}

std::string Song::getAlbum() const
{
    return albumTitle_;
}

void Song::setAlbum(std::string &albumTitle)
{
    albumTitle_ = albumTitle;
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
