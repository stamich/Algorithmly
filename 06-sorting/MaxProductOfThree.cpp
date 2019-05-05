//
// Created by michal on 04.05.19.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {

    sort(A.begin(), A.end());

    int maximum1 = A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];

    int maximum2 = A[0] * A[1] * A[A.size() - 1];

    int maximum = max(maximum1, maximum2);
    return maximum;
}

int main(){
    vector<int> A = {-3,1,2,-2,5,6};
    cout << "Maximum: " << solution(A) << endl;

    return 0;
}
