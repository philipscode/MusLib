#include "unit.h"


QString Unit::getArtist() const
{
    return artist;
}

QString Unit::getTitle() const
{
    return title;
}

QString Unit::getPath() const
{
    return path;
}

int Unit::getDuration() const
{
    return duration;
}

int Unit::getYear() const
{
    return year;
}

void Unit::setArtist(QString &_artist)
{
    artist = _artist;
}

void Unit::setTitle(QString &_title)
{
    title = _title;
}

void Unit::setPath(QString &_path)
{
    path = _path;
}

void Unit::setDuration(int _duration)
{
    duration = _duration;
}

void Unit::setYear(int _year)
{
    year = _year;
}
