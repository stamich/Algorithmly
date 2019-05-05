//
// Created by michal on 05.05.19.
//
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    if (A.size() == 0){
        return 0;
    }

    int minValue = A[0];

    vector<int> vmin(A.size());

    for (size_t i = 0; i < A.size(); i++) {
        minValue = min(minValue, A[i]);
        vmin[i] = minValue;
    }

    vector<int> vmax(A.size());
    int maxValue = A[int(A.size()) - 1];

    for (int i = int(A.size()) - 1; i >= 0; i--) {
        maxValue = max(maxValue, A[i]);
        vmax[i] = maxValue;
    }

    int maxProfit = 0;
    for (size_t i = 0; i < A.size(); i++) {
        maxProfit = max(vmax[i] - vmin[i], maxProfit);
    }

    return maxProfit;
}