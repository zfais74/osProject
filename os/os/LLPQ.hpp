//
//  LLPQ.hpp
//  Lab 3 Zeke Faison
//
//  Created by Zeke on 10/19/16.
//  Copyright © 2016 Zeke. All rights reserved.
//

#ifndef LLPQ_hpp
#define LLPQ_hpp

#include <stdio.h>
#include <string>
#include "LLNode.hpp"
#include "Job.hpp"
using namespace std;

class LLPQ{
    
    int size;
    LLNode *first;
    LLNode *last;
    
public:
    LLPQ();
    ~LLPQ();
    //Prints out the Linked List/ queue
    void printLLQ();
    //Adds the first node with the char x to the list
    // the node's code value will start off as -1
    void addFirst(Job *job);
    //Adds a node to the front of the list/queue
    // with the char value x and a code value of -1
    void addAtFirst(Job *job);
    //Removes the first node of the list/queue
    LLNode *remFirst();
    //inserts the node n into the linked list in order of its count value
    void insertInOrder(LLNode *n);
    
    
    
};//LLPQ Header


#endif /* LLPQ_hpp */
