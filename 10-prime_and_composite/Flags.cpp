//
// Created by michal on 05.05.19.
//
// Find the maximum number of flags that can be set on mountain peaks.
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &a) {

    if(a.size() < 3) return 0;
    vector<int> peaks(a.size());
    int lastPeak = -1;
    peaks.back() = lastPeak;

    for(auto i = ++a.rbegin();i != --a.rend();i++){

        int index = a.size() - (i - a.rbegin()) - 1;
        if(*i > *(i - 1) && *i > *(i + 1))
            lastPeak = index;
        peaks[index] = lastPeak;
    }

    peaks.front() = lastPeak;
    int maxFlags = 0;

    for(int i = 1;i*i <= a.size() + i;i++){
        int nextPeak = peaks[0];
        int flags = 0;
        for(int j = 0;j < i && nextPeak != -1;j++, flags++){
            if(nextPeak + i >= a.size())
                nextPeak = -1;
            else
                nextPeak = peaks[nextPeak + i];
        }
        maxFlags = std::max(maxFlags, flags);
    }
    return maxFlags;
}

int solution2(vector<int> &A) {
    if(A.empty())
        return 0;

    vector<int> P;
    for(size_t i = 1; i < (A.size() - 1); i ++)
        if((A[i] > A[i - 1]) && (A[i] > A[i + 1]))
            P.push_back(i);

    const int peaks_count = int(P.size());
    if(peaks_count <= 1)
        return peaks_count;

    // The distance for k flags requires k(k-1) distance between first and last flag
    int max_flags_possible = peaks_count;
    const int dist = P[P.size() - 1] - P[0];
    while((max_flags_possible * (max_flags_possible - 1)) > dist)
        max_flags_possible --;

    for(int K = max_flags_possible; K >= 0; K --) {
        int flags_set = 1;
        int distance = 0;
        for(int i = 1; i < peaks_count; i ++) {
            distance += P[i] - P[i - 1];
            if(distance >= K) {
                flags_set += 1;
                distance = 0;
            }
        }
        if(flags_set >= K)
            return K;
    }
    return 0;
}

int main(void) {
    vector<int> A = {1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
    cout << "Flags: " << solution(A) << endl;
    cout << "Flags: " << solution2(A) << endl;
    return 0;
}