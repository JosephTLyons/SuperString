//
//  SuperString.cpp
//  SuperString
//
//  Created by Joseph Lyons on 8/9/17.
//  Copyright © 2017 Joseph Lyons. All rights reserved.
//

#include "SuperString.hpp"
#include <iostream>

void SuperString::init()
{
    size = 0;
    head = new node;
    tail = head;
    head->character = '\0';
}

SuperString::SuperString()
{
    init();
}

SuperString::SuperString(char text[])
{
    init();
    addText(text);
}

SuperString::~SuperString()
{
    clear();
    delete head;
}

SuperString& SuperString::operator= (const SuperString &superString)
{
    addText(superString.getText());
    
    return *this;
}

bool SuperString::operator== (const SuperString &superString) const
{
    return isEqual(superString);
}

istream& operator>> (istream &in, SuperString &superString)
{
    superString.size = 0;
    char character = cin.get();
    
    while(character != '\n')
    {
        superString.addCharacterToEnd(character);
        character = cin.get();
    }
    
    return in;
}

ostream& operator<< (ostream &out, const SuperString &superString)
{
    SuperString::node *iter = superString.head;
    
    for (int i = 0; i < superString.size; i++)
    {
        out << iter->character;
        iter = iter->next;
    }
    
    return out;
}

void SuperString::addText(char text[])
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        addCharacterToEnd(text[i]);
    }
    
    tail->character = '\0';
}

void SuperString::addCharacterToEnd(const char &input)
{
    ++size;
    
    tail->character = input;
    tail->next = new node;
    tail->next->previous = tail;
    tail = tail->next;
}

bool SuperString::isEqual(const SuperString &superString) const
{
    if (size != superString.size)
    {
        return false;
    }
    
    node *iterOne = head, *iterTwo = superString.head;
    
    for (int i = 0; i < size; i++)
    {
        if (iterOne->character != iterTwo->character)
        {
            return false;
        }
        
        iterOne = iterOne->next;
        iterTwo = iterTwo->next;
    }
        
    return true;
}

char* SuperString::getText() const
{
    char *textArrayPtr = new char[size];
    node *iter = head;
    
    for (int i = 0; i < size; i++)
    {
        textArrayPtr[i] = iter->character;
        iter = iter->next;
    }
    
    return textArrayPtr;
}

void SuperString::print() const
{
    node *iter = head;
    
    for (int i = 0; i < size; i++)
    {
        std::cout << iter->character;
        iter = iter->next;
    }
    
    std::cout << std::endl;
}

void SuperString::printReverse() const
{
    node *iter = tail->previous;
    
    for (int i = 0; i < size; i++)
    {
        std::cout << iter->character;
        iter = iter->previous;
    }
    
    std::cout << std::endl;
}

void SuperString::clear()
{
    for (int i = 0; i < size; i++)
    {
        tail = tail->previous;
        delete tail->next;
    }
    
    head->character = '\0';
    size = 0;
}

long unsigned int SuperString::getSize() const
{
    return size;
}
