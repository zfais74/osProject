//
//  projectRunner.cpp
//  os
//
//  Created by Zeke on 5/12/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include "projectRunner.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
ProjectRunner::ProjectRunner(){
    
}

string ProjectRunner::readFile(string fileName){
    cout<<fileName<<endl;
    ifstream myFile(fileName.c_str());
    //myFile.open("test.txt");
    string line;
    if(myFile.is_open()){
        while (!myFile.eof()){
            myFile >> line;
            cout << line << endl;
        }
        myFile.close();
        return "done";
    } else {
        return "error reading file";
    }

}
