//
// Created by michal on 22.02.19.
//
// Check whether array A is a permutation.
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// the best solution
int solution(vector<int> &A){

    // sort the array ascending
    sort(A.begin(), A.end());

    // check each one element of array if is missing
    for (int i = 0; i < A.size(); i++){
        if (A[i] != i + 1)
            return 0;
    }
    return 1;
}

int solution2(vector<int> &A) {
    set<int> s;
    int maximum = 1;
    for (auto i: A) {
        if (s.find(i) == s.end()) {
            s.insert(i);
        } else {
            return false;
        }
        maximum = max(i, maximum);
    }
    return (maximum == s.size());
}

int solution3(vector<int> &A) {
    if(A.empty()){
        return 0;
    }
    const size_t N = A.size();
    const size_t N1 = N + 1;
    unsigned char e[N1];
    for(size_t i = 0; i < N1; i ++){
        e[i] = 0;
    }
    for(size_t i = 0; i < N; i ++){
        if(A[i] > int(N))
            return 0;
        e[A[i]] = 1;
    }
    for(size_t i = 1; i < N1; i ++){
        if(!e[i])
            return 0;
    }
    return 1;
}

int main(){
    vector<int> A = {4,1,3,2};
    vector<int> B = {4,1,3};
    vector<int> C = {5,3,4,1,2,6};
    cout << solution(A) << ", " << solution2(A) << ", " << solution3(A) << endl;
    cout << solution(B) << ", " << solution2(B) << ", " << solution3(B) << endl;
    cout << solution(C) << ", " << solution2(C) << ", " << solution3(C) << endl;
    return 0;
}