#ifndef FIND_FILE_LIB_H
#define FIND_FILE_LIB_H
#include<thread>

//Previous announcement my function with my library
std::thread createThread(int);
void coutPath(const char& , const char& );
void coutNotFound();
void searcName(const char& path, const char& name);

#endif
