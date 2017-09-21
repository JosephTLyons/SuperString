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

class SuperString
{
private:
    long unsigned int length;
    
    struct Node
    {
        char character;
        Node *next, *previous;
    };
    
    Node *head, *tail;
    
    // Private methods
    void init();
    bool createNewNode(Node *&node);
    
public:
    SuperString();
    SuperString(const char text[]);
    SuperString(const SuperString &superString);
    ~SuperString();
    
    // Deep copy
    SuperString& operator= (const SuperString &superString);
    SuperString& operator= (char text[]);
    bool operator== (const SuperString &superString) const;
    bool operator!= (const SuperString &superString) const;
    void operator+= (const char &input);
    void operator+= (const SuperString &superString);
    SuperString operator+ (const SuperString &superString);
    char operator[] (long unsigned int index);
    friend std::istream& operator>> (std::istream &in, SuperString &superString);
    friend std::ostream& operator<< (std::ostream &out, const SuperString &superString);
    
    void addText(const char text[]);
    void addCharacterToBeginning(const char &input);
    void addCharacterToEnd(const char &input);
    void concatenate(const SuperString &superString);
    void consolidate(SuperString &superString);
    SuperString add(const SuperString &superString) const;
    bool isEqual(const SuperString &superString) const;
    char* getText() const;
    void print() const;
    void printReverse() const;
    void reverse();
    char getCharAtPosition(long unsigned int &index) const;
    void trimWhiteSpace();
    void trimBeginningWhiteSpace();
    void trimEndWhiteSpace();
    void clear();
    
    long unsigned int getLength() const;
    char getFirstCharacter() const;
    char getLastCharacter() const;
    
    // Use these methods to convert between std::string and SuperString
    std::string convertToStdString() const;
    static SuperString convertToSuperString(const std::string &stdString);
};

#endif /* SuperString_hpp */
