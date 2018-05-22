//
//  Node.hpp
//  os
//
//  Created by Zeke on 5/21/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Job.hpp"
class Node{
    friend class HoldQ1;
    friend class HoldQ2;
    Node *previous;
    Node *next;
    Job *job;
    
public:
    Node(Job *job);
    ~Node();
    Job* getJob();
    int getJobPriority();
};
#endif /* Node_hpp */
