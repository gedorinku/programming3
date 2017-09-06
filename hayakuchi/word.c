#include <stdlib.h>
#include <string.h>
#include "word.h"
#include "mora.h"
#include "morabigram.h"

static inline double evaluateWord(const char *roma);

static inline int isVowel(char c);

Word CreateWord(const char *roma, const char *jpn, enum HINSHI hinshi) {
    Word result;
    strcpy(result.roma, roma);
    strcpy(result.jpn, jpn);
    result.hinshi = hinshi;
    result.evaluation = evaluateWord(roma);
    return result;
}

Word *CreateWordPointer(const char *roma, const char *jpn, enum HINSHI hinshi) {
    Word *result = (Word*) malloc(sizeof(Word));
    strcpy(result->roma, roma);
    strcpy(result->jpn, jpn);
    result->hinshi = hinshi;
    result->evaluation = evaluateWord(roma);
    return result;
}

void WordDeepCopy(Word *dist, const Word *src) {
    dist->hinshi = src->hinshi;
    strcpy(dist->roma, src->roma);
    strcpy(dist->jpn, src->jpn);
    dist->evaluation = src->evaluation;
}


double evaluateWord(const char *roma) {
    for (int i = 0; roma[i]; ++i) {
        const char c = roma[i];
        if (('a' <= c && c <= 'z') || c == '-' || c == '\'') continue;
        return 0.0;
    }

    int count = 0;
    Mora moras[256] = {0};

    for (int i = 0; roma[i];) {
        if (isVowel(roma[i])) {
            moras[count].roma[0] = roma[i];
            moras[count].length = 1;
            count++;
            i++;
            continue;
        }

        if (roma[i] == '-') {
            moras[count].roma[0] = roma[i - 1];
            moras[count].length = 1;
            count++;
            i++;
            continue;
        }

        for (int j = i + 1; ; ++j) {
            if (!isVowel(roma[j]) && !(roma[i] == 'n' && roma[j] == '\'')) continue;

            for (int k = 0; k <= j - i; ++k) {
                moras[count].roma[k] = roma[i + k];
            }
            moras[count].length = (size_t)(j - i + 1);
            count++;
            i = j + 1;
            break;
        }
    }

    return EvaluateMoras(count, moras);
}

int isVowel(char c) {
    const char vowels[] = { 'a', 'i', 'u', 'e', 'o' };
    for (int i = 0; i < 5; ++i) {
        if (c == vowels[i]) return 1;
    }
    return 0;
}
