#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <vector>
#include "mesh.h"
#include "raster.h"
#include "vect4.h"

using namespace std;

class Graphics {
	public:
		Graphics();

		vector<Mesh> meshes;
		Raster raster;
	
		int addMesh(Mesh&);
		Mesh * getMeshes();

		void exportGraph();
		void display();
	private:		
};

#endif
