//
// Created by michal on 03.02.19.
//
// Find value that occurs in odd number of elements.
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> &A) {

    int element = 0;

    // very smart idea is to use the bitwise XOR with assignment (set element to element ^ A[i])
    for (int i = 0; i < A.size() ; ++i) {
        element ^=A[i];
    }
    return element;
}

int solution2(vector<int> &A) {

    set<int> s;

    for (auto i: A) {
        if (s.find(i) == s.end()) {
            s.insert(i);
        } else {
            s.erase(i);
        }
    }

    return *s.begin();
}

int main(){
    vector<int> A = {9,3,9,3,9,7,9};
    cout << "Unpaired element of array: " << "is: " << solution(A) << endl;
    cout << "Unpaired element of array: " << "is: " << solution2(A) << endl;
    return 0;
}