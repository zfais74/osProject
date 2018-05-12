//
//  LLNode.hpp
//  Lab 3 Zeke Faison
//
//  Created by Zeke on 10/19/16.
//  Copyright © 2016 Zeke. All rights reserved.
//

#ifndef LLNode_hpp
#define LLNode_hpp

#include <stdio.h>
#include <string>
#include "Job.hpp"

class LLNode{
    friend class LLPQ;
    friend class LLHuff;
    Job *job;
    int numOfOccurence;
    std::string code;
    LLNode *left;
    LLNode *right;
    LLNode *prev;
    LLNode *next;
    LLNode *parent;
    
public:
    LLNode(Job *Job);
    ~LLNode();
    Job* getJob();

};//LLNode class

#endif /* LLNode_hpp */
