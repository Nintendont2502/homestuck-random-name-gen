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
    int lastName = 0;
    int classpect = 0;
    int blood = 0;



    while (choice != 5){

        cout << "Enter choice:\n";
        cout << "1. Last names:";
        if (lastName == 1){
            cout << " ON\n";
        } else {
            cout << " OFF\n";
        }
        cout << "2. Classpect:";
         if (classpect == 1){
            cout << " ON\n";
        } else {
            cout << " OFF\n";
        }

        cout << "3. Bloodtype:";
         if (blood == 1){
            cout << " ON\n";
        } else {
            cout << " OFF\n";
        }

        cout << "4. Generate names with selected options.\n";
        cout << "5. Quit.\n";

        cin >> choice;

        switch(choice){
        case 1:
            if (lastName == 0){
                lastName = 1;
            } else {
                lastName = 0;
            }
        break;
        case 2:
            if (classpect == 0){
                classpect = 1;
            } else {
                classpect = 0;
            }
        break;
        case 3:
            if (blood == 0){
                blood = 1;
            } else {
                blood = 0;
            }
        break;
        case 4:
            nameGen(listSize, patternArr, lastName, classpect, blood);
            break;
        case 5:
            delete(patternArr);
            return 0;
            break;
        default:
            cout << "Invalid option. Enter number 1 - 5.\n";
            break;
        }

        cout << "\n";

        }



    delete(patternArr);

    return 0;

}
