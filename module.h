#ifndef MODULE_H
#define MODULE_H

#include "song.h"
#include "video.h"


class Module
{
public:
    struct Node
    {
        Node();
        Unit *data;
        Node *next;
        Node *prev;
    };

    class iterator
    {
    public:
        iterator();
        iterator(Node*);

        Node* getCurrent() const;

        iterator& operator ++();
        iterator& operator ++(int);
        iterator& operator --();
        iterator& operator --(int);
        bool operator ==(const iterator&) const;
        bool operator !=(const iterator&) const;
        Unit* operator *();
    private:
        Node *current;
    };


    Module();
    Module(const Module&);

    iterator begin() const;
    iterator end() const;

    void insert(Unit*);
    void popBack();
    void remove(const std::string&);
    void removeAll();
    int size() const;

private:
    int size_;
    Node *first, *last;

    void push(Unit*);
};

#endif // MODULE_H
