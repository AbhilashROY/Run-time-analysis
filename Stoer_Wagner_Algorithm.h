int GetStoerWagnerMinCut(vector<vector<int> > graph) //This function returns the min-cut of an undirected, weighted graph using Stoer-Wagner Algorithm
{
    const int INF = 1000000000;
    int N = graph.size()-1; //N is the no. of nodes in the graph; 1 is subtracted because indexing of nodes starts from 1 and 0 is not a node
    vector<int> used(N+1,0); //Represents no. of nodes which has been merged
    int min_cut_value = -1; //required min-cut value

    for (int phase = N; phase >= 1; phase--) //Iterating through phases till only two nodes are remaining
    {
        vector<int> w = graph[1]; //First node 1 is selected for every phase
        vector<int> added = used; //Represents node added to Set A
        added[1]=true; //Since 1 is already chosen
        int prev, last = 0; //prev-Previous node which was added to set A; last-Most tightly attached node to set A in the present iteration
        for (int i = 1; i < phase; i++)
        {
            prev = last;
            last = -1;
            for (int j = 1; j <= N; j++) //Iterating through all the nodes not added in A to update last
            {
                if (!added[j] && (last == -1 || w[j] > w[last])) last = j; //updating last
            }
            if (i == phase-1)
            {
                for (int j = 1; j <= N; j++) graph[prev][j] += graph[last][j]; //merging edges
                for (int j = 1; j <= N; j++) graph[j][prev] = graph[prev][j];
                used[last] = true;
                if (min_cut_value == -1 || w[last] < min_cut_value)
                {
                    min_cut_value = w[last]; //updating min_cut_value
                }
            }
            else
            {
                for (int j = 1; j <= N; j++)
                {
                    w[j] += graph[last][j]; //merging edges
                    added[last] = true;     //adding last node to added vector
                }
            }
        }
    }
    return min_cut_value; //returning min_cut_value
}
