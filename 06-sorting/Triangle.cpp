//
// Created by michal on 04.05.19.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A){

    sort(A.begin(), A.end());

    for(int i=2; i< A.size(); i++){
        if((long)A[i-2] + (long)A[i-1] > (long)A[i]) // note: using "long" for overflow cases
            return 1;
    }
    return 0;
}

bool isTriangle(int64_t a, int64_t b, int64_t c){
    return (a + b > c) && (b + c > a) && (c + a > b);
}

int solution2(vector<int> &A){

    if (A.size() < 3){
        return 0;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < int(A.size() - 2); i++){
        if (isTriangle(A[i], A[i + 1], A[i + 2])) return 1;
    }
    return 0;
}

int main(){
    vector<int> A = {10,2,5,1,8,20};
    vector<int> B = {};

    if (solution(A)) {
        cout << "Triplet for array: " << " exists." << endl;
    } else {
        cout << "Triplet for array: " << " not exists." << endl;
    }
    cout << "Second solution: " << endl;

    if (solution2(A)){
        cout << "Triplet for array: " << " exists." << endl;
    } else {
        cout << "Triplet for array: " << " not exists." << endl;
    }
    return 0;
}