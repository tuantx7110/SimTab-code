#ifndef GRAPH_H
#define GRAPH_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

class Graph
{
public:
	int n;	//number of nodes
	int m;	//number of edges
	int** inAdjList;
	int** outAdjList;
	int* indegree;
	int* outdegree;

	Graph(){
		
	}

	~Graph(){
	
	}
	
	void inputGraph(string filename){
		m=0;
		ifstream infile(filename.c_str());
		infile >> n;

		indegree=new int[n];
		outdegree=new int[n];
		for(int i=0;i<n;i++){
			indegree[i]=0;
			outdegree[i]=0;
		}
		//read graph and get degree info
		int from;
		int to;
		while(infile>>from>>to){
			outdegree[from]++;
			indegree[to]++;
		}

		inAdjList=new int*[n];
		outAdjList=new int*[n];
		for(int i=0;i<n;i++)
		{
			inAdjList[i]=new int[indegree[i]];
			indegree[i] = 0;
			outAdjList[i]=new int[outdegree[i]];
			outdegree[i] = 0;
		}
		
		infile.clear();
		infile.seekg(0);

		clock_t t1=clock();
		infile >> n;
		cout << "Vertice num = " << n << endl;
		while(infile>>from>>to){
			outAdjList[from][outdegree[from]]=to;
			outdegree[from]++;
			inAdjList[to][indegree[to]]=from;
			indegree[to]++;

			m++;
		}
		infile.close();
		clock_t t2 = clock();
		cout << "Edge num = " << m << endl;
		cout << "loading graph takes " << (t2-t1)/(double)CLOCKS_PER_SEC << " s." << endl;
	}
	int getInSize(int vert){
		return indegree[vert];
	}
	int getInVert(int vert, int pos){
		return inAdjList[vert][pos];
	}
	int getOutSize(int vert){
		return outdegree[vert];
	}
	int getOutVert(int vert, int pos){
		return outAdjList[vert][pos];
	}

};


#endif
