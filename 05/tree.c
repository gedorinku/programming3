#include <memory.h>
#include <string.h>
#include <stdio.h>
#include "node2.h"

struct node2 *create_node2(char *eng, char *jpn) {
    struct node2 *p = (struct node2*) malloc(sizeof(struct node2));
    strcpy(p->eng, eng);
    strcpy(p->jpn, jpn);
    return p;
}

void print_tree(struct node2 *p) {
    if (p->left != NULL) {
        print_tree(p->left);
    }
    if (p->right != NULL) {
        print_tree(p->right);
    }
    printf("%p\t %s\t %s\t %p\t %p\t\n",
            p, p->eng, p->jpn, p->left, p->right);
}

void insert_tree(struct node2 *p, struct node2 *tree) {
    if (tree->left != NULL) {
        insert_tree(p, tree->left);
        return;
    }
    tree->left = p;
}

