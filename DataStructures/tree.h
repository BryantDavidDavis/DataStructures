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

struct bt_node* bst_find_largest_descendant(struct bt_node* root) {
    while (root->right_child != NULL) {
        root = root->right_child;
    }
    return root;
}

char bst_delete(char to_delete, struct bt_node** root) {
    char deleted_char = '\0';
    if (*root == NULL) {
        return '\0';
    } else if ((*root)->data > to_delete) {
        return bst_delete(to_delete, &((*root)->left_child));
    } else if ((*root)->data < to_delete) {
        return bst_delete(to_delete, &((*root)->right_child));
    } else { //we have found the node to delete
        if (((*root)->left_child == NULL) && ((*root)->right_child) == NULL) {
            deleted_char = (*root)->data;
            *root = NULL;
            return deleted_char;
        } else if ((*root)->left_child == NULL) { //in this case there is a right child so just set it to the parent
            deleted_char = (*root)->data;
            *root = (*root)->right_child;
            return deleted_char;
        } else if ((*root)->right_child == NULL){
            deleted_char = (*root)->data;
            *root = (*root)->left_child;
            return deleted_char;
        } else { //there are two nodes so we need to find the inorder predecessor which is the rightmost node of the left subtree of the item to be romoved
            struct bt_node* temp = bst_find_largest_descendant((*root)->left_child);
            deleted_char = (*root)->data;
            (*root)->data = temp->data;
            bst_delete(temp->data, &((*root)->left_child));
            return deleted_char;
        }
    }
}

void bt_traverse_preorder(struct bt_node* my_tree) { //prints out the characters using preorder traversal
    if (my_tree == NULL) {
        return ;
    } else {
        printf("%c\t", my_tree->data);
        bt_traverse_preorder(my_tree->left_child);
        bt_traverse_preorder(my_tree->right_child);
    }
}

void bt_traverse_inorder(struct bt_node* my_tree) { //prints out the characters using inorder traversal
    if (my_tree == NULL) {
        return;
    } else {
        bt_traverse_inorder(my_tree->left_child);
        printf("%c\t", my_tree->data);
        bt_traverse_inorder(my_tree->right_child);
    }
}

void bt_traverse_postorder(struct bt_node* my_tree) { //prints out the characters using inorder traversal
    if (my_tree == NULL) {
        return;
    } else {
        bt_traverse_postorder(my_tree->left_child);
        bt_traverse_postorder(my_tree->right_child);
        printf("%c\t", my_tree->data);
    }
}

#endif
