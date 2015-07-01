#include "Graph.h"
#include "Singleton.hpp"

int main()
{
	Graph g = Singleton<Graph>::instance();
	g.test();
	Graph g1 = Singleton<Graph>::instance();
	g1.test();
	system("pause");
	return 0;
}