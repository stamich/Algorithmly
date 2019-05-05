//
// Created by michal on 03.05.19.
//
#include <iostream>
#include <vector>

using namespace std;

int solution(int X, vector<int> &A){

    bool isLeaf[X+1];

    for (int i = 0; i < X; i++) {
        isLeaf[i] = false;
    }

    for(int i = 0; i < A.size(); i++) {
        if (!isLeaf[A[i] - 1]) {
            isLeaf[A[i] - 1] = true;

            if (--X == 0) {
                return i;
            }
        }
    }

    return -1;
}

int main(){
    int X = 5;
    vector<int> A = {1,3,1,4,2,3,5,4};

    cout << solution(X, A) << endl;
    return 0;
}