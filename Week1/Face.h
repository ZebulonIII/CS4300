#ifndef _FACE_H_
#define _FACE_H_

#include <string>

enum Color : int;

class Face {
private:
	Color colors[9];

public:
	Face() {}
	~Face() {}

	Color getCenterColor() const;
	std::string toString() const;
	Color& operator[] (const int& i) {
		return colors[i];
	}
	Color operator[] (const int& i) const {
		return colors[i];
	}
};

#endif