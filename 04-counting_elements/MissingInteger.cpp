//
// Created by michal on 03.05.19.
//
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {

    sort(A.begin(), A.end());

    int N = A.size();

    if (A[N - 1] <= 0) {
        return 1;
    }

    if (A[0] > 1) {
        return 1;
    }

    for (int i = 0; i < (N - 1); i++) {
        if (A[i] <= 0) {
            if (A[i + 1] > 1) {
                return 1;
            }

            continue;
        }

        if ((A[i + 1] - A[i]) > 1) {
            return (A[i] + 1);
        }
    }

    return A[N-1] + 1;
}

int solutionTwo(vector<int> &A){
    vector<int> B = {0};
    int min = 1;

    int number = INT_MAX;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] > 0){
            B.push_back(A[i]);
        }
    }
    for (int i = 1; i < number; i++) {
        if(!B[i] == i){
            return i;
        }
    }
    return min;
}

int main(){
    vector<int> A = {4,1,3,2};
    cout << solution(A) << endl;
    return 0;
}