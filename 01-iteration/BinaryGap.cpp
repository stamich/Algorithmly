//
// Created by michal on 02.01.19.
//
// Find the longest sequence of zeros in binary representation of an integer.
#include <iostream>
#include <vector>

using namespace std;

int solution(int N){

    int longestBinaryGap = 0;
    int currentBinaryGap = -1;
    int value = N;

    // iterate by value as long as is positive
    while (value != 0) {

        // bitwise AND operator checks if the value contains binary 1
        if ((value & 1) == 1) {

            // counting the sequence of zeros in binary representation of an integer
            if (longestBinaryGap < currentBinaryGap) {
                longestBinaryGap = currentBinaryGap;
            }

            currentBinaryGap = 0;
        } else if (currentBinaryGap != -1) {
            ++currentBinaryGap;
        }

        // right-shift operator makes an integer division of the value by 2
        // (shifts all the bits in the value one place to the right)
        value = value >> 1;
    }

    return longestBinaryGap;
}

// slightly more efficient solution
int solution2(int N) {
    int zeros = -1;
    int maxGap = 0;

    while (N > 0) {
        if ((N & 1) == 1) {
            zeros = 0;
        } else if (zeros != -1) {
            zeros++;
            if (maxGap < zeros) {
                maxGap = zeros;
            }
        }

        N = N >> 1;
    }
    return maxGap;
}

int main() {

    vector<int> arr {529, 1041, 2049};

    for (int i = 0; i < arr.size() ; i++) {
        cout << "The longest sequence of zeros for value: " << arr[i] << " is: " << solution(arr[i]) << endl;
        cout << "Second solution: " << endl;
        cout << "The longest sequence of zeros for value: " << arr[i] << " is: " << solution2(arr[i]) << endl;
    }
    return 0;
}