#include <iostream>
#include <map>
#include "RubiksCube.h"
#include "Face.h"

RubiksCube::RubiksCube() {}
RubiksCube::~RubiksCube() {}
void RubiksCube::initial(std::istream& is) {
	std::string color;
	for (int i = 0; i < NUM_FACES; i++) {
		Face* face = new Face();
		for (int j = 0; j < FACE_SIZE ; j++) {
			is >> color;
			face->at(j) = stringToColor(color);
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
	Side s;
	for (int i = 0; i < NUM_FACES; i++) {
		s = static_cast<Side>(i);
		if (faces[s]->getCenterColor() == color) {
			Face* temp;
			switch (s) {
				case Top:
				case Bottom:
					temp = faces[Bottom];
					if (direction == "cw") {
						faces[Bottom] = faces[Right2];
						faces[Right2] = faces[Top];
						faces[Top]	  = faces[Center];
						faces[Center] = temp;
					}
					else { // ccw
						faces[Bottom] = faces[Center];
						faces[Center] = faces[Top];
						faces[Top]	  = faces[Right2];
						faces[Right2] = temp;
					}
					return;
				case Left:
				case Right1:
				case Center:
				case Right2:
					temp = faces[Left];
					if (direction == "cw") {
						faces[Left]	  = faces[Center];
						faces[Center] = faces[Right1];
						faces[Right1] = faces[Right2];
						faces[Right2] = temp;
					}
					else { // ccw
						faces[Left]	  = faces[Right2];
						faces[Right2] = faces[Right1];
						faces[Right1] = faces[Center];
						faces[Center] = temp;
					}
					return;
				default:
					throw "Error in rotate";
			}
			return;
		}
	}
	// shouldn't reach here
	throw "Error in rotate";
}
void RubiksCube::show(std::ostream& os) {
	for (int i = 0; i < NUM_FACES; i++)
		os << faces[(Side)i]->toString() << '\n';
}
void RubiksCube::isequal(std::istream& is, std::ostream& os) {
	std::string color;  
	for (int i = 0; i < NUM_FACES; i++) {
		Face* face = faces[(Side)i];		
		for (int j = 0; j < FACE_SIZE ; j++) {
			is >> color;
			if (face->at(j) != stringToColor(color)) {
				os << "FALSE\n";
				return; // no need for more comparisons
			}
		}
	}
	os << "TRUE\n";
}
const Color RubiksCube::stringToColor(const std::string& side) {
	switch (side[0]) {
		case 'w': return Color::White;
		case 'y': return Color::Yellow;
		case 'g': return Color::Green;
		case 'o': return Color::Orange;
		case 'b': return Color::Blue;
		case 'r': return Color::Red;
		default:  throw "Invalid String";
	}
}
const std::string RubiksCube::colorToString(const Color& color) {
	switch (color) {
		case Yellow: return "yellow";
		case Green:  return "green";
		case Blue:	 return "blue";
		case Red:	 return "red";
		case White:	 return "white";
		case Orange: return "orange";
		default:	 throw "Invalid Color";
	}
}
