#ifndef HAYAKUCHI_DICTIONARY_H
#define HAYAKUCHI_DICTIONARY_H

#include <stddef.h>
#include "word.h"

typedef struct {
    size_t size;
    Word *words;
} Dictionary;

#endif //HAYAKUCHI_DICTIONARY_H
