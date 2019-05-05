//
// Created by michal on 05.05.19.
//
#include <set>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {

    set<int> s;
    for (auto i: A) {
        s.insert(abs(i));
    }

    return s.size();
}

int main(){

    vector<int> A = {};
    cout << solution(A) << endl;
    return 0;
}