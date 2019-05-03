//
// Created by michal on 03.05.19.
//
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> &A){

    int max = 0;
    int lastMax = 0;
    vector<int> * counters = new vector<int>(N);

    for (int i = 0; i < A.size(); i++) {
        if ((*counters)[A[i] - 1] < lastMax) {
            (*counters)[A[i] - 1] = lastMax;
        }

        if ((A[i] <= N) && (A[i] >= 0)) {
            if (++((*counters)[A[i] - 1]) > max) {
                max = (*counters)[A[i] - 1];
            }
        } else if (A[i] == (N + 1)) {
            lastMax = max;
        }
    }

    for (int i = 0; i < N; i++) {
        if ((*counters)[i] < lastMax) {
            (*counters)[i] = lastMax;
        }
    }

    return *counters;
}

int main(){
    int N = 5;
    vector<int> A = {3,4,4,6,1,4,4};

    auto result = solution(N, A);
    for (auto const& item: result){
        cout << item << " ";
    }
    cout << endl;
}