#include "genlib.h"
#include <iostream>
#include <ctime>

using namespace std;

/* author: @nintendont2502 on tumblr, https://github.com/Nintendont2502. direct any questions/suggestions/bugs there
* created: 22/04/2025.
* last updated: 23/04/2025
* if youre looking through here im assuming you know how to program. ignore how inefficient this probably is and how little
* i give a shit about best practices. i spend enough time worrying about that for my uni assignments
*/

/*todo:
* - i would KILL to have a Faggot check in here somewhere. its possible. i know it is. CVCCVC is one of the most common patterns. its just a matter
* of time
* - maybe tweak letter balancing some more. idfk. odds are this is never producing consistent name adjacent things but why not try
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
    int moon = 0;



    while (choice != 6){

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

        cout << "4. Moon alignment:";
        if (moon == 1){
            cout << " ON\n";
        } else {
            cout << " OFF\n";
        }

        cout << "5. Generate names with selected options.\n";
        cout << "6. Quit.\n\n";

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
            if (moon == 0){
                moon = 1;
            } else {
                moon = 0;
            }
            break;
        case 5:
            nameGen(listSize, patternArr, lastName, classpect, blood, moon);
            break;
        case 6:
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
