//
// Created by michal on 18.03.19.
//
// Find the minimal positive integer not occurring in a given sequence.
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    if(A.empty()){
        return 1;
    }

    const size_t N = A.size();
    const size_t N1 = N + 1;
    bool e[N1];
    for(size_t i = 0; i < N1; i ++){
        e[i] = false;
    }

    for(size_t i = 0; i < N; i ++){
        if((A[i] >= 1) && (A[i] <= int(N))){
            e[A[i]] = true;
        }
    }

    for(size_t i = 1; i < N1; i ++){
        if(!e[i]){
            return i;
        }
    }
    return N1;
}

int solution2(vector<int> &A){

    sort(A.begin(), A.end());

    int N = A.size();

    if (A[N - 1] <= 0){
        return 1;
    }

    if (A[0] > 1){
        return 1;
    }

    for (int i = 0; i < (N - 1); i++){
        if (A[i] <= 0) {
            if (A[i + 1] > 1){
                return 1;
            }

            continue;
        }

        if ((A[i + 1] - A[i]) > 1){
            return (A[i] + 1);
        }
    }

    return A[N-1] + 1;
}

int main(){
    vector<int> A = {4,1,3,2};

    cout << "The smallest positive integer (greater than 0) that does not occur in array is: " << solution(A) << endl;
    cout << "The smallest positive integer (greater than 0) that does not occur in array is: " << solution2(A) << endl;

    return 0;
}