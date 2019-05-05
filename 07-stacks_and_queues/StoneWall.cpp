//
// Created by michal on 04.05.19.
//
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &H) {

    int N = H.size();
    vector<int> stack(N,0);
    int ss = 0;
    int result = 0;

    for(int i=0;i<N;i++)
    {
        while(ss>0 && stack[ss]>H[i])ss--;

        if(H[i]!=stack[ss])
        {
            result++;
            stack[++ss] = H[i];
        }
    }
    return result;
}

int main(){
    vector<int> H = {8,8,5,7,9,8,7,4,8};

    cout << "Minimum number of blocks: " << solution(H) << endl;
    return 0;
}