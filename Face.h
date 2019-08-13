class Face {
private
  Color colors[SIZE];

public:
  static int SIZE = 9;
  
  Face();
  ~Face();
  
  Color& operator[](int& i);
};
