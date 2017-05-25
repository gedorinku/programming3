#include <stdlib.h>
#include "node.h"

void print_list(struct node *p);

void init_node(
    struct node *p,
    char eng[256],
    char jpn[256],
    struct node *next
);


int main() {
    struct node init, a, b, c;
    init_node(&init, "", "", &a);
    init_node(&a, "aaa", "あああ", &b);
    init_node(&b, "bbb", "いいい", NULL);

    print_list(init.next);

    return 0;
}
