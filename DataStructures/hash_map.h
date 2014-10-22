//
//  hash_map.h
//  DataStructures
//
//  Created by Bryant Davis on 10/21/14.
//  Copyright (c) 2014 Bryant Davis. All rights reserved.
//

#ifndef DataStructures_hash_map_h
#define DataStructures_hash_map_h

#define INITIAL_HASHMAP_CAPACITY 5
#include <string.h>

//this table will be an array whose indexes each store a pointer to the first node of a doubley-linked list, whose data is a string.

struct hash_map {
    struct ll_string_node** table;
    int size;
    int capacity;
};

struct ll_string_node {
    char* value;
    struct ll_string_node* prev; //if prev is null then it is the root of the list
    struct ll_string_node* next;
};

//need a method to initiate an empty map
//need a method to start a new linked_list
//need a method to contstuct a new node, then hashcode the element, and then insert it into the map or into the linked list reference by the map index
//get, put(key, value), remove, size, and isempty, also resize?

struct hash_map* hm_build_map() {
    struct hash_map* my_map = malloc(sizeof(struct hash_map));
    struct ll_string_node** my_table = malloc(sizeof(struct ll_string_node)*INITIAL_HASHMAP_CAPACITY);
    my_map->table = my_table; //do I need to initialize the value of each pointer in the table array to be null?
    my_map->size = 0;
    my_map->capacity = INITIAL_HASHMAP_CAPACITY;
    return my_map;
}

int hm_hash_me(char* value, int capacity) {
    unsigned long long hashcode = 0;
    for (char i = 0; value[i] != '\0'; i++) {
        hashcode = hashcode*31 + value[i];
    }
    return hashcode % capacity;
}

int hm_put(char* value, struct hash_map** my_map) {
    struct ll_string_node* my_node = malloc(sizeof(struct ll_string_node));
    struct ll_string_node* root = malloc(sizeof(struct ll_string_node));
    int hash_code = hm_hash_me(value, (*my_map)->capacity);
    my_node->value = value; //now we have a new node allocated with the given string
    //now we go to the proper index using the hashcode and insert my_node at the beginning of the list that is where the root is
    root = (*my_map)->table[hash_code];
    my_node->next = root;
    root = my_node;
    my_node->prev = root;
    
    
    //    my_node->value = value;
//    my_node->prev = NULL;
//    my_node->next = NULL;
//    int hash_code = hm_hash_me(value, (*my_map)->capacity);
//    //now we should insert at the beginning of the list, since it's easiet
//    first = NULL;
//    my_node->next = first;
//    first = my_node;
//    if ((*my_map)->table[hash_code] == NULL) { //if there is nothing in the index yet, then put this list node there
//       (*my_map)->table[hash_code] = my_node;
//       printf("%s\n", (*my_map)->table[hash_code]->value);
//    } else {
////        my_node = (*my_map)->table[hash_code];
////        //my_node->prev = (*my_map)->table[hash_code]->prev;
////        my_node->next = (*my_map)->table[hash_code]->next;
////        while (my_node->next != NULL) {
////            my_node->prev = my_node; //can I do this? or do I need yet another temp?  I'll try this first
////            temp = my_node->next->next;
////            my_node = my_node->next; //now current has been set to the last element in the array
////            my_node->next = temp;
////            printf("%s\n", my_node->value);
////        }
//        //my_node->prev = current->prev;
//        //my_node->next = current->next; //now the new node should be set to the last node
//        //printf("%s\n", my_node->value);
////    }
    return 1;
}

#endif
