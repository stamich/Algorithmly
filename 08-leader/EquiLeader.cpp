//
// Created by michal on 05.05.19.
//
// Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S]
// and A[S + 1], A[S + 2], ..., A[N - 1] are the same.
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {

    if (A.size() < 2) return 0;

    unordered_map<int, int> um;
    int dominantNum = 0;
    int dominant = A[0];
    for (auto i: A){
        if (um.find(i) != um.end()){
            um[i]++;
            if (dominantNum < um[i]){
                dominant = i;
                dominantNum = um[i];
            }
            if (dominantNum >= int(A.size()) / 2 + 1) break;
        } else {
            um[i] = 1;
        }
    }
    if (dominantNum < int(A.size()) / 2 + 1) {
        return 0;
    }

    vector<int> preSum;
    int s = 0;
    for (auto i: A){
        if (i == dominant){
            s++;
        }
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

int solution2(vector<int> &A) {
    if(A.empty())
        return 0;
    if(A.size() == 1)
        return 0;

    const int N = int(A.size());
    int stack = 0;
    int size = 0;
    for(int i = 0; i < N; i ++) {
        if(size == 0) {
            stack = A[i];
            size = 1;
        } else {
            if(stack == A[i]) {
                size ++;
            } else {
                size --;
            }
        }
    }

    if(size == 0)
        return 0;

    int cnt = 0;
    for(int i = 0; i < N; i ++)
        if(A[i] == stack)
            cnt ++;

    if(cnt < int(N / 2))
        return 0;

    int el_cnt = 0;
    int cnt_left = 0;
    int cnt_right = cnt;
    for(int i = 0; i < (N - 1); i ++ ) {
        if(stack == A[i]) {
            cnt_left ++;
            cnt_right --;
        }
        int left_limit = (i + 1) / 2;
        int right_limit = (N - i - 1) / 2;
        if((cnt_left > left_limit) && (cnt_right > right_limit)) {
            //cout << "EL: " << i << endl;
            el_cnt ++;
        }

    }

    return el_cnt;
}

int main(){
    vector<int> A = {4,3,4,4,4,2};

    cout << "The equi leader of given array is: " << solution(A) << endl;
    cout << "The equi leader of given array is: " << solution2(A) << endl;
    return 0;
}