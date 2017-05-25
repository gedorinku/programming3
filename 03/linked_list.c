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

