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
	void readMatrix();
	void readAdjencyList();
	void readEdgeList();
	void readEdgeListNoOrient();

	void printMatrix();
	void printAdjencyList();
	void printEdgeList();

	void printSource(void);
	void printDrain(void);
	int vertexCountAdjency(int v);
	bool isRegular(void);
	void printVertexCountAdjency();
	bool isOrient(void);
	bool isFull(void);
};


Graph::Graph()
{
}

Graph::Graph(const Graph& graph)
{
	m.init(graph.m.verts);
	for (int i = 0; i < m.verts; ++i)
	{
		for (int j = 0; j < m.verts; ++j)
		{
			m.data[i][j] = graph.m.data[i][j];
		}
	}
}

Graph::~Graph()
{
	m.free();
}

void Graph::readMatrix()
{
	int verts = 0;
	std::cin >> verts;
	m.init(verts + 1); //todo: сделать так чтобы тут не было +1
	for (int i = 1; i < m.verts; ++i)
	{
		for (int j = 1; j < m.verts; ++j)
		{
			std::cin >> m.data[i][j];
		}
	}
}

void Graph::readAdjencyList()
{
	int verts = 0;
	std::cin >> verts;
	m.init(verts + 1);
	for (int from = 1; from < m.verts; ++from)
	{
		int count = 0;
		std::cin >> count;
		for (int j = 0; j < count; ++j)
		{
			int to = 0;
			std::cin >> to;
			m.data[from][to] = 1;
		}
	}
}

void Graph::readEdgeList()
{
	int verts = 0;
	std::cin >> verts;
	m.init(verts + 1);
	int edges = 0;
	std::cin >> edges;
	for (int i = 0; i < edges; ++i)
	{
		int a = 0;
		int b = 0;
		std::cin >> a >> b;
		m.data[a][b] = 1;
	}
}

void Graph::readEdgeListNoOrient()
{
		int verts = 0;
	std::cin >> verts;
	m.init(verts + 1);
	int edges = 0;
	std::cin >> edges;
	for (int i = 0; i < edges; ++i)
	{
		int a = 0;
		int b = 0;
		std::cin >> a >> b;
		m.data[a][b] = 1;
		m.data[b][a] = 1;
	}
}

void Graph::printMatrix()
{
	std::cout << m.verts - 1 << "\n";
	for (int i = 1; i < m.verts; ++i)
	{
		for (int j = 1; j < m.verts; ++j)
		{
			std::cout << m.data[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void Graph::printAdjencyList()
{
	std::cout << m.verts - 1 << "\n";
	for (int i = 1; i < m.verts; ++i)
	{
		std::cout << m.edgesFrom(i) << " ";
		for (int j = 1; j < m.verts; ++j)
		{
			if (m.data[i][j] != 0)
			{
				std::cout << j << " ";
			}
		}
		std::cout << "\n";
	}
}

void Graph::printEdgeList()
{
	std::cout << m.verts - 1 << " " << m.edges() << "\n";
	for (int i = 1; i < m.verts; ++i)
	{
		for (int j = 1; j < m.verts; ++j)
		{
			if (m.data[i][j] != 0)
			{
				std::cout << i << " " << j << "\n";
			}
		}
	}
}

void Graph::printSource(void)
{
	if (m.isInit())
	{
		int nums = 0;

		for (int i = 1; i < m.verts; ++i)
		{
			bool is_source = true;
			for (int j = 1; j < m.verts; ++j)
			{
				if (m.data[j][i] == 1)
				{
					is_source = false;
				}
			}
			if (is_source)
			{
				nums += 1;
			}
		}

		std::cout << nums << " ";

		for (int i = 1; i < m.verts; ++i)
		{
			bool is_source = true;
			for (int j = 1; j < m.verts; ++j)
			{
				if (m.data[j][i] == 1)
				{
					is_source = false;
				}
			}
			if (is_source)
			{
				std::cout << i << " ";
			}
		}

		std::cout << "\n";
	}
}

void Graph::printDrain(void)
{
	if (m.isInit())
	{
		int nums = 0;

		for (int i = 1; i < m.verts; ++i)
		{
			bool is_source = true;
			for (int j = 1; j < m.verts; ++j)
			{
				if (m.data[i][j] == 1)
				{
					is_source = false;
				}
			}
			if (is_source)
			{
				nums += 1;
			}
		}

		std::cout << nums << " ";

		for (int i = 1; i < m.verts; ++i)
		{
			bool is_source = true;
			for (int j = 1; j < m.verts; ++j)
			{
				if (m.data[i][j] == 1)
				{
					is_source = false;
				}
			}
			if (is_source)
			{
				std::cout << i << " ";
			}
		}

		std::cout << "\n";
	}
}

int Graph::vertexCountAdjency(int v)
{
	if (v <= 0 || v >= m.verts)
	{
		throw;
	}

	int sum_adjency = 0;

	for (int j = 1; j < m.verts; ++j)
	{
		sum_adjency += m.data[v][j];
	}

	return sum_adjency;
}

bool Graph::isRegular(void)
{
	int vert_adj = vertexCountAdjency(1);

	for (int i = 1; i < m.verts; ++i)
	{
		if (vert_adj != vertexCountAdjency(i))
		{
			return false;
		}
	}

	return true;
}

void Graph::printVertexCountAdjency()
{
	if (m.isInit())
	{
		for (int i = 1; i < m.verts; ++i)
		{
			std::cout << vertexCountAdjency(i) << " ";
		}
	}
}

bool Graph::isOrient(void)
{
	if (m.isInit())
	{
		for (int i = 1; i < m.verts; ++i)
		{
			if (m.data[i][i] == 1)
			{
				return false;
			}
		}

		for (int i = 1; i < m.verts; ++i)
		{
			for (int j = i + 1; j < m.verts; ++j)
			{
				if (m.data[i][j] != m.data[j][i])
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool Graph::isFull(void)
{
	if (m.isInit())
	{
		for (int i = 1; i < m.verts; ++i)
		{
			for (int j = i + 1; j < m.verts; ++j)
			{
				if (!(m.data[i][j] == 1 && m.data[j][i] == 1))
				{
					return false;
				}
			}
		}

	}

	return true;
}


int main(int argc, char* argv[])
{
	Graph g;
	g.readMatrix();
	g.printSource();
	g.printDrain();
	return EXIT_SUCCESS;
}