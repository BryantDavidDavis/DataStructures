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

#endif
