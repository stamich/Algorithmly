//
// Created by michal on 02.05.19.
//
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {

    int element = 0;

    for (int i = 0; i < A.size() ; ++i) {
        element ^=A[i];
    }
    return element;
}

int main(){
    vector<int> A = {9,3,9,3,9,7,9};
    cout << solution(A) << endl;
    return 0;
}