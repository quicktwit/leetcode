/*
* Written by Alok Pratap <https://github.com/quicktwit/>, 2020
*/

/*
Result is: Time Limit Exceeded
*/

class Solution {
public:
    string simplifyPath(string path) {
        std::stack<char> st;
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == '/')
            {
                if(st.empty())
                {
                    st.push(path[i]);
                }
                else if(st.top() >= 'a' && st.top() <= 'z')
                {
                    st.push(path[i]);
                }
            }
            else if(path[i] >= 'a' && path[i] <= 'z')
            {
                st.push(path[i]);
            }
            else if(path[i] == '.')
            {
                if(i < path.size() - 1)
                {
                    if(path[i + 1] == '.')
                    {
                        if(!st.empty())
                        {
                            st.pop();
                            // Let's remove the folder
                            while(!st.empty() && st.top() != '/')
                            {
                                st.pop();
                            }
                        }
                        i++;
                    }
                }
            }
        }
        string finalString = "";
        while(!st.empty())
        {
            finalString += st.top();
            st.top();
        }
        if(finalString[finalString.size() - 1] == '/')
        {
            finalString.erase(finalString.size() - 1, 1);
        }
        return finalString;
    }
};