//
// Created by michal on 22.02.19.
//
// Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int solution(vector<int> &A) {

    int total = 0;

    for (int i = 0; i < A.size(); i++){
        total += A[i];
    }

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

int solution2(vector<int> &A) {

    const size_t N = A.size();
    vector<int> prev(N), next(N);

    prev[0] = A[0];
    next[N - 1] = A[N - 1];

    for(size_t i = 1; i < N; i ++)
        prev[i] = prev[i - 1] + A[i];

    for(int i = int(N - 2); i >= 0; i --)
        next[i] = next[i + 1] + A[i];

    int min = INT_MAX;
    for(size_t i = 0; i < (N - 1); i ++) {
        const int currentMin = abs(prev[i] - next[i + 1]);
        if(currentMin < min) {
            min = currentMin;
        }
    }
    return min;
}

int main(){

    vector<int> A = {3,1,2,4,3};

    cout << "The minimal difference that can be achieved is: " << solution(A) << endl;
    cout << "Second solution: " << endl;
    cout << "The minimal difference that can be achieved is: " << solution2(A) << endl;
    return 0;
}