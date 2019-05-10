//
// Created by michal on 04.05.19.
//
// Divide array A into K blocks and minimize the largest sum of any block.
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool validBlockSum(const vector<int> &A, int maxBlockCount, int maxBlockSize) {
    int blockSum = 0;
    int blockCount = 0;
    for(size_t i = 0; i < A.size(); i ++){
        if((blockSum + A[i]) > maxBlockSize){
            blockSum = A[i];
            blockCount ++;
        } else
            blockSum += A[i];
        if(blockCount >= maxBlockCount){
            return false;
        }
    }
    return true;
}

int solution(int K, int M, vector<int> &A) {
    int maxItem = INT_MIN; // Max item of the array
    for(size_t i = 0; i < A.size(); i ++){
        if(A[i] > maxItem){
            maxItem = A[i];
        }
    }

    int itemSum = 0; // Sum of all array items
    for(size_t i = 0; i < A.size(); i ++){
        itemSum += A[i];
    }

    int lowerBound = maxItem;
    int upperBound = itemSum;
    const int maxBlockCount = K;

    // Checking border conditions
    if(maxBlockCount == 1){
        return upperBound;
    }
    if(maxBlockCount >= int(A.size())){
        return lowerBound;
    }

    // Binary searching for the minimal block sum
    while(lowerBound <= upperBound) {
        int candidateMid = (lowerBound + upperBound) / 2;
//        cout << "low:" << lowerBound << "\t";
//        cout << "up:" << upperBound << "\t";
//        cout << "avg:" << candidateMid << "\n";
        if(validBlockSum(A, maxBlockCount, candidateMid))
            upperBound = candidateMid - 1;
        else
            lowerBound = candidateMid + 1;
    }
    return lowerBound;
}

int main(void){

    int K = 3;
    int M = 5;
    vector<int> A = {2,1,5,1,2,2,2};
    cout << "Minimized sum of largest block: " << solution(K, M, A) << endl;
    return 0;
}