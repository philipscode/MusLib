#include "unit.h"


std::string Unit::getArtist() const
{
    return artist_;
}

std::string Unit::getTitle() const
{
    return title_;
}

std::string Unit::getPath() const
{
    return path_;
}

int Unit::getYear() const
{
    return year_;
}

void Unit::setArtist(const std::string &artist)
{
    artist_ = artist;
}

void Unit::setTitle(const std::string &title)
{
    title_ = title;
}

void Unit::setPath(const std::string &path)
{
    path_ = path;
}


void Unit::setYear(int year)
{
    year_ = year;
}
