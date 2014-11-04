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

//void shell_sort(int* to_sort) {
//    int next_pos = 0;
//    int length = 50;
//    int gap_val = length/2;
//    int temp = 0;
//    
//    while (gap_val > 0) {
//        for (int end_pos = gap_val; end_pos < length; end_pos++) { //this condition is wrong
//            next_pos = end_pos;
//            temp = to_sort[next_pos];
//            int i = end_pos;
//            while (to_sort[i] < temp) {
//                i = i + gap_val;
//            }
//            for (int j = next_pos; j > i; j = j - gap_val) {
//                to_sort[j] = to_sort[j - gap_val];
//            }
//            to_sort[i] = temp;
//        }
//        if (gap_val == 2) {
//            gap_val = 1;
//        } else {
//            gap_val = gap_val/2.2;
//        }
//    }
//}

void shell_sort(int* to_sort) {
    int length = 50;
    int gap_val = length/2;
    while (gap_val > 0) {
        for (int iterator = gap_val; iterator < length; iterator++) {
            
            int temp = 0;
            for (int next_pos = iterator; next_pos < length; next_pos = next_pos + gap_val) {
                int sub_iterator = next_pos - gap_val;
                temp = to_sort[next_pos];
                int sub_value = to_sort[sub_iterator]; //this will always equal the value at temp because sub_iterator is being set to it
                while ((temp < to_sort[sub_iterator])&&((sub_iterator - gap_val) >= 0)) { //this condition is wrong, for next pos is 31, sub iterator should go to 6 becase 6 is smaller
                    sub_iterator = sub_iterator - gap_val;
                    sub_value = to_sort[sub_iterator];
                }
                if (to_sort[sub_iterator] > temp) { //now check this condition, I think that it may be wrong, do I need this condition? actually I think it is ok
                    for (int j = next_pos; j >= sub_iterator; j = j - gap_val) {
                        to_sort[j] = to_sort[j - gap_val];
                    }
                    to_sort[sub_iterator] = temp;
                }
            }
        }
        if (gap_val == 2) {
            gap_val = 1;
        } else {
            gap_val = gap_val/2.2;
        }
    }
}

void merge_sort(int* to_sort, int length) {
    int left_length = length/2;
    int right_length = length - left_length;
    int array_left[left_length];
    int array_right[right_length];
    int i = 0, j = 0, k = 0;
    
    if (length > 1) {
        
        for (int i = 0; i < left_length; i++) {
            array_left[i] = to_sort[i];
        }
        
        for (int i = 0; i < right_length; i++) {
            array_right[i] = to_sort[i + left_length];
        }
        
        merge_sort(array_left, left_length);
        merge_sort(array_right, right_length);
    }
    
    while ((i < left_length) && (j < right_length)) {
        if (array_left[i] < array_right[j]) {
            to_sort[k] = array_left[i];
            i++;
        } else {
            to_sort[k] = array_right[j];
            j++;
        }
        k++;
    }
    if (i > j) {
        while (j < right_length) {
            to_sort[k] = array_right[j];
            j++;
            k++;
        }
    } else if (j > i) {
        while (i < left_length) {
            to_sort[k] = array_left[i];
            i++;
            k++;
        }
    } else if(j) { //i == j, so we have two situations, either there is a one element right array, or there is a right and left array that still has one more element in the right array, so if j is still zero it means that there was only a one element right array, as there has been no iterations, and so we do nothing, otherwise we put the last element into the to_sort array.
        to_sort[k] = array_right[j]; //this adds the last element from the right array
    }
}

#endif
