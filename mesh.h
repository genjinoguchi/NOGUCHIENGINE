#ifndef MESH_H
#define MESH_H

#include <vector>
#include "vect4.h"
#include "matrix.h"
#include "raster.h"
#define MIN_MAT_SIZE 64
#define VECTOR_COMPS 4

using std::vector;

class Mesh : public Mat4 {
	
	public:
		vector<int> edges;
		
		Mesh();

		// Insert 2 edges into the edge matrix.
		void insertEdge(int, int);

	private:

};

#endif
