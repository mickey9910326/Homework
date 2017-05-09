#include <avr\io.h>
#include <avr\interrupt.h>
#include <stdio.h>

#ifndef MAXERBUFERSIZE
#define MAXERBUFERSIZE 32
#endif

int main(void) {

    return 0;
}

typedef struct {
    uint8_t PUTindex;
    uint8_t GETindex;
    uint8_t data[MAXERBUFERSIZE];
} TypeBuffer;
