//
// Created by michal on 05.05.19.
//
// Find a maximum sum of a compact subsequence of array elements.
#include <iostream>
#include <vector>
#include <cassert>
#include <climits>

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

int solution2(vector<int> &A) {
    int max_ending = 0;
    int max_slice = 0;
    for(size_t i = 0; i < A.size(); i ++) {
        max_ending = max(0, max_ending + A[i]);
        max_slice = max(max_slice, max_ending);
    }

    if(max_slice != 0){
        return max_slice;
    }
    max_slice = INT_MIN;
    for(size_t i = 0; i < A.size(); i ++)
        if(A[i] > max_slice){
            max_slice = A[i];
        }
    return max_slice;
}

int main(){

    vector<int> A = {3,2,-6,4,0};
    cout << "Maximum sum of elements: " << solution(A) << endl;
    cout << "Maximum sum of elements: " << solution2(A) << endl;
    return 0;
}