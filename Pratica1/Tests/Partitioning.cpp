/*
 * Partioning.cpp
 */

#include "Partitioning.h"


int s_recursive(int n,int k) {
    if (k == 1 || k == n) return 1; else return s_recursive(n - 1, k - 1) + k*s_recursive(n - 1, k);
}

int s_dynamic(int n,int k) {
    int res = 1;
    return res;
}


int b_recursive(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += s_recursive(n, i);
    return sum;
}

int b_dynamic(int n) {
    int sum = 0;
    for (int i=1 ; i<=n ; i++)
        sum += s_dynamic(n,i);
    return sum;
}


