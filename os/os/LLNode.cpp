//
//  LLNode.cpp
//  Lab 3 Zeke Faison
//
//  Created by Zeke on 10/19/16.
//  Copyright © 2016 Zeke. All rights reserved.
//

#include "LLNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

LLNode::LLNode(Job *job){
    this->job = job;
    next = NULL;
    prev = NULL;
    parent = NULL;
    left = NULL;
    right = NULL;
    
}//LLNode

LLNode::~LLNode(){
    if(next !=NULL || prev !=NULL || left !=NULL || right !=NULL || parent !=NULL){
        cout<<"Deleting this node may cause data leak!!"<<endl;
    }//if
}//~LLNode

Job* LLNode::getJob(){
    return job;
}//

