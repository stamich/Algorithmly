//
// Created by michal on 02.04.19.
//
// Compute number of integers divisible by k in range [a..b].
#include <iostream>

using namespace std;

int solution(int A, int B, int K){

    return (B/K) - (A/K) + (A%K == 0 ? 1 : 0);
}

int solution2(int A, int B, int K) {

    if (A % K != 0){
        A = (A / K + 1) * K;
    }

    if (B < A){
        return 0;
    }
    return (B - A) / K + 1;
}

int main(){

    cout << solution(6,11,1) << endl;
    cout << solution(6,11,2) << endl;
    cout << solution(6,11,3) << endl;
    cout << solution(6,11,4) << endl;

    cout << solution2(6,11,1) << endl;
    cout << solution2(6,11,2) << endl;
    cout << solution2(6,11,3) << endl;
    cout << solution2(6,11,4) << endl;
    return 0;
}