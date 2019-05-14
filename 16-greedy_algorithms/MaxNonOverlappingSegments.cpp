//
// Created by michal on 05.05.19.
//
// Find a maximal set of non-overlapping segments
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &B){
    int count = 1;
    int length = A.size();
    if (0 == length){
        return 0;
    }
    vector<int> lastCmp = vector<int>(length, -1);
    for (int i = 1; i < length; i++){
        if (A[i] > B[i - 1] || (-1 != lastCmp[i - 1] && A[i] > lastCmp[i - 1])){
            ++count;
        }else{
            lastCmp[i] = -1 != lastCmp[i - 1] ? lastCmp[i - 1] : B[i - 1];
        }
    }
    return count;
}

//--------------------------------------------

bool isOverlapped(int a1, int b1, int a2, int b2){
    return ((a1 <= a2) && (a2 <= b1)) || ((a2 <= a1) && (a1 <= b2));
}

int solution2(vector<int> &A, vector<int> &B) {

    int s = int(A.size());
    if (s == 0) return 0;
    else if (s == 1) return 1;

    int start = A[s- 1];
    int end = B[s - 1];
    int number = 1;
    for (int i = (B.size() - 2); i >= 0; i--) {
        if (!isOverlapped(start, end, A[i], B[i])) {
            number ++;
            start = A[i];
            end = B[i];
        } else {
            start = max(A[i], start);
        }
    }
    return number;
}

int main(void){

    vector<int> A = {1,3,7,9,9};
    vector<int> B = {5,6,8,9,10};
    cout << "Maximal set of non-overlapping segments: " << solution(A, B) << endl;
    cout << "Second solution: " << endl;
    cout << "Maximal set of non-overlapping segments: " << solution(A, B) << endl;
    return 0;
}