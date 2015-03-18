#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "mesh.h"

using namespace std;

Mesh::Mesh() {
	transformation = identity();
}


void Mesh::insertEdge(int a, int b) {
	edges.push_back(a);
	edges.push_back(b);
}

/* Circle Functions */
void Mesh::insertCircle(double cx, double cy, double r) {
	double t;
	double  x,  y,
		   x0, y0;

	x0 = cx + r;
	y0 = cy;
	for( t=0; t<=1+STEP_SIZE; t+=STEP_SIZE ) {
		x = cx + r*unitCircleX(t);
		y = cy + r*unitCircleY(t);
		insertEdge(insert(x0,y0,0,1), insert(x,y,0,1));
		x0 = x;
		y0 = y;
	}
}
inline double Mesh::unitCircleX(double t) {
	return cos(t*2*M_PI);
}
inline double Mesh::unitCircleY(double t) {
	return sin(t*2*M_PI);
}

void Mesh::applyTransformation() {
	apply(transformation);
}
Mat4 Mesh::transformPoints() {
	return Mat4::mult(transformation, *this);
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
