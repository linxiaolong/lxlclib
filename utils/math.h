
#ifndef _MATH_H_
#define _MATH_H_

#include <stdio.h>
#include <stdint.h>

static inline void
number2hex(char* s, uint32_t id){
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    uint32_t i;
    for (i = 0; i < 8; i++){
        s[i] = hex[(id >> (28 - 4*i)) & 0xf];
    }
    s[8] = '\0';
}

#endif

