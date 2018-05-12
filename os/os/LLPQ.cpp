//
//  LLPQ.cpp
//  Lab 3 Zeke Faison
//
//  Created by Zeke on 10/19/16.
//  Copyright © 2016 Zeke. All rights reserved.
//

#include "LLPQ.hpp"
#include "LLNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


LLPQ::LLPQ(){
    first = NULL;
    last = NULL;
    size = 0;

}//LLPQ

LLPQ::~LLPQ(){
    LLNode *tmp = first;
    while(first !=NULL){
        tmp = first->next;
        delete first;
        first = tmp;
        size --;
    }//while
    
    first = NULL;
    last = NULL;
    
}//~LLPQ

void LLPQ::printLLQ(){
    LLNode *tmp = first;
    while(tmp!=NULL){
        cout<<tmp->job<<":"<<" ->";
        tmp = tmp->next;
    }//while
    
    cout<<endl;
    return;
}//printLLQ

void LLPQ::addFirst(Job *job){
    size++;
    LLNode *top = new LLNode(job);
    first = top;
    top->next = NULL;
    last = top;
    return;
    
}//addFirst

void LLPQ::addAtFirst(Job *job){
    size++;
    LLNode *newFirst = new LLNode(job);
    LLNode *tmp = first;
    newFirst->next = tmp;
    tmp->prev = newFirst;
    first = newFirst;
    if(tmp->next == NULL){
        last = tmp;
    }//if
    
}//addAtFirst


LLNode *LLPQ::remFirst(){
    LLNode *tmp = first;
    first = tmp->next;
    size --;
    return tmp;
    
}//remFirst

void LLPQ::insertInOrder(LLNode *addedNode){
    /*
        i run into an odd problem here, 
        my first go around witht the list is fine.
    
    */
    cout<<"Insert in order called: " <<endl;
   
    //if the list is empty
    if(size == 0){
        first = addedNode;
        last = addedNode;
        size++;
        return;
    }//if
     //checks to see if the new node is equal to the first node.
     //adds the new node to the front of the list
    LLNode *tmp = first;
    LLNode *prev = first;
    if(addedNode->job->priority == first->job->priority){
        addedNode->next = first;
        first = addedNode;
        size++;
        return;
    }//if
     //looks for a node that is greater than the new node and
     //has the new node point to the greater null
    while(tmp!= NULL && tmp->job->priority >){
        
    }
   
    return;
    
    
}//insertInOrder



