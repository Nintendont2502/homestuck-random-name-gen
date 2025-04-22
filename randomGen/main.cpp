#include "genlib.h"
#include <iostream>
#include <ctime>

using namespace std;

/*todo:

* - add menu? loopable, able to toggle different options on and off
* - options: last name, bloodtype, classpect - *maybe* true sign? maybe not actually. can i really be assed
* making sure it aligns with the randomly assigned classpect. fuck that actually
* maybe ill add moon in to make up for it. bc the thing with two different options really makes up for the thing
* with 144 different options not being implemented
* - make program loopable. should be able to run menu, make change (have menu reprint to reflect change? so like. "Last name: ON"
* or whatever. could be fun to figure out.
* - have menu reappear after list is generated so options can be changed/more names can be printed without needing to rerun the program
* - i would KILL to have a Faggot check in here somewhere. its possible. i know it is. CVCCVC is one of the most common patterns. its just a matter
* of time
* - maybe tweak letter balancing. idfk. odds are this is never producing consistent name adjacent things but why not try
* - *maybe* tweak pattern balancing? maybe not actually. program is designed to be able to swap pattern lists at runtime without any other code
* changing - thatd throw it off. sign
*/

int main()
{

 srand(time(0));
    int listSize = getSize();

    string patternArr[listSize];

    fillList(listSize, patternArr);

    int nameNo = 0;
    int choice = 0;

    string pattern;

    cout << "Number of names to generate:\n";
    cin >> nameNo;


    if (nameNo <= 0){
        nameNo = 1;
    }

    cout << "Generate last names? (1, yes. 2, no.)\n";
    cin >> choice;

    if (choice > 1 || choice < 0){
        choice = 0;
    }

    for (int i = 0; i < nameNo; i ++){
         pattern = getRandPattern(listSize, patternArr);
            getName(pattern);

            if (choice == 1){
                cout << " ";
                pattern = getRandPattern(listSize, patternArr);
            getName(pattern);

            }
            cout << ", " << getClass() << " of " << getAspect() << ". " << getBlood() << ".\n";


    }


    delete(patternArr);

    return 0;

}
