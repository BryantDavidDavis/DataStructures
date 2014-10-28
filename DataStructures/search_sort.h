//
//  search_sort.h
//  DataStructures
//
//  Created by Bryant Davis on 10/14/14.
//  Copyright (c) 2014 Bryant Davis. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef DataStructures_search_sort_h
#define DataStructures_search_sort_h

//char* search_string_binary(char* to_find, char** sorted_array) {
//    if (sorted_array) {
//        
//    } else {
//        return NULL;
//    }
//}

int search_array_binary(int to_find, int* sorted_array, int first, int last) {
    if (first > last) {
        return -1; //number not found
    } else {
        int middle = (first + last) / 2;
        if (to_find == sorted_array[middle]) {
            return middle;
        } else {
            if (to_find > sorted_array[middle]) {
                return search_array_binary(to_find, sorted_array, middle + 1, last);
            } else {
                return search_array_binary(to_find, sorted_array, first, middle - 1);
            }
        }
    }
}

void select_sort(int* to_sort) {
    int temp = 0;
//    int* pos_min;
//    int* next;
//    int* fill = to_sort;
    int length = 50;
    int pos_min = 0;
    
    for (int fill = 0; fill < length - 1; fill++) {
        pos_min = fill;
        for (int next = fill + 1; next < length; next++) {
            if (to_sort[next] < to_sort[pos_min]) {
                pos_min = next;
            }
        }
        temp = to_sort[fill];
        to_sort[fill] = to_sort[pos_min];
        to_sort[pos_min] = temp;
    }
}

void bubble_sort(int* to_sort) {
    int has_swapped = 0;
    int temp = 0;
    int end_point = 0;
    int length = 50;
    while (end_point < length - 1) {
        has_swapped = 0;
        for (int i = 1; i < length - end_point; i++) {
            if (to_sort[i] < to_sort[i - 1]) {
                temp = to_sort[i];
                to_sort[i] = to_sort[i-1];
                to_sort[i-1] = temp;
                has_swapped = 1;
            }
        }
        if (!has_swapped) {
            printf("it was sorted after pass %d\n", end_point);
            return; //it is sorted
            
        }
        end_point++;
    }
}

void insert_sort(int* to_sort) {
    int temp = 0;
    int next_pos = 0;
    int length = 50;
    for (int end_pos; end_pos < length - 1; end_pos++) {
        next_pos = end_pos + 1;
        temp = to_sort[next_pos];
        int i = 0;
        while (to_sort[i] < temp) {
            i++;
        }
        for (int j = next_pos; j >= i; j--) {
            to_sort[j] = to_sort[j-1];
        }
        to_sort[i] = temp;
    }
}

void shell_sort(int* to_sort) {
    
}

#endif
