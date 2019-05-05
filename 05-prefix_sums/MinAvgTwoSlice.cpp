//
// Created by michal on 03.05.19.
//
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {
    vector<int> pre_sum(A.size());
    int pre_s = 0;

    for (size_t i = 0; i < A.size(); i++) {
        pre_s += A[i];
        pre_sum[i] = pre_s;
    }

    int start = 0;
    int end = 1;
    int min_start = start;
    double min_avg = double(pre_sum[end] - pre_sum[start] + A[start]) / (end - start + 1);

    for (size_t i = 1; i < A.size(); i++) {
        double avg = double(pre_sum[i] - pre_sum[start] + A[start]) / (i - start + 1);

        if (avg < min_avg) {
            min_avg = avg;
            min_start = start;
        }

        if (A[i] < min_avg) {
            start = i;
        }

    }

    return min_start;
}

int main(){
    vector<int> A = {4,2,2,5,1,5,8};
    cout << "Number of Passes: " << solution(A) << endl;
    return 0;
}