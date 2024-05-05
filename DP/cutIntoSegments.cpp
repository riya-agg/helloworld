// Input: integer N - length of the rod
//      : three integers X, Y, Z
// Determine max number of segments that can be made 
// provided that each segment should be of length X, Y or Z

#include<iostream>
#include<vector>
using namespace std;

int solve(int n, int x, int y, int z, vector<int> &dp) {

    if(n < 0)
        return INT_MIN;

    // length of the rod = 0
    if(n == 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    int ans_x = solve(n-x, x, y, z, dp) + 1;
    int ans_y = solve(n-y, x, y, z, dp) + 1;
    int ans_z = solve(n-z, x, y, z, dp) + 1;

    dp[n] = max(ans_x, max(ans_y, ans_z));
    return dp[n];
}

int main() {

    int n = 7, x = 5, y = 2, z = 2;
    vector<int> dp(n+1, -1); // as we need dp[n] for 0 based indexing

    int segments = solve(n, x, y, z, dp);

    if(segments < 0)
        cout<<"\nCannot cut the rod in given segments.";
    else
        cout<<"\nMax Segments: " << segments;

    return 0;
}