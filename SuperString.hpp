//
//  SuperString.hpp
//  SuperString
//
//  Created by Joseph Lyons on 8/9/17.
//  Copyright © 2017 Joseph Lyons. All rights reserved.
//

#ifndef SuperString_hpp
#define SuperString_hpp

#include <iostream>
using namespace std;

class SuperString
{
private:
    struct node
    {
        char character;
        
        node *next, *previous;
    };
    
    node *head, *tail;
    
    long unsigned int size;
    
    // Private methods
    void init();
    
public:
    
    SuperString();
    SuperString(char text[]);
    ~SuperString();
    
    SuperString& operator= (const SuperString &superString);
    
    friend ostream& operator<< (ostream &out, const SuperString &superString);
    
    void addText(char text[]);
    void addCharacter(const char input);
    char* getText() const;
    void print() const;
    void printReverse() const;
    void clear();
    
    long unsigned int getSize() const;
};

#endif /* SuperString_hpp */
