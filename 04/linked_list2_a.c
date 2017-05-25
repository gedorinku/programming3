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

int main() {
    struct node *init, *a, *b;
    init = (struct node*)malloc(sizeof(struct node));
    a = (struct node*)malloc(sizeof(struct node));
    b = (struct node*)malloc(sizeof(struct node));
    init_node(init, "", "", a);
    init_node(a, "aaa", "あああ", b);
    init_node(b, "bbb", "いいい", NULL);

    print_list(init->next);

    return 0;
}
