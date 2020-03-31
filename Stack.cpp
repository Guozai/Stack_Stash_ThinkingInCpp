//
//  Stack.cpp
//  Stack_Stash
//
//  Created by Yiping Guo on 15/3/20.
//  Copyright © 2020 Yiping Guo. All rights reserved.
//
//  Linked list with nesting

#include "Stack.hpp"
#include "Stash.hpp"
#include "require.h"
using namespace::std;

const int bufsize = 80;

void Stack::Link::initialize(Stash* dat, Link* nxt) {
    data = dat;
    next = nxt;
}

void Stack::initialize() {
    Stash* stash = new Stash;
    stash->initialize(sizeof(char) * bufsize);
    head->data = stash;
    head->next = 0;
}

void Stack::push(const void * element) {
    // each stash stores 5 lines
    if (head->data->count() < 5) {
        head->data->add(element);
    } else {
        // Push old stash
        Link* newLink = new Link;
        newLink->initialize(head->data, head);
        head = newLink;
        head->data->cleanup();
        // Create new stash
        Stash* newStash = new Stash;
        newStash->initialize(sizeof(char) * bufsize);
        head->data = newStash;
        // Add element to new stash
        head->data->add(element);
    }
}

void* Stack::peek() {
    require(head != 0, "Stack empty");
    return head->data->fetch(head->data->next);
}

void* Stack::pop() {
    if (head == 0) return 0;
    
    void* result;
    Stash* stash = head->data;
    int index = stash->next;
    // retrieve next stash
    if (index < 0) {
        if (head->next == 0) return 0;
        stash->cleanup();
        head = head->next;
        stash = head->data;
    }
    // pop 5 lines within stash
    result = stash->fetch(index);
    stash->next = index - 1;

    return result;
}

void Stack::cleanup() {
    require(head == 0, "Stack not empty");
}
