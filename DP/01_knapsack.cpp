// 01 Knapsack using 2D dynamic prog
#include<iostream>
#include<vector>
using namespace std;

// recursion + memoisation: top down approach
int solveMem(vector<int> wt, vector<int> val, int index, int cap,
            vector<vector<int>> dp) {

    // base case
    // moving from right to left
    // if index 0 is reached
    // check if there is still some capacity left in the knapsack
    // if yes, return the value for that weight
    if(index == 0) {
        if(wt[0] <= cap)
            return val[0];
        else
            return 0;
    }

    // dp base case
    if(dp[index][cap] != -1)
        return dp[index][cap];

    // recursion
    // calculate value using inclusion / exclusion logic
    int include = 0, exclude = 0;
    if(wt[index] <= cap)
        include = val[index] + solveMem(wt, val, index-1, cap-wt[index], dp);

    exclude = solveMem(wt, val, index-1, cap, dp);

    dp[index][cap] = max(include, exclude);
    return dp[index][cap];
}

void print(vector<int> t) {
    for(auto i: t)
        cout<<i<< " ";
    cout<<endl;
}

int main() {

    vector<int> wt = {1,2,4,5};
    vector<int> val = {5,4,8,6};
    int wtOfKnapsack = 5;
    int n = wt.size();

    vector<vector<int> > dp(n, vector<int>(wtOfKnapsack+1, -1));
    int ans = solveMem(wt, val, n-1, wtOfKnapsack, dp);

    cout<<"\nWeight: ";
    print(wt);
    cout<<"Value: ";
    print(val);
    cout<<"Weight of Knapsack: "<<wtOfKnapsack;
    cout << "\nMax value robbed: " << ans << "\n";

    return 0;
}