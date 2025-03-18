#include<iostream>
#pragma once

struct Matrix
{
	int verts;
	int** data;
	Matrix() : verts(0), data(nullptr) {} 
	void free()
	{
		if (data != nullptr)
		{
			for (int i = 0; i < verts; ++i)
			{
				delete[] data[i];
			}
			delete[] data;
			data = nullptr;
		}
	}
	void init(int verts)
	{
		if (data != nullptr)
		{
			free();
		}
		this->verts = verts;
		data = new int* [verts] { 0 };
		for (int i = 0; i < verts; ++i)
		{
			data[i] = new int[verts] { 0 };
		}
	}
	int edgesFrom(int i)
	{
		int count = 0;
		for (int j = 1; j < verts; ++j)
		{
			count += (data[i][j] == 0 ? 0 : 1);
		}
		return count;
	}
	int edges()
	{
		int count = 0;
		for (int i = 1; i < verts; ++i)
		{
			count += edgesFrom(i);
		}
		return count;
	}

	bool isInit(void)
	{
		return (data != nullptr);
	}

};

struct Edge
{
	int from;
	int to;
};

struct EdgeList
{
	int count;
	Edge* edges;
};

struct AdjencyList
{
	int verts;
	int** adjencies;
};

class Graph
{
private:
	Matrix m;

public:
	Graph();
	Graph(const Graph& graph);
	~Graph();

	int getArc(int v1, int v2);
	bool isArc(int v1, int v2);

	int getCountVertex(void);

	void readMatrix(int verts = 0);
	void readAdjencyList();
	void readEdgeList();
	void readEdgeListNoOrient(int verts = 0, int edges = 0);
	int readEdgeListOnceArc();
	void readToNextArc(int verts = 0);

	void printMatrix();
	void printAdjencyList();
	void printEdgeList();

	void printSource(void);
	void printDrain(void);
	int vertexCountAdjency(int v);
	void printCountAdjency();

	int vertexCountArc(int v);
	void printCountArc(void);

	bool isRegular(void);
	bool isNoLoop(void);
	bool isTournament(void);
	bool isOrient(void);
	bool isFull(void);
};
