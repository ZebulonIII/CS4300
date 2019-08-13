#include <string>
#include "Face.h"

class RubiksCube {
private:
  std::map<Side, Face> faces;
  
public:  
  enum Side { Top, Bottom, Left, Center, Right1, Right2 };
  enum Color { White, Green, Red, Blue, Orange, Yellow };
  
  RubiksCube();
  ~RubiksCube();
  
  void initial();
  void rotate(const Color& color, const std::string& direction);
  void show();
  bool isequal();
  
  bool operator== (const RubiksCube& rhs) const {
    return false;
  }
  bool operator< (const RubiksCube& rhs) const {
    return false;
  }
};
