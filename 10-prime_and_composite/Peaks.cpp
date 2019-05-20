//
// Created by michal on 25.04.19.
//
// Divide an array into the maximum number of same-sized blocks,
// each of which should contain an index P such that A[P - 1] < A[P] > A[P + 1].
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int solution(vector<int> &A){

    int s = int(A.size());
    if (s < 3) {
        return 0;
    }
    int i = 1;
    vector<int> factors;

    while (i * i < s){
        if (s % i == 0){
            factors.push_back(i);
            factors.push_back(s / i);
        }
        i++;
    }

    if (i * i == s){
        factors.push_back(i);
    }

    sort(factors.begin(), factors.end());
    vector<int> peaks(s, 0);
    int peak_num = 0;

    for (int j = 1; j < s - 1; j++){
        if ((A[j] > A[j - 1]) && (A[j] > A[j + 1])){
            peaks[j] = 1;
            peak_num++;
        }
    }

    if (peak_num == 0){
        return 0;
    }
    if (peak_num == 1){
        return 1;
    }
    vector<int> pre_sum_peaks;
    int ss = 0;

    for (auto j: peaks){
        ss += j;
        pre_sum_peaks.push_back(ss);
    }

    for (int j = 1; j < int(factors.size()); j++){
        bool no_peak = false;
        for (int k = 0; k < s; k += factors[j]){

            int start_s = (k == 0) ? 0 : pre_sum_peaks[k - 1];

            if (pre_sum_peaks[k + factors[j] - 1] - start_s == 0){
                no_peak = true;
                break;
            }
        }
        if (!no_peak) return s / factors[j];
    }
    return 0;
}

int solution2(vector<int> &A) {
    if(A.empty())
        return 0;
    int N = int(A.size());

    // Find peaks and mark it in the dedicated array
    vector<int> P(N);
    int p_cnt = 0;
    P[0] = 0;
    for(int i = 1; i < (N - 1); i ++) {
        if((A[i] > A[i - 1]) && (A[i] > A[i + 1]))
            p_cnt ++;
        P[i] = p_cnt;
    }
    P[N - 1] = p_cnt;

    if(p_cnt == 0)
        return 0; // No peaks detected

    // Find divider variants
    vector<int> D;
    long long d = 1;
    while((d * d) <= N) {
        if((N % d) == 0) {
            D.push_back(d);
            if((N / d) != d)
                D.push_back(N / d);
        }
        d ++;
    }
    sort(D.begin(), D.end());

    // Search for the max K
    int candidate_d = 1;	// at-least one block should be there;
    for(size_t i = 1; i < D.size(); i ++) {
        int cur_d = D[i];
        int cur_step = N / cur_d;

        int prev_p = P[0];
        bool no_new_peaks = false;
        for(int j = 1; j <= cur_d; j ++) {
            int cur_p = P[j * cur_step - 1];
            if(prev_p == cur_p) {
                // found a block with no peaks
                no_new_peaks = true;
                break;
            }
            prev_p = cur_p;
        }
        if(no_new_peaks)
            break;
        candidate_d = cur_d;
    }
    return candidate_d;
}

int solution3(vector<int> &A){
    // main idea:
    // 1) find all the peaks, and put them into a List
    // 2) try to divide the array into a number of groups,
    //    and check if all the groups have at least one peak
    //--> if yes, return the "number of groups"

    // use "List" to store all the peaks
    list<int> peaksIndexList = {};
    // 1) find the peaks (and store them)
    for(int i=1; i<A.size()-1; i++){
        if( A[i-1]<A[i] && A[i]>A[i+1] ){ // A[i] > A[i-1], A[i] > A[i+1]
            peaksIndexList.push_front(i);
        }
    }

    // 2) check the number of Blocks
    int N = A.size();
    // from the "biggest possible number" to smaller number
    for(int numBlocks =N; numBlocks >=1; numBlocks--){
        if( N % numBlocks ==0){ // it is divisible
            int blockSize = N / numBlocks;
            int ithOkBlock =0;  // the ith block has peak(s)
            // test all the peaks
            // if a peak is found in the ith block
            // then, go to the (i+1)th block
            for(int peaksIndex : peaksIndexList){
                if( peaksIndex/blockSize == ithOkBlock){ // peak in the ith block
                    ithOkBlock++; // go to check (i+1)th block
                }
            }
            // ithOkBlock: the number of blocks having peak(s)
            // if all the blocks have peak(s)
            // then, return the number of blocks
            // note: we test from the biggest possible number
            // so, once we find it, we can just return it
            // (no need to check the smaller possible numbers)
            if(ithOkBlock == numBlocks){
                return numBlocks;
            }
        }
    }
    return 0;
}

int main(){
    vector<int> A = {1,2,3,4,3,4,1,2,3,4,6,2};
    cout << "Peak(s): " << solution(A) << endl;
    cout << "Second solution: " << endl;
    cout << "Peak(s): " << solution2(A) << endl;
    return 0;
}