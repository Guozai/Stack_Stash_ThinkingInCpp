//
//  main.cpp
//  Stack_Stash
//
//  Created by Yiping Guo on 15/3/20.
//  Copyright © 2020 Yiping Guo. All rights reserved.
//

#include "Stack.hpp"
#include "require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace::std;

int main(int argc, const char * argv[]) {
    
    requireArgs(argc, 1);
    ifstream in(argv[1]);
    Stack textlines;
    textlines.initialize();
    string line;
    // Read file and store lines in the Stack:
    while (getline(in, line)) {
        textlines.push(new string(line));
    }
    // Pop the lines from the Stack and print them:
    string* s;
    while ((s = (string *)textlines.pop()) != 0) {
        cout << *s << endl;
        delete s;
    }
    textlines.cleanup();

    return 0;
}
