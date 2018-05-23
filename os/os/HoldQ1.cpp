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
        cout<<"job q1"<<endl;
        cout<<traverse->getJob()->getId()<<endl;
        cout<<traverse->getJob()->getUnitsOfTime()<<endl;
        traverse = traverse->next;
    }
}
