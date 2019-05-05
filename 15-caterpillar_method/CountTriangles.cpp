//
// Created by michal on 05.05.19.
//
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {

    int s = int(A.size());
    if (s < 3) return 0;

    sort(A.begin(), A.end());

    if (A[0] + A[1] > A[s - 1]) {
        return s * (s - 1) * (s - 2) / 6;
    }

    int num = 0;
    for (int i = 0; i < s - 2; i++) {
        for (int j = i + 1; j < s - 1; j++) {
            for (int k = j + 1; k < s; k++) {
                if (A[i] + A[j] > A[k]) {
                    num++;
                } else {
                    break;
                }
            }
        }
    }

    return num;
}

int main(){

    vector<int> A = {};
    cout << solution(A) << endl;
    return 0;
}