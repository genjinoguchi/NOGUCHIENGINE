#ifndef LOADER_H
#define LOADER_H

#include <string>

/*
 * Container class for loading in drawing files.
 */
class Loader {

	public:

		static loadObj(string filename);


		/*
		 * Loads in a mesh using Mr. DW's file syntax.
		 *
		 * Syntax: 
		 * l: add a line to the point matrix -  takes 6 arguemnts (x0, y0, z0, x1, y1, z1)
		 * i: set the transform matrix to the identity matrix
		 * s: create a scale matrix, then multiply the transform matrix by the scale matrix -  takes 3 arguments (sx, sy, sz)
		 * t: create a translation matrix, then multiply the transform matrix by the translation matrix - takes 3 arguments (tx, ty, tz)
		 * x: create an x-axis rotation matrix, then multiply the transform matrix by the rotation matrix - takes 1 argument (theta)
		 * y: create an y-axis rotation matrix, then multiply the transform matrix by the rotation matrix - takes 1 argument (theta)
		 * z: create an z-axis rotation matrix, then multiply the transform matrix by the rotation matrix - takes 1 argument (theta)
		 * a: apply the current transformation matrix to the edge matrix
		 * v: draw the lines of the point matrix to the screen, display the screen (not applicable for java)
		 * g: draw the lines of the point matrix to the screen/frame save the screen/frame to a file - takes 1 argument (file name)
		 * 
		 *
		 * NOTE : commands are separated from the arguments by a new line
		 * NOTE : arguments are separated by a single space
		 */
		static loadDWFile(string filename);






};
