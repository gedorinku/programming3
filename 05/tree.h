struct node2 {
    char eng[256];
    char jpn[256];
    struct node2 *right;
    struct node2 *left;
}


struct node2 *create_node2(char *eng, char *jpn);

void print_tree(struct node2 *p);

void insert_tree(struct node2 *p, struct node2 *tree);

