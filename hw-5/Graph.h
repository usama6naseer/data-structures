#ifndef GRAPH__H
#define GRAPH__H
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
#include "pqueue.h"
#include <map>

using namespace std;
class node;

class edge
{
	public:
		node* Origin;
		node* Dest;
		float weight;	
		friend bool operator < (edge a, edge b);
		friend bool operator == (edge a, edge b);
		friend bool operator > (edge a, edge b);
		edge() {
			Origin = NULL;
			Dest = NULL;
			weight = 0;
		}
};
class node
{
	public:
		int visit; // flag to check if the node has been already visited
		float dist;
		string name;
		node* prev;

		float x,y; // coordinates of node
		vector<edge> edges; // edges connected to node
		friend bool operator < (node a, node b);
		friend bool operator == (node a, node b);
		friend bool operator > (node a, node b);
		node() {
			name = "";
			dist = 999999;
			prev = NULL;
			x = 0;
			y = 0;
			visit = 0;
		}
};
class tree
{
	public:
		set<node*> treeS;
		tree() {}
		void insert(node* n);
		bool if_present(node* n);
		void merge(set<node*> t);
};

class Graph
{
	public:
		vector<node*> Mst; // minimum spanning tree
		vector<node*> cities;
		vector<edge> arcs;
		map<string, int> place;

		Graph() {}
		Graph(char*);
		node* getCity(string s);
		vector<node*> Kruskal(); //runs kruskal algorithm and returns the Minimum spanning tree
		void display(node*);// displays the graph
		vector<string> Dijkstra(string, string, float &);
};

#endif
