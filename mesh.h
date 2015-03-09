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
		Mesh();
				
		vector<int> edges;
		Mat4 transformation;
		

		/* Insert 2 edges into the edge matrix. */
		void insertEdge(int, int);

		/* Apply the transformation matrix */
		void transform();

		/* Transformation function overrides.
		 *
		 * This is necessary because meshes must behave differently than standar Mat4 matrices.
		 	* Mat4 matrix operations work directly on the original points themselves.
			* Mesh matrix operations will alter the transformation matrix, which will be applied right before drawing in order to maintain the integrity of the original positions of the points of the mesh.
		*/
		bool trans(double dx, double dy, double dz);
		bool scale(double a, double b, double c);
		bool rotateX(double theta);
		bool rotateY(double theta);
		bool rotateZ(double theta);

		/* Resets the transformation matrix back to the unit matrix. */
		void resetPosition();

	private:

};

#endif
