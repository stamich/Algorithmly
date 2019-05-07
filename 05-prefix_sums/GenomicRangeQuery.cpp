//
// Created by michal on 01.04.19.
//
// Find the minimal nucleotide from a range of sequence DNA.
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {

    vector<int> preSumA;
    vector<int> preSumC;
    vector<int> preSumG;

    int countA = 0;
    int countC = 0;
    int countG = 0;

    for (size_t i = 0; i < S.size(); i++) {
        if (S[i] == 'A') countA++;
        else if (S[i] == 'C') countC++;
        else if (S[i] == 'G') countG++;

        preSumA.push_back(countA);
        preSumC.push_back(countC);
        preSumG.push_back(countG);
    }

    vector<int> result(P.size());
    for (int i = 0; i < int(P.size()); i++) {
        int A = (S[P[i]] == 'A') ? 1 : 0;
        int C = (S[P[i]] == 'C') ? 1 : 0;
        int G = (S[P[i]] == 'G') ? 1 : 0;
        if (preSumA[Q[i]] - preSumA[P[i]] + A > 0) result[i] = 1;
        else if (preSumC[Q[i]] - preSumC[P[i]] + C > 0) result[i] = 2;
        else if (preSumG[Q[i]] - preSumG[P[i]] + G > 0) result[i] = 3;
        else result[i] = 4;
    }
    return result;
}

vector<int> solution2(string &S, vector<int> &P, vector<int> &Q) {
    const int NUCLEOTIDES_TO_USE = 3;
    const int N = S.length();
    const int M = P.size();

    int **dna = new int*[NUCLEOTIDES_TO_USE];

    for (int i = 0; i < NUCLEOTIDES_TO_USE; i++) {
        dna[i] = new int[N + 1];
        dna[i][0] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < NUCLEOTIDES_TO_USE; j++) {
            dna[j][i] = dna[j][i - 1];
        }

        switch (S[i - 1]) {
            case 'A':
                dna[0][i]++;
                break;
            case 'C':
                dna[1][i]++;
                break;
            case 'G':
                dna[2][i]++;
                break;
            default:
                break;
        }
    }

    std::vector<int> *results = new std::vector<int>(M);

    for (int i = 0; i < M; i++) {
        (*results)[i] = 4;

        for (int j = 0; j < NUCLEOTIDES_TO_USE; j++) {
            if ((dna[j][Q[i] + 1] - dna[j][P[i]]) > 0) {
                (*results)[i] = j + 1;
                break;
            }
        }
    }

    for (int j = 0; j < NUCLEOTIDES_TO_USE; j++) {
        delete[] dna[j];
    }
    delete[] dna;

    return *results;
}

vector<int> solution3(string &S, vector<int> &P, vector<int> &Q) {
    if(S.empty() || P.empty() || Q.empty())
        return vector<int>();

    vector<int> ret(P.size());
    for(size_t K = 0; K < P.size(); K ++) {
        int impact = INT_MAX;
        for(int i = P[K]; i <= Q[K]; i ++) {
            switch(S[i]) {
                case 'A': impact = min(impact, 1); break;
                case 'C': impact = min(impact, 2); break;
                case 'G': impact = min(impact, 3); break;
                default: impact = min(impact, 4); break;
            }
        }
        ret[K] = impact;
    }
    return ret;
}

static bool equal(const vector<int> &r1, const vector<int> &r2) {
    if(r1.size() != r2.size())
        return false;
    for(size_t i = 0; i < r1.size(); i ++)
        if(r1[i] != r2[i])
            return false;
    return true;
}

static void print(const vector<int> &r, const string &tag) {
    cout << tag << ": ";
    for(size_t i = 0; i < r.size(); i ++)
        cout << r[i] << " ";
    cout << endl;
}

int main(void) {
    { // 1
        string S = "CAGCCTA";
        int p[] = {2, 5, 0};
        int q[] = {4, 5, 6};
        int exp[] = {2, 4, 1};
        vector<int> P(p, p + sizeof(p) / sizeof(p[0]));
        vector<int> Q(q, q + sizeof(q) / sizeof(q[0]));
        vector<int> Exp(exp, exp + sizeof(exp) / sizeof(exp[0]));

        vector<int> r1 = solution(S, P, Q);
        if(!equal(r1, Exp)) {
            print(r1, "result");
            print(Exp, "expected");
            cout << "ERROR1" << endl;
        }

        vector<int> r2 = solution2(S, P, Q);
        if(!equal(r2, Exp)) {
            print(r2, "BF result");
            print(Exp, "expected");
            cout << "ERROR12" << endl;
        }
    }

    { // 2
        srand(time(NULL));
        for(int test = 0; test < 100; test ++) {
            cout << "Test " << test << "..." << endl;
            const int N = 12;
            const int M = 50;

            string S;
            for(int i = 0; i < N; i ++) {
                int ch = rand() % 4;
                switch(ch) {
                    case 0: S += 'A'; break;
                    case 1: S += 'C'; break;
                    case 2: S += 'G'; break;
                    case 3: S += 'T'; break;
                }
            }

            vector<int> P(M), Q(M);
            for(int i = 0; i < M; i ++) {
                int p = rand() % N;
                int q = rand() % N;
                P[i] = min(p, q);
                Q[i] = max(p, q);
            }

            vector<int> r1 = solution(S, P, Q);
            vector<int> r2 = solution2(S, P, Q);
            if(!equal(r1, r2)) {
                cout << "S: " << S << endl;
                print(P, "P");
                print(Q, "Q");
                print(r1, "result");
                print(r2, "2 result");
                cout << "ERROR2" << endl;
            } else
                cout << "OK" << endl;
        }
    }


    return 0;
}