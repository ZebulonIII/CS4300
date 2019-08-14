#include <iostream>
#include <map>
#include "RubiksCube.h"

RubiksCube::RubiksCube() {}
RubiksCube::~RubiksCube() {}

void RubiksCube::initial(std::istream& is) {
	std::string color;
	for (int i = 0; i < NUM_FACES; i++) {
		Face face;
		for (int j = 0; j < Face::SIZE; j++) {
			is >> color;
			face[j] = stringToColor(color);
		}
		faces[(Side)i] = face;
	}
}
void RubiksCube::rotate(std::istream& is) {
	Color color;
	std::string color_str, direction;

	is >> color_str >> direction;
	if (direction != "cw" && direction != "ccw")
		return;
	color = stringToColor(color_str);
	// find face with center tile equal to color and rotate
	Face face;
	for (int i = 0; i < NUM_FACES; i++)
		if (faces[(Side)i].getCenterColor() == color) {

			return;
		}
	// shouldn't reach here
	throw "Error in rotate";
}
void RubiksCube::show(std::ostream& os) {
	for (int i = 0; i < NUM_FACES; i++) {
		os << faces.at((Side)i).toString() << "\n\n";
	}
}
void RubiksCube::isequal(std::istream& is, std::ostream& os) {
	std::string color;
  
	for (int i = 0; i < NUM_FACES; i++) {
		Face& face = faces[(Side)i];
		
		for (int j = 0; j < Face::SIZE; j++) {
			is >> color;
			if (face[j] != stringToColor(color)) {
				os << "FALSE";
				return;
			}
		}
	}
	os << "TRUE";
}
Color RubiksCube::stringToColor(const std::string& side) const {
	switch (side[0]) {
	case 'w': return Color::White;
	case 'y': return Color::Yellow;
	case 'g': return Color::Green;
	case 'o': return Color::Orange;
	case 'b': return Color::Blue;
	case 'r': return Color::Red;
	default: throw "Invalid String";
	}
}
std::string RubiksCube::colorToString(const Color& color) const {
	switch (color) {
	case Yellow: return "yellow";
	case Green: return "green";
	case Blue: return "blue";
	case Red: return "red";
	case White: return "white";
	case Orange: return "orange";
	default: throw "Invalid Color";
	}
}