#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int validBit;
    int tag; // will have to bitwise total bits to get this value
    int bBits;
    int setIndex;
} cache;

typedef cache *set;
typedef set *setPointer; // maybe call it memory later

// TODO: add bitwise function to get tag bits and b bits.

int main() {
    
    
}