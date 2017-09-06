#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionaryReader.h"
#include "word.h"
#include "dictionary.h"

typedef struct Node {
    Word word;
    struct Node *next;
} Node;

typedef struct {
    int index;
    double evaluation;
} Relation;

inline static int relationCmp(const Relation *left, const Relation *right);

inline static void mergeSortWords(size_t count, Word *words);

Dictionary ReadDictionary() {
    Dictionary result;
    Node *init = (Node*) malloc(sizeof(Node));
    Node *current = init;
    const char fileName[] = "NAIST_Japanese_Dictionary.txt";
    //const char fileName[] = "hoge.txt";
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("file could not be opened:%s\n", fileName);
        exit(1);
    }

    size_t count = 0;
    char jpn[256];
    char roma[256];
    enum HINSHI hinshi;
    while (fscanf(file, " %s %s %d", jpn, roma, &hinshi) != EOF) {
        count++;
        current->next = (Node*) malloc(sizeof(Node));
        current = current->next;
        current->word = CreateWord(roma, jpn, hinshi);
    }
    fclose(file);

    printf("%d words\n", count);
    result.size = count;
    result.words = (Word*) malloc(sizeof(Word) * count);


    for (int i = 0; init->next != NULL; ++i) {
        Node *temp = init;
        init = init->next;
        free(temp);
        WordDeepCopy(result.words + i, &init->word);
    }
    free(init);

    mergeSortWords(count, result.words);

    return result;
}


int relationCmp(const Relation *left, const Relation *right) {
    if (left->evaluation == right->evaluation) return 0;
    if (left->evaluation < right->evaluation) return 1;
    return -1;
}

void mergeSortWords(size_t count, Word *words) {
    Relation *relations = (Relation*)malloc(sizeof(Relation) * count);
    for (int i = 0; i < count; ++i) {
        relations[i].index = i;
        relations[i].evaluation = words[i].evaluation;
    }
    qsort(relations, count, sizeof(Relation), (int(*)(const void*, const void*))relationCmp);

    Word *temp = (Word*)malloc(sizeof(Word) * count);
    for (int i = 0; i < count; ++i) {
        WordDeepCopy(temp + i, words + i);
    }
    for (int i = 0; i < count; ++i) {
        WordDeepCopy(words + i, temp + relations[i].index);
    }
    free(temp);
    free(relations);
}
