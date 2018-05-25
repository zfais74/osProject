//
//  projectRunner.cpp
//  os
//
//  Created by Zeke on 5/12/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include "projectRunner.hpp"
#include "SystemConfig.hpp"
#include "Job.hpp"
#include "HoldQ2.hpp"
#include "HoldQ1.hpp"
#include "Process.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
ProjectRunner::ProjectRunner(){
    
}

string ProjectRunner::readFile(string fileName){
    SystemConfig system;
    cout<<"Filename: " + fileName<<endl;
    ifstream myFile(fileName.c_str());
    Process *runningJob;
    string line;
    vector<Job*>jobs;
    if(myFile.is_open()){
        while (myFile >> line){
            vector<string> lineSeparated;
            vector<int> commandValues;
            string lineSegment;
            char command = line[0];
            switch (command) {
                //if the line is a system config
                case 'C':{
                    //read the next number
                    myFile >> line;
                    int arrivalTime = stoi(line);
                    for(int properties = 0; properties < 3; properties++){
                        myFile >> line;
                        //separates the Letter=Number string since there's no clean way to do it in c++...
                        stringstream lineToSeparate(line);
                        while(getline(lineToSeparate, lineSegment, '=')){
                            lineSeparated.push_back(lineSegment);
                        }
                        int value = stoi(lineSeparated[1]);
                        commandValues.push_back(value);
                        lineSeparated.clear();
                    }
                    //make a new system
                    system = SystemConfig(arrivalTime, commandValues[0], commandValues[1], commandValues[2]);
                    system.hq1 = new HoldQ1();
                    system.hq2 = new HoldQ2();
                    break;
                }
                //if the line is a job
                case 'A': {
                    //read the next number
                    myFile >> line;
                    int arrivalTime = stoi(line);
                    for(int properties = 0; properties < 5; properties++){
                        myFile >> line;
                        //separates the Letter=Number string since there's no clean way to do it in c++...
                        stringstream lineToSeparate(line);
                        while(getline(lineToSeparate, lineSegment, '=')){
                            lineSeparated.push_back(lineSegment);
                        }
                        int value = stoi(lineSeparated[1]);
                        lineSeparated.clear();
                        commandValues.push_back(value);
                    }
                    Job *job = new Job(arrivalTime, commandValues[0], commandValues[1], commandValues[2], commandValues[3], commandValues[4]);
                    
                    if(job->getPriority() == 2 && (system.getAvailableMem() > job->getUnitsOfMem() && system.getAvailableDevices() > job->getMaxDevices())){//if there's avaialble memeory and devies?, push to the rq
                        system.useMem(job->getUnitsOfMem());
                        system.useDevices(job->getMaxDevices());
                        Process *proc = new Process(job, system.getTime());
                        system.rq.push_back(proc);
                        jobs.push_back(job);
                    } else if(job->getPriority() == 2 && (system.getMemSize() > job->getUnitsOfMem())) {//push to the hold queue 2
                        system.hq2->insert(job);
                        jobs.push_back(job);
                    }
                    else if(job->getPriority() == 1 && (system.getAvailableMem() > job->getUnitsOfMem() && system.getAvailableDevices() > job->getMaxDevices())) {//
                        cout<<"push to q1"<<endl;
                        system.useMem(job->getUnitsOfMem());
                        system.useDevices(job->getMaxDevices());
                        Process *proc = new Process(job, system.getTime());
                        system.rq.push_back(proc);
                        jobs.push_back(job);
                    } else if(job->getPriority() == 1 && (system.getMemSize() > job->getUnitsOfMem())) {
                        system.hq1->insertJob(job);
                        jobs.push_back(job);
                    } else {//reject the job if it's memory is too big for the system
                        cout<<"reject job"<<endl;
                    }
                    system.updateSystem(arrivalTime);
                    
                    break;
                }
                //if the line is a request
                case 'Q': {
                    myFile >> line;
                    int arrivalTime = stoi(line);
                    for(int properties = 0; properties < 2; properties++){
                        myFile >> line;
                        //separates the Letter=Number string since there's no clean way to do it in c++...
                    }
                    system.updateSystem(arrivalTime);
                    break;
                }
                //if the line is a display command
                case 'D':{
                    myFile >> line;
                    int displayTime = stoi(line);
                    cout<<"Current Time: ";
                    cout<< displayTime<<endl;
                    system.updateSystem(displayTime);
                    cout<<"rq: ";
                    int rqSize = system.rq.size();
                    for(int i = 0; i < rqSize; i++){
                        if(i != rqSize - 1){
                            cout<<"id: " + to_string(system.rq.at(i)->job->getId()) + " Time remaining: " + to_string(system.rq.at(i)->job->getUnitsOfTime()) + " , ";
                        } else {
                            cout<<"id: " + to_string(system.rq.at(i)->job->getId()) + " Time remaining: " + to_string(system.rq.at(i)->job->getUnitsOfTime());
                        }
                    }
                    cout<<endl;
                    cout<<"Total mem: " + to_string(system.getMemSize())<<endl;
                    cout<<"Available mem: " + to_string(system.getAvailableMem())<<endl;
                    cout<<"Total Devices: " + to_string(system.getDevices())<<endl;
                    cout<<"Available devices: " + to_string(system.getAvailableDevices())<<endl;
                    cout<<"Running: " ;
                    if(system.running == NULL){
                        cout<<" "<<endl;
                    } else {
                    cout<<system.running->job->getId()<<endl;
                    }
                    cout<<"q1: ";
                    system.hq1->printJobs();
                    cout<<"q2: ";
                    system.hq2->print();
                    cout<<"cq: ";
                    if(system.cq.size() > 0){
                        cout<<system.cq.at(0)->getId()<<endl;
                    } else {
                        cout<< "[]"<<endl;
                    }
                    cout<<"Quantum: ";
                    cout<<system.getQuantum()<<endl;
                    cout<<"---------------------"<<endl;
                    if(displayTime == 9999){
                        myFile.close();
                        return "done";
                    }
                    break;
                    
                }
                //if the line is a release request
                case 'L': {
                    break;
                }
                default: {
                    cout<<"error reading a line!"<<endl;
                    break;
                }
            }
        }
        
        return "done";
    } else {
        return "error reading file";
    }
    
}
