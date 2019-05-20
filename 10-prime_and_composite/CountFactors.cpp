//
// Created by michal on 25.04.19.
//
// Count factors of given number n.
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

int solution2(int N) {
    if(N < 0)
        return 0;
    int counter = 0;
    unsigned int ui = 1;
    while((ui * ui) <= (unsigned int) N) {
        if((N % ui) == 0) {
            if((N / ui) == ui){
                counter += 1;
            } else {
                counter += 2;
            }
        }
        ui++;
    }
    return counter;
}

int main(void){

    int N = 24;
    cout << "Number of factors of " << N << " is: " << solution(N) << endl;
    cout << "Number of factors of " << N << " is: " << solution2(N) << endl;
    return 0;
}