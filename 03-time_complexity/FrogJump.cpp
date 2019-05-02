//
// Created by michal on 02.05.19.
//
#include <cmath>
#include <iostream>

using namespace std;

int solution(int X, int Y, int D) {
    return (int)ceil((double)(Y - X) / D);
}


int main(){
    int X = 10;
    int Y = 85;
    int D = 30;
    cout << "Frog needs: " << solution(X, Y, D) << " jumps." << endl;
}