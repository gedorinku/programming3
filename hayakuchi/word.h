#ifndef HAYAKUCHI_WORD_H
#define HAYAKUCHI_WORD_H

enum HINSHI {
    Meishi,
    Doshi,
    Keiyoshi,
    Fukushi,
    Rentaishi,
    Kandoshi,
    Other
};

typedef struct {
    enum HINSHI hinshi;
    char roma[256];
    char jpn[256];
    //数字が大きいほど発音がしにくい　
    double evaluation;
} Word;

Word CreateWord(const char *roma, const char *jpn, enum HINSHI hinshi);

Word* CreateWordPointer(const char *roma, const char *jpn, enum HINSHI hinshi);

void WordDeepCopy(Word *dist, const Word *src);

#endif //HAYAKUCHI_WORD_H
