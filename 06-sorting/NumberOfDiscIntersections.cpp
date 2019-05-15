//
// Created by michal on 04.05.19.
//
// Compute the number of intersections in a sequence of discs.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    // main idea:
    // 1. store all the "lower points" and "upper points" of the discs
    // 2. count the intersections (if one upper point > one lower point)

    int sum=0;
    vector<int> start(A.size(),0);
    vector<int> end(A.size(),0);

    for (unsigned int i = 0;i < A.size(); i++){
        if ((int)i < A[i]){
            start[0]++;
        }else{
            start[i - A[i]]++;
        }
        if (i + A[i] >= A.size()){
            end[A.size() - 1]++;
        }else{
            end[i + A[i]]++;
        }
    }

    int active=0;
    for (unsigned int i = 0; i < A.size(); i++){
        sum += active * start[i] + (start[i] * (start[i] - 1)) / 2;

        if (sum>10000000){
            return -1;
        }
        active += start[i] - end[i];
    }
    return sum;
}

int solution2( const vector<int> &A ) {

    int sum=0;
    vector<int> start(A.size(),0);
    vector<int> end(A.size(),0);

    for (unsigned int i = 0;i < A.size(); i++){
        if ((int)i < A[i]){
            start[0]++;
        } else {
            start[i - A[i]]++;
        }
        if (i + A[i] >= A.size()){
            end[A.size() - 1]++;
        } else {
            end[i+A[i]]++;
        }
    }
    int active = 0;
    for (unsigned int i = 0;i < A.size(); i++){
        sum += active * start[i] + (start[i] * (start[i] - 1)) / 2;
        if (sum>10000000){
            return -1;
        }
        active += start[i] - end[i];
    }
    return sum;
}

int main(){
    vector<int> A = {10,2,5,1,8,20};

    if (solution(A) >= 0){
        cout << " the number of (unordered) pairs of intersecting discs: " << solution(A) << endl;
    } else {
        cout << "The number of intersecting pairs exceeds 10,000,000." << endl;
    }
    cout << "Second solution: " << endl;

    if (solution2(A) >= 0){
        cout << " the number of (unordered) pairs of intersecting discs: " << solution(A) << endl;
    } else {
        cout << "The number of intersecting pairs exceeds 10,000,000." << endl;
    }
    return 0;
}