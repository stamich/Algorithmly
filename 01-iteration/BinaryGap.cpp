//
// Created by michal on 02.05.19.
//
#include <iostream>
#include <string>

using namespace std;

//string getNextDigit(string value){
//    return value.substr(0, 1);
//}

int solution(int n){

    int longestBinaryGap = 0;
    int currentBinaryGap = -1;

    int value = n;

    while (value != 0) {
        if ((value & 1) == 1) {

            if (longestBinaryGap < currentBinaryGap) {
                longestBinaryGap = currentBinaryGap;
            }

            currentBinaryGap = 0;
        } else if (currentBinaryGap != -1) {
            ++currentBinaryGap;
        }

        value = value >> 1;
    }

    return longestBinaryGap;
}

int main(){
    cout << solution(1041) << endl;

    return 0;
}