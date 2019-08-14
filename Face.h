#ifndef _FACE_H_
#define _FACE_H_

#include <string>
#include "RubiksCube.h"

enum Color;

class Face {
private:
	Color colors[9];

public:
	const static int SIZE = 9;

	Face();
	~Face();

	Color getCenterColor() const;
	std::string toString() const;
	Color& operator[] (const int& i) {
		return colors[i];
	}
};

#endif