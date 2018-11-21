#ifndef MODULE_H
#define MODULE_H

#include "song.h"
#include "video.h"

#include <functional>


class Module
{
public:
    using function_bool = const std::function<bool(Unit*, Unit*)>;
    using function_str = const std::function<std::string(Unit*)>;

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

    void insert(Unit*, function_bool &rule = [](Unit *a, Unit *b) { return true; });
    void pushBack(Unit*);
    void popBack();
    void remove(const std::string&, function_str&);
    void removeAll();
    int size() const;

private:
    int size_;
    Node *first, *last;
};

#endif // MODULE_H
