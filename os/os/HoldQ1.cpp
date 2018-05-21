//
//  HoldQ1.cpp
//  os
//
//  Created by Zeke on 5/21/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include "HoldQ1.hpp"
HoldQ1::HoldQ1(){
    head = NULL;
    tail = NULL;
    size = 0;
}

void HoldQ1::insertJob(Job *job){
    if(this->size == 0){
        addFirstJob(job);
        return;
    }
    Node node = Node(job);
    Node *insertingNode = &node;
    Node *traverseNode = head;
    while(insertingNode != NULL && insertingNode->getJobPriority() >= traverseNode->getJobPriority()){
        
    }
    
}

void HoldQ1::addFirstJob(Job *job){
    size++;
    Node node = Node(job);
    Node *ptr = &node;
    head = ptr;
    tail = ptr;
}
