//
// Created by michal on 04.05.19.
//
// Maximze A[P] * A[Q] * A[R] for any triplet (P, Q, R).
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#include <algorithm>

int solution(vector<int> &A) {
    
    sort(A.begin(), A.end());

    int s = int(A.size());

    int m1 = A[s - 1] * A[s- 2] * A[s - 3];
    if ((A[s - 1] < 0) || (A[0] > 0)) return m1;

    int m2 = A[0] * A[1] * A[s- 1];

    return max(m1, m2);
}
int solution2(vector<int> &A) {

    sort(A.begin(), A.end());

    int maximum1 = A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];

    int maximum2 = A[0] * A[1] * A[A.size() - 1];

    int maximum = max(maximum1, maximum2);
    return maximum;
}

int main(){
    vector<int> A = {-3,1,2,-2,5,6};
    cout << "Maximum: " << solution(A) << endl;
    cout << "Second solution: " << endl;
    cout << "Maximum: " << solution2(A) << endl;
    return 0;
}
