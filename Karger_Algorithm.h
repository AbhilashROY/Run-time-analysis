set<int> nodes_available;
int noOfNodes;
void mergeNode(vector<vector<int> >& graph, int x, int y) //Merges node x and y 
{
    if(x<y) swap(x,y);
    graph[y].insert(graph[y].end(), graph[x].begin(), graph[x].end());
    auto nodesConnectedToA = graph[x];
    for(auto node : nodesConnectedToA)
    {
        auto position = graph[node].end();
        while ((position =find(graph[node].begin(),graph[node].end(),x)) != graph[node].end()) //Merging nodes
        {
            *position = y;
        }
    }
    
    auto selfNodePos = graph[y].end();
    while ((selfNodePos = find(graph[y].begin(),graph[y].end(),y)) != graph[y].end()) //Removing self loops
    {
        graph[y].erase(selfNodePos);
    }
    
    nodes_available.erase(x); //Removing node x from available list since it is merged with y
    graph[x].clear();
}

int GetKargerMinCut(vector<vector<int> >& graph, int numberOfRepetitions) //This function returns the min-cut of an undirected, unweighted graph using Karger's Algorithm
{
    int n = graph.size(); //no. of nodes of graph 
    for(int i=1;i<n;i++) nodes_available.insert(i);
    int min_cut = (n*(n - 1)) / 2; //initialize to maximum number of possible edges
    auto originalGraph = graph;

    for (int i = 0; i < numberOfRepetitions; i++) //Repeating the algorithm to increase probability of correct answer 
    {
        graph = originalGraph;
        for (noOfNodes = nodes_available.size(); noOfNodes > 2; noOfNodes = nodes_available.size()) //For a particular repeatition, selecting random edges and merging them till only two nodes remain
        {
            vector<int> an;
            for(auto x: nodes_available) an.push_back(x); //an contains the nodes_available
            int s=an.size(); 
            int firstNode=rand()%s,secondNode; 
            firstNode=an[firstNode]; //Randomly selects a first node
            secondNode=graph[firstNode][rand()%(graph[firstNode].size())]; //Randomly selects a second node
            mergeNode(graph, firstNode, secondNode); //Contracting firstNode and secondNode
        }
        for(int i=1;i<n;i++) nodes_available.insert(i);
        int nodeNumber = graph[*nodes_available.begin()].size();
        if (nodeNumber < min_cut)
            min_cut = nodeNumber; //updating min_cut
    }
    nodes_available.clear(); //Clearing nodes_available
    return min_cut; //returning min-cut
}
