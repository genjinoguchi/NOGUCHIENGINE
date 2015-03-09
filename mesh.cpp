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

void Mesh::transform() {
	apply(transformation);
}


// Transformation Function Overrides
bool Mesh::trans(double dx, double dy, double dz) {
	transformation.apply(transMatrix(dx,dy,dz));
	return true;
}
bool Mesh::scale(double a, double b, double c) {
	transformation.apply(scaleMatrix(a,b,c));
	return true;
}
bool Mesh::rotateX(double theta) {
	transformation.apply(rotXMatrix(theta));
	return true;
}
bool Mesh::rotateY(double theta) {
	transformation.apply(rotYMatrix(theta));
	return true;
}
bool Mesh::rotateZ(double theta) {
	transformation.apply(rotZMatrix(theta));
	return true;
}

void Mesh::resetPosition() {
	transformation = identity();
}
