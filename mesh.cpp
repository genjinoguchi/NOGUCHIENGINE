#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "mesh.h"

using namespace std;


Mesh::Mesh() {

}

/*
 * Inserting edges
 *
 * void insert_edge()
 * ARGS:
 * 		int p1, int p2
 * Inserts p1 and p2, indices of points in the point matrix, into the edge matrix.
 */
void Mesh::insertEdge(int p1, int p2) {
	edges.push_back(p1);
	edges.push_back(p2);
}


