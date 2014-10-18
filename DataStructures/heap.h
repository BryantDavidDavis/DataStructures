//
//  heap.h
//  DataStructures
//
//  Created by Bryant Davis on 10/17/14.
//  Copyright (c) 2014 Bryant Davis. All rights reserved.
//

#ifndef DataStructures_heap_h
#define DataStructures_heap_h
#define INITIAL_HEAP_CAPACITY 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "search_sort.h"
#include "tree.h"

//the heap will be an array of what, an array of struct with an int value and a string
struct heap_item {
    int value;
    char* string;

};

struct heap {
    struct heap_item* item; //an array of heap items
    int size; //number of items in the heap
    int capacity; //amount of storage allocated to the heap
};

//creates a heap from a heap_item
struct heap_item* heap_item_create(int value, char* string) {
    struct heap_item* new_item = malloc(sizeof(struct heap_item));
    new_item->value = value;
    new_item->string = malloc(strlen(string)*sizeof(char));
    for (int i = 0; string[i] != '\0'; i++) {
        new_item->string[i] = string[i];
    }
    return new_item;
}

struct heap* heap_create(struct heap_item* item) {
    struct heap* new_heap = malloc(sizeof(struct heap));
    if (new_heap) {
        new_heap->item = malloc(INITIAL_HEAP_CAPACITY*sizeof(struct heap_item));
        if (new_heap->item) {
            new_heap->capacity = INITIAL_HEAP_CAPACITY;
            new_heap->item[0] = *item;
            new_heap->size = 1;
        }
    }
    return new_heap;
    
}

int heap_insert(struct heap_item* item, struct heap** my_heap) {
    //if the heap is already full the use amortized doubling to create a new one
    //actually it is not the heap that needs to be reallocated but the heap item array
    if ((*my_heap)->size == (*my_heap)->capacity) {
        struct heap_item* doubled_item = malloc(sizeof(struct heap_item)*2*(*my_heap)->capacity);
        if (doubled_item) {
            //now we need to copy all of the old elements into the new heap
            for (int i = 0; i < (*my_heap)->size; i++) {
                doubled_item[i] = (*my_heap)->item[i];
            }
            free((*my_heap)->item);
            (*my_heap)->item = doubled_item;  //here we need to free the heap, and then point it to the doubled heap
        } else {
            return 0; //we are out of memory my friends
        }
    }
    //then add the new item to the last element in the array
    (*my_heap)->item[(*my_heap)->size] = *item;
    //(*my_heap)->size++;//need to increase the size
    //now that it is in the array, while it is not at the root, and it is smaller than its parent we should swap it with its larger parent
    struct heap_item temp_item;
    int i = (*my_heap)->size; //set the index to the place the item was inserted
    while (i && ( (*my_heap)->item[i].value < (*my_heap)->item[(i-1)/2].value) ) {
        //i is the index of our inserted element
        //if the parent is greater than the child, we swap them
        if ((*my_heap)->item[i].value < (*my_heap)->item[(i-1)/2].value) {
            temp_item = (*my_heap)->item[(i-1)/2];
            (*my_heap)->item[(i-1)/2] = (*my_heap)->item[i];
            (*my_heap)->item[i] = temp_item;
        }
        i = (i - 1)/2;
    }
    (*my_heap)->size++;
    return 1;
}

struct heap_item heap_remove(struct heap** my_heap) {
    struct heap_item item_to_remove = (*my_heap)->item[0];
    
    (*my_heap)->item[0] = (*my_heap)->item[(*my_heap)->size - 1];
    (*my_heap)->size--;
    int i = 0;
    struct heap_item temp_item;
    //while the value is greater than one or both of its children swap it with the smaller of the two
    while(((*my_heap)->item[i].value > (*my_heap)->item[(i+1)*2].value)||(*my_heap)->item[i].value > (*my_heap)->item[(i+1)*2 - 1].value) {
        if((*my_heap)->item[(i+1)*2].value < (*my_heap)->item[(i+1)*2 - 1].value) {
            temp_item = (*my_heap)->item[(i+1)*2];
            (*my_heap)->item[(i+1)*2] = (*my_heap)->item[i];
            (*my_heap)->item[i] = temp_item;
        } else {
            temp_item = (*my_heap)->item[(i+1)*2 - 1];
            (*my_heap)->item[(i+1)*2 - 1] = (*my_heap)->item[i];
            (*my_heap)->item[i] = temp_item;
        }
    }
    
    return item_to_remove;
}

#endif
