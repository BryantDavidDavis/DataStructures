//
//  queue.h
//  DataStructures
//
//  Created by Bryant Davis on 10/13/14.
//  Copyright (c) 2014 Bryant Davis. All rights reserved.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef DataStructures_queue_h
#define DataStructures_queue_h
#define INITIAL_STACK_CAPACITY 50
#define INITIAL_STACK_STRING_CAPACITY 25

//circular array implementation of queue
struct queue {
    char contents[INITIAL_STACK_CAPACITY][INITIAL_STACK_STRING_CAPACITY];
    int front;
    int rear;
    int size;
    int capacity;
    int string_length;
};

struct queue* queue_create() {
    struct queue* new_queue = malloc(sizeof(struct queue));
//    char* outer_array[] = malloc(initial_capacity*sizeof(char*));
//    for (int i = 0; i < initial_cpacity; i++) {
//        outer_array[i] = malloc(25*sizeof(char));
//    }
//    new_queue->contents = outer_array;
    new_queue->front = 0;
    new_queue->rear = INITIAL_STACK_CAPACITY - 1;
    new_queue->size = 0;
    new_queue->capacity = INITIAL_STACK_CAPACITY;
    new_queue->string_length = INITIAL_STACK_STRING_CAPACITY;
    return new_queue;
}

int queue_offer(char* to_insert, struct queue* my_queue) {
    int iterator = my_queue->front;
    
    if (my_queue->size == my_queue->capacity) {
        //now I need to allocate a new memory block with a multidimensional array of char pointers
        char** tempArray = malloc((my_queue->capacity*2)*sizeof(*tempArray));
        for (int i = 0; i < (my_queue->capacity*2); i++) {
            tempArray[i] = malloc(my_queue->string_length);
        }
        //now copy the data
        for (int j = 0; j < my_queue->size; j++) {
            strcpy(tempArray[j], my_queue->contents[iterator]);
            iterator = (iterator + 1) % my_queue->capacity;
        }
        //now free the old memory block and point the contents pointer to the new one
        //my_queue->contents = tempArray;
        
    }
    my_queue->rear = ((my_queue->rear) + 1) % my_queue->capacity;
    strcpy(my_queue->contents[my_queue->rear], to_insert);
    my_queue->size++;
    return 1;
}

char* queue_poll(struct queue* my_queue) {
    if ((my_queue)->size) {
        char* result = malloc((my_queue)->string_length);
        if (result) {
            result = (my_queue)->contents[(my_queue)->front];
            my_queue->front = (my_queue->front + 1) % my_queue->capacity;
            (my_queue)->size--;
            return result;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}
#endif
