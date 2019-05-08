//
// Created by michal on 04.05.19.
//
// N voracious fish are moving along a river. Calculate how many fish are alive.
#include <iostream>
#include <vector>
#include <stack>

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

int solution2(vector<int> &A, vector<int> &B) {
    stack<int> st;
    int eaten = 0;
    for(size_t i = 0; i < A.size(); i ++) {
        if(B[i] == 1)
            st.push(A[i]);
        else {
            while(!st.empty()) {
                if(A[i] > st.top()) {
                    st.pop();
                    // The fish going upstream is bigger
                    // and it eats another one
                    eaten ++;
                } else
                    break;
            }
            if(!st.empty())
                // The fish going downstream is bigger
                // and it eats another one
                eaten ++;
        }
    }
    return (A.size() - eaten);
}

int main(){

    vector<int> A = {4,3,2,1,5};
    vector<int> B = {0,1,0,0,0};

    cout << solution(A, B) << " fish will stay alive." << endl;
    cout << solution2(A, B) << " fish will stay alive." << endl;

    return 0;
}