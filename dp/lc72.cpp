#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> diffBetweenTwoStrings(const string& source, const string& target)
{
  return {};
}

int minDistance(string word1, string word2){
  /*
    dp[0,0] = 0
    dp[0,i] = i;
    dp[j,0] = j;
    what is the min number of edits to get to word1[0:n] and word2[0:m] to 
      if word1[n] && word2[m] are the same we don't need to increment the edits
        dp[n-1,m-1] = dp[n,m]
      else:
        delete: dp[n-1,m]+1
        insert: dp[n,m-1]+1,
        replace: dp[n-1, m-1]+1
  */
  int n = word1.size(), m = word2.size();
  vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
  for(int i = 0; i <= n; i++){
    dp[i][0] = i;
  }
  for(int j = 0; j <= m; j++){
    dp[0][j] = j;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(word1[i-1] == word2[j-1]){
        dp[i][j] = dp[i-1][j-1];
      }
      if(dp[i-1][j] + 1 < dp[i][j])
        dp[i][j] = dp[i-1][j] + 1;
      if(dp[i][j-1] + 1 < dp[i][j])
        dp[i][j] = dp[i][j-1] + 1;
      if(dp[i-1][j-1] + 1 < dp[i][j])
        dp[i][j] = dp[i-1][j-1] + 1;
    }
  }
  return dp[n][m];
}

int main() 
{
  string source = "intention", target = "execution";
  cout<<minDistance(source, target);
	return 0;
}
