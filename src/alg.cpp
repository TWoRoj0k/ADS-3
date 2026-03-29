// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxVal = num;

    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {  // else на той же строке, что и закрывающая скобка
            num = 3 * num + 1;
        }

        if (num > maxVal) {
            maxVal = num;
        }
    }

    return maxVal;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;

    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {  // else на той же строке, что и закрывающая скобка
            num = 3 * num + 1;
        }
        length++;
    }

    return length;
}

unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int bestNum = static_cast<unsigned int>(lbound);
    unsigned int maxLength = collatzLen(lbound);

    for (uint64_t num = lbound + 1; num <= rbound; ++num) {
        unsigned int currentLength = collatzLen(num);

        if (currentLength > maxLength) {
            maxLength = currentLength;
            bestNum = static_cast<unsigned int>(num);
        }
    }

    *maxlen = maxLength;
    return bestNum;
}
