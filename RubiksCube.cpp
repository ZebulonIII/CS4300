class RubiksCube {
private:
  
public:  
  enum Face { Top, Down, Left, Center, Right1, Right2 };
  
  RubiksCube() {}
  ~RubiksCube() {}
  
  void initial() {}
  void rotate() {}
  void show() {}
  void isequal() {}
  
  bool operator== (const RubiksCube& rhs) const {
    return false;
  }
  bool operator< (const RubiksCube& rhs) const {
    return false;
  }
};
