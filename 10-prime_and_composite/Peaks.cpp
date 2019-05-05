//
// Created by michal on 05.05.19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

int solution(vector<int> &A) {

    int s = int(A.size());
    if (s < 3) return 0;
    int i = 1;
    vector<int> factors;

    while (i * i < s) {
        if (s % i == 0) {
            factors.push_back(i);
            factors.push_back(s / i);
        }
        i++;
    }

    if (i * i == s) {
        factors.push_back(i);
    }

    sort(factors.begin(), factors.end());
    vector<int> peaks(s, 0);
    int peak_num = 0;

    for (int j = 1; j < s - 1; j++) {
        if ((A[j] > A[j - 1]) && (A[j] > A[j + 1])) {
            peaks[j] = 1;
            peak_num++;
        }
    }

    if (peak_num == 0) return 0;
    if (peak_num == 1) return 1;
    vector<int> pre_sum_peaks;
    int ss = 0;

    for (auto j: peaks) {
        ss += j;
        pre_sum_peaks.push_back(ss);
    }

    for (int j = 1; j < int(factors.size()); j++) {
        bool no_peak = false;
        for (int k = 0; k < s; k += factors[j]) {

            int start_s = (k == 0) ? 0 : pre_sum_peaks[k - 1];

            if (pre_sum_peaks[k + factors[j] - 1] - start_s == 0) {
                no_peak = true;
                break;
            }
        }
        if (!no_peak) return s / factors[j];
    }
    return 0;
}

//int solution2(vector<int> &A){
//    // main idea:
//    // 1) find all the peaks, and put them into a List
//    // 2) try to divide the array into a number of groups,
//    //    and check if all the groups have at least one peak
//    //--> if yes, return the "number of groups"
//
//    // use "List" to store all the peaks
//    list<int> peaksIndexList = {};
//
//    // 1) find the peaks (and store them)
//    for(int i=1; i<A.size()-1; i++){
//        if( A[i-1]<A[i] && A[i]>A[i+1] ){ // A[i] > A[i-1], A[i] > A[i+1]
//            peaksIndexList.push_front(i);
//        }
//    }
//
//    // 2) check the number of Blocks
//    int N = A.size();
//
//    // from the "biggest possible number" to smaller number
//    for(int numBlocks =N; numBlocks >=1; numBlocks--){
//
//        if( N % numBlocks ==0){ // it is divisible
//
//            int blockSize = N / numBlocks;
//            int ithOkBlock =0;  // the ith block has peak(s)
//
//            // test all the peaks
//            // if a peak is found in the ith block
//            // then, go to the (i+1)th block
//            for(int peaksIndex : peaksIndexList){
//                if( peaksIndex/blockSize == ithOkBlock){ // peak in the ith block
//                    ithOkBlock++; // go to check (i+1)th block
//                }
//            }
//
//            // ithOkBlock: the number of blocks having peak(s)
//            // if all the blocks have peak(s)
//            // then, return the number of blocks
//            // note: we test from the biggest possible number
//            // so, once we find it, we can just return it
//            // (no need to check the smaller possible numbers)
//            if(ithOkBlock == numBlocks){
//                return numBlocks;
//            }
//        }
//    }
//
//    return 0;
//}