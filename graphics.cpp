#include <iostream>
#include <cstdlib>
#include <string>
#include "graphics.h"

using namespace std;

Graphics::Graphics() {
	
}

int Graphics::addMesh(Mesh& m) {
	meshes.push_back(m);
	return meshes.size()-1;
}

void Graphics::exportGraph() {
	int i,j;
	vector<Vect4> p;
	vector<int> e;
	
	for (j=0;j<meshes.size();j++) {
		p = meshes[j].data;
		e = meshes[j].edges;
		cout << "e.size() " << to_string(e.size()) << endl;
		for (i=0;i<e.size();i+=2) {
			raster.drawLine(
				p[e[i]].x,	
				p[e[i]].y,	
				p[e[i+1]].x,	
				p[e[i+1]].y
			);
		}
	}

	raster.exportPPM();
}


