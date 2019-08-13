class Face {
private
  Color colors[SIZE];

public:
  static int SIZE = 9;
  
  Face();
  ~Face();
  
  std::string toString();
  Color& operator[](int& i);
};
