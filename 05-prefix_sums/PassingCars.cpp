//
// Created by michal on 01.04.19.
//
// Count the number of passing cars on the road.
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {

    int count = 0;
    int passing  = 0;

    for (int i : A)
    {
        if (i == 1) {
            passing += count;
            if(passing > 1000000000)
                return -1;
        }else
            count++;
    }
    return passing;
}

int solution2(vector<int> &A) {

    vector<int> preSum(A.size(), 0);

    int s = 0;
    for (size_t i = 0; i < A.size(); i++) {
        s += A[i];
        preSum[i] = s;
    }

    int result = 0;

    for (int i = int(A.size() - 1); i >= 0; i--) {
        if (A[i] == 0) {
            result += (preSum[A.size() - 1] - preSum[i]);
            if (result > 1000000000) return -1;
        }
    }

    return result;
}

int solution3(vector<int> &A) {
    if(A.empty())
        return 0;
    int cnt = 0;
    for(int i = int(A.size() - 1); i >= 0; i --) {
        if(A[i] == 1)
            A[i] = ++cnt;
        else
            A[i] = (-1) * cnt;
    }

    int pairs = 0;
    for(size_t i = 0; i < A.size(); i ++) {
        if(A[i] < 0) {
            pairs += (-1) * A[i];
            if(pairs > 1000000000)
                return (-1);
        }
    }
    return pairs;
}

int main(){
    vector<int> A = {0,1,0,1,1};
    cout << "Number of Passes (solution 1): " << solution(A) << endl;
    cout << "Second solution: " << endl;
    cout << "Number of Passes (solution 2): " << solution2(A) << endl;
    cout << "Third solution: " << endl;
    cout << "Number of Passes (solution 3): " << solution3(A) << endl;
    return 0;
}