#include <iostream>
#include <map>
#include "RubiksCube.h"

RubiksCube::RubiksCube() {}
RubiksCube::~RubiksCube() {}

void RubiksCube::initial(std::istream& is) {
	std::string color;
	for (int i = 0; i < NUM_FACES; i++) {
		Face face;
		for (int j = 0; j < FACE_SIZE ; j++) {
			is >> color;
			face[j] = stringToColor(color);
		}
		faces[(Side)i] = face;
	}
}
// rotate entire face
void RubiksCube::rotate(std::istream& is) {
	Color color;
	std::string color_str, direction;

	is >> color_str >> direction;
	if (direction != "cw" && direction != "ccw")
		return;
	color = stringToColor(color_str);
	// find face with center tile equal to color and rotate
	for (int i = 0; i < NUM_FACES; i++) {
		if (faces[(Side)i].getCenterColor() == color) {
			/*switch ((Side)i) {
				case Top:
				case Bottom:
					Face temp = faces[Bottom];
					if (direction == "cw") {
						faces[Bottom] = faces[Right2];
						faces[Right2] = faces[Top];
						faces[Top] = faces[Center];
						faces[Center] = temp;
					}
					else { // ccw
						faces[Bottom] = faces[Center];
						faces[Center] = faces[Top];
						faces[Top] = faces[Right2];
						faces[Right2] = temp;
					}
					return;
				case Left:
				case Right1:
					Face temp = faces[Left];
					if (direction == "cw") {
						faces[Left] = faces[Center];
						faces[Center] = faces[Right1];
						faces[Right1] = faces[Right2];
						faces[Right2] = temp;
					}
					else { // ccw
						faces[Left] = faces[Right2];
						faces[Right2] = faces[Right1];
						faces[Right1] = faces[Center];
						faces[Center] = temp;
					}
					return;
				default: return;
			}*/
			return;
		}
	}
	// shouldn't reach here
	throw "Error in rotate";
}
void RubiksCube::show(std::ostream& os) {
	for (int i = 0; i < NUM_FACES; i++)
		os << faces[(Side)i].toString() << "\n\n";
}
void RubiksCube::isequal(std::istream& is, std::ostream& os) {
	std::string color;  
	for (int i = 0; i < NUM_FACES; i++) {
		Face& face = faces[(Side)i];		
		for (int j = 0; j < FACE_SIZE ; j++) {
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
