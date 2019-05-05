//
// Created by michal on 05.05.19.
//
#include <iostream>
#include <vector>

using namespace std;

int solution(int K, vector<int> &A) {

    int s = 0;
    int number = 0;
    for (size_t i = 0; i < A.size(); i++) {
        s += A[i];

        if (s >= K) {
            number++;
            s = 0;
        }
    }
    return number;
}