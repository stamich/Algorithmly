//
// Created by michal on 05.05.19.
//
// Count the semiprime numbers in the given range [a..b]
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> &P, vector<int> &Q){
    assert(N > 0 && N < 50001);
    int lenp = P.size();
    int lenq = Q.size();
    assert(lenp == lenq && lenp > 0 && lenp < 30001);
    vector<int> primesDivisors(N + 1, 0);
    vector<int> counts(N + 1, 0), result(lenp, 0);
    int i = 2, k;
    while (i * i <= N){
        if (0 == primesDivisors[i]){
            k = i*i;
            while (k <= N){
                primesDivisors[k] = i;
                k += i;
            }
        }
        ++i;
    }
    for (i = 2, k = 0; i <= N; ++i){
        if (0 != primesDivisors[i] && 0 == primesDivisors[i / primesDivisors[i]])
            ++k;
        counts[i] = k;
    }
    for (i = 0; i < lenp; ++i){
        result[i] = counts[Q[i]] - counts[P[i] - 1];
    }
    return result;
}

int main(void){

    int N = 26;
    vector<int> P = {1,4,16};
    vector<int> Q = {26,10,20};
    auto result = solution(N, P, Q);

    cout << "Number of semiprimes: ";
    for (auto const& item: result){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}