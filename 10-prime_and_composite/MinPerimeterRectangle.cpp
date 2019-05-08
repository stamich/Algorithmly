//
// Created by michal on 05.05.19.
//
#include <iostream>
#include <cmath>

using namespace std;

int solution(int N) {

    int i = 1;
    int A = 1;
    while (i * i < N) {
        if (N % i == 0) {
            A = i;
        }
        i++;
    }
    if (i * i == N) {
        A = i;
    }
    return (A + (N / A)) * 2;
}

int solution2(int N){
    // main idea:
    // try to find the one "closest to sqrt(N)"

    int sqrtN = (int) sqrt(N);
    int perimeter = (1 * 2) + (N * 2); // perimeter = (A*2)+(B*2)

    for(int i = sqrtN; i > 0; i--){ // from the one closest to sqrt(N)
        if( N % i ==0){             // key point: "N % i ==0"
            int A = i;
            int B = N/i;
            perimeter = (A * 2) + (B * 2);
            break;                  // be careful: break from the for-loop
        }
    }

    return perimeter;
}

int main(void){

    int N = 30;
    cout << "The minimal perimeter is: " << solution(N) << endl;
    cout << "The minimal perimeter is: " << solution2(N) << endl;
    return 0;
}