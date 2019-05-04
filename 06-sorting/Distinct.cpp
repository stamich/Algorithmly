//
// Created by michal on 04.05.19.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {

    sort(A.begin(), A.end());
    int count = 1;
    const int fim = A.size() - 1;

    if (A.size() == 0) {
        return 0;
    }

    if (A.size() == 1) {
        return 1;
    }

    for (int i = 0; i < A.size() - 1; i++) {
        if (A[i] != A[i + 1]) {
            count++;
        }
    }
    return count;
}


int main()
{
    vector<int> A = {2,1,1,2,3,1};
    cout << "Distinct: " << solution(A) << endl;
}
