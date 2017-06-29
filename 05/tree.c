#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"

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
    int res = strcmp(p-> eng, tree->eng);
    if (res == 0) {
        return;
    }
    if (res < 0) {
        printf("%sの左に%sを追加\n", tree->eng, p->eng);
        if (tree->left == NULL) {
            tree->left = p;
            return;
        }
        insert_tree(p, tree->left);
        return;
    }

    printf("%sの右に%sを追加\n", tree->eng, p->eng);
    if (tree->right == NULL) {
        tree->right = p;
        return;
    }
    insert_tree(p, tree->right);
}

void print_tree_sorted(struct node2 *p) {
    if (p->left != NULL) {
        print_tree_sorted(p->left);
    }
    printf("%s\t %s\t\n", p->eng, p->jpn);
    if (p->right != NULL) {
        print_tree_sorted(p->right);
    }
}

