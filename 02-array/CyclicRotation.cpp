//
// Created by michal on 02.01.19.
//
// Rotate an array to the right by a given number of steps.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// a little better solution
vector<int> solution(vector<int> &A, int K) {

    if (A.empty()){
        return A;
    }

    // K is the reminder of dividing K by size of A
    K = K % A.size();

    // exclude the border cases and rotate the array
    if (A.empty() || A.size()==1 || K==0){
        return A;
    } else {
        rotate(A.rbegin(), A.rbegin() + K, A.rend());
        return A;
    }
}

vector<int> solution2(vector<int> &A, int K) {

    if (A.empty()){
        return A;
    }

    K = K % A.size();

    if (K == 0){
        return A;
    }

    vector<int> result(A.size());
    const int size1 = int(A.size() - K);

    for (int i = 0; i < size1; i++){
        result[i + K] = A[i];
    }

    for (int i = size1; i < int(A.size()); i++){
        result[i - size1] = A[i];
    }
    return result;
}

int main(){

    int K = 3;
    vector<int> A = {3,8,9,7,6};
    auto result = solution(A, K);

    cout << "Rotated array: ";
    for (auto const& item: result){
        cout << item << " ";
    }
    cout << endl;
    cout << "Second solution: " << endl;

    auto result2 = solution2(A, K);

    cout << "Rotated array: ";
    for (auto const& item: result2){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}