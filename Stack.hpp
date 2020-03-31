//
//  Stack.hpp
//  Stack_Stash
//
//  Created by Yiping Guo on 15/3/20.
//  Copyright © 2020 Yiping Guo. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include "Stash.hpp"

struct Stack {
    struct Link {
        Stash* data;
        Link* next;
        void initialize(Stash* dat, Link* nxt);
    } *head;
    
    void initialize();
    void push(const void * element);
    void* peek();
    void* pop();
    void cleanup();
};

#endif /* Stack_hpp */
