#include "unit.h"


std::string Unit::getArtist() const
{
    return artist;
}

std::string Unit::getTitle() const
{
    return title;
}

std::string Unit::getPath() const
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

void Unit::setArtist(const std::string &_artist)
{
    artist = _artist;
}

void Unit::setTitle(const std::string &_title)
{
    title = _title;
}

void Unit::setPath(const std::string &_path)
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
