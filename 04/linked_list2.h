#ifndef INCLUDED_LINKED_LIST2
#define INCLUDED_LINKED_LIST2

#include "../03/node.h"

struct node* create_node(char *eng, char *jpn);

void destory_list(struct node *list);

void concat_list(struct node *p, struct node *list);

#endif

