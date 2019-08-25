#include <fstream>
#include <iostream>
#include <string>
#include "RubiksCube.h"

int main() {

	RubiksCube cube;
	std::ifstream is;
	std::ostream& os = std::cout;
	is.open("input.txt");

	std::string command;
	while (!is.eof()) {			
		is >> command;
		if (command[0] == '#') { // comment
			getline(is, command);
			continue;
		}
		else if (command == "initial")
			cube.initial(is);
		else if (command == "show")
			cube.show(os);
		else if (command == "isequal")
			cube.isequal(is, os);
		else if (command == "rotate")
			cube.rotate(is);
	}

	if (WINDOWS)
		system("PAUSE");

	return 0;
}