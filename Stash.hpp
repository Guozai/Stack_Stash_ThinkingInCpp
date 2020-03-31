//
//  Stash.hpp
//  Stash
//
//  Created by Yiping Guo on 17/3/20.
//  Copyright © 2020 Yiping Guo. All rights reserved.
//
//  Header file for a C++-like library

#ifndef Stash_hpp
#define Stash_hpp

struct Stash {
    int size;
    int quantity;
    int next;
    // Dynamically allocated array of bytes:
    unsigned char* storage;

    void initialize(int size);
    void cleanup();
    int add(const void* element);
    void* fetch(int index);
    int count();
    void inflate(int increase);
};

#endif /* Stash_hpp */
