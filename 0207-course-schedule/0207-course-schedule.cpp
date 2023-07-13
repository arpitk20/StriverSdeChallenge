class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        for(auto x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
        int inDegree[numCourses];
        for(int i=0;i<numCourses;i++)
            inDegree[i] = 0;
        for(int i=0;i<numCourses;i++)
        {
            for(auto x:adj[i])
                inDegree[x]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto x:adj[node])
            {
                inDegree[x]--;
                if(inDegree[x]==0)
                    q.push(x);
            }
        }
        if(topo.size()==numCourses)
            return true;
        return false;
    }
};