//
// Created by michal on 04.04.19.
//
// Find the minimal average of any slice containing at least two elements.
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {
    vector<int> preSum(A.size());
    int preS = 0;

    for (size_t i = 0; i < A.size(); i++) {
        preS += A[i];
        preSum[i] = preS;
    }

    int start = 0;
    int end = 1;
    int minStart = start;
    double minAvg = double(preSum[end] - preSum[start] + A[start]) / (end - start + 1);

    for (size_t i = 1; i < A.size(); i++) {
        double avg = double(preSum[i] - preSum[start] + A[start]) / (i - start + 1);

        if (avg < minAvg) {
            minAvg = avg;
            minStart = start;
        }

        if (A[i] < minAvg) {
            start = i;
        }

    }
    return minStart;
}

int solution2(vector<int> &A) {
    if(A.empty())
        return 0;
    double minAvg = INT_MAX;
    int minIdx = -1;
    for(int size = 2; size < int(A.size()); size ++) {
        for(size_t i = 0; i < (A.size() - size + 1); i ++) {
            int sum = 0;
            const int P = i;
            const int Q = P + size - 1;
            for(int j = P; j <= Q; j ++)
                sum += A[j];
            double avg = 1.0 * sum / (Q - P + 1);
            if(avg < minAvg) {
                minAvg = avg;
                minIdx = i;
            }
        }
    }
    return minIdx;
}

int main(){
    vector<int> A = {4,2,2,5,1,5,8};
    cout << "Number of Passes: " << solution(A) << endl;
    cout << "Number of Passes: " << solution2(A) << endl;
    return 0;
}