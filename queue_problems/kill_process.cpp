/*
* Written by Alok Pratap <https://github.com/quicktwit/>, 2020
*/

/*
Result is: Time Limit Exceeded
*/

class Solution {
public:
    vector<int> result;
    queue<int> q;
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        q.push(kill);
        result.push_back(kill);
        while(!q.empty())
        {
            int current = q.front();
            int n = 0;
            for(int i = 0; i < n; i++)
            {
                if(ppid[i] == current)
                {
                    q.push(pid[i]);
                    result.push_back(pid[i]);
                }
            }
        }
        return result;
    }
};