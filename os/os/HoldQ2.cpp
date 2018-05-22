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
    Node *tmp = head;
    while(head !=NULL){
        tmp = head->next;
        delete head;
        head = tmp;
        size --;
    }//while
    
    head = NULL;
    tail = NULL;
}

bool HoldQ2::insert(Job *job){
    //If the queue is empty
    Node *newNode = new Node(job);
    if(size == 0){
        size++;
        head = newNode;
        tail = newNode;
        cout<<"hi" + newNode->job->toString()<<endl;
        return true;
    }
    
    try {
        //makes the new node the head and point it's next value to the previous head. It's a regular queue
        if(size == 1){
            head->next = newNode;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
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
        return head->getJob();
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

void HoldQ2::print(){
    Node *traverse = head;
    while(traverse != NULL){
        cout<<"job pr: "<<endl;
        cout<<traverse->getJobPriority()<<endl;
        cout<<traverse->getJob()->getId()<<endl;
        traverse = traverse->next;
    }
}
