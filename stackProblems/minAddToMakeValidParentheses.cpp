/*
* Written by Alok Pratap <https://github.com/quicktwit/>, 2020
*/

#include <iostream>
#include <stack> 

class Solution {
public:
    int minAddToMakeValid(string S) {
        std::stack<int> st;
        for(int i = 0; i < S.size(); i++)
        {
            if(st.empty())
            {
                st.push(S[i]);
            }
            else if(st.top() == '(' && S[i] == ')')
            {
                st.pop();
            }
            else{
                st.push(S[i]);
            }
                
        }
        return st.size();
    }
};