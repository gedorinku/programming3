#define NODE_WORD_LENGTH 256

struct node {
    char eng[NODE_WORD_LENGTH];
    char jpn[NODE_WORD_LENGTH];
    struct node *next;
};

