#include <string>
#include "Face.h"

class RubiksCube {
private:
  std::map<Side, Face> faces;
  
public:  
  enum Side { Top, Left, Center, Right1, Right2, Bottom };
  enum Color { White, Green, Red, Blue, Orange, Yellow };
  static int NUM_FACES = 6;
  
  RubiksCube();
  ~RubiksCube();
  
  void initial(std::istream& is);
  void rotate(const Color& color, const std::string& direction);
  void show(std::ostream& os);
  bool isequal(std::istream& is, std::ostream& os);
  
  Color sideToColor(const Side& side);
  
  bool operator== (const RubiksCube& rhs) const {
    return false;
  }
  bool operator< (const RubiksCube& rhs) const {
    return false;
  }
};
