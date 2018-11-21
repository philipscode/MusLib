#ifndef UNIT_H
#define UNIT_H

#include <QString>
#include <string>
#include <QDate>
#include <QMediaPlayer>
#include <QUrl>


class Unit
{
public:
    std::string getTitle() const;
    std::string getArtist() const;
    std::string getPath() const;
    int getYear() const;
    void setTitle(const std::string&);
    void setArtist(const std::string&);
    void setPath(const std::string&);
    void setYear(int);
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void forward() = 0;
    virtual void back() = 0;
protected:
    std::string title_, artist_, path_;
    int year_;
};

#endif // UNIT_H
