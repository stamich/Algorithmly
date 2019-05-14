//
// Created by michal on 05.05.19.
//
// Tie adjacent ropes to achieve the maximum number of ropes of length >= K
#include <iostream>
#include <vector>

using namespace std;

int solution(int K, vector<int> &A){

    int s = 0;
    int number = 0;
    for (size_t i = 0; i < A.size(); i++){
        s += A[i];

        if (s >= K){
            number++;
            s = 0;
        }
    }
    return number;
}

int solution2(int K, vector<int> &A) {
    int result = 0;
    int number = A.size();
    long long s = -K;
    for(int i = 0; i < number; i++){
        s += A[i];
        if (s >= 0){
            result++;
            s = -K;
        }
    }
    return result;
}

int main(void){
    int K = 4;
    vector<int> A = {1,2,3,4,1,1,3};
    cout << "The maximum number of ropes of length greater than or equal to K that can be created: " << solution(K, A) << endl;
    cout << "Second solution: " << endl;
    cout << "The maximum number of ropes of length greater than or equal to K that can be created: " << solution2(K, A) << endl;
    return 0;
}