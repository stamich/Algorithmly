//
// Created by michal on 05.05.19.
//
#include <iostream>

using namespace std;

int solution(int N, int M){

    int oneRoundMaxChocolate = N / M + 1;
    int num = 0;
    int round = 1;

    while(round <= (N / oneRoundMaxChocolate) + 1 ){

        if(((round*(long)N))%M == 0){
            return (int)(((round*(long)N)) / M);
        }
        else round++;
    }
    return N;
}
