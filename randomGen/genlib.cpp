#include "genlib.h"

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cctype>
using namespace std;

int getSize(){

    ifstream infile("allUniquePatterns_canonOnly.txt");

    string temp;

    getline(infile, temp);


    return stoi(temp);

    }

void fillList(int listSize, string * patternArray){

    ifstream infile("allUniquePatterns_canonOnly.txt");
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
  //all consonants:
  //BCDFGHJKLMNPQRSTVWXYZ
  //22 of em

  string cons = "bdcdfghjklmnpqrstvwxyzbdcdfghjklmnprstv";
  string consCap = "BDCDFGHJKLMNPQRSTVWXYZBDCDFGHJKLMNPRSTV";
  int randomNum = rand() % 39;
  //cout << "random consonant: " << cons[randomNum] << "\n";


  if (index == 0){
    return consCap[randomNum];
  } else {
    return cons[randomNum];
  }


}

char getV (int index)
{
  //all consonants:
  //aeiouy
  //6 of em

  string vow = "aeiouaeiouaeiouy";
  string vowCap = "AEIOUAEIOUAEIOUY";
  int randomNum = rand() % 16;
  //cout << "random consonant: " << cons[randomNum] << "\n";

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
