#ifndef INCLUDED_FILE_OUT
#define INCLUDED_FILE_OUT

#include <stdio.h>
#include "../04/linked_list2.h"
#include "../05/tree.h"

void store_dicdata(char *filename, char eng[][256], char jpn[][256], int count);

void store_list(char *filename, struct node *list);

//void store_list0(FILE *fp, struct node *list);

void store_tree(char *filename, struct node2 *tree);

//void store_tree0(FILE *fp, struct node2 *tree);

#endif

