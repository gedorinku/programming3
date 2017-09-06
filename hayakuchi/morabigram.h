#ifndef HAYAKUCHI_MORABIGRAM_H
#define HAYAKUCHI_MORABIGRAM_H

#include "mora.h"

typedef struct {
    Mora first, second;
    //評価値が大きいほど発音しにくい
    double evaluation;
} MoraBigram;

MoraBigram CreateMoraBigram(const Mora *first, const Mora *second);

double EvaluateBigrams(int count, const MoraBigram *bigrams);

double EvaluateMoras(int count, const Mora *moras);

#endif //HAYAKUCHI_MORABIGRAM_H
