#include <iostream>
#include "graphics.h"
#include "raster.h"
#include "matrix.h"

using namespace std;

int main() {
	Mesh m;
	Graphics g;

	int p1,p2,p3,p4;
	int m1;


	p1 = m.insert(10,10,0,1);
	p2 = m.insert(100,10,0,1);
	p3 = m.insert(100,100,0,1);
	p4 = m.insert(10,100,0,1);
		
	m.insertEdge(p1,p2);
	m.insertEdge(p2,p3);
	m.insertEdge(p3,p4);
	m.insertEdge(p4,p1);

	//m.insertEdge(p4,p1);
	m.toString();

	m1 = g.addMesh(m);
	g.exportGraph();

	cout << "Done." << endl;

}
