#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "mora.h"


Mora CreateMora(const char *roma) {
    Mora result;
    strcpy(result.roma, roma);
    result.length = strlen(roma);
    assert(0 < result.length);
    return result;
}

Mora *CreateMoraPointer(const char *roma) {
    Mora *result = (Mora*) malloc(sizeof(Mora));
    strcpy(result->roma, roma);
    result->length = strlen(roma);
    assert(0 < result->length);
    return result;
}
