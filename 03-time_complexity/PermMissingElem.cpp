//
// Created by michal on 03.05.19.
//
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    long N = A.size() + 1;
    long sum = N * (N + 1) / 2;
    for (int i = 0; i < A.size(); i++) sum -= A[i];
    return (int) sum;
}

int main(){
    vector<int> A = {2,3,1,5};
    cout << solution(A) << endl;
    return 0;
}