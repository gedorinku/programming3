#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

struct node* create_node(char *eng, char *jpn) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    strcpy(p->eng, eng);
    strcpy(p->jpn, jpn);
    return p;
}

void destory_list(struct node *list) {
    if (list == NULL) return;
    destory_list(list->next);
    free(list);
}

void concat_list(struct node *p, struct node *list) {
    assert(list != NULL);
    if (list->next != NULL) {
        concat_list(p, list->next);
        return;
    }
    list->next = p;
}


