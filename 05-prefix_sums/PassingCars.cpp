//
// Created by michal on 03.05.19.
//
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {

    int count = 0;
    int passing  = 0;

    for (int i : A)
    {
        if (i == 1) {
            passing += count;
            if(passing > 1000000000)
                return -1;
        }else
            count++;
    }
    return passing;
}

int main()
{
    vector<int> A = {0,1,0,1,1};
    cout << "Number of Passes: " << solution(A) << endl;
}