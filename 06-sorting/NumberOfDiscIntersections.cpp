//
// Created by michal on 04.05.19.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    // main idea:
    // 1. store all the "lower points" and "upper points" of the discs
    // 2. count the intersections (if one upper point > one lower point)

    // note: use "long" for big numbers (be careful)
//    long lower[] = new long[A.size()];
//    long upper[] = new long[A.size()];

    int sum=0;
    vector<int> start(A.size(),0);
    vector<int> end(A.size(),0);

    for (unsigned int i=0;i<A.size();i++){
        if ((int)i<A[i]){
            start[0]++;
        }else{
            start[i-A[i]]++;
        }
        if (i+A[i]>=A.size()){
            end[A.size()-1]++;
        }else{
            end[i+A[i]]++;
        }
    }

    int active=0;
    for (unsigned int i=0;i<A.size();i++){
        sum+=active*start[i]+(start[i]*(start[i]-1))/2;

        if (sum>10000000){
            return -1;
        }
        active += start[i]-end[i];
    }
    return sum;

//    for(int i=0; i<A.size(); i++){
//        lower[i] = i - (long)A[i]; // note: lower = center - A[i]
//        upper[i] = i + (long)A[i]; // note: upper = center + A[i]
//    }
//
//    // "sort" the "lower points" and "upper points"
//    sort(lower.begin(), lower.end());
//    sort(upper.begin(), upper.end());
////    Arrays.sort(upper);
////    Arrays.sort(lower);
//
//    int intersection = 0; // number of intersections
//    int j=0; // for the lower points
//
//    // scan the upper points
//    for(int i=0; i<A.size(); i++){
//
//        // for the curent "j" (lower point)
//        while( j < A.size() && upper[i] >= lower[j]){
//            intersection = intersection + j; // add j intersections
//            intersection = intersection - i; // minus "i" (avoid double count)
//            j++;
//        }
//    }
//
//    // for the overflow cases
//    if(intersection > 10000000)
//        return -1;
//
//    return intersection; // number of intersections
}

int number_of_disc_intersections ( const vector<int> &A ) {
    int sum=0;
    vector<int> start(A.size(),0);
    vector<int> end(A.size(),0);
    for (unsigned int i=0;i<A.size();i++){
        if ((int)i<A[i]) start[0]++;
        else        start[i-A[i]]++;
        if (i+A[i]>=A.size())   end[A.size()-1]++;
        else                    end[i+A[i]]++;
    }
    int active=0;
    for (unsigned int i=0;i<A.size();i++){
        sum+=active*start[i]+(start[i]*(start[i]-1))/2;
        if (sum>10000000) return -1;
        active+=start[i]-end[i];
    }
    return sum;
}

int main(){
    vector<int> A = {10,2,5,1,8,20};

    if (solution(A) >= 0){
        cout << " the number of (unordered) pairs of intersecting discs: " << solution(A) << endl;
    }
    cout << "The number of intersecting pairs exceeds 10,000,000." << endl;

}