#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "mesh.h"

using namespace std;


Mesh::Mesh() {
}

void Mesh::insertEdge(int a, int b) {
	edges.push_back(a);
	edges.push_back(b);
}
