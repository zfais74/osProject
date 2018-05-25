//
//  HoldQ1.hpp
//  os
//
//  Created by Zeke on 5/21/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#ifndef HoldQ1_hpp
#define HoldQ1_hpp

#include <stdio.h>
#include "Node.hpp"
class HoldQ1{
    Node *head;
    Node *tail;
    int size;
    
public:
    HoldQ1();
    ~HoldQ1();
    void insertJob(Job *job);
    void addFirstJob(Job *job);
    Job* popJob();
    void printJobs();
    int getSize();
    
};

#endif /* HoldQ1_hpp */
