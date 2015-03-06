#include <iostream>
#include "graphics.h"
#include "raster.h"
#include "matrix.h"

using namespace std;

int main() {
	Mesh m;
	Graphics g;

	int p1,p2,p3,p4,p5,p6;
	int m1;


	p1 = m.insert(210,210,0,1);
	p2 = m.insert(300,210,0,1);
	p3 = m.insert(300,300,0,1);
	p4 = m.insert(210,300,0,1);
	p5 = m.insert(400,300,0,1);
	p6 = m.insert(300,400,0,1);


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
