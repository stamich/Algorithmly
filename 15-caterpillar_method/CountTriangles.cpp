//
// Created by michal on 05.05.19.
//
// Count the number of triangles that can be built from a given set of edges.
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {

    int s = int(A.size());
    if (s < 3) return 0;

    sort(A.begin(), A.end());

    if (A[0] + A[1] > A[s - 1]) {
        return s * (s - 1) * (s - 2) / 6;
    }

    int number = 0;
    for (int i = 0; i < s - 2; i++) {
        for (int j = i + 1; j < s - 1; j++) {
            for (int k = j + 1; k < s; k++) {
                if (A[i] + A[j] > A[k]) {
                    number++;
                } else {
                    break;
                }
            }
        }
    }
    return number;
}

int solution2(vector<int> &A) {
    int length = A.size();
    std::sort(A.begin(), A.end());
    int s, ss, l, h, m;
    long long count = 0LL;
    for (int i = 0; i < length - 2; ++i)
    {
        ss = i + 2;
        for (int j = i + 1; j < length - 1; ++j)
        {
            l = ss;
            h = length - 1;
            s = -1;
            while (l <= h)
            {
                m = l + (h - l) / 2;
                if (A[m] >= A[i] + A[j])
                    h = m - 1;
                else
                {
                    s = m;
                    l = m + 1;
                }
            }
            if (-1 != s)
            {
                ss = s;
                count += s - j;
            }
        }
    }
    return count;
}

int main(){

    vector<int> A = {10,2,5,1,8,12};
    cout << "The number of triangles that can be built from a given set of edges: " << solution(A) << endl;
    cout << "Second solution: " << endl;
    cout << "The number of triangles that can be built from a given set of edges: " << solution2(A) << endl;
    return 0;
}