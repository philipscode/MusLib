#include "module.h"

#include <iostream>
#include <functional>


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
        this->pushBack(*it);
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
    if (last == nullptr)
    {
        return nullptr;
    }
    return iterator(last->next);
}

void Module::insert(Unit *item, function_bool &rule)
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
        while (it != end() && (rule(*it, item)))
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
        Node *tmp = last;
        last = last->prev;
        delete tmp;
        --size_;
    }
}

void Module::remove(const std::string &str, function_str &target)
{
    iterator it = begin();
    while (it != end() && (target(*it) != str))
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
    while (last)
    {
        this->popBack();
    }
    first = last;
}

int Module::size() const
{
    return size_;
}

void Module::pushBack(Unit *other)
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
