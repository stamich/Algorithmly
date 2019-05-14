//
// Created by michal on 05.05.19.
//
// Compute number of distinct absolute values of sorted array elements.
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;

int solution(vector<int> &A) {

    set<int> s;
    for (auto i: A) {
        s.insert(abs(i));
    }

    return s.size();
}

int solution2(vector<int> &A) {
    int result = 0;
    map<int, int> m;
    for(size_t i = 0; i < A.size(); i ++) {
        int a = A[i];
        if( a < 0)
            a *= -1;
        if(m.count(a) > 0)
            continue;
        m[a] = a;
        result ++;
    }
    return result;
}

int main(){

    vector<int> A = {-5,-3,-1,0,3,6};
    cout << "Number of distinct absolute values: " << solution(A) << endl;
    cout << "Second solution: " << endl;
    cout << "Number of distinct absolute values: " << solution2(A) << endl;
    return 0;
}