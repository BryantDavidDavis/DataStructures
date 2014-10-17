//
//  linked_list.h
//  DataStructures
//
//  Created by Bryant Davis on 10/10/14.
//  Copyright (c) 2014 Bryant Davis. All rights reserved.
//
#include <stdlib.h>
#ifndef DataStructures_linked_list_h
#define DataStructures_linked_list_h

/**
 * a linked list node struct
 * @'value' is the value to be stored
 * @'size' represents the total number of nodes in the list.  This value is only set on the root node
 * @'next' is a pointer to the next element in the list
 * @'end' is a pointer to the final element in the list in the list.  This pointer is only set on the root node
 */
struct ll_node {
    int value;
    int size;
    struct ll_node* next;
    struct ll_node* end;
};

/**
 * initializes a root element with a given value
 * @'value' is the value to be stored
 */
struct ll_node* create_linked_list(int value) {
    struct ll_node* root = (struct ll_node*) malloc( sizeof(struct ll_node));
    root->value = value;
    root->size = 1;
    root->next = 0;
    root->end = root;
    return root;
}

/**
 * appends an element to the linked_list, return 1 if successful
 * @'value' is the value to be stored
 * @root is the address of the pointer to the root node
 */
int ll_append(int value, struct ll_node** root) {
    struct ll_node* new_guy = (struct ll_node*) malloc( sizeof(struct ll_node));
    if(new_guy) {
        new_guy->value = value;
        (*root)->size++;
        (*root)->end->next = new_guy;
        (*root)->end = new_guy;
        new_guy->next = 0;
        return 1;
    } else {
        return 0;
    }
}

/**
 * returns a pointer to the first node with a certain value
 * @'value' is the value to be found
 * @root is the pointer to the root node
 */
struct ll_node* ll_get(int value, struct ll_node* root) {
    struct ll_node* current = root;
    while ((current->next != 0)&&(current->value != value)) {
        current = current->next;
    }
    return current;
}

/**
 * returns a pointer to the element before the first occurance of an element with a certain value
 * @'value' is the value we are looking for
 * @root is the pointer to the root node
 */
struct ll_node* ll_get_previous(int value, struct ll_node* root) {
    struct ll_node* current_node = root;
    struct ll_node* previous_node;
    
    if (root->value == value) {
        return 0; //root is the value so there is no previous
    }
    while ((current_node != 0)&&(current_node->value != value)) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node) {
        return previous_node;
    } else {
        return 0; //the item was not in the array
    }
}

/**
 * inserts a node with a certain value after the first occurance of a certain value, return 1 if successful
 * @'item_value' is the value we are looking to insert after
 * @'new_value' is the value to be inserted
 * @root is the address of the pointer to the root node
 */
int ll_insert_after(int item_value, int new_value, struct ll_node** root) {
    struct ll_node* new_guy = (struct ll_node*) malloc( sizeof(struct ll_node));
    struct ll_node* current = *root;
    if(new_guy) {
        new_guy->value = new_value;
        while((current->value != item_value)&&(current != NULL)) {
            current = current->next;
        }
        new_guy->next = current->next;
        current->next = new_guy;
        if (new_guy->next == NULL) {
            (*root)->end = new_guy;
        }
        (*root)->size++;
        return 1;
    } else {
        return 0;
    }
}

/**
 * removes the first occurance of a certain value, return 1 if successful
 * @'item_value' is the value we are looking to remove
 * @'root' is the address of the pointer to the root node
 */
int ll_remove(int item_value, struct ll_node** root) { //if we are deleting the last element we need to update the end variable
    struct ll_node* end_node = 0;
    struct ll_node* previous_node = 0;
    if ((*root)->value == item_value) { //if the root is the value
        if ((*root)->next == NULL) { //if it is the only value in the list then just delete the reference to the list
            free(*root);
            *root = NULL; //should probably free the pointer to avoid memory leak
            return 1;
        } else {
            end_node = (*root)->end;
            (*root)->next->size = (*root)->size;
            (*root) = (*root)->next;  //replace root with root->next
            (*root)->end = end_node;
            (*root)->size--;
            return 1;
        }
    }
    previous_node = ll_get_previous(item_value, *root); //so if the value wasnt the first item in the list
    
    if (previous_node) {
        if (previous_node->next->next == NULL) { //check if it is the last item in the list
            previous_node->next = NULL;
            (*root)->end = previous_node;
            (*root)->size--;
            return 1;
        } else {
            previous_node->next = previous_node->next->next;
            (*root)->size--;
            return 1;
        }
    } else {
        return 0; //out of memory
    }
}

/**
 * iterates through the whole list printing out each value
 * @root is the address of the pointer to the root node
 */
void ll_print(struct ll_node *root) {
    struct ll_node* iterator = root;
    //iterator = root;
    while (iterator != NULL) {
        printf("%d\t", iterator->value);
        iterator = iterator->next;
    }
    printf("\n");
}

/**
 * returns the value of element at a specified index
 * @'index' is the index of the node we are looking at
 * @root pointer to the root node
 */
int ll_get_value_by_index(int index, struct ll_node* root) {
    struct ll_node* current = root;
    for (int i = 0; ((i < index) && (current != NULL)); i++) {
        current = current->next;
    }
    if (current) {
        return current->value;
    } else {
        return -1; //if we are using negative numbers then this would give a false result, so need to figure this out
    }
}

/**
 * returns the address of the pointer to the node at an index
 * @'index' is the index we are looking at
 * @root is the pointer to the root node
 */
struct ll_node** ll_get_node_by_index(int index, struct ll_node* root) {
    struct ll_node* current = root;
    for (int i = 0; ((i < index) && (current != NULL)); i++) {
        current = current->next;
    }
    if (current) {
        return &current;
    } else {
        return NULL;
    }
}

/**
 * sets the value at a certain index, return 1 if successful 0 if index is not in list
 * @'index' is the index we want to set
 * @'value' is the value we want to give it
 * @root is the address of the pointer to the root node
 */
int ll_set_by_index(int index, int value, struct ll_node** root) {
    struct ll_node** current = ll_get_node_by_index(index, *root);
    
    if (current) {
        (*current)->value = value;
        return 1;
    } else {
        return 0;
    }
}

#endif
