//
// Created by michal on 17.03.19.
//
// Calculate the values of counters after applying all alternating operations:
// increase counter by 1; set value of all counters to current maximum.
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int N, vector<int> &A) {

    vector<int> result(N, 0);

    int base = 0;
    int maximum = 0;
    for (int i = 0; i < int(A.size()); i++) {
        if (A[i] != N + 1) {
            result[A[i] - 1] = max(base, result[A[i] - 1]) + 1;
            maximum = max(maximum, result[A[i] - 1]);
        } else {
            base = maximum;
        }
    }

    for (int i = 0; i < N; i++) {
        if (result[i] < base) {
            result[i] = base;
        }
    }
    return result;
}

vector<int> solution2(int N, vector<int> &A) {
    vector<int> counters(N);
    for(int i = 0; i < N; i ++){
        counters[i] = 0;
    }
    if(A.empty()){
        return counters;
    }

    int currentMax = 0;
    int applyMax = 0;
    const int N1 = N + 1;
    for(size_t i = 0; i < A. size(); i++){
        if(A[i] != N1){
            const int idx = A[i] - 1;
            counters[idx] = max(counters[idx], applyMax);
            counters[idx] ++;

            if(counters[idx] > currentMax){
                currentMax = counters[idx];
            }
        } else
            applyMax = currentMax;
    }

    for(size_t i = 0; i < counters.size(); i ++){
        counters[i] = max(counters[i], applyMax);
    }
    return counters;
}

vector<int> solution3(int N, vector<int> &A){

    int max = 0;
    int lastMax = 0;
    vector<int> * counters = new vector<int>(N);

    for (int i = 0; i < A.size(); i++){
        if ((*counters)[A[i] - 1] < lastMax){
            (*counters)[A[i] - 1] = lastMax;
        }

        if ((A[i] <= N) && (A[i] >= 0)){
            if (++((*counters)[A[i] - 1]) > max){
                max = (*counters)[A[i] - 1];
            }
        } else if (A[i] == (N + 1)){
            lastMax = max;
        }
    }

    for (int i = 0; i < N; i++){
        if ((*counters)[i] < lastMax){
            (*counters)[i] = lastMax;
        }
    }
    return *counters;
}

int main(){

    int N = 5;
    vector<int> A = {3,4,4,6,1,4,4};

    auto result = solution(N, A);
    cout << "Sequence of integers representing the values of the counters: ";
    for (auto const& item: result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}