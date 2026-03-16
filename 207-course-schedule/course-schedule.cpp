class Solution {
public:
    bool chkLoop(vector<vector<int>> &graph, int i, vector<int> &visited)
    {
        if(visited[i]==1)
        {
            return true;
        }

        if(visited[i]==2)
        {
            return false;
        }

        visited[i] = 2;

        //check neighbours
        for(int index:graph[i])
        {
            if(!chkLoop(graph,index,visited))
            {
                return false;
            }
        }

        visited[i] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        // check prerequisite and create graph
        for(auto prerequisite : prerequisites)
        {
            int firstCourse = prerequisite[0];
            int secondCourse = prerequisite[1];

            graph[firstCourse].push_back(secondCourse);
        }

        vector<int> visited(numCourses,0);

        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i]!=1)
            {
                bool tmp = chkLoop(graph,i,visited);

                if(!tmp)
                {
                    return false;
                }
            }
        }
        return true;
    }
};