//
// Created by michal on 04.05.19.
//
// Determine whether given string of parentheses is properly nested.
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int solution(string &S){
    if(S.empty()){
        return 1;
    }
    if(S.length() % 2){
        return 0;
    }

    int count = 0;

    for(size_t i = 0; i <  S.length(); i ++){
        if(S[i] == '('){
            count++;
        } else if(S[i] == ')'){
            count--;
        }
        if(count < 0){
            return 0;
        }
    }
    return ((count == 0) ? 1 : 0);
}

//---------------------

inline int invert(int c){
    switch (c) {
        case '[': return ']';
        case '{': return '}';
        default: return ')';
    }
}

int solution2(string &S) {
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
            return 0;
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

    string s1 = "(()(())())";
    string s2 = "())";

    if (solution(s1)){
        cout << "String: " << s1 << " is properly nested." << endl;
    } else {
        cout << "String: " << s1 << " is not properly nested." << endl;
    }
    cout << "Second solution: " << endl;
    if (solution2(s1)){
        cout << "String: " << s1 << " is properly nested." << endl;
    } else {
        cout << "String: " << s1 << " is not properly nested." << endl;
    }

    return 0;
}