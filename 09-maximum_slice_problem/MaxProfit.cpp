//
// Created by michal on 05.05.19.
//
// Given a log of stock prices compute the maximum possible earning.
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

int solution2(vector<int> &A){
    if(A.size() <= 1){
        return 0;
    }

    const int N = int(A.size());
    int tmp = A[0];
    for(int i = 1; i < N; i ++){
        int tmp2 = A[i];
        A[i] -= tmp;
        tmp = tmp2;
    }
    A[0] = 0;

    int max_ending = 0;
    int max_slice = 0;
    for(int i = 0; i < N; i ++){
        max_ending = max(0, max_ending + A[i]);
        max_slice = max(max_slice, max_ending);
    }
    return max(0, max_slice);
}

int main(){

    vector<int> A = {23171,21011,21123,21366,21013,21367};
    cout << "Maximum possible profit from the transaction is: " << solution(A) << endl;
    cout << "Second solution: " << endl;
    cout << "Maximum possible profit from the transaction is: " << solution2(A) << endl;
    return 0;
}