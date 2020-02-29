/*
* Written by Alok Pratap <https://github.com/quicktwit/>, 2020
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
                else if(st.top() != '/' && st.top() != '.')
                {
                    st.push(path[i]);
                }
            }
            else if(path[i] != '/' && path[i] != '.')
            {
                st.push(path[i]);
            }
            else if(path[i] == '.')
            {
                if(i < path.size() - 1)
                {
                    if(path[i + 1] == '.')
                    {
                        if (i < path.size() - 2) {
                            if (path[i + 2] == '/') {
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
                            else {
                                while (i < path.size() && path[i] != '/') {
                                    st.push(path[i]);
                                    i++;
                                }
                                i--;
                            }
                        }
                        else {
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
                    else if (path[i + 1] != '/'){
                        while (i < path.size() && path[i] != '/') {
                            st.push(path[i]);
                            i++;
                        }
                        i--;
                    }
                }
            }
        }
        string finalString = "";
        while(!st.empty())
        {
            finalString += st.top();
            st.pop();
        }
        std::reverse(finalString.begin(), finalString.end());
        if(finalString[finalString.size() - 1] == '/')
        {
            finalString.erase(finalString.size() - 1, 1);
        }
        if (finalString == "")
            finalString = "/";
        return finalString;
        
    }
};