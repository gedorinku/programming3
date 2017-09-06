#include <stdio.h>
#include "debug.h"
#include "dictionaryReader.h"
#include "dictionary.h"
#include "word.h"

void PrintWords() {
    Dictionary dictionary = ReadDictionary();
    for (int i = 0; i < 100; ++i) {
        printf("%s %s %d %lf\n", dictionary.words[i].jpn, dictionary.words[i].roma, dictionary.words[i].hinshi, dictionary.words[i].evaluation);
    }
}
