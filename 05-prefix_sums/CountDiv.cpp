//
// Created by michal on 03.05.19.
//
#include <iostream>

using namespace std;

int solution(int A, int B, int K){

    return (B/K) - (A/K) + (A%K == 0 ? 1 : 0);
}

int main(){

    cout << solution(6,11,1) << endl;
    cout << solution(6,11,2) << endl;
    cout << solution(6,11,3) << endl;
    cout << solution(6,11,4) << endl;
    return 0;
}