//
//  stack.h
//  DataStructures
//
//  Created by Bryant Davis on 10/12/14.
//  Copyright (c) 2014 Bryant Davis. All rights reserved.
//

#ifndef DataStructures_stack_h
#define DataStructures_stack_h
#define STARTING_CAPACITY 50
#include <stdio.h>
#include <stdlib.h>
struct stack {
    char* contents;
    int top_of_stack;
    int capacity;
    
};

struct stack* stack_create(int initial_capacity) {
    struct stack* new_stack = (struct stack*) malloc(sizeof(struct stack));

    new_stack->contents = (char*) malloc(initial_capacity);
    new_stack->capacity = initial_capacity;
    new_stack->top_of_stack = -1; //stack is empty
    return new_stack;
}




int stack_push(char letter, struct stack* my_stack) {
    if (my_stack->top_of_stack == (my_stack->capacity - 1)) {
        //need to reallocate memory for a new contents array
        char* new_array = (char*) malloc((my_stack->capacity)*2); //amortized doubling
        if (new_array) {
            for (int i = 0; i <= (my_stack->top_of_stack); i++) {
                new_array[i] = my_stack->contents[i];
            }
            free(my_stack->contents); //this should free the original memory block
            my_stack->contents = new_array; //contents should now point to the new array
            my_stack->capacity *= 2;
            my_stack->top_of_stack++;
            my_stack->contents[my_stack->top_of_stack] = letter;
            return 1;
        } else {
            return 0;
        }

    }
    my_stack->top_of_stack++;
    my_stack->contents[my_stack->top_of_stack] = letter;
    return 1;
}

char stack_pop(struct stack* my_stack) {
    char top_element = '\0';
    if (my_stack->top_of_stack > -1) {
        top_element = my_stack->contents[my_stack->top_of_stack];
        my_stack->contents[my_stack->top_of_stack] = '\0';
        my_stack->top_of_stack--;
        return top_element;
    } else {
        return top_element; //there is nothing in the stack so return a null character
    }
}

char stack_peek(struct stack* my_stack) {
    if (my_stack->top_of_stack > -1) {
        return my_stack->contents[my_stack->top_of_stack];
    } else {
        return '\0';
    }
}

int stack_is_empty(struct stack* my_stack) {
    if (my_stack->top_of_stack == -1) {
        return 1;
    } else {
        return 0;
    }
}

#endif
