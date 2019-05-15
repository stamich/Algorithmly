//
// Created by michal on 05.05.19.
//
// Count the minimum number of jumps required for a frog to get to the
// other side of a river.
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

#include <set>

int solution(vector<int> &A) {
    int N = A.size();

    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    while (fib[fib.size() - 1] <= N + 1){
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    set<int> positions;
    positions.insert(N);
    for (int j = 1; ; j++){
        set<int> indexes;
        for (int i: positions){
            for (int f: fib){

                int p = i - f;
                if (p == -1){
                    return j;
                }
                if (p < 0) {
                    break;
                }
                if (A[p]){
                    indexes.insert(p);
                }
            }
        }
        if (indexes.size() == 0){
            return -1;
        }
        positions = indexes;
    }
}

int solution2(vector<int> &A) {
    const bool logs = false;

    const int N = int(A.size());
    A.push_back(1);

    // 2. Prepare Fibonacci numbers, likely applicable for jumping
    vector<int> fibs;
    fibs.push_back(1);
    fibs.push_back(2);
    int last_idx = 2;
    while(true) {
        const int fib = fibs[last_idx - 1] + fibs[last_idx - 2];
        if(fib > (N + 1))
            break;
        fibs.push_back(fib);
        last_idx ++;
    }

    if(logs) {
        cout << "Useful Fibonacci:" << endl;
        for(size_t i = 0; i < fibs.size(); i ++)
            cout << fibs[i] << endl;
        cout << "---------" << endl;
    }

    // this array will hold the optimal jump count that reaches this index
    vector<int> reachable(A.size(), -1);

    // get the leafs that can be reached from the starting shore
    for(size_t i = 0; i < fibs.size(); i ++) {
        const int jump = fibs[i];
        if(A[jump - 1] == 1)
            reachable[jump -1] = 1;
    }

    if(logs) {
        cout << "Reachable leafs from the first bank:" << endl;
        for(size_t i = 0; i < reachable.size(); i ++)
            if(reachable[i] == 1)
                cout << i << " ";
        cout << endl;
        cout << "---------" << endl;
    }

    // iterate all the positions until you reach the other shore
    for(int idx = 0; idx < int(A.size()); idx ++) {
        // ignore non-leafs and already found paths
        if((A[idx] == 0) || (reachable[idx] > 0))
            continue;

        if(logs)
            cout << "Analyzing leaf pos: " << idx << endl;

        // get the optimal jump count to reach this leaf
        int min_idx = -1;
        int min_value = 100000;

        for(size_t i = 0; i < fibs.size(); i ++) {
            const int jump = fibs[i];
            int previous_idx = idx - jump;

            if(logs) {
                cout << "jump = " << jump << "\t";
                cout << "previous_idx = " << previous_idx <<
                     endl;
            }

            if(previous_idx < 0)
                break;


            if(logs) {
                if(reachable[previous_idx] > 0)
                    cout << "\t\treachable!" << endl;
                else
                    cout << "\t\tUN reachable!" << endl <<
                         endl;;
            }

            if((reachable[previous_idx] > 0)
               && (min_value > reachable[previous_idx])) {
                min_value = reachable[previous_idx];
                min_idx = previous_idx;
            }

            if(min_idx != -1)
                reachable[idx] = min_value + 1;
        }
    }

    return reachable[A.size() - 1];
}

// ----------------------------------------------------------------------------

int calc_jumps_bf(int start_pos, int N,
                  const map<int, int> &_fibs,
                  const vector<int> &leafs,
                  int start_idx) {

    if(start_pos == N)
        return 0; // Reached the end of the recursion

    int min_cnt = INT_MAX;
    for(size_t i = start_idx; i < leafs.size(); i ++) {
        if(_fibs.count(leafs[i] - start_pos) <= 0)
            continue; // can not jump on this leaf

        // Try to jump on this leaf and see what would happen
        int cur_cnt = calc_jumps_bf(leafs[i], N, _fibs, leafs, i + 1);
        if(cur_cnt < min_cnt)
            min_cnt = cur_cnt;
    }
    if(min_cnt == INT_MAX)
        return INT_MAX;
    return (min_cnt + 1);
}

int main(void) {

    vector<int> A = {0,0,0,1,1,0,1,0,0,0,0};
    cout << "The minimum number of jumps by which the frog can get to the other side of the river: " << solution(A) << endl;
    cout << "Second solution: " << endl;
    cout << "The minimum number of jumps by which the frog can get to the other side of the river: " << solution2(A) << endl;
    return 0;
}