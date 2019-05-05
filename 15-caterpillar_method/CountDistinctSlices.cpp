//
// Created by michal on 05.05.19.
//
#include <set>
#include <vector>
#include <iostream>

using namespace std;

int solution(int M, vector<int> &A) {

    int start = 0;
    int end = 0;
    int s = int(A.size());
    int num = 0;
    set<int> ss;

    while((start <= end) && (end < s)) {
        if (ss.find(A[end]) == ss.end()) {
            num++;
            ss.insert(A[end]);
            end++;
        } else {
            ss.clear();
            start++;
            end = start;
        }
    }

    num += int((ss.size() - 1) * ss.size()) / 2;
    return num;
}

int main(){

    int M = 0;
    vector<int> A = {};
    cout << solution(M, A) << endl;
    return 0;
}