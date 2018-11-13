#ifndef UNIT_H
#define UNIT_H

#include <QString>
#include <QDate>
#include <QMediaPlayer>
#include <QUrl>


class Unit
{
public:
    QString getTitle() const;
    QString getArtist() const;
    QString getPath() const;
    int getDuration() const;
    int getYear() const;
    void setTitle(QString&);
    void setArtist(QString&);
    void setPath(QString&);
    void setDuration(int);
    void setYear(int);
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void forward() = 0;
    virtual void back() = 0;
protected:
    QString title, artist, path;
    int duration, year;
};

#endif // UNIT_H
