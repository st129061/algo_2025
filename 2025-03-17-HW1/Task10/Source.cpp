
#include<iostream>

struct Matrix
{
	int verts;
	bool** data;
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
		data = new bool* [verts] { 0 };
		for (int i = 0; i < verts; ++i)
		{
			data[i] = new bool[verts] { 0 };
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

	void readToNextArc(int verts = 0);
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

void Graph::readToNextArc(int verts)
{
	if (verts == 0)
	{
		std::cin >> verts;
	}
	m.init(verts + 1);
	for (int i = 2; i < m.verts; ++i)
	{
		int a = 0;

		std::cin >> a;
		m.data[i][a] = 1;
	}
}

int Graph::getCountVertex(void)
{
	return m.isInit() ? m.verts - 1 : 0;
}

int Graph::getArc(int v1, int v2)
{
	if (!(0 < v1 && v1 < m.verts && 0 < v2 && v2 < m.verts && m.isInit()))
	{
		return -1;
	}

	return m.data[v1][v2];
}

bool Graph::isArc(int v1, int v2)
{
	if (!(0 < v1 && v1 < m.verts && 0 < v2 && v2 < m.verts && m.isInit()))
	{
		return 0;
	}

	return !!m.data[v1][v2];
}

int main(int argc, char* argv[])
{
	Graph g;

	// std::cout << g.solutionTask10();

	int verts = 0;
	int otd[2] = {0, 0};

	std::cin >> verts >> otd[0] >> otd[1];
	
	verts = std::max(std::max(verts, otd[0]), otd[1]);


	int * my_graph = new int[verts + 1];

	for (int j = 2; j < verts + 1; ++j)
	{
		int tmp;
		
		std::cin >> tmp;
		my_graph[j] = tmp;
	}

	bool * way_mass[2] = {new bool[verts + 1] { 0 }, new bool[verts + 1] { 0 }};

	for (int i = 0; i < 2; ++i)
	{
		int start = otd[i];
		way_mass[i][start] = 1;

		while (start != 1)
		{
			start = my_graph[start];
			way_mass[i][start] = 1;
		}
	}

	for (int i = verts; i > 0; --i)
	{
		if (way_mass[0][i] == 1 && way_mass[1][i] == 1)
		{
			std::cout << i;
			break;
		}
	}

	delete[] way_mass[0];
	delete[] way_mass[1];

	delete[] my_graph;

	return EXIT_SUCCESS;
}