//
//  main.c
//  DataStructures
//
//  Created by Bryant Davis on 10/10/14.
//  Copyright (c) 2014 Bryant Davis. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "search_sort.h"
#include "tree.h"
#include "heap.h"
#include "hash_map.h"

int main(int argc, const char * argv[]) {

//    struct ll_node* root = create_linked_list(7);
//    
//    ll_append(9, &root);
//    ll_append(3, &root);
//    ll_print(root);
//
//    ll_insert_after(9, 6, &root);
//    
//    ll_set_by_index(0, 42, &root);
//    printf("the value is: %d\n", ll_get_value_by_index(0, root));
//    ll_print(root);
//
//    ll_remove(9, &root);
//
//    ll_remove(7, &root);
//
//    ll_remove(3, &root);
//
//    ll_append(107, &root);
// 
//    printf("%d\n", root->size);
//    ll_append(107, &root);
//    
//    printf("\n");
//    ll_remove(107, &root);
//    
//    ll_print(root);
//    ll_remove(6, &root);
//    ll_remove(42, &root);
//    ll_print(root);
//    printf("\n");
//    printf("%d\n", root->size);
//    int* int_array;
//    int_array = (int*) malloc(50*sizeof(int));
//    int_array[5] = 42;
//    printf("%d\n", int_array[5]);
//    
//    char* char_array;
//    char_array = (char*)malloc(50);
//    char_array[5] = 'b';
//    char* char_pointer = &char_array[1];
//    printf("%d\n", char_array);
//    printf("%d\n", char_pointer);
//    printf("%c\n", char_array[5]);
    //stack_push('a', &my_stack);

//    
//    struct stack* my_stack = stack_create(50);
//    char counter = 32;
//    for (int j = 0; j < 100; j++) {
//        stack_push(counter, my_stack);
//        counter++;
// 
//        printf("%c, %d\t", my_stack->contents[j], j);
//    }
//
//    printf("%c\n", stack_pop(my_stack));
//    printf("%c\n", stack_pop(my_stack));
//
//    printf("%c\n", stack_peek(my_stack));
//    printf("%d\n", stack_is_empty(my_stack));
//    
    
//    struct queue* my_queue = queue_create();
    //strcpy(my_queue->contents[0], "Spencer");
    //queue_offer("Daniels", my_queue);
    //printf("%s\n", my_queue->contents[0]);
    //printf("%s\n", queue_poll(my_queue));
    //printf("%s\n", queue_poll(my_queue));
    //char* last_names[] = {"Alito", "Breyer", "Ginsberg", "Kagan", "Kennedy", "Roberts", "Scalia", "Sotomayor", "Thomas"};
//    for (int counter = 0; counter < 100; counter++) {
//        
//        queue_offer(last_names[counter % 9], my_queue);
//    }
//    printf("%s\n", queue_peek(my_queue));
//    while (my_queue->size) {
//        printf("%s\t", queue_poll(my_queue));
//    }
    //printf("found Justice %s\n", search_string_binary("Ginsberg", &last_names));
//    int my_array[100];
//    for (int i = 0; i < 100; i++) {
//        my_array[i] = i*2;
//    }
//    printf("found number: %d\n", search_array_binary(259, my_array, 0, 99));
    
    //struct bt_node* node1 = bt_create_tree('b', bt_create_tree('a', NULL, NULL), bt_create_tree('c', NULL, NULL));
    
    //struct bt_node* root;
    //struct queue* my_queue;
    //bst_insert('l', &root);
    //bst_insert('x', &root);
    //bst_build_tree("from moscow to nakhotka it is better with vodka than without", &root);
    //printf("%d\n", bst_contains('r', root));
    //bst_insert('l', &root);
    //bst_insert('p', &root);
    //bst_delete('f', &root);
    //bst_delete('f', &root);
    //bst_delete('c', &root);
    //bst_delete('k', &root);
    //bst_delete('s', &root);
    //bst_insert('q', &root);
    //bst_insert('f', &root);
    //bt_traverse_preorder(root);
    //bt_traverse_inorder(root);
    //printf("%c\n", bst_delete('x', &root));
    //printf("%lu", bts_find('l', root));
    //bt_traverse_postorder(root);
    //printf("%c\n", node1->right_child->data);
    //printf("%lu", bts_find('a', node1));
//    struct heap_item* a = heap_item_create(406, "A Tale of Two Cities");
//    struct heap_item* b = heap_item_create(889, "War and Peace");
//    struct heap_item* c = heap_item_create(123, "Old Man and the Sea");
//    struct heap_item* d = heap_item_create(234, "The Great Gatsby");
//    struct heap_item* e = heap_item_create(345, "To Kill a Mockingbird");
//    struct heap_item* f = heap_item_create(555, "The Firm");
//    struct heap_item* g = heap_item_create(20, "M is for Murder");
//    struct heap_item* h = heap_item_create(477, "The Hunger Games");
//    struct heap_item* i = heap_item_create(621, "Crime and Punishment");
//    struct heap_item* j = heap_item_create(110, "The Metamorphosis");
//    struct heap_item* k = heap_item_create(713, "Madame Bovary");
//    struct heap_item* l = heap_item_create(5, "A Catcher in the Rye");
//    struct heap_item* m = heap_item_create(1007, "The Oddysey");
//    struct heap_item* n = heap_item_create(101, "The Idiot");
//
//    struct heap* my_heap = heap_create(a);
//    heap_insert(b, &my_heap);
//    heap_insert(c, &my_heap);
//    heap_insert(d, &my_heap);
//    heap_insert(e, &my_heap);
//    heap_insert(f, &my_heap);
//    heap_insert(g, &my_heap);
//    heap_insert(h, &my_heap);
//    heap_insert(i, &my_heap);
//    heap_insert(j, &my_heap);
//    heap_insert(k, &my_heap);
//    heap_insert(l, &my_heap);
//    heap_insert(m, &my_heap);
//    heap_insert(n, &my_heap);
//    //ok, so amortized doubling works, and insertion works
//    //printf("%s\n", my_heap->item[0].string);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);
//    printf("%s\n", my_heap->item[0].string);
//    heap_remove(&my_heap);

    struct hash_map* my_map = hm_build_map();
    //printf("%d\n", hm_put("bonanza", &my_map));
    hm_put("law and order", &my_map);
    hm_put("Batman", &my_map);
    hm_put("CSI Miami", &my_map);
    hm_put("Snoopy", &my_map);
    hm_put("The Flash", &my_map);
    //printf("%d\n", hm_put("The Good Wife", &my_map));
    //hm_print(my_map);
    //printf("%s", my_map->table->value);
    hm_get("law and order", my_map);
    hm_get("CSI Miami", my_map);
    hm_get("The Flash", my_map);
    hm_get("Batman", my_map);
    hm_get("Pinwheel", my_map);
    return 0;
}
