#include "Graph.h"

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

int Graph::getCountVertex(void)
{
	return m.isInit() ? m.verts - 1 : 0;
}

int Graph::getCountAdjency(void)
{
	int res = 0;

	if (m.isInit())
	{
		for (int i = 1; i < m.verts; ++i)
		{
			res += vertexCountAdjency(i);
		}
	}

	return res;
}

void Graph::readMatrix(int verts)
{
	if (verts == 0)
	{
		std::cin >> verts;
	}

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

void Graph::readEdgeListNoOrient(int verts, int edges)
{
	if (verts == 0)
	{
		std::cin >> verts;
	}
	
	m.init(verts + 1);
	
	if (edges == 0)
	{
		std::cin >> edges;
	}

	for (int i = 0; i < edges; ++i)
	{
		int a = 0;
		int b = 0;
		std::cin >> a >> b;
		m.data[a][b] = 1;
		m.data[b][a] = 1;
	}
}

int Graph::readEdgeListOnceArc()
{
	bool res = true;
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
		if (m.data[a][b] == 1)
		{
			res = false;
		}
		m.data[a][b] = 1;
	}

	return res;
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

	for (int i = 1; i < m.verts; ++i)
	{
		sum_adjency += m.data[v][i];
	}

	return sum_adjency;
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

int Graph::vertexCountArc(int v)
{
	if (v <= 0 || v >= m.verts)
	{
		throw;
	}

	int sum_adjency = 0;

	for (int i = 1; i < m.verts; ++i)
	{
		sum_adjency += m.data[v][i];
	}
	for (int i = 1; i < m.verts; ++i)
	{
		sum_adjency += m.data[i][v];
	}

	return sum_adjency;
}

void Graph::printVertexCountArc(void)
{
	if (m.isInit())
	{
		for (int i = 1; i < m.verts; ++i)
		{
			std::cout << vertexCountArc(i) << " ";
		}
	}
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

bool Graph::isNoLoop(void)
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
	}
	return true;
}

bool Graph::isTournament(void)
{
	if (!isNoLoop())
	{
		return false;
	}
	if (m.isInit())
	{
		for (int i = 1; i < m.verts; ++i)
		{
			for (int j = i + 1; j < m.verts; ++j)
			{
				if (m.data[i][j] == m.data[j][i])
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool Graph::isOrient(void)
{
	if (m.isInit())
	{
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

int Graph::getAdjency(int v1, int v2)
{
	if (!(0 < v1 && v1 < m.verts && 0 < v2 && v2 < m.verts && m.isInit()))
	{
		throw;
	}

	return m.data[v1][v2];
}

bool Graph::isAdjency(int v1, int v2)
{
	if (!(0 < v1 && v1 < m.verts && 0 < v2 && v2 < m.verts && m.isInit()))
	{
		throw;
	}

	return !!m.data[v1][v2];
}

