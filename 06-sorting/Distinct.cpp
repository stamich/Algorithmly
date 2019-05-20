//
// Created by michal on 04.05.19.
//
// Compute number of distinct values in an array.
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> &A) {

    set<int> s;
    for (auto i: A) {
        s.insert(i);
    }

    return int(s.size());
}

int solution2(vector<int> &A) {

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
    cout << "Second solution: " << endl;
    cout << "Distinct: " << solution2(A) << endl;
    return 0;
}
