#pragma once  
#include "GraphLists.h"  
class Game1  
{  
	int _w = 0;  
	int _l = 0;  
	int _s = 0;  

public:  
	GraphList _gL;  
	Game1(int l, int w, int s) : _l(l), _w(w), _s(s) { _gL.MakeEmptyGraph(l, s); }  
	void buildG();
	vector<Vertex> BFS(const Vertex& start, const Vertex& goal);



};
