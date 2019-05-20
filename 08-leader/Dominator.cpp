//
// Created by michal on 05.05.19.
//
// Find an index of an array such that its value occurs at more
// than half of indices in the array.
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#include <unordered_map>

int solution(vector<int> &A){
    unordered_map<int, int> um;

    for (size_t i = 0; i < A.size(); i++){
        if (um.find(A[i]) != um.end()){
            um[A[i]]++;
        } else {
            um[A[i]] = 1;
        }

        if (um[A[i]] > A.size() / 2){
            return i;
        }
    }

    return -1;
}

int solution2(vector<int> &A) {

    int stack = 0;
    int size = 0;
    int idx = -1;
    for(size_t i = 0; i < A.size(); i++){
        if(size == 0) {
            size = 1;
            stack = A[i];
            idx = i;
        } else {
            if(stack == A[i]){
                size++;
            } else {
                size--;
            }
        }
    }
    unsigned int count = 0;
    for(size_t i = 0; i < A.size(); i++){
        if(A[i] == stack){
            count++;
            if(count > (A.size() / 2)){
                return idx;
            }
        }
    }
    return -1;
}

int main(){

    vector<int> A = {3,4,3,2,3,-1,3,3};
    cout << "The dominator is: " << solution(A)  << " and his value is: " << A[solution(A)] << endl;
    cout << "Second solution: " << endl;
    cout << "The dominator is: " << solution2(A)  << " and his value is: " << A[solution2(A)] << endl;
    return 0;
}