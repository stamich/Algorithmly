//
// Created by michal on 05.05.19.
//
// There are N chocolates in a circle. Count the number of chocolates
// you will eat.
#include <iostream>

using namespace std;

int solution(int N, int M){

    int oneRoundMaxChocolate = N / M + 1;
    int round = 1;

    while(round <= (N / oneRoundMaxChocolate) + 1 ){

        if(((round*(long)N))%M == 0){
            return (int)(((round*(long)N)) / M);
        }
        else round++;
    }
    return N;
}

int solution2(int N, int M) {
    int a = (N > M) ? N : M;
    int b = (N > M) ? M : N;
    while(true) {
        if((a % b) == 0)
            break;
        else {
            int tmp = a;
            a = b;
            b = tmp % a;
        }
    }

    return (N / b);
}

int main(void){

    int N = 10;
    int M = 4;
    cout << "Number of chocolates: " << solution(N, M) << endl;
    cout << "Second solution: " << endl;
    return 0;
}