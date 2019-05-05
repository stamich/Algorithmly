//
// Created by michal on 05.05.19.
//
#include <iostream>
#include <vector>

using namespace std;

bool is_overlapped(int a1, int b1, int a2, int b2)
{
    return ((a1 <= a2) && (a2 <= b1)) ||
           ((a2 <= a1) && (a1 <= b2));
}

int solution(vector<int> &A, vector<int> &B) {

    int s = int(A.size());
    if (s == 0) return 0;
    else if (s == 1) return 1;

    int start = A[s- 1];
    int end = B[s - 1];
    int number = 1;
    for (int i = (B.size() - 2); i >= 0; i--) {
        if (!is_overlapped(start, end, A[i], B[i])) {
            number ++;
            start = A[i];
            end = B[i];
        } else {
            start = max(A[i], start);
        }
    }
    return number;
}