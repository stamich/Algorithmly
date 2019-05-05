//
// Created by michal on 05.05.19.
//
#include <iostream>

using namespace std;

int solution(int N) {
    unsigned int i = 1;
    int number = 0;
    while (i * i < (unsigned int)N) {
        if (N % i == 0) {
            number += 2;
        }
        i++;
    }

    if (i * i == N) {
        number++;
    }
    return int(number);
}
