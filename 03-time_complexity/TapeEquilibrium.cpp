//
// Created by michal on 03.05.19.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int solution(vector<int> &A) {

    int total = 0;

    for (int i = 0; i < A.size(); i++)
        total += A[i];

    int difference = INT_MAX;
    int prev = 0;
    int next = total;

    for (int p = 1; p < A.size(); p++) {
        prev += A[p - 1];
        next = total - prev;
        difference = min(difference, abs(prev - next));
    }

    return difference;
}

int main(){
    vector<int> A = {3,1,2,4,3};
    cout << solution(A) << endl;
}