#include<iostream>
#include "Graph.h"

// https://acmp.ru/asp/do/index.asp?main=topic&id_course=2&id_section=21&id_topic=49

int main(int argc, char* argv[])
{
	Graph g;

	/*
	g.readMatrix();
	g.printMatrix();
	g.printAdjencyList();
	g.printEdgeList();
	std::cout << "\n\n";
	g.readAdjencyList();
	g.printMatrix();
	g.printAdjencyList();
	g.printEdgeList();
	std::cout << "\n\n";
	g.readEdgeList();
	g.printMatrix();
	g.printAdjencyList();
	g.printEdgeList();
	*/

	int verts;

	std::cin >> verts;
	g.readEdgeListNoOrient(verts, verts - 1);

	g.printMatrix();

	return EXIT_SUCCESS;
}