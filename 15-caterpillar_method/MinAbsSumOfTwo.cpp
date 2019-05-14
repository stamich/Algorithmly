//
// Created by michal on 05.05.19.
//
// Find the minimal absolute value of a sum of two elements.
#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int solution(vector<int> &A) {

    if (A.size() == 1) return abs(A[0]) * 2;

    sort(A.begin(), A.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });

    int min_sum = abs(A[0]) * 2;

    for (int i = 0; i < A.size() - 1; i++) {
        min_sum = min(min_sum, abs(A[i] + A[i + 1]));
    }

    return min_sum;
}

int solution2(vector<int> &A){
    sort(A.begin(), A.end());
    int N = A.size();
    int i = 0, j = N - 1;
    int m = INT_MAX;
    while (i <= j){
        int tmp = A[i] + A[j];
        m = min(m, abs(tmp));
        if (tmp <= 0){
            i++;
        }
        else j--;
    }
    return m;
}

int main(){

    vector<int> A = {1,4,-3};
    vector<int> B = {-8,4,5,-10,3};
    cout << "The minimal absolute value of a sum: " << solution(A) << endl;
    cout << "The minimal absolute value of a sum: " << solution(B) << endl;
    cout << "Second solution: " << endl;
    cout << "The minimal absolute value of a sum: " << solution2(A) << endl;
    cout << "The minimal absolute value of a sum: " << solution2(B) << endl;
    return 0;
}