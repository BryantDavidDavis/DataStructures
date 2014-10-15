//
//  tree.h
//  DataStructures
//
//  Created by Bryant Davis on 10/14/14.
//  Copyright (c) 2014 Bryant Davis. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "search_sort.h"
#ifndef DataStructures_tree_h
#define DataStructures_tree_h
struct bt_node {
    char data;
    struct bt_node* left_child;
    struct bt_node* right_child;
};

struct bt_node* bt_create_tree(char data, struct bt_node* left_tree, struct bt_node* right_tree) {
    struct bt_node* root = malloc(sizeof(struct bt_node));
    
    if(data) {
        root->data = data;
    }else {
        root->data = '\0';
    }
    if (left_tree != NULL) {
        root->left_child = left_tree;
    } else {
        root->left_child = NULL;
    }
    if (right_tree != NULL) {
        root->right_child = right_tree;
    } else {
        root->right_child = NULL;
    }
    return root;
}

struct bt_node* bst_find(char data, struct bt_node* root) {
    if(root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (root->data < data) {
        return bst_find(data, root->right_child);
    } else {
        return bst_find(data, root->left_child);
    }
}

int bst_insert(char data, struct bt_node** root) {
    if (*root == NULL) {
        *root = bt_create_tree(data, NULL, NULL);
        return 1;
    } else if ((*root)->data == data) {
        return 0; //already in the tree
    } else if ((*root)->data < data) {
        return bst_insert(data, &((*root)->right_child));
    } else {
        return bst_insert(data, &((*root)->left_child));
    }
}

void bst_build_tree(char* data_array, struct bt_node** root) {
    while (*data_array != '\0') {
        bst_insert(*data_array, root);
        data_array++;
    }
}

int bst_contains(char data, struct bt_node* root) {
    if (bst_find(data, root) == NULL) {
        return 0;
    } else {
        return 1;
    }
}

char bst_delete(char to_delete, struct bt_node** root) {
    if (bst_find(to_delete, *root) == NULL) {
        return '\0';
    }
}

#endif
