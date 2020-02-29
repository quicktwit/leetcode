/*
* Written by Alok Pratap <https://github.com/quicktwit/>, 2020
*/

class Solution {
    
    int dp[110][110];
    
    int countPaths(int i, int j, int m, int n)
    {
        int &result = dp[i][j];
        if(result != -1)
        {
            return result;
        }
        if(i == m && j == n)
        {
            return result = 1;
        }
        if(i > m || j > n)
        {
            return result = 0;
        }
        result = countPaths(i + 1, j, m, n) + countPaths(i, j + 1, m, n);
        return result;
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp);
        return countPaths(1, 1, m, n);
    }
};