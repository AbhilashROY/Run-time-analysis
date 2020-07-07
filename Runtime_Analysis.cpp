#include<bits/stdc++.h>
using namespace std;
#include"Karger_Algorithm.h"
#include"Stoer_Wagner_Algorithm.h"
#include"Random_Graph_Generator.h"

double get_time()
{
	return (double)clock()/CLOCKS_PER_SEC;  //Returns the time in seconds
}

string file_name;
FILE* f;

int test_karger_algorithm(vector<vector<int>>& g, int rep, int n)  //testing the Karger's Algorithm against a given graph 
{								   //g is the graph; rep is the no. of times a single phase of
	double start , end;					   //Karger's Algorithm will be repeated; n is no. of nodes in graph g
	start = get_time();  //Timer starts
	int res = GetKargerMinCut(g,rep);  //Karger's Algorithm is called, the function is defined in 'Karger_Algorithm.h' header file
	end = get_time();    //Timer ends
	double runtime = end - start;  //Calculates the time required to run the algorithm
	fprintf(f, "%d ", n); //Writes the data to file
	fprintf(f, "%f\n", runtime);  //Writes the data to file
	cout << "Runtime is " << runtime << endl;  //Outputs the runtime in console
	return res; // Returns the result
}

int test_stoer_wagner_algorithm(vector<vector<int>>& g, int n)  //testing the Stoer-Wagner Algorithm against a given graph 
{								//g is the graph; n is no. of nodes in graph g
	double start , end;										
	start = get_time();
	int res = GetStoerWagnerMinCut(g);
	end = get_time();				        //All parameters here are similar to the above function
	double runtime = end - start;
	fprintf(f, "%d ", n);
	fprintf(f, "%f\n", runtime);
	cout << "Runtime is " << runtime << endl;
	return res;
}

void test_karger_algorithm_driver()   //Driver function for Karger's algorithm which selects the different files 
{				      //to which runtime data will be written to and the type of graph for a particular number of nodes n
	file_name="runtime_data/data_sparse_karger.dat"; //Path of the file to which data will be written
	f = fopen(file_name.c_str(),"w");                //Opening the partucular file
	for(int n = 2; n < 40; n+=2)                     //Iterating through graphs of different sizes
	{
		cout<<"For n = "<<n<<" : "<<endl;
		int rep = n*n*log2(n); //Specifies the number of iterations for the Karger's algorithm
		vector<vector<int>> g = generate_sparse_list(n); //Generates a sparse connected graph with n nodes
		int res = test_karger_algorithm(g, rep, n); //Calls the testing function
		cout << "The min-cut is : " << res << "\n\n"; //Outputs the result, i.e, the min-cut of the graph
	}
	fclose(f); // file is closed

	file_name="runtime_data/data_dense_karger.dat";
	f = fopen(file_name.c_str(),"w");                         //Similar to above function
	for(int n = 2; n < 40; n+=2)
	{
		cout<<"For n = "<<n<<" : "<<endl;
		int rep = n*n*log2(n);
		vector<vector<int>> g = generate_dense_list(n);//Generates a dense connected graph with n nodes
		int res = test_karger_algorithm(g, rep, n);
		cout << "The min-cut is : " << res << "\n\n";
	}
	fclose(f);

	file_name="runtime_data/data_very_dense_karger.dat";
	f = fopen(file_name.c_str(),"w");			//Similar to above function
	for(int n = 2; n < 40; n+=2)
	{
		cout<<"For n = "<<n<<" : "<<endl;
		int rep = n*n*log2(n);
		vector<vector<int>> g = generate_very_dense_list(n);//Generates a very dense connected graph with n nodes
		int res = test_karger_algorithm(g, rep, n);
		cout << "The min-cut is : " << res << "\n\n";
	}
	fclose(f);
}

void test_stoer_wagner_algorithm_driver()  //Driver function for Stoer-Wagner algorithm which selects the different files 
{					   //to which runtime data will be written to and the type of graph for a particular number of nodes n
	file_name="runtime_data/data_sparse_stoer_wagner.dat";
	f = fopen(file_name.c_str(),"w");                          //Similar to above function
	for(int n = 2; n < 300; n+=5)
	{
		cout<<"For n = "<<n<<" : "<<endl;
		vector<vector<int>> g = generate_sparse_matrix(n);
		int res = test_stoer_wagner_algorithm(g, n);
		cout << "The min-cut is : " << res << "\n\n";
	}
	fclose(f);

	file_name="runtime_data/data_dense_stoer_wagner.dat";
	f = fopen(file_name.c_str(),"w");                          //Similar to above function
	for(int n = 2; n < 300; n+=5)
	{
		cout<<"For n = "<<n<<" : "<<endl;
		vector<vector<int>> g = generate_dense_matrix(n);
		int res = test_stoer_wagner_algorithm(g, n);
		cout << "The min-cut is : " << res << "\n\n";
	}
	fclose(f);

	file_name="runtime_data/data_very_dense_stoer_wagner.dat";
	f = fopen(file_name.c_str(),"w");                          //Similar to above function
	for(int n = 2; n < 300; n+=5)
	{
		cout<<"For n = "<<n<<" : "<<endl;
		vector<vector<int>> g = generate_very_dense_matrix(n);
		int res = test_stoer_wagner_algorithm(g, n);
		cout << "The min-cut is : " << res << "\n\n";
	}
	fclose(f);
}

int main()
{
	test_karger_algorithm_driver();           //Calls the driver function for Karger's Algorithm
	test_stoer_wagner_algorithm_driver();     //Calls the driver function for Stoer-Wagner Algorithm
	return 0;
}













