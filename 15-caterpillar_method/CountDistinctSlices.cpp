//
// Created by michal on 05.05.19.
//
// Count the number of distinct slices (containing only unique numbers)
#include <set>
#include <vector>
#include <iostream>

using namespace std;

int solution(int M, vector<int> &A){

    int start = 0;
    int end = 0;
    int s = int(A.size());
    int number = 0;
    set<int> ss;

    while((start <= end) && (end < s)){
        if (ss.find(A[end]) == ss.end()){
            number++;
            ss.insert(A[end]);
            end++;
        } else {
            ss.clear();
            start++;
            end = start;
        }
    }
    number += int((ss.size() - 1) * ss.size()) / 2;
    return number;
}

int solution2(int M, vector<int> &A){
    vector<bool> slice(M + 1, false);
    long long int result = 0;
    int front = 0, back = 0;
    while (front != A.size()){
        if (back != A.size() && slice[A[back]] == false){
            slice[A[back]] = true;
            ++back;
        } else {
            result += (back - front);
            if(result > 1000000000) {
                return 1000000000;
            }
            slice[A[front]] = false;
            ++front;
        }
    }
    return result;
}

int main(){

    int M = 6;
    vector<int> A = {3,4,5,5,2};
    cout << "The number of distinct slices: " << solution(M, A) << endl;
    cout << "Second solution: " << endl;
    cout << "The number of distinct slices: " << solution2(M, A) << endl;
    return 0;
}