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

struct bt_node* bts_find(char data, struct bt_node* root) {
    if(root == NULL) {
        return NULL;
    } else if (root->data == data) {
        return root;
    } else if (root->data < data) {
        return bts_find(data, root->right_child);
    } else {
        return bts_find(data, root->left_child);
    }
}


#endif
