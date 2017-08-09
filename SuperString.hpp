//
//  SuperString.hpp
//  SuperString
//
//  Created by Joseph Lyons on 8/9/17.
//  Copyright © 2017 Joseph Lyons. All rights reserved.
//

#ifndef SuperString_hpp
#define SuperString_hpp

class SuperString
{
private:
    struct node
    {
        char letter;
        
        node *next, *previous;
    };
    
    node *head, *tail, *temporary;
    
    long unsigned int size;
    
    // Private methods
    void init();
    
public:
    
    SuperString();
    SuperString(char text[]);
    ~SuperString();
    
    void addText();
    void print();
    void printReverse();
};

#endif /* SuperString_hpp */
