#include "genlib.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
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

    // Get a different random number each time the program runs

    // Generate a random number between 0 and 100
    int randomNum = rand() % listSize;


    return patternArray[randomNum];

}

void getName(string pattern, string * name){

    cout << "pattern is " << pattern << "\n";

   for (int i = 0; i < 6; i ++){

    if (pattern[i] == 'C'){

        cout << getC();

    } else {
        cout << getV();
    }
   }


}

char getC ()
{
  //all consonants:
  //BCDFGHJKLMNPQRSTVWXYZ
  //22 of em

  string cons = "bdcdfghjklmnpqrstvwxyz";
  int randomNum = rand() % 22;
  //cout << "random consonant: " << cons[randomNum] << "\n";

  return cons[randomNum];

}

char getV ()
{
  //all consonants:
  //aeiouy
  //6 of em

  string vow = "aeiouy";
  int randomNum = rand() % 6;
  //cout << "random consonant: " << cons[randomNum] << "\n";

  return vow[randomNum];

}

