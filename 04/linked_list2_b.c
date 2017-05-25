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

struct node* create_node(char *eng, char *jpn) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    strcpy(p->eng, eng);
    strcpy(p->jpn, jpn);
    return p;
}

int main() {
    struct node *init, *a, *b;
    init = create_node("", "");
    a = create_node("aaa", "あああ");
    b = create_node("bbb", "いいい");
    init->next = a;
    a->next = b;
    
    print_list(init->next);

    return 0;
}
