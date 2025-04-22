#include "genlib.h"
#include <iostream>
#include <ctime>

using namespace std;


int main()
{

 srand(time(0));
    int listSize = getSize();

    string patternArr[listSize];

    fillList(listSize, patternArr);

    string pattern;

    string name[6];

    for (int i = 0; i < 10; i ++){
         pattern = getRandPattern(listSize, patternArr);
            getName(pattern, name);
            cout << "\n";

    }

    pattern = getRandPattern(listSize, patternArr);


    getName(pattern, name);

    delete(patternArr);

    return 0;

}
