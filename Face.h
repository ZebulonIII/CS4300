class Face {
private
  Color colors[SIZE];

public:
  const int SIZE = 9;
  
  Face(Color color) {
    for (int i = 0; i < SIZE; i++)
      colors[i] = color;
  }
  Face(Color colors[SIZE]) {
    for (int i = 0; i < SIZE; i++)
      this->colors[i] = colors[i];
  }
  ~Face() {}
  
  Color& operator[](int i) {
    return colors[i];
  }
};
