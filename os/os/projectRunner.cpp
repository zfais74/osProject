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
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#define COMMAND_PROPERTIES int 3;
#define JOB_PROPERTIES int 5;
using namespace std;
ProjectRunner::ProjectRunner(){
    
}

string ProjectRunner::readFile(string fileName){
    SystemConfig system;
    cout<<fileName<<endl;
    ifstream myFile(fileName.c_str());
    //myFile.open("test.txt");
    HoldQ2 q2 = HoldQ2();
    HoldQ1 q1 = HoldQ1();
    string line;
    vector<Job*>jobs;
    if(myFile.is_open()){
        while (myFile >> line){
            cout << line << endl;
            vector<string> lineSeparated;
            vector<int> commandValues;
            string lineSegment;
            char command = line[0];
            switch (command) {
                    //if the line is a system config
                case 'C':{
                    cout<<"config!"<<endl;
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
                    system = SystemConfig(arrivalTime, commandValues[0], commandValues[1], commandValues[2]);
                    break;
                }
                    //if the line is a job
                case 'A': {
                    cout<<"job"<<endl;
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
                    if(job->getPriority() == 2 && (system.getAvailableMem() > job->getUnitsOfMem() && system.getAvailableDevices() > job->getMaxDevices())){
                        system.useMem(job->getUnitsOfMem());
                        system.useDevices(job->getMaxDevices());
                        q2.insert(job);
                    } else {
                        cout<<"reject"<<endl;
                    }
                    if(job->getPriority() == 1 && (system.getAvailableMem() > job->getUnitsOfMem() && system.getAvailableDevices() > job->getMaxDevices())) {
                        cout<<"push to q1"<<endl;
                        system.useMem(job->getUnitsOfMem());
                        system.useDevices(job->getMaxDevices());
                        q1.insertJob(job);
                    } else {
                        cout<<"reject q1"<<endl;
                    }
                    jobs.push_back(job);
                    break;
                }
                    //if the line is a request
                case 'Q': {
                    cout<<"request"<<endl;
                    myFile >> line;
                    int arrivalTime = stoi(line);
                    cout<<arrivalTime<<endl;
                    for(int properties = 0; properties < 2; properties++){
                        myFile >> line;
                        //separates the Letter=Number string since there's no clean way to do it in c++...
                    }
                    break;
                }
                    //if the line is a display command
                case 'D':{
                    cout<<"display"<<endl;
                    break;
                    
                }
                    //if the line is a release request
                case 'L': {
                    cout<<"release"<<endl;
                    break;
                }
                default: {
                    cout<<"error!"<<endl;
                    break;
                }
            }
        }
        myFile.close();
        cout<<system.toString()<<endl;
        //cout<<jobs[2]->toString()<<endl;
        cout<<"q2 ---------"<<endl;
        q2.print();
        cout<<"bllaha"<<endl;
        q1.printJobs();
        return "done";
    } else {
        return "error reading file";
    }

}
