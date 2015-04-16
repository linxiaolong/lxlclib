
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

static inline uint32_t
netbytes2uint32(uint8_t* s){
    uint32_t* t = (uint32_t*)s;
    uint32_t ret = ntohl((uint32_t)*t);
    return ret;
}

static inline void
uint322netbytes(uint32_t i, uint8_t* s){
    uint32_t ret = htonl(i);
    uint8_t* p = (uint8_t*)&ret;
    s[0] = *(p);
    s[1] = *(p + 1);
    s[2] = *(p + 2);
    s[3] = *(p + 3);
}

static inline uint32_t
netbytes2uint32_m(uint8_t* s){
    uint32_t a0 = s[0] << 24;
    uint32_t a1 = s[1] << 16;
    uint32_t a2 = s[2] << 8;
    uint32_t a3 = s[3];
    uint32_t ret = (uint32_t)(a0 | a1 | a2 | a3);
    return ret;
}

static inline void
uint322netbytes_m(uint32_t i, uint8_t* s){
    s[0] = (uint8_t)(i >> 24);
    s[1] = (uint8_t)(i >> 16);
    s[2] = (uint8_t)(i >> 8);
    s[3] = (uint8_t)(i);
}
