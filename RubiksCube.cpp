#include "RubiksCube.h"
#include <iostream>

RubiksCube() {}
RubiksCube(std::map<Side, Face> faces) {}
~RubiksCube() {}

void initial(bool solved = true) {
  
}
void rotate(const Color& color, const std::string& direction) {

}
void show() {

}
bool isequal(istream& is, ostream& os) {
  std::string color;
  RubiksCube new_cube;
  Side side;
  
  for (int i = 0; i < NUM_FACES; i++) {
    Face face;
    side = (Side)i;
    
    new_cube.add_face(side, face);
  }
  return *this == RubiksCube(new_faces);
}

void add_face(Side side, Face face) {

}
