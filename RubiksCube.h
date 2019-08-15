#ifndef _RUBIKSCUBE_H_
#define _RUBIKSCUBE_H_

#include <string>
#include <map>
#include "Face.h"

#define NUM_FACES 6
#define FACE_SIZE 9

enum Side { Top, Left, Center, Right1, Right2, Bottom };
enum Color { White, Green, Red, Blue, Orange, Yellow };

class RubiksCube {
private:
	std::map<Side, Face> faces;
  
public:
	RubiksCube() {}
	~RubiksCube() {}

	void initial(std::istream&);
	void rotate(std::istream&);
	void show(std::ostream&);
	void isequal(std::istream&, std::ostream&);

	static const Color stringToColor(const std::string&);
	static const std::string colorToString(const Color&);

	bool operator== (const RubiksCube& rhs) {
		for (int i = 0; i < NUM_FACES; i++)
			for (int j = 0; j < FACE_SIZE; j++)
				if (faces[(Side)i][j] != rhs.faces.at((Side)i)[j])
					return false;
		return true;
	}
	bool operator< (const RubiksCube& rhs) {
		for (int i = 0; i < NUM_FACES; i++)
			for (int j = 0; j < FACE_SIZE; j++) {
				int left_tile = (int)faces[(Side)i][j];
				int right_tile = (int)rhs.faces.at((Side)i)[j];			  
				if (left_tile < right_tile)
					return true;
				else if (left_tile > right_tile)
					return false;
			}
		return false;
	}
};
#endif
