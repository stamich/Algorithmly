//
// Created by michal on 04.05.19.
//
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

inline int invert(int c){
    switch (c) {
        case '[': return ']';
        case '{': return '}';
        default: return ')';
    }
}

int solution(string &S) {
    int N = S.size();
    char c;
    stack<char> mm;
    if (N<4){
        return 0;
    }

    if (N % 2 != 0){
        return 0;
    }

    for (int i = 0; i< N; ++i){
        if (S[i] == '{' || S[i] == '[' || S[i] == '('){
            mm.push(S[i]);
        }

        if (mm.empty() == 0){
            return 1;
        }

        c = mm.top();
        if (S[i] == '}' || S[i] == ']' || S[i] == ')'){
            if (S[i] == invert(c)){
                mm.pop();
            }else{
                return 0;
            }
        }
    }
    return 1;
}

int main(){

    string s = "AAA";
    solution(s);
}