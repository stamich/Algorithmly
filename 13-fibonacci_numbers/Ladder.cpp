//
// Created by michal on 05.05.19.
//
// Count the number of different ways of climbing to the top of a ladder.
#include <iostream>
#include <cassert>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B){

    const int L = 30000;
    const int M = 30;
    unsigned int divisor = 1ULL << 30;

    int lengthA = A.size();
    int lengthB = B.size();
    assert(lengthA > 0 && lengthA == lengthB);

    vector<int> memory(L + 1);
    vector<int> result(lengthA);

    memory[0] = 1;
    memory[1] = 1;

    for (int i = 2; i <= L; ++i){
        assert(memory[i - 2] <= numeric_limits<int>::max() - memory[i - 1]);
        memory[i] = (memory[i - 2] + memory[i - 1]) % divisor;
    }

    for (int i = 0; i < lengthA; ++i){
        assert(B[i] > 0 && B[i] <= M);
        assert(A[i] > 0 && A[i] <= L);
        result[i] = memory[A[i]] % (1 << B[i]);
    }
    return result;
}

int main(void){

    vector<int> A = {4,4,5,5,1};
    vector<int> B = {3,2,4,3,1};
    auto result = solution(A,B);

    cout << "An array consisting of L integers: ";
    for (auto const& item: result){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}