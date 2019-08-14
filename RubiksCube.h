#ifndef _RUBIKSCUBE_H_
#define _RUBIKSCUBE_H_

#include <string>
#include <map>
#include "Face.h"

enum Side { Top, Left, Center, Right1, Right2, Bottom };
enum Color { White, Green, Red, Blue, Orange, Yellow };

class Face;

class RubiksCube {
private:
  std::map<Side, Face> faces;
  
public:  
  const static int NUM_FACES = 6;
  
  RubiksCube();
  ~RubiksCube();
  
  void initial(std::istream&);
  void rotate(std::istream&);
  void show(std::ostream&);
  void isequal(std::istream&, std::ostream&);
  
  Color stringToColor(const std::string&) const;
  std::string colorToString(const Color&) const;
  
  bool operator== (const RubiksCube& rhs) const {
    return false;
  }
  bool operator< (const RubiksCube& rhs) const {
    return false;
  }
};
#endif