#ifndef _RUBIKSCUBE_H_
#define _RUBIKSCUBE_H_

#define NUM_FACES 6

#include <string>
#include <map>
#include "Face.h"

#if defined(_WIN32)
static const bool WINDOWS = true;
#else
static const bool WINDOWS = false;
#endif

enum Side { Top, Left, Center, Right1, Right2, Bottom };
enum Color { White, Green, Red, Blue, Orange, Yellow };

class RubiksCube {
private:
	std::map<Side, Face*> faces;
  
public:
	RubiksCube();
	~RubiksCube();

	void initial(std::istream&);
	void rotate(std::istream&);
	void show(std::ostream&);
	void isequal(std::istream&, std::ostream&);

	static const Color stringToColor(const std::string&);
	static const std::string colorToString(const Color&);

	bool operator== (const RubiksCube& rhs) {
		Side s;
		for (int i = 0; i < NUM_FACES; i++) {
			s = static_cast<Side>(i);
			for (int j = 0; j < FACE_SIZE; j++)
				if (faces[s]->at(j) != rhs.faces.at(s)->at(j))
					return false;
		}
		return true;
	}
	bool operator< (const RubiksCube& rhs) {
		Side s;
		for (int i = 0; i < NUM_FACES; i++) {
			s = static_cast<Side>(i);
			for (int j = 0; j < FACE_SIZE; j++) {
				int left_tile = (int)faces[s]->at(j);
				int right_tile = (int)rhs.faces.at(s)->at(j);
				if (left_tile < right_tile)
					return true;
				else if (left_tile > right_tile)
					return false;
			}
		}
		return false;
	}
};
#endif
