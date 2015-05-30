#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int minIndex(const vector<int> &vec, const vector<bool> &mst_set)
{
	int min=INT_MAX; // assuming all the edges are positive
	int min_index=-1;
	for(int i=0; i<vec.size(); i++)
	{
		if(vec[i] < min && mst_set[i] == false)
		{ 
			min = vec[i];
			min_index = i;
		}
	}
	return min_index;
}

void mst(vector< vector<int> > &graph)
{
	vector<bool> mst_set(graph.size(), false);
	// int count_mst_set = 0; // Initially mst_set is empty.
	vector<int> edge_costs(graph.size(), INT_MAX);
	edge_costs[0] = 0;
	vector<int> parent(graph.size());
	for(int i=0; i<mst_set.size(); i++)
	{
		int min_edge_ind = minIndex(edge_costs, mst_set);
		mst_set[min_edge_ind] = true;
		for(int j=0; j<graph.size(); j++)
		{
			if(graph[min_edge_ind][j]>0 && mst_set[j] == false && edge_costs[j] > graph[min_edge_ind][j])
			{
				edge_costs[j] = graph[min_edge_ind][j];
				parent[j] = min_edge_ind;
			}
		}
	}
	for(int i=1; i<parent.size(); i++)
		cout << i << "----" << parent[i] << " = " << graph[i][parent[i]] << endl;
}

void printGraph(vector< vector<int> > &graph)
{
	cout << "Graph printed in the form of Adjacency Matrix:" << endl;
	for(int i=0; i<graph.size(); i++)
	{
		for(int j=0; j<graph[i].size(); j++)
		{
			cout << graph[i][j] << ", ";
		}
		cout << endl;
	}
}

int main()
{
	// Only valid for a c++11 compiler
	vector< vector<int> > graph = { {0, 2, 1, 0, 0, 0, 0, 0},
								{2, 0, 0, 3, 1, 0, 5, 0},
								{1, 0, 0, 0, 0, 4, 0, 0},
								{0, 3, 0, 0, 0, 1, 4, 2},
								{2, 1, 0, 0, 0, 2, 0, 0},
								{0, 0, 4, 1, 2, 0, 0, 3},
								{0, 5, 0, 4, 0, 0, 0, 0},
								{0, 0, 0, 2, 0, 3, 0, 0} };

	// vector< vector<int> > graph = {{0, 2, 0, 6, 0},
 //                      {2, 0, 3, 8, 5},
 //                      {0, 3, 0, 0, 7},
 //                      {6, 8, 0, 0, 9},
 //                      {0, 5, 7, 9, 0},
 //                     };

	// vector< vector<int> > graph = {{0, 1, 1, 0},
	// 							   {1, 0, 2, 3},
	// 							   {1, 2, 0, 0},
	// 							   {0, 3, 0, 0}};
	// printGraph(graph);
	mst(graph);
	return 0;
}