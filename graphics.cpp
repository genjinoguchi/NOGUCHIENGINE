#include <iostream>
#include <cstdlib>
#include <string>
#include "graphics.h"

using namespace std;

Graphics::Graphics(const Raster &r)
			: raster(r) {
	size_m = 0;
}

int Graphics::add_mesh(Mesh& m) {
	int temp;

	temp = meshes.size();
	
	
	return;
}

Mesh * Graphics::get_meshes() {
	return meshes;
}

void Graphics::export_graph() {
	int i,j;
	double * tmp_p;
	int * tmp_e;
	
	for (j=0;j<size_m;j++) {
		tmp_p = meshes[j].get_points();
		tmp_e = meshes[j].get_edges();
		for (i=0;i<meshes[j].get_length_e();i+=2) {
			raster.draw_line(
					tmp_p[tmp_e[i]*VECTOR_COMPS],
					tmp_p[tmp_e[i]*VECTOR_COMPS+1],
					tmp_p[tmp_e[i+1]*VECTOR_COMPS],
					tmp_p[tmp_e[i+1]*VECTOR_COMPS+1]);
		}
	}

	raster.export_ppm();
}

int Graphics::mem_m() {
	return sizeof(meshes) / sizeof(Mesh);
}

