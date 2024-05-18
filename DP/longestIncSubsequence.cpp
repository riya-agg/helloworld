#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    int solve(vector<int>& nums, int n, int curr, int prev) {
        // recursion TLE   
        // base case
        if(curr == n)
            return 0;
        
        // include case
        int lenTake = 0;
        if(prev == -1 // standing at first element
            || nums[curr] > nums[prev] ) // increasing
            
            lenTake = 1 + solve(nums, n, curr+1, curr);

        // exclude case
        int noTake = 0 +  solve(nums, n, curr+1, prev);

        return max(lenTake, noTake);
    }

    int solveMem(vector<int> &nums, int n, int curr, int prev, vector<vector<int>> &dp) {
        // recursion + memoisation
        // base case
        if(curr == n)
            return 0;

        if(dp[curr][prev] != -1)
            return dp[curr][prev];

        // include case
        int lenTake = 0;
        if(prev == 0 // standing at first element
            || nums[curr] > nums[prev] ) // increasing
            
            lenTake = 1 + solveMem(nums, n, curr+1, curr, dp);

        // exclude case
        int noTake = 0 +  solveMem(nums, n, curr+1, prev, dp);

        return dp[curr][prev] = max(lenTake, noTake);
    }

    int solveTab(vector<int> &nums, int n) {
        // tabulation
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int curr = n-1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                // include case
                int lenTake = 0;
                if(prev == -1 // standing at first element
                    || nums[curr] > nums[prev] ) // increasing
                    
                    lenTake = 1 + dp[curr+1][curr+1];

                // exclude case
                int noTake = 0 +  dp[curr+1][prev+1];

                dp[curr][prev+1] = max(lenTake, noTake);
            }
        }

        return dp[0][0];
    }

    int solveSO(vector<int> &nums, int n) {
        // space optimization
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr = n-1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                // include case
                int lenTake = 0;
                if(prev == -1 // standing at first element
                    || nums[curr] > nums[prev] ) // increasing
                    
                    lenTake = 1 + nextRow[curr+1];

                // exclude case
                int noTake = 0 +  nextRow[prev+1];

                currRow[prev+1] = max(lenTake, noTake);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }

    int solveOptimal(vector<int> &nums, int n) {
        // dp with binary search
        if(n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i = 1; i < n; i++) {
            if(nums[i] >  ans.back()) {
                ans.push_back(nums[i]);
            }
            else {
                // find the element which is just greater than nums[i]
                int ind = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[ind] = nums[i];
            }
        }
        return ans.size();
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        //nums.insert(nums.begin(), 0);
        int n = nums.size();

        //return solve(nums, n, 0, -1);

        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //return solveMem(nums, n, 1, 0, dp);

        //return solveTab(nums, n);

       // return solveSO(nums, n);

        return solveOptimal(nums, n);
    }

};

int main() {

    vector<int> v1 = {10,9,2,5,3,7,101,18};
    vector<int> v2 = {0,1,0,3,2,3};
    vector<int> v3 = {7,7,7,7,7,7};
    
    Solution s = Solution();
    int ans1 = s.lengthOfLIS(v1);
    int ans2 = s.lengthOfLIS(v2);
    int ans3 = s.lengthOfLIS(v3);

    cout<<"\n Length of Longest Increasing Subsequence";
    cout<<"\n V1 : {10,9,2,5,3,7,101,18} : " << ans1;
    cout<<"\n V2 : {0,1,0,3,2,3} : " << ans2;
    cout<<"\n V3 : {7,7,7,7,7,7} : " << ans3;

    return 0;
}