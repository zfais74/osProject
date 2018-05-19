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
    cout<<fileName<<endl;
    ifstream myFile(fileName.c_str());
    //myFile.open("test.txt");
    string line;
    vector<Job>jobs;
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
                        commandValues.push_back(value);
                    }
                    Job job = Job(arrivalTime, commandValues[0], commandValues[1], commandValues[2], commandValues[3], commandValues[4]);
                    jobs.push_back(job);
                    break;
                }
                    //if the line is a request
                case 'Q': {
                    cout<<"request"<<endl;
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
        cout<<jobs[2].toString()<<endl;
        return "done";
    } else {
        return "error reading file";
    }

}
