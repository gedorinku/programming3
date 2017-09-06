#ifndef HAYAKUCHI_MORA_H
#define HAYAKUCHI_MORA_H

#include <stddef.h>

typedef struct {
    char roma[10];
    size_t length;
} Mora;

Mora CreateMora(const char *roma);

Mora* CreateMoraPointer(const char *roma);

#endif //HAYAKUCHI_MORA_H
