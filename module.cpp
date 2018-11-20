#include "module.h"

#include <iostream>


Module::Module()
{
    first = last = nullptr;
    size_ = 0;
}

Module::Module(const Module &other)
{
    first = last = nullptr;
    size_ = 0;
    for (iterator it = other.begin(); it != other.end(); it++)
    {
        this->push((*it));
        ++size_;
    }
}

Module::iterator Module::begin() const
{
    return iterator(first);
}

//Need finishing
Module::iterator Module::end() const
{
    return iterator(last->next);
}

void Module::insert(Unit *item)
{
    Node *tmp = new Node();
    tmp->data = item;
    if (first == nullptr)
    {
        first = tmp;
        last = tmp;
    }
    else
    {
        iterator it = begin();
        while (it != end() && ((*it)->getTitle() < item->getTitle()))
        {
            ++it;
        }
        if (it == begin())
        {
            first->prev = tmp;
            tmp->next = first;
            first = tmp;
        }
        else if (it != end())
        {
            tmp->next = it.getCurrent();
            tmp->prev = it.getCurrent()->prev;
            it.getCurrent()->prev->next = tmp;
            it.getCurrent()->prev = tmp;
        }
        else
        {
            tmp->prev = last;
            tmp->next = nullptr;
            last->next = tmp;
            last = tmp;
        }
    }
    ++size_;
}

void Module::popBack()
{
    if (size_)
    {
        last = last->prev;
        --size_;
    }
}

void Module::remove(const std::string &str)
{
    iterator it = begin();
    while (it != end() && ((*it)->getTitle() != str))
    {
        ++it;
    }
    if (it == begin())
    {
        Node *tmp = first;
        first = first->next;
        first->prev = nullptr;
        delete tmp;

    }
    else if (it == last)
    {
        Node *tmp = last;
        last = last->prev;
        delete tmp;
    }
    else if (it != end())
    {
        it.getCurrent()->prev->next = it.getCurrent()->next;
        it.getCurrent()->next->prev = it.getCurrent()->prev;
        delete it.getCurrent();
        --size_;
    }
}

void Module::removeAll()
{
    while (first)
    {
        this->popBack();
    }
    size_ = 0;
}

int Module::size() const
{
    return size_;
}

void Module::push(Unit *other)
{
    Node *tmp = new Node();
    if (first)
    {
        tmp->data = other;
        tmp->prev = last;
        last->next = tmp;
        last = tmp;
    }
    else
    {
        first = last = tmp;
    }
}

Module::Node::Node()
{
    data = nullptr;
    next = prev = nullptr;
}

Module::iterator::iterator()
{
    current = nullptr;
}

Module::iterator::iterator(Node *other)
{
    current = other;
}

Module::Node* Module::iterator::getCurrent() const
{
    return current;
}

Module::iterator& Module::iterator::operator ++()
{
    current = current->next;
    return *this;
}

Module::iterator& Module::iterator::operator ++(int)
{
    iterator tmp = current;
    current = current->next;
    return tmp;
}

Module::iterator& Module::iterator::operator --()
{
    current  = current->prev;
    return *this;
}

Module::iterator& Module::iterator::operator --(int)
{
    iterator tmp = current;
    current = current->prev;
    return tmp;
}

bool Module::iterator::operator ==(const Module::iterator &other) const
{
    return current == other.getCurrent();
}

bool Module::iterator::operator !=(const Module::iterator &other) const
{
    return !(current == other.getCurrent());
}

Unit* Module::iterator::operator *()
{
    return current->data;
}
