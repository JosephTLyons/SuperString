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
    length = 0;
    
    if (createNewNode(head))
    {
        tail = head;
        head->character = '\0';
    }
}

bool SuperString::createNewNode(Node *&nodePtr)
{
    nodePtr = new (std::nothrow) Node;
    
    if (nodePtr)
    {
        nodePtr->previous = nullptr;
        nodePtr->next = nullptr;
        
        return true;
    }
    
    return false;
}

SuperString::SuperString()
{
    init();
}

SuperString::SuperString(const char text[])
{
    init();
    addText(text);
}

SuperString::SuperString(const SuperString &superString)
{
    init();
    addText(superString.getText());
}

SuperString::~SuperString()
{
    clear();
    delete head;
    head = tail = nullptr;
}

SuperString& SuperString::operator= (const SuperString &superString)
{
    addText(superString.getText());
    
    return *this;
}

SuperString& SuperString::operator= (char text[])
{
    addText(text);
    
    return *this;
}

bool SuperString::operator== (const SuperString &superString) const
{
    return isEqual(superString);
}

bool SuperString::operator!= (const SuperString &superString) const
{
    return ! (*this == superString);
}

void SuperString::operator+= (const char &input)
{
    addCharacterToEnd(input);
}

void SuperString::operator+= (const SuperString &superString)
{
    concatenate(superString);
}

SuperString SuperString::operator+ (const SuperString &superString)
{
    return (this->add(superString));
}

char SuperString::operator[] (long unsigned int index)
{
    return getCharAtPosition(index);
}

std::istream& operator>> (std::istream &in, SuperString &superString)
{
    superString.length = 0;
    char character = std::cin.get();
    
    while(character != '\n')
    {
        superString.addCharacterToEnd(character);
        character = std::cin.get();
    }
    
    return in;
}

std::ostream& operator<< (std::ostream &out, const SuperString &superString)
{
    SuperString::Node *iter = superString.head;
    
    for (unsigned long int i = 0; i < superString.length; i++)
    {
        out << iter->character;
        iter = iter->next;
    }
    
    return out;
}

void SuperString::addText(const char text[])
{
    for (unsigned long int i = 0; text[i] != '\0'; i++)
    {
        addCharacterToEnd(text[i]);
    }
}

void SuperString::addCharacterToBeginning(const char &input)
{
    ++length;
    
    if (createNewNode(head->previous))
    {
        head->previous->next = head;
        head = head->previous;
        head->character = input;
    }
}

void SuperString::addCharacterToEnd(const char &input)
{
    ++length;
    
    tail->character = input;
    
    if (createNewNode(tail->next))
    {
        tail->next->previous = tail;
        tail = tail->next;
        tail->character = '\0';
    }
}

void SuperString::concatenate(const SuperString &superString)
{
    addText(superString.getText());
}

void SuperString::consolidate(SuperString &superString)
{
    length += superString.length;
    tail->previous->next = superString.head;
    superString.head->previous = tail->previous;
    Node *temp = tail;
    tail = superString.tail;
    superString.head = superString.tail = temp;
    temp->next = temp->previous = nullptr;
    superString.length = 0;
}

SuperString SuperString::add(const SuperString &superString) const
{
    SuperString temp = *this;
    temp.concatenate(superString);
    return temp;
}

bool SuperString::isEqual(const SuperString &superString) const
{
    if (length != superString.length)
    {
        return false;
    }
    
    Node *iterOne = head, *iterTwo = superString.head;
    
    for (unsigned long int i = 0; i < length; i++)
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
    // Length + 1 to account for the extra char needed for '\0'
    char *textArrayPtr = new char[length + 1];
    Node *iter = head;
    
    for (unsigned long int i = 0; i < length + 1; i++)
    {
        textArrayPtr[i] = iter->character;
        iter = iter->next;
    }
    
    return textArrayPtr;
}

void SuperString::print() const
{
    Node *iter = head;
    
    for (unsigned long int i = 0; i < length; i++)
    {
        std::cout << iter->character;
        iter = iter->next;
    }
    
    std::cout << std::endl;
}

void SuperString::printReverse() const
{
    // tail->previous because tail is '\0'
    Node *iter = tail->previous;
    
    for (unsigned long int i = 0; i < length; i++)
    {
        std::cout << iter->character;
        iter = iter->previous;
    }
    
    std::cout << std::endl;
}

void SuperString::reverse()
{
    Node *iterOne = head, *iterTwo = tail->previous;
    const long unsigned int halfWayPoint = length / 2;
    
    for (unsigned long int i = 0; i < halfWayPoint; i++)
    {
        std::swap(iterOne->character, iterTwo->character);
        iterOne = iterOne->next;
        iterTwo = iterTwo->previous;
    }
}

char SuperString::getCharAtPosition(long unsigned int &index) const
{
    if (index > length - 1)
    {
        return '\0';
    }
    
    Node *iter = head;
    
    for (long unsigned int i = 0; i != index; i++)
    {
        iter = iter->next;
    }
    
    return iter->character;
}

void SuperString::trimWhiteSpace()
{
    trimBeginningWhiteSpace();
    trimEndWhiteSpace();
}

void SuperString::trimBeginningWhiteSpace()
{
    Node *iter = head;
    
    while(std::isspace(iter->character))
    {
        iter = iter->next;
        delete iter->previous;
        length--;
    }
    
    head = iter;
}

void SuperString::trimEndWhiteSpace()
{
    Node *iter = tail;
    
    while(std::isspace(iter->previous->character))
    {
        iter = iter->previous;
        delete iter->next;
        length--;
    }
    
    tail = iter;
    tail->character = '\0';
}

void SuperString::clear()
{
    for (unsigned long int i = 0; i < length; i++)
    {
        tail = tail->previous;
        delete tail->next;
        tail->next = nullptr;
    }
    
    head->character = '\0';
    length = 0;
}

long unsigned int SuperString::getLength() const
{
    return length;
}

char SuperString::getFirstCharacter() const
{
    return head->character;
}

char SuperString::getLastCharacter() const
{
    return tail->previous->character;
}
