#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void print_list(struct node *p) {
    assert(p != NULL);

    printf("%p eng->%s jpn->%s next->%p\n",
        p,
        p->eng,
        p->jpn,
        p->next
    );

    if (p->next == NULL) return;
    print_list(p->next);
}

void init_node(
    struct node *p,
    char eng[256],
    char jpn[256],
    struct node *next) {
    strcpy(p->eng, eng);
    strcpy(p->jpn, jpn);
    p->next = next;
}

