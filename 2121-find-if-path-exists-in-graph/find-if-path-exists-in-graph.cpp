class Solution {
    bool dfs(unordered_map<int, vector<int>>& graph, int src,int dst, vector<bool> &visited, int n)
    {
        if(src == dst) return true;
        visited[src] = true;

        for(auto neighbor : graph[src])
        {
            if(!visited[neighbor])
            {
                if(dfs(graph,neighbor,dst,visited,n))
                {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n,false);
      return  dfs(graph,source,destination,visited,n);
    }
};