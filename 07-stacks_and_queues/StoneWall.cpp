//
// Created by michal on 04.05.19.
//
// Cover "Manhattan skyline" using the minimum number of rectangles.
#include <iostream>
#include <vector>
#include <stack>

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

int solution2(vector<int> &H){
    stack<int> stack;
    int count = 0;
    for(size_t i = 0; i < H.size(); i ++){
        if(stack.empty()){
            stack.push(H[i]);
            count++;
        }
        else {
            while(!stack.empty() && (stack.top() > H[i]))
                stack.pop();
            if(stack.empty() || (stack.top() != H[i])) {
                stack.push(H[i]);
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> H = {8,8,5,7,9,8,7,4,8};

    cout << "Minimum number of blocks: " << solution(H) << endl;
    cout << "Minimum number of blocks: " << solution2(H) << endl;

    return 0;
}