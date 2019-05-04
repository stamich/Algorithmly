//
// Created by michal on 04.05.19.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A){

    sort(A.begin(), A.end());

    for(int i=2; i< A.size(); i++){
        if((long)A[i-2] + (long)A[i-1] > (long)A[i]) // note: using "long" for overflow cases
            return 1;
    }

    return 0;
}

int main(){
    vector<int> A = {10,2,5,1,8,20};

    if (solution(A)){
        cout << "Triplet for array: " << " exists." << endl;

//        auto result = solution(A);
//        for (auto const& item: result){
//            cout << item << " ";
//        }
//
//        cout << endl;
    }
    cout << "Triplet for array: " << " not exists." << endl;
}