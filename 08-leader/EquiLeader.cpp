//
// Created by michal on 05.05.19.
//
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {

    if (A.size() < 2) return 0;

    unordered_map<int, int> um;
    int dominant_num = 0;
    int dominant = A[0];
    for (auto i: A) {
        if (um.find(i) != um.end()) {
            um[i]++;
            if (dominant_num < um[i]) {
                dominant = i;
                dominant_num = um[i];
            }

            if (dominant_num >= int(A.size()) / 2 + 1) break;
        } else {
            um[i] = 1;
        }
    }

    if (dominant_num < int(A.size()) / 2 + 1) return 0;

    vector<int> preSum;
    int s = 0;

    for (auto i: A) {
        if (i == dominant) s++;
        preSum.push_back(s);
    }

    int result = 0;
    int size = int(A.size());
    for (int i = 0; i < size; i++) {
        if ((preSum[i] > (i + 1) / 2) && (preSum[size - 1] - preSum[i] > (size - i - 1) / 2)) {
            result++;
        }
    }

    return result;
}