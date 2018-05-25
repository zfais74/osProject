//
//  Node.cpp
//  os
//
//  Created by Zeke on 5/21/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include "Node.hpp"
#include <iostream>
using namespace std;
Node::Node(Job *job){
    previous = NULL;
    next = NULL;
    this->job = job;
}

Node::~Node(){
    if(this->previous !=NULL || this->next !=NULL){
        //cout<< "Warning, there may be a data leak after deleting this node"<<endl;
    }
}

Job* Node::getJob(){
    return job;
}

int Node::getJobPriority(){
    return job->priority;
}
