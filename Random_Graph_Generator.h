const int N=1e3;                          //Disjoint Set Union(DSU) implementation starts
vector<int> ln(N+2),rn(N+2);

void DSUinit()
{
	for(int i=0;i<=N;i++)
		ln[i]=i,rn[i]=1;
}

int fin(int x)
{
	if(ln[x]==x) return x;
	return ln[x]=fin(ln[x]);				//DSU is used here to ensure that the graphs 
}								//that this random generator generates is
void unite(int x, int y)					//always connected.
{
	int a=fin(x),b=fin(y);
	if(a!=b)
	{
		if(rn[a]<rn[b]) swap(a,b);
		ln[b]=a,rn[a]+=rn[b];
	}
}
bool same(int x, int y)
{
	if(fin(x)==fin(y)) return true;
	return false;
}
					   //Disjoint Set Union(DSU) implementation ends

vector<vector<int> > generate_sparse_list(int n)  //Function that returns a adjacency list of a random sparse graph 
{						  //with n nodes
	DSUinit();
	vector<vector<int> > g(n+1);
	vector<pair<int,int> > edges;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			edges.push_back({i,j});
		}
	}
	while(1)
	{
		int s=edges.size();
		int a=rand()%s;
		int x=edges[a].first,y=edges[a].second;
		if(!same(x,y))
		{
			unite(x,y);
			g[x].push_back(y);
			g[y].push_back(x);
			edges.erase(edges.begin()+a);
			if(rn[fin(x)]>=n) break;
		}
	}
	return g;
}

vector<vector<int> > generate_dense_list(int n)  //Function that returns a adjacency list of a random dense graph 
{					         //with n nodes
	DSUinit();
	vector<vector<int> > g(n+1);
	vector<pair<int,int> > edges;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			edges.push_back({i,j});
		}
	}
	while(1)
	{
		int s=edges.size();
		int a=rand()%s;
		int x=edges[a].first,y=edges[a].second;
		if(!same(x,y))
		{
			unite(x,y);
			g[x].push_back(y);
			g[y].push_back(x);
			edges.erase(edges.begin()+a);
			if(rn[fin(x)]>=n) break;
		}
	}
	int e=(n*(n-1))/6-(n-1);
	while(e>0)
	{
		int s=edges.size();
		int a=rand()%s;
		int x=edges[a].first,y=edges[a].second;
		g[x].push_back(y);
		g[y].push_back(x);
		edges.erase(edges.begin()+a);
		e--;
	}
	return g;
}

vector<vector<int> > generate_very_dense_list(int n)  //Function that returns a adjacency list of a random very dense graph 
{						      //with n nodes
	vector<vector<int> > g(n+1); 
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			g[i].push_back(j);
			g[j].push_back(i);
		}
	}
	return g;
}

vector<vector<int> > generate_sparse_matrix(int n)  //Function that returns a adjacency matrix of a random sparse graph 
{						    //with n nodes
	vector<vector<int> > t(n+1);
	vector<vector<int> > g(n+1,vector<int>(n+1,0) );
	t=generate_sparse_list(n);
	for(int i=1;i<=n;i++)
	{
		for(auto x: t[i])
		{
			if(g[i][x]==g[x][i]&&g[i][x]==0)
				g[i][x]=g[x][i]=(int)rand()%20;
		}
	}
	return g;
}

vector<vector<int> > generate_dense_matrix(int n)  //Function that returns a adjacency matrix of a random dense graph
{					           //with n nodes
	vector<vector<int> > t(n+1);
	vector<vector<int> > g(n+1,vector<int>(n+1,0) );
	t=generate_dense_list(n);
	for(int i=1;i<=n;i++)
	{
		for(auto x: t[i])
		{
			if(g[i][x]==g[x][i]&&g[i][x]==0)
				g[i][x]=g[x][i]=(int)rand()%20;
		}
	}
	return g;
}

vector<vector<int> > generate_very_dense_matrix(int n)  //Function that returns a adjacency matrix of a random very dense graph
{														//with n nodes
	vector<vector<int> > g(n+1,vector<int>(n+1,0) );
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++) g[i][j]=g[j][i]=(int)rand()%20;
	}
	return g;
}

