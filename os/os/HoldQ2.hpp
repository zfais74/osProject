//
//  HoldQ2.hpp
//  os
//
//  Created by Zeke on 5/21/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#ifndef HoldQ2_hpp
#define HoldQ2_hpp

#include <stdio.h>
#include "Node.hpp"
class HoldQ2{
    Node *head;
    Node *tail;
    int size;
public:
    HoldQ2();
    ~HoldQ2();
    bool insert(Job *job);
    Job* popJob();
    void print();
    int getSize();
};
#endif /* HoldQ2_hpp */
