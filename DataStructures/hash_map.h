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
#define INITIAL_TABLE_STRING_LENGTH 40
#include <string.h>
#include <limits.h>
//this table will be an array whose indexes each store a pointer to the first node of a doubley-linked list, whose data is a string.

struct hash_map {
    struct ll_string_node** table;
    int size;
    int capacity;
};

struct ll_string_node {
    char* value;
    struct ll_string_node* next;
};

//need a method to initiate an empty map -- check
//need a method to start a new linked_list --not necessary
//need a method to contstuct a new node, then hashcode the element, and then insert it into the map or into the linked list reference by the map index -- check
//get, put(key, value), remove, size, and isempty, also resize/reshash?

struct hash_map* hm_build_map() {
    struct hash_map* new_map = malloc(sizeof(struct hash_map));
    new_map->table = malloc(sizeof(struct ll_string_node*)*INITIAL_HASHMAP_CAPACITY);
    for (int i = 0; i < INITIAL_HASHMAP_CAPACITY; i++) {
        new_map->table[i] = NULL;
    }
    new_map->size = 0;
    new_map->capacity = INITIAL_HASHMAP_CAPACITY;
    return new_map;
}

int hm_hash_me(char* value, int capacity) {
    unsigned long long int hashcode = 0;
    for (int i = 0; value[i] != '\0'; i++) {
        hashcode = hashcode*31 + value[i];
    }
    return hashcode % capacity;
}

int hm_put(char* value, struct hash_map** my_map) {
    struct ll_string_node* new_node = malloc(sizeof(struct ll_string_node));
    int hashcode = 0;
    if (new_node) {
        new_node->value = malloc(sizeof(char)*INITIAL_TABLE_STRING_LENGTH); //new_node->value is also an address
        if (new_node->value) {
            new_node->next = NULL;
            strcpy(new_node->value, value); //value is now stored in new_node->value
            hashcode = hm_hash_me(value, (*my_map)->capacity);
            if ((*my_map)->table[hashcode] == NULL) {
                (*my_map)->table[hashcode] = new_node;
            } else {
                new_node->next = (*my_map)->table[hashcode];
                (*my_map)->table[hashcode] = new_node;
            }
            (*my_map)->size++;
            return 1;
        } else {
            return 0;
        }

    } else {
        return 0;
    }

}

struct ll_string_node* hm_get(char* value, struct hash_map* my_map) {
    struct ll_string_node* temp;
    int hashcode = hm_hash_me(value, my_map->capacity);
    temp = my_map->table[hashcode];
    while (temp != NULL) {
        if (strcmp(temp->value, value) == 0) {
            printf("%s\t", temp->value);
            //return my_map->table[hashcode]; //but this doesn't return the right address
            return temp; //this should be the correct address
        } else {
            printf("%s\t", temp->value);
            temp = temp->next;
        }
    }
    return temp;
}



#endif
