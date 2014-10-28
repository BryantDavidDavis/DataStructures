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

void hm_rehash(struct hash_map** old_map);
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

//I think I also need to add a provision that checks if something is already in the table or not
int hm_put(char* value, struct hash_map** my_map) {
    struct ll_string_node* new_node = malloc(sizeof(struct ll_string_node));
    int hashcode = 0;
    //now check the load factor of the map
    if ((((*my_map)->size/(*my_map)->capacity)) >= 1) {
        //rehashing fun begins and ends with this function
        hm_rehash(my_map);
        printf("%d\n", (*my_map)->capacity);
        
    } //something is wrong here, after rehashing, the value is reset and we begin inserting it again.
    
    //nothing below here should change
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

//this will create a new map, double the size of the old one, free the old memory and point the my_map variable to the new map
void hm_rehash(struct hash_map** old_map) {
    struct hash_map* new_map = hm_build_map();
    struct ll_string_node** new_table;
    struct ll_string_node* temp;
    if (new_map) {
        new_map->capacity = (*old_map)->capacity * 2;
        new_map->size = 0; //should start at zero because we haven't copied anything into it yet
        //since the hm_build_map function built a table with the original capacity we need to make a new table and point to it.
        new_table = malloc(sizeof(struct ll_string_node*)*new_map->capacity);
        if (new_table) {
            free(new_map->table);
            new_map->table = new_table;
            for (int i = 0; i < new_map->capacity; i++) {
                new_map->table[i] = NULL;
            }
            //now iterate through the old map elements and traverse the list putting all old values into new table
            for (int j = 0; j < (*old_map)->capacity; j++) {
                temp = (*old_map)->table[j];
                while (temp != NULL) {
                    hm_put(temp->value, &new_map);
                    temp = temp->next;
                }
            }
            //now that all of the old values should be in the new map we can free the old map memory and point the variable to the new map
            free(*old_map); //I guess I free the dereferenced double pointer
            *old_map = new_map;
        }

    }//should I have an else condition here?
}

int hm_remove(char* value, struct hash_map** my_map) {
    int hashcode = hm_hash_me(value, (*my_map)->capacity);
    struct ll_string_node* current;
    struct ll_string_node* previous;

    if ((*my_map)->table[hashcode] == NULL) {
        return 0;
        //its not in the table
    } else {
        current = (*my_map)->table[hashcode];
        previous = NULL;
        while ((strcmp(value, current->value) != 0)&&(current != NULL)) {
            previous = current;
            current = current->next;
        }
        //now we check if it got to the end of the list or if it found the item
        if (current == NULL) {
            return 0;
        } else if(previous == NULL){
            (*my_map)->table[hashcode] = (*my_map)->table[hashcode]->next;
            //the first node is the value to remove
            return 1;
        } else {
            //we have found the node and it is at current
            previous->next = current->next;
            free(current);
            return 1;
        }
    }
}

#endif
