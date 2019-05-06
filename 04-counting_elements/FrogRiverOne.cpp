//
// Created by michal on 17.03.19.
//
//
// Created by michal on 03.05.19.
//
// Find the earliest time when a frog can jump to the other side of a river.
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// The best solution
int solution(int X, vector<int> &A){

    set<int> s;
    for (size_t i = 0; i < A.size(); i++){
        s.insert(A[i]);
        if (s.size() == X){
            return i;
        }
    }
    return -1;
}

int solution2(int X, vector<int> &A){

    bool isLeaf[X+1];

    for (int i = 0; i < X; i++){
        isLeaf[i] = false;
    }

    for(int i = 0; i < A.size(); i++){
        if (!isLeaf[A[i] - 1]) {
            isLeaf[A[i] - 1] = true;

            if (--X == 0) {
                return i;
            }
        }
    }
    return -1;
}

int solution3(int X, vector<int> &A){
    if(A.empty())
        return (-1);

    long long sumExp = (long long)X + 1;
    sumExp *= X;
    sumExp /= 2;

    const size_t X_const = X + 1;
    size_t l[X_const];
    for(size_t i = 0; i < X_const; i ++) l[i] = 0;

    long long sum = 0;
    for(size_t i = 0; i < A.size(); i ++){
        const int pos = A[i];
        if(pos > X) continue;
        if(!l[pos]) {
            l[pos] = 1;
            sum += pos;
            if(sum == sumExp)
                return i;
        }
    }
    return (-1);
}

int main(){
    int X = 5;
    vector<int> A = {1,3,1,4,2,3,5,4};

    cout << "The earliest time when the frog can jump is: " << solution(X, A) << endl;
    cout << "The earliest time when the frog can jump is: " << solution2(X, A) << endl;
    cout << "The earliest time when the frog can jump is: " << solution3(X, A) << endl;

    return 0;
}