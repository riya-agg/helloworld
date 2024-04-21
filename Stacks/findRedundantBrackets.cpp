#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s) {

    stack<char> st;
    for(int i = 0; i< s.length(); i++) {

        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' ||
           ch == '/' ) {
            st.push(ch);
        }
        else {
            if(ch == ')') {
                bool flg = true;
                while(st.top() != '(') {
                    char ch1 = st.top();
                    if(ch1 == '+' || ch1 == '-' || ch1 == '*' ||
                        ch1 == '/') {
                            flg = false;
                    }
                    st.pop();
                }

                if(flg == true) return true;
                st.pop(); // removing the '(' bracket
            }
        }
        
    }
    return false;
}

int main() {
    // if there is no operator between ( and ), 
    // then there is a redundant bracket in expression

    cout<<"\nFind Redundant Brackets!";

    string s = "(a+b)";
    cout<<"\n(a+b): "<< findRedundantBrackets(s);

    s = "((a+b))";
    cout<<"\n((a+b)): "<< findRedundantBrackets(s);

    s = "((a+b)*c)";
    cout<<"\n((a+b)*c): "<< findRedundantBrackets(s);

    return 0;
}