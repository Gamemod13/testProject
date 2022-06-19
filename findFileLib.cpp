#include "findFileLib.h"
#include <iostream>
#include <io.h>
#include <string>
#include <fstream>
#include <thread>

//Function, where created 8 thread
std::thread createThread(int numOfThread) {
	std::thread t1, t2, t3, t4, t5, t6, t7, t8;
	switch (numOfThread)
	{
	case(0):
		std::cout << "t1" << std::endl;
		return t1;
		break;
	case(1):
		std::cout << "t2" << std::endl;
		return t2;
		break;
	case(2):
		std::cout << "t3" << std::endl;
		return t3;
		break;
	case(3):
		std::cout << "t4" << std::endl;
		return t4;
		break;
	case(4):
		std::cout << "t5" << std::endl;
		return t5;
		break;
	case(5):
		std::cout << "t6" << std::endl;
		return t6;
		break;
	case(6):
		std::cout << "t7" << std::endl;
		return t7;
		break;
	case(7):
		std::cout << "t8" << std::endl;
		return t8;
		break;
	default:
		break;
	}
}

void coutPath(const char& path, const char& name) {

	std::cout << path << '\\' << name << std::endl;
}

void coutNotFound() {

	std::cout << "File is not found!" << std::endl;
}

void searcName(const char& path, const char& name)
{
    //This static variable use to create a new thread each time
    //(before s_numOfTreat >= 8)
	static int s_numOfTreat{ 0 };

    //create Thread
	createThread(s_numOfTreat++);

    //This variable indicate whether the search in progress
    bool inProgress(true);

    //This variable indicate that find the file
    bool triggerFind(false);
    

    while(inProgress && !triggerFind)
    {
        //Struct with lib io.h, create file data
	    _finddata_t data;

        //Searching with patn and comparison with delegated file name &name
	    intptr_t handle = _findfirst(&path, &data);

	    do {

            //If data.name is our name - use function and cout path and name
		    if (data.name == &name) {

			    coutPath(path, *data.name);

                inProgress = false;

                triggerFind = true;

		    }

            //If we find the folder - open it and recursing use this function
		    else if (data.attrib & _A_SUBDIR) {
                char path_iteration(path);
                char *name = strcat(&path_iteration, data.name);
			    searcName(path, *name);
		    }

        //All directory files are scaned
	    } while (_findnext(handle, &data) == 0);
	_findclose(handle);
    inProgress=false;
    }

    //If file is not found - cout "NotFound"
    if(!triggerFind){
        coutNotFound();
    }

}