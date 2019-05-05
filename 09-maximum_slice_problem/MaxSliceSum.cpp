//
// Created by michal on 05.05.19.
//
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const size_t MAX_ARRAY_SIZE = 1000000;
const size_t MIN_ARRAY_SIZE = 1;
const int MIN_VALUE = -1000000;
const int MAX_VALUE = 1000000;
const int MAX_RESULT = 2147483647;
const int MIN_RESULT = -2147483647;

int solution(vector<int> &A) {

    assert(A.size() <= MAX_ARRAY_SIZE);
    assert(A.size() >= MIN_ARRAY_SIZE);

    if (A.size() == 1) return A[0];

    long long sum = 0;
    long long result = A[0];

    for (size_t i = 0; i < A.size(); i ++) {
        assert((A[i] >= MIN_VALUE) && (A[i] <= MAX_VALUE));

        if (sum + A[i] > 0) {
            sum = max<long long>(A[i], sum + A[i]);
            result = max<long long>(sum, result);
        } else {
            sum = 0;
            result = max<long long>(A[i], result);
        }
    }

    assert((result >= MIN_RESULT) && (result <= MAX_RESULT));

    return int(result);
}