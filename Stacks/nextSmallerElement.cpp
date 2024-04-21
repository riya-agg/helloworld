#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for(int i=n-1; i>=0; i--) {
        int curr = arr[i];
        while(s.top() >= curr) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;

}

void print(vector<int> v){
    cout<< "\n";
    for(int i=0;i<v.size();i++) {
        cout<<v[i] << " ";
    }
}

int main() {

    vector<int> v = {5,1,4,3};
    int n = 4;
    vector<int> ans = nextSmallerElement(v, n);
    print(ans);

    return 0;
}