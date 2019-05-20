//
// Created by michal on 03.02.19.
//
// Count minimal number of jumps from position X to Y.
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int solution(int X, int Y, int D) {
    return (int)ceil((double)(Y - X) / D);
}

int solution2(int X, int Y, int D) {
    return (Y - X + (D - 1)) / D;
}

int main(){

    int X = 10;// first position
    int Y = 85;// last position
    int D = 30;// jump length
    vector<int> arr {10, 85, 30};

    cout << "Frog needs: " << solution(X, Y, D) << " jumps." << endl;
    cout << "Second solution: " << endl;
    cout << "Frog needs: " << solution2(arr[0], arr[1], arr[2]) << " jumps." << endl;
    return 0;
}