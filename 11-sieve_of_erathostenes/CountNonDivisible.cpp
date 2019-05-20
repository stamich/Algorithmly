//
// Created by michal on 05.05.19.
//
// Calculate the number of elements of an array that are not divisors of each element.
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> &A) {
    int len = A.size();
    assert(len > 0);
    int j;
    unordered_map<int,int> result;
    vector<int> sortedA(len,0);
    vector<int> counts(2 * (*std::max_element(A.begin(), A.end())) + 1, 0);
    for (int i : A)++counts[i];
    copy(A.begin(), A.end(), sortedA.begin());
    sort(sortedA.begin(), sortedA.end());
    vector<int>::iterator itor = sortedA.begin();
    while (sortedA.end() != itor)
    {
        j = 1;
        if (result.end() == result.find(*itor))
        {
            result[*itor] = len;
            while (j*j < *itor)
            {
                if (0 == *itor % j)
                {
                    if (true == binary_search(sortedA.begin(), itor + 1, j))
                        result[*itor] -= counts[j];
                    if (true == binary_search(sortedA.begin(), itor + 1, *itor / j))
                        result[*itor] -= counts[*itor / j];
                }
                ++j;
            }
            if (j*j == *itor && binary_search(sortedA.begin(), itor + 1, j))
                result[*itor] -= counts[j];
        }
        ++itor;
    }
    vector<int> result1(len, 0);
    for (int i = 0; i < len; ++i)
        result1[i]=result[A[i]];
    return result1;
}

vector<int> solution2(vector<int> &A) {

    int N = A.size();
    vector<int> counts (*max_element(A.begin(), A.end()) + 1,0);

    // Calculate occurences of each number in the array
    for (int i = 0; i < N; ++i)
    {
        counts[A[i]] += 1;
    }

    vector<int> answer(N,0);

    // For each element of the array
    for (int i = 0; i < N; ++i)
    {
        // Calulate how many of its divisors are in the array
        int divisors = 0;

        for (int j = 1; j * j <= A[i]; ++j)
        {
            if (A[i] % j == 0)
            {
                divisors += counts[j];
                if (A[i] / j != j)
                {
                    divisors += counts[A[i] / j];
                }
            }
        }
        // Subtract the number of divisors from the number of elements in the array
        answer[i] = N - divisors;
    }
    return answer;
}

int main(void){

    vector<int> A = {3,1,2,3,6};
    auto result = solution(A);

    cout << "Sequence of integers representing the amount of non-divisors: ";
    for (auto const& item: result){
        cout << item << " ";
    }
    cout << endl;

    cout << "Second solution: " << endl;
    
    auto result2 = solution2(A);

    cout << "Sequence of integers representing the amount of non-divisors: ";
    for (auto const& item: result2){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}