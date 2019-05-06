//
// Created by michal on 03.02.19.
//
//
// Find the missing element in a given permutation.
#include <iostream>
#include <vector>

using namespace std;

// the best solution
int solution(vector<int> &A) {

    long N = A.size() + 1;
    long sum = N * (N + 1) / 2;

    for (int i = 0; i < A.size(); i++){
        sum -= A[i];
    }
    return (int) sum;
}

int solution2(vector<int> &A) {

    int result = 0;

    for (int i = 0; i < int(A.size()); i++) {
        result += (i + 1 - A[i]);
    }

    result += int(A.size() + 1);

    return result;
}

int solution3(vector<int> &A) {

    if(A.empty()){
        return 1;
    }

    const size_t N = A.size();
    long long sum = 0;

    for(size_t i = 0; i < N; i ++){
        sum += A[i];
    }

    long long sumExp = ((long long)(2 + N) * (N + 1)) / 2;
    return int(sumExp - sum);
}

int main(){
    vector<int> A = {2,3,1,5};
    cout << "The missing element is: " << solution(A) << endl;
    cout << "The missing element is: " << solution2(A) << endl;
    cout << "The missing element is: " << solution3(A) << endl;
    return 0;
}