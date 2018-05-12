//
//  main.cpp
//  os
//
//  Created by Zeke on 5/12/18.
//  Copyright © 2018 Zeke. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "projectRunner.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Test"<<endl;
    ProjectRunner pr;
    string result = pr.readFile("input.txt");
    cout<<result<<endl;
    return 0;
}
