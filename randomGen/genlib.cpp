#include "genlib.h"

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cctype>
using namespace std;

int getSize(){

    //Note: this + fillList *should* work with any list of CV patterns, as long as they follow the same format as the two included files
    //(First line is number of patterns, each line below that is a CV pattern 6 letters long in all caps, no letters other than C or V)
    //Just switch out the below line with the appropriate file name. (this program doesnt have any checks for if the file opens correctly,
    //so just make sure its saved in the correct location. no clue what'll happen otherwise)

    ifstream infile("allUniquePatterns_canonOnly.txt");
    //ifstream infile("allUniquePatterns_withWinterstuck.txt");
    //^ alternate file with 4 extra CV patterns, taken from a fansession I'm in. Include this if you want a few extra patterns

    string temp;
    //a

    getline(infile, temp);


    return stoi(temp);

    }

void fillList(int listSize, string * patternArray){

    //if you changed the input file in getSize(), make sure you change it here too

    ifstream infile("allUniquePatterns_canonOnly.txt");
    //ifstream infile("allUniquePatterns_withWinterstuck.txt");

    string temp;

    getline(infile, temp);

    for (int i = 0; i < listSize; i++){

        getline(infile, temp);

        patternArray[i] = temp;

    }


    }

string getRandPattern(int listSize, string * patternArray){

    int randomNum = rand() % listSize;

    return patternArray[randomNum];

}

void getName(string pattern){

   for (int i = 0; i < 6; i ++){

    if (pattern[i] == 'C'){

        cout << getC(i);

    } else {
        cout << getV(i);
    }
   }


}

char getC (int index)
{
    //yes im counting y as both a vowel and a consonant. sue me

  //all consonants:
  //BCDFGHJKLMNPQRSTVWXYZ
  //22 of em

  //repeated common letters to weigh the selection a little. too many q's and z's and x's looks like shit
  string cons = "bdcdfghjklmnpqrstvwxyzbdcdfghjklmnprstv";
  string consCap = "BDCDFGHJKLMNPQRSTVWXYZBDCDFGHJKLMNPRSTV";
  int randomNum = rand() % 39;


  if (index == 0){
    return consCap[randomNum];
  } else {
    return cons[randomNum];
  }


}

char getV (int index)
{
  //all vowels:
  //aeiouy
  //6 of em

  //repeated common vowels to decrease the likelihood of Y's. fuck em
  string vow = "aeiouaeiouaeiouy";
  string vowCap = "AEIOUAEIOUAEIOUY";
  int randomNum = rand() % 16;

   if (index == 0){
    return vowCap[randomNum];
  } else {
    return vow[randomNum];
  }
}

string getClass(){

    string ass[12] = {"Page", "Heir", "Maid", "Knight", "Sylph", "Seer", "Witch", "Mage", "Thief", "Rogue", "Prince", "Bard"};

   int ranAss = rand() % 12;


   return ass[ranAss];
}

string getAspect(){

    string aspect[12] = {"Breath", "Blood", "Light", "Void", "Space", "Time", "Heart", "Mind", "Life", "Doom", "Hope", "Rage"};
   int ranAsp = rand() % 12;


   return aspect[ranAsp];

}

string getBlood(){

    string blood[12] = {"Rustblood", "Bronzeblood", "Goldblood", "Limeblood", "Oliveblood", "Jadeblood", "Tealblood", "Cobaltblood", "Indigoblood", "Purpleblood", "Violetblood", "Fuschiablood"};
    int ranBlood = rand() % 12;

    return blood[ranBlood];

}

string getMoon(){

string moon[2] = {"Prospit", "Derse"};
int ranMoon = rand() % 2;

return moon[ranMoon];
}

void nameGen(int listSize, string * patternArr, int lastName, int classpect, int blood, int moon){

    int nameNo = 0;
    string pattern;
    cout << "\nNumber of names to generate:\n\n";
    cin >> nameNo;


    if (nameNo <= 0){
        nameNo = 1;
    }

    for (int i = 0; i < nameNo; i ++){

         pattern = getRandPattern(listSize, patternArr);
            getName(pattern);

            if (lastName == 1){
                cout << " ";
                pattern = getRandPattern(listSize, patternArr);
            getName(pattern);


            }
            if (classpect == 1){
                cout << ", " << getClass() << " of " << getAspect();
            }
            if (blood == 1){
                cout << ", " << getBlood();
            }
            if (moon == 1){
                cout << ", " << getMoon();
            }

            cout << ".\n";


    }

    return;

}
