class Face {
private
  Color colors[SIZE];

public:
  const int SIZE = 9;
  
  Face(Color color);
  Face(Color colors[SIZE]);
  ~Face();
  
  Color& operator[](int i);
};
