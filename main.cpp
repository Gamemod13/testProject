#include <iostream>

//My static library with logic
#include "findFileLib.h"


int main() {

	char path[70];

	std::cout << "\nEnter full path (for example, C:\\):";

	std::cin >> path;

	char name[20];

	std::cout << "\nEnter name (for example, source.txt):";

	std::cin >> name;

    //Use function with static lib "findFileLib.h"
	searcName(*path, *name);

    return 0;
}