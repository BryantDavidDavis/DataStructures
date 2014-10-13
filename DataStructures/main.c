//
//  main.c
//  DataStructures
//
//  Created by Bryant Davis on 10/10/14.
//  Copyright (c) 2014 Bryant Davis. All rights reserved.
//

#include <stdio.h>
#include "linked_list.h"

int main(int argc, const char * argv[]) {

    struct ll_node* root = create_linked_list(7);
    
    ll_append(9, &root);
    ll_append(3, &root);
    ll_print(root);

    ll_insert_after(9, 6, &root);
    
    ll_set_by_index(0, 42, &root);
    printf("the value is: %d\n", ll_get_value_by_index(0, root));
    ll_print(root);

    ll_remove(9, &root);

    ll_remove(7, &root);

    ll_remove(3, &root);

    ll_append(107, &root);
 
    printf("%d\n", root->size);
    ll_append(107, &root);
    
    printf("\n");
    ll_remove(107, &root);
    
    ll_print(root);
    printf("\n");
    printf("%d\n", root->size);
    return 0;
}
