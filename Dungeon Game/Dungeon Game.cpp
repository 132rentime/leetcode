/*
    ��dp[i][j]��ʾ��(i,j)��(n-1,m-1)ʱ��(i,j)��������Ҫ����HP
    ��ôת�Ʒ��̾��� dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j],1);
    ע����ÿ���������ٶ�Ҫ��1������ֵ
    ʱ�临�Ӷ�  O(nm)
    �ռ临�Ӷ�  O(nm)
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int **dp = new int*[n];
        for(int i = 0;i < n;i++)    dp[i] = new int[m];
        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                if(i != n - 1 && j != m - 1)    dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j],1);
                else if(i != n - 1)     dp[i][j] = max(dp[i+1][j] - dungeon[i][j],1);
                else if(j != m - 1)     dp[i][j] = max(dp[i][j+1] - dungeon[i][j],1);
                else    dp[i][j] = max(1 - dungeon[i][j],1);
            }
        }
        int res = dp[0][0];
        for(int i = 0;i < n;i++)    delete dp[i];
        delete dp;
        return res;
    }
};

