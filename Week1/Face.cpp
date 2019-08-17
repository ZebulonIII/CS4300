#include <sstream>
#include "Face.h"
#include "RubiksCube.h"

Color Face::getCenterColor() const {
	return colors[4];
}
std::string Face::toString() const {
	std::stringstream ss;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			ss << RubiksCube::colorToString(colors[i * 3 + j]) << ' ';
		ss << '\n';
	}
	return ss.str();
}