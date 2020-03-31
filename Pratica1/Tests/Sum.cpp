/*
 * Sum.cpp
 */

#include "Sum.h"
#include <chrono>

string calcSum(int* sequence, int size) {
    string s = "";
    for (int m = 1 ; m <= size ; m++) {
        int min = 0;
        for (int i = 0; i < m; i++) {
            min += sequence[i];
        }
        int idx = 0;
        int current = min;
        for (int i = 1; i < (size - m + 1); i++) {
            current -= sequence[i - 1];
            current += sequence[i + m - 1];
            if (current < min) {
                min = current;
                idx = i;
            }
        }
        s += to_string(min) + "," + to_string(idx) + ";";
    }
    return s;
}

