//
// Created by michal on 04.05.19.
//
// Determine whether a given string of parentheses is properly nested
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string &S)
{
    if(S.size() % 2) // 1 An odd numbers of brackets implies bad nesting.
        return 0;

    stack<char> buffer; // 2 I am going to push on a stack all the open brackets, popping them as soon as a close one is found.

    for(auto it = S.begin(); it != S.end(); ++it) // 3 Loop on all the input elements.
    {
        switch(*it) // 4 If the current character is an open bracket, in any supported flavor, push it on the stack.
        {
            case '(': case '[': case '{':
                buffer.push(*it);
                continue;
        }

        if(buffer.empty()) // 5 Otherwise, if the buffer is empty the current element is a bad one. It could be an unexpected close bracket or a dirty character. In any case I return failure.
            return 0;

        char prev = buffer.top(); // 6 Check the current element on stack top. If it is a matching bracket, pop it and check the next input value.
        if((*it == ')' && prev == '(') || (*it == ']' && prev == '[') || (*it == '}' && prev == '{'))
            buffer.pop();
        else
            return 0;
    }

    return buffer.empty() ? 1 : 0; // 7 After checking all the elements, we return success only if no open bracket is still lingering in the stack.
}

int solution2(string &S) {
    if(S.empty())
        return 1;
    stack<char> st;
    st.push(S[0]);
    for(size_t i = 1; i < S.length(); i ++) {
        const char ch = S[i];
        switch(ch) {
            case '{':
                st.push('{');
                break;
            case '}':
                if(st.empty() || (st.top() != '{'))
                    return 0;
                st.pop();
                break;
            case '(':
                st.push('(');
                break;
            case ')':
                if(st.empty() || (st.top() != '('))
                    return 0;
                st.pop();
                break;
            case '[':
                st.push('[');
                break;
            case ']':
                if(st.empty() || (st.top() != '['))
                    return 0;
                st.pop();
                break;
            default:
                return 0;
        }
    }
    return st.empty();
}

int main(){
    string S0 = "{[()()]}";
    string S1 = "([)()]";

    if (solution(S0)){
        cout << "String nested properly." << endl;
    } else {
        cout << "String is not nested." << endl;
    }

    if (solution(S1)){
        cout << "String nested properly." << endl;
    } else {
        cout << "String is not nested." << endl;
    }

    return 0;
}