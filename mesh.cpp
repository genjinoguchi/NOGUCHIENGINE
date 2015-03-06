#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "mesh.h"

using namespace std;


Mesh::Mesh() {
}


/*
 * int insert_point();
 *
 * ARGS:
 * 		double x, y, z
 * 		double s
 *		OVERLOAD:
 * 		double * - a single point as a 4x1 matrix.
 * RETURNS:
 * 		the point's position inside the point matrix
 * 
 * Copies the point information into the point matrix.
 * Will resize the memory of the point matrix if necessary.
 *
 */
int Mesh::insert_point(double x, double y, double z, double s) {
	cout << "\ninsert point" << endl;
	if (length_p == size_p) {
		cout <<"expanding point matrix" << endl;
		//expand_pm();
	} else if (length_p <= (size_p/4) &&
			   length_p < MIN_MAT_SIZE) {
		cout << "reducing point matrix" << endl;
		//reduce_pm();
	}

	cout << "A : no segfault here" << endl;

	int tmp;
	cout << "Inserting to index: " << to_string(length_p) << endl;
	points[length_p*VECTOR_COMPS+0] = x;
	points[length_p*VECTOR_COMPS+1] = y;
	points[length_p*VECTOR_COMPS+2] = z;
	points[length_p*VECTOR_COMPS+3] = s;

	cout << "B : no segfault here" << endl;

	tmp = length_p;
	length_p++;
	return tmp;

}
int Mesh::insert_point(double * p) {
	return insert_point(p[0],p[1],p[2],p[3]);
}
double * Mesh::get_points() {
	return points;
}


/*
 * Inserting edges
 *
 * void insert_edge()
 * ARGS:
 * 		int p1, int p2
 * 
 * Inserts p1 and p2, indices of points in the point matrix, into the edge matrix.
 */
void Mesh::insert_edge(int p1, int p2) {
	// Insert resizing code here

	edges[length_e] = p1;
	edges[length_e+1] = p2;

	length_e += 2;
}

int * Mesh::get_edges() {
	return edges;
}


/* 
 * More getters and setters
 */
int Mesh::get_size_p() { return size_p; }
int Mesh::get_size_e() { return size_e; }
int Mesh::get_length_p() { return length_p; }
int Mesh::get_length_e() { return length_e; }




/*
 * Memory Management
 * 
 * void expand_pm()-- double the size of point matrix 
 * void reduce_pm()-- halve the size of the point matrix 
 * void expand_em()-- double the size of the edge matrix
 * void reduce_em()-- halve the size of the edge matrix
 *
 */
/*
void Mesh::expand_pm() {
	points = (double **)realloc(points, size_p*2);
	size_p *= 2;
}
void Mesh::reduce_pm() {
	points = (double **)realloc(points, size_p/2);
	size_p /= 2;
}
void Mesh::expand_em() {
	edges = (int *)realloc(edges, size_e*2);
	size_e *= 2;
}
void Mesh::reduce_em() {
	edges = (int *)realloc(edges, size_e/2);
	size_e /= 2;
}
*/


/*
 * void print_points();
 */
void Mesh::print_points() {
	int i,j;

	for (i=0; i<length_p; i++) {
		for (j=0; j<4; j++) {
			cout << to_string(points[i*VECTOR_COMPS+j]) << " ";
		}
		cout << endl;
	}
}
