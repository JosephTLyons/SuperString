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
    
}

void SuperString::addText(char text[])
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        addCharacter(text[i]);
    }
}

void SuperString::addCharacter(const char input)
{
    ++size;
    
    node *temporary = tail;
    temporary->character = input;
    temporary->next = new node;
    tail = temporary->next;
    tail->previous = temporary;
    tail->character = '\0';
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
