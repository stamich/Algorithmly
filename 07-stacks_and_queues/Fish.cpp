//
// Created by michal on 04.05.19.
//
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    int survivors = (int)A.size();// survivors: initially equal to total number of fishes

    vector<int> usfish={};// upstream fishs stack

    for(unsigned int i=0; i<A.size(); i++){

        if( B[i]==1)// if upstream : goes to stack
        {
            usfish.push_back(i);
        }

        else // if downstream : fights with upstream fishes
        {
            int j = (int)usfish.size()-1;
            while(usfish.size()>0 && j>-1)
            {

                if( A[usfish[j]] > A[i]) // upstream is bigger: ds fish dies, check next ds fish
                {
                    survivors--;
                    break;
                }

                else // upstream is smaller: us fish dies, next us fish fights
                {
                    survivors--;
                    usfish.erase(usfish.begin() + j);
                    j--;
                }
            }
        }
    }

    return survivors;
}

int main(){

    vector<int> A = {};
    vector<int> B = {};

    cout << solution(A, B) << endl;
    return 0;
}