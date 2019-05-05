//
// Created by michal on 03.05.19.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A){

    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++){
        if (A[i] != i + 1)
            return 0;
    }
    return 1;
}

int main(){
    vector<int> A = {4,1,3,2};
    vector<int> B = {4,1,3};
    vector<int> C = {5,3,4,1,2,6};
    cout << solution(A) << endl;
    cout << solution(B) << endl;
    cout << solution(C) << endl;
    return 0;
}