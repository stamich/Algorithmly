//
// Created by michal on 05.05.19.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

int solution(vector<int> &A){
    if(A.size() < 3)
        return 0;

    const int N = int(A.size());

    /* Calculate the most possible summ, moving left-to-right */
    vector<int> fromLeft(N);
    for(int i = 2; i < N; i++)
        fromLeft[i] = max(0, fromLeft[i - 1] + A[i - 1]);

    /* Calculate the most possible summ, moving right-to-left */
    vector<int> fromRight(N);
    for(int i = (N - 3); i >= 0; i--)
        fromRight[i] = max(0, fromRight[i + 1] + A[i + 1]);

    /* Calculate the most possible summ of the array */
    int max_slice = 0;
    for(int i = 1; i < (N - 1); i++)
        max_slice = max(max_slice, fromLeft[i] + fromRight[i]);

    return max_slice;
}

int solution2(vector<int> &A) {
    int n = A.size();
    int end = 2;
    int ret = 0;
    int sum = 0;
    int min = A[1];

    while (end < n-1)
    {
        if (A[end] < min)
        {
            sum = max(0, sum + min);
            ret = max(ret, sum);
            min = A[end];
            ++end;
            continue;
        }
        sum = max(0, sum + A[end]);
        ret = max(ret, sum);
        ++end;
    }
    return ret;
}

// Practical use of Kadane's algorithm.
//int solution3(vector<int> &A){
//
//    int N = A.size();
//    vector<int> K1 = {N};
//    vector<int> K2 = {N};
//
//    for (int i = 1; i < N - 1; i++){
//        K1[i] = max(K1[i - 1] + A[i], 0);
//        cout << K1[i] << " ";
//    }
//    for (int i = N - 2; i > 0; i--){
//        K2[i] = max(K2[i + 1] + A[i], 0);
//        cout << K2[i] << " ";
//    }
//    int maximum = 0;
//
//    for (int i = 1; i < N - 1; i++){
//        maximum = max(maximum, K1[i - 1] + K2[i + 1]);
//    }
//    return maximum;
//}

int main(void) {
    vector<int> A = {3,2,6,-1,4,5,-1,2};
    cout <<  "Maximal sum of double slice is: " << solution(A) << endl;
    cout <<  "Maximal sum of double slice is: " << solution2(A) << endl;

    return 0;
}