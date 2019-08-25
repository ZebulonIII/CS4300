#ifndef _FACE_H_
#define _FACE_H_

#define FACE_SIZE 9

#include <string>

enum Color : int;

class Face {
private:
	Color colors[FACE_SIZE];

public:
	Face();
	~Face();

	Color getCenterColor() const;
	std::string toString() const;
	Color& at(const int& i) {
		return colors[i];
	}
	Color at(const int& i) const {
		return colors[i];
	}
	Color& operator[] (const int& i) {
		return colors[i];
	}
	Color operator[] (const int& i) const {
		return colors[i];
	}
};

#endif