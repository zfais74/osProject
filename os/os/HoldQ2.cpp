//
//  HoldQ2.cpp
//  os
//
//  Created by Zeke on 5/21/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include "HoldQ2.hpp"
#include <iostream>
using namespace std;
HoldQ2::HoldQ2(){
    head = NULL;
    tail = NULL;
    size = 0;
}

HoldQ2::~HoldQ2(){
    if(head != NULL || tail !=NULL){
        cout<<"Warning:: Q2 is not empty!"<<endl;
    }
}

bool HoldQ2::insert(Job *job){
    //If the queue is empty
    Node newNode = Node(job);
    Node *newPtr = &newNode;
    if(size == 0){
        size++;
        head = newPtr;
        tail = newPtr;
        return true;
    }
    
    try {
        //makes the new node the head and point it's next value to the previous head. It's a stack
        newPtr->next = head;
        head->previous = newPtr;
        head = newPtr;
        tail = newPtr->next;
        size++;
    } catch (const exception& e) {
        cout<<e.what()<<endl;
        cout<<"Insertion error"<<endl;
        return false;
    }
    return true;
}

Job* HoldQ2::popJob(){
    //if the queue is 0 or less return null
    if(size <= 0){
        return NULL;
    } else {
        //get rid of the first job and return it's pointer
        Job *job = head->job;
        size--;
        Node *temp = head;
        head = temp->next;
        head->previous = NULL;
        temp->next = NULL;
        tail = head->next;
        return job;
    }
}
