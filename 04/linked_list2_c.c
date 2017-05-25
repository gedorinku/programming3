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

int main() {
    struct node *init, *a[16];
    int i;

    init = create_node("", "");

    for (i = 0; i < 16; ++i) {
        a[i] = create_node("hoge", "ほげ");
        concat_list(a[i], init);
    }

    print_list(init->next);

    destory_list(init);

    return 0;
}
