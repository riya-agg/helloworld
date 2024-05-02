#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int solve3(vector<int> coins, int amt) {
        vector<int> dp(amt+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amt; i++) {

            for(int j = 0; j < coins.size(); j++) {
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        if(dp[amt] != INT_MAX)
            return dp[amt];

        return -1;
        
    }

    int solve2(vector<int> coins, int amt) {
        // recursion
        if(amt == 0)
            return 0;

        if(amt < 0)
            return INT_MAX;

        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            int ans = solve2(coins, amt-coins[i]);
            if(ans != INT_MAX)
                mini = min(mini, ans+1);
        }

        return mini;       

    }

    int solve(vector<int> coins, int amt, vector<int> &dp) {
        // memoization
        if(amt == 0)
            return 0;

        if(amt < 0)
            return INT_MAX;

        if(dp[amt] != -1)
            return dp[amt];

        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            int ans = solve(coins, amt-coins[i], dp);
            if(ans != INT_MAX)
                mini = min(mini, ans+1);
        }
        dp[amt] = mini;
        return mini;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        //vector<int> dp(amount+1, -1);
        //int ans = solve(coins, amount, dp);
        //if(ans == INT_MAX)
        //    return -1;
        //return ans;
        return solve3(coins, amount);
    }
};

int main() {


    return 0;
}