//
// Created by michal on 05.05.19.
//

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {

    if (A.size() == 1) return abs(A[0]) * 2;

    sort(A.begin(), A.end(), [](int a, int b) {
        return abs(a) < abs(b); });

    int min_sum = abs(A[0]) * 2;

    for (int i = 0; i < A.size() - 1; i++) {
        min_sum = min(min_sum, abs(A[i] + A[i + 1]));
    }

    return min_sum;
}

int main(){

    vector<int> A = {};
    cout << solution(A) << endl;
    return 0;
}