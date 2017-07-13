#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "file_out.h"

void store_dicdata(char *filename, char eng[][256], char jpn[][256], int count) {
    FILE *fp = fopen(filename, "w");
    assert(fp != NULL);

    int i;
    for (i = 0; i < count; ++i) {
        fprintf(fp, "%s %s\n", eng[i], jpn[i]);
    }

    fclose(fp);
}

void store_list0(FILE *fp, struct node *list) {
    if (list == NULL) return;
    fprintf(fp, "%s %s\n", list->eng, list->jpn);
    store_list0(fp, list->next);
}

void store_list(char *filename, struct node *list) {
    FILE *fp = fopen(filename, "w");
    assert(fp != NULL);

    store_list0(fp, list);

    fclose(fp);
}

void store_tree0(FILE *fp, struct node2 *tree) {
    if (tree == NULL) return;
    store_tree0(fp, tree->left);
    fprintf(fp, "%s %s\n", tree->eng, tree->jpn);
    store_tree0(fp, tree->right);
}

void store_tree(char *filename, struct node2 *tree) {
    FILE *fp = fopen(filename, "w");
    assert(fp != NULL);

    store_tree0(fp, tree);

    fclose(fp);
}

