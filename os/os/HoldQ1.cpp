//
//  HoldQ1.cpp
//  os
//
//  Created by Zeke on 5/21/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include "HoldQ1.hpp"
#include <iostream>
HoldQ1::HoldQ1(){
    head = NULL;
    tail = NULL;
    size = 0;
}

HoldQ1::~HoldQ1(){
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

void HoldQ1::insertJob(Job *job){
    if(size == 0){
        addFirstJob(job);
        return;
    }
    Node *newNode = new Node(job);
    Node *previousNode;
    Node *traverseNode = head;
    while(traverseNode !=NULL && newNode->getJob()->getUnitsOfTime() >= traverseNode->getJob()->getUnitsOfTime()){
        previousNode = traverseNode;
        traverseNode = traverseNode->next;
    }
    if(traverseNode == NULL){
        previousNode->next = newNode;
        tail = previousNode;
        size++;
        return;
    } else if(traverseNode == head){
        newNode->next = head;
        head = newNode;
        size++;
    }else {
        previousNode->next = newNode;
        newNode->next = traverseNode;
        size++;
        return;
    }
    
}

void HoldQ1::addFirstJob(Job *job){
    size++;
    Node *newNode = new Node(job);
    head = newNode;
    tail = newNode;
}

void HoldQ1::printJobs(){
    Node *traverse = head;
    while(traverse !=NULL){
        cout<<traverse->getJob()->getId();
        cout<<", ";
        traverse = traverse->next;
    }
    cout<<endl;
}

int HoldQ1::getSize(){
    return size;
}

Job* HoldQ1::popJob(){
    //if the queue is 0 or less return null
    if(size <= 1){
        return head->getJob();
    } else {
        //get rid of the first job and return it's pointer
        Job *job = head->job;
        size--;
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        tail = head->next;
        return job;
    }
}
