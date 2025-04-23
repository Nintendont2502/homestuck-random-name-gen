
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int getSize();

void fillList(int listSize, string * patternArray);

string getRandPattern(int listSize, string * patternArray);

void getName(string pattern);
char getC (int index);
char getV (int index);
string getClass();
string getAspect();
string getBlood();
string getMoon();

void nameGen(int listSize, string * patternArr, int lastName, int classpect, int blood, int moon);
