//
// Created by michal on 04.05.19.
//
#include <iostream>
#include <string>
#include <stack>

using namespace std;

//int solution(string &S) {
//    // write your code in C++14 (g++ 6.2.0)
//}

int solution(string& input)
{
    if(input.size() % 2) // 1 An odd numbers of brackets implies bad nesting.
        return 0;

    stack<char> buffer; // 2 I am going to push on a stack all the open brackets, popping them as soon as a close one is found.

    for(auto it = input.begin(); it != input.end(); ++it) // 3 Loop on all the input elements.
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

int main(){
    string S0 = "{[()()]}";
    string S1 = "([)()]";

    if (solution(S0)){
        cout << "String nested properly." << endl;
    } else {
        cout << "String is not nested." << endl;
    }
}