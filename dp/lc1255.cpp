#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Given a list of words and score for each characters in the alphabets. 
    Find the max score you can obtain from words with available letters 
    
    map the score to each letter
    calculate the score of a given word based on the score of all available char
    rank the score of the words
    starting from the highest score words
*/
int res = 0;

pair<bool, vector<int>> test(const vector<int> w, const vector<int>& counts){
    vector<int> tmp(counts);
    for(int i = 0; i < w.size(); i++){
        tmp[i] -= w[i];
        if(tmp[i] < 0){
            return {false, counts};
        }
    }
    return {true, tmp};
}

void backtrack(vector<vector<int>>& words, vector<vector<int>>& wScore, vector<int>& counts, int curr, int n){
    if(n == wScore.size()){
        res = max(res, curr);
        return;
    }
    auto score = wScore[n][1], idx = wScore[n][0];
    auto [isTaken, newCounts] = test(words[idx], counts);
    if(isTaken){
        backtrack(words, wScore, newCounts, curr+score, n+1);
    }
    backtrack(words, wScore, counts, curr, n+1);
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    vector<int> counts(26, 0);
    for(auto &c: letters){
        counts[c-'a'] ++;
    }
    //calculate the score of each word
    vector<vector<int>> wCounts(words.size(), vector<int>(26, 0));
    vector<vector<int>> wScore(words.size(), vector<int>(2, 0)); //[n,2]
    for(int i = 0; i < words.size(); i++){
        wScore[i][0] = i;
        for(auto &c: words[i]){
            wCounts[i][c-'a']++;
        }
        for(int c = 0; c < 26; c++){
            wScore[i][1] += counts[c] >= wCounts[i][c] ? score[c] * wCounts[i][c] : 0;
        }
    }
    //rank the word based on their score
    sort(wScore.begin(), wScore.end(), [](const auto &a, const auto &b){
        return a[1] > b[1];
    });
    //remove zeros score words
    while(wScore.back()[1] == 0){
        wScore.pop_back();
    }
    // for(auto p: wScore){
    //     cout<<p[0]<<" "<<p[1]<<endl;
    // }
    //starting from the begining to check each word score
    //keep track of the current available char
    //BF: back track to find all the possible combinations
    backtrack(wCounts, wScore, counts, 0, 0);
    return res;
}


int main(){
    vector<string> words {"dog","cat","dad","good"};
    vector<char> letters {'a','a','c','d','d','d','g','o','o'};
    vector<int> score {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    cout<<maxScoreWords(words, letters, score);
}