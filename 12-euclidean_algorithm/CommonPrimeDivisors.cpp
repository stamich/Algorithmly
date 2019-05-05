//
// Created by michal on 05.05.19.
//
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

static int gcd(int a, int b){
    if (a % b == 0){
        return b;
    }else{
        return gcd(b, a % b);
    }
}

int solution(vector<int> &A, vector<int> &B){

    int length = A.size();
    assert(length >= 1 && length < 60001 && B.size() == length);
    int a, b, c, d = 0, count = 0;
    for (int i = 0; i < length; ++i){
        a = A[i];
        b = B[i];
        d = gcd(a, b);
        while ((c = gcd(a, d)) != 1)
            a /= c;
        while ((c = gcd(b, d)) != 1)
            b /= c;
        if (1 == a && 1 == b)
            ++count;
    }
    return count;
}