#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "morabigram.h"
#include "mora.h"


static inline void evaluate(MoraBigram *bigram);

MoraBigram CreateMoraBigram(const Mora *first, const Mora *second) {
    MoraBigram result;
    result.first = *first;
    result.second = *second;
    evaluate(&result);
    return result;
}

static inline int checkHaveIOrU(const MoraBigram *bigram) {
    if (bigram->first.length <= 1 || bigram->second.length <= 1) {
        return 0;
    }

    const size_t firstLength = bigram->first.length;
    const size_t secondLength = bigram->second.length;
    const char firstLast = bigram->first.roma[firstLength - 1];
    const char secondLast = bigram->second.roma[secondLength - 1];

    return (firstLast == 'u' || firstLast == 'i') &&
            (secondLast == 'u' || secondLast == 'i');
}

static inline int checkHaveA(const MoraBigram *bigram) {
    if (bigram->first.length <= 1 || bigram->second.length <= 1) {
        return 0;
    }

    const size_t firstLength = bigram->first.length;
    const size_t secondLength = bigram->second.length;
    const char firstLast = bigram->first.roma[firstLength - 1];
    const char secondLast = bigram->second.roma[secondLength - 1];

    return firstLast == 'a' && secondLast == 'a';
}

static inline int checkHaveKyaKyuKyo(const MoraBigram *bigram) {
    if (bigram->first.length <= 1 || bigram->second.length <= 1) {
        return 0;
    }

    const char *bigrams[] = { bigram->first.roma, bigram->second.roma };

    const char map[][3][5] = {
            { "ka", "ku", "ko" },
            { "kya", "kyu", "kyo" }
    };

    for (int i = 0; i < 2; ++i) {
        int flags[2] = {0};
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (strcmp(map[(j + i) % 2][k], bigrams[j]) != 0) {
                    continue;
                }

                flags[j] = 1;
                break;
            }
        }

        if (flags[0] && flags[1]) {
            return 1;
        }
    }

    return 0;
}

static inline int checkHaveConsonants(const MoraBigram *bigram, const char *consonants) {
    const char *bigrams[] = { bigram->first.roma, bigram->second.roma };
    const size_t count = strlen(consonants);
    int flags[2] = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < count; ++j) {
            if (consonants[j] != bigrams[i][0]) continue;
            flags[i] = 1;
            break;
        }
    }

    return flags[0] && flags[1];
}


static inline int checkHaveSyaSyuSyo(const MoraBigram *bigram) {
    if (bigram->first.length <= 1 || bigram->second.length <= 1) {
        return 0;
    }

    const char *bigrams[] = { bigram->first.roma, bigram->second.roma };

    const char map[][5][5] = {
            { "sa", "si", "su", "se", "so" },
            { "kya", "kyu", "kyo" }
    };

    for (int i = 0; i < 2; ++i) {
        int flags[2] = {0};
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (strcmp(map[(j + i) % 2][k], bigrams[j]) != 0) {
                    continue;
                }

                flags[j] = 1;
                break;
            }
        }

        if (flags[0] && flags[1]) {
            return 1;
        }
    }

    return 0;
}

void evaluate(MoraBigram *bigram) {
    int flag = 0;
    flag |= //checkHaveIOrU(bigram) ||
            checkHaveA(bigram) ||
            checkHaveKyaKyuKyo(bigram) ||
            checkHaveSyaSyuSyo(bigram) ||
            checkHaveConsonants(bigram, "sh") ||
            checkHaveConsonants(bigram, "m") ||
            checkHaveConsonants(bigram, "n");
    double eval = 0.0;
    eval += checkHaveIOrU(bigram) * 0.8;
    eval += checkHaveA(bigram) * 0.8;
    eval += checkHaveKyaKyuKyo(bigram) * 2.0;
    eval += checkHaveSyaSyuSyo(bigram) * 2.0;
    eval += checkHaveConsonants(bigram, "sh") * 1.5;
    eval += checkHaveConsonants(bigram, "m") * 1.5;
    eval += checkHaveConsonants(bigram, "n") * 1.5;
    //bigram->evaluation = eval;
    bigram->evaluation = flag ? 1 : 0;
}

double EvaluateBigrams(int count, const MoraBigram *bigrams) {
    double value = 0.0;
    int temp = 0;
    for (int i = 0; i < count; ++i) {
        if (bigrams[i].evaluation == 0) {
            if (temp != 0) {
                value += pow(1.3, (double) (temp - 1));
                temp = 0;
            }
            continue;
        }

        //temp++;
        temp += bigrams[i].evaluation;
    }

    if (temp != 0) {
        value += pow(2.0, (double) (temp - 1));
    }

    return value;
}

double EvaluateMoras(int count, const Mora *moras) {
    MoraBigram *bigrams = (MoraBigram*)malloc(sizeof(MoraBigram) * (count + 5));

    for (int i = 0; i < count - 1; ++i) {
        bigrams[i] = CreateMoraBigram(&moras[i], &moras[i + 1]);
    }

    double result = EvaluateBigrams(count - 1, bigrams);
    free(bigrams);
    return result;
}
