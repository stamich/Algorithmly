//
// Created by EB79OJ on 2019-05-06.
//
// Given a string containing words, find the longest word that satisfies specific conditions.
// https://codesays.com/2016/solution-to-longest-password-by-codility/
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

int solution(string &S) {
    long long cntAlpha = 0, cntDigit = 0, cnt = 0, ans = -1, len = S.size() * -1LL;
    auto end = S.end(), itor = S.begin();
    while (1) {
        cntDigit = cntAlpha = cnt = 0;
        while (itor != end && ' ' != *itor){
            if (isdigit(*itor)){
                ++cntDigit;
            }
            else if (isalpha(*itor)){
                ++cntAlpha;
            }
            else{
                cnt = len;
            }
            ++itor, ++cnt;
        }
        if (cnt > 0 && cntDigit & 1 && !(cntAlpha & 1)){
            ans = std::max(ans, cnt);
        }
        if (end == itor || end == ++itor){
            break;
        }
    }
    return ans;
}

//---------

bool isPass(string& s)
{
    unsigned number = 0, letter = 0;
    for(unsigned i = 0; i < s.size(); i++){
        if(isalnum(s.at(i)) == 0){
            return false;
        }
        if(isalpha(s.at(i)) != 0){
            letter++;
        }
        if(isdigit(s.at(i)) != 0){
            number++;
        }
    }
    if(letter %2 !=0 || number %2 !=1){
        return false;
    }
    return true;
}
int solution2(string &S){
    string ss;
    int maximal =-1, n = 0, result =-1;
    int i=S.find(" ");

    while(i != S.npos){
        ss=S.substr(n, i - n);

        if(isPass(ss) == true){
            maximal = ss.size();
        }

        result = max(result, maximal);
        n =++i;
        i = S.find(" ",i);
    }

    ss = S.substr(n, S.size() - n);

    if(isPass(ss) == true){
        maximal = ss.size();
    }
    result = max(result, maximal);
    return result;
}