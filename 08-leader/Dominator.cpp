//
// Created by michal on 05.05.19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//struct C
//{
//    unsigned int idx;
//    int cnt;
//
//    int Counting(unsigned int idx_)
//    {
//        idx = idx_;
//        ++cnt;
//        return cnt;
//    }
//};
//
//static bool compare(const C& a, const C& b)
//{
//    return a.cnt > b.cnt;
//}
//
//int solution(vector<int>& A)
//{
//    if (A.size() < 1) return -1;
//    if (A.size() == 1) return 0;
//    int idxDominator = -1;
//
//    map<unsigned int, C> m;
//    vector<C> candidates;
//    unsigned int cntMax = 0;
//
//    for (unsigned int i = 0; i < A.size(); ++i)
//    {
//        int curr = A[i];
//        unsigned int cntCurr = m[curr].Counting(i);
//        if (cntMax < cntCurr) cntMax = cntCurr;
//    }
//
//    //@ find dominator.
//    if (cntMax > A.size() / 2)
//    {
//        for (map<unsigned int, C>::iterator iter = m.begin(); iter != m.end(); iter++)
//        {
//            candidates.push_back(iter->second);
//        }
//
//        sort(candidates.begin(), candidates.end(), compare);
//        int cnt = candidates[0].cnt;
//
//        idxDominator = candidates[0].idx;
//    }
//
//    return idxDominator;
//}
//
//int solution2(vector<int> &A)
//{
//    if (A.empty())
//    {
//        return -1;
//    }
//
//    int counter = 1;
//    int candidate = A[0];
//
//    for (std::size_t i = 1; i < A.size(); ++i)
//    {
//        if (A[i] == candidate)
//        {
//            ++counter;
//        }
//        else
//        {
//            --counter;
//            if (0 == counter)
//            {
//                candidate = A[i];
//                counter = 1;
//            }
//        }
//    }
//
//    counter = 0;
//    for (std::size_t i = 0; i < A.size(); ++i)
//    {
//        if (A[i] == candidate)
//        {
//            ++counter;
//        }
//    }
//    int dominator = -1;
//    if (counter > (A.size() / 2))
//    {
//        dominator = candidate;
//    }
//
//    return dominator;
//}
//
//int solution3(vector<int> & A) {
//    if (A.empty()) {
//        return -1;
//    }
//    if (A.size() == 1) {
//        return 0;
//    }
//    std::map values;
//    unsigned int half = A.size() / 2;
//    for (unsigned int index = 0; index < A.size(); index++) {
//        if (++values[A[index]] > half) {
//            return index;
//        }
//    }
//    return -1;
//}
//
//int solution4(vector<int> & A) {
//    if (A.empty()) {
//        return -1;
//    }
//    if (A.size() == 1) {
//        return 0;
//    }
//    std::set usedValues;
//    unsigned int half = A.size() / 2;
//    unsigned int indexMax = (unsigned int)((float)A.size() / 2.0 + 0.5);
//    for (unsigned int index = 0; index < indexMax; index++) {
//        if (usedValues.find(A[index]) != usedValues.end()) {
//            continue;
//        }
//        if (std::count(A.begin() + index, A.end(), A[index]) > half) {
//            return index;
//        }
//        usedValues.insert(A[index]);
//    }
//    return -1;
//}

#include <unordered_map>

int solution(vector<int> &A) {
    unordered_map<int, int> um;

    for (size_t i = 0; i < A.size(); i++) {
        if (um.find(A[i]) != um.end()) {
            um[A[i]]++;
        } else {
            um[A[i]] = 1;
        }

        if (um[A[i]] > A.size() / 2) return i;
    }

    return -1;
}

