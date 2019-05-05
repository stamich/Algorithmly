//
// Created by michal on 02.05.19.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> &A, int K) {

    if (A.empty()){
        return A;
    }
    K = K % A.size();

    if (A.size()==0 || A.size()==1 || K==0){
        return A;
    } else {
        rotate(A.rbegin(), A.rbegin() + K, A.rend());
        return A;
    }
}

int main(){
    vector<int> A = {3,8,9,7,6};
    int K = 3;
    auto result = solution(A, K);
    for (auto const& item: result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}