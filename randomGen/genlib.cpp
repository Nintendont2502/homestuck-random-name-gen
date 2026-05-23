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

    string blood[12] = {"Rustblood", "Bronzeblood", "Goldblood", "Limeblood", "Oliveblood", "Jadeblood", "Tealblood", "Blueblood", "Indigoblood", "Purpleblood", "Violetblood", "Fuschiablood"};
    int ranBlood = rand() % 12;

    return blood[ranBlood];

}

string getMoon(){

string moon[2] = {"Prospit", "Derse"};
int ranMoon = rand() % 2;

return moon[ranMoon];
}

void nameGen(int listSize, string * patternArr, int lastName, int classpect, int blood, int moon, int sign){

    int nameNo = 0;
    string pattern;
    cout << "\nNumber of names to generate:\n\n";
    cin >> nameNo;

    string smoon;
    string saspect;
    string sblood;


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
            if (blood == 1 || sign == 1){
                sblood = getBlood();
                cout << ", " << sblood;
            }
            if (moon == 1 || sign == 1){
                smoon = getMoon();
                cout << ", " << smoon;
            }
            if (classpect == 1 || sign == 1){
                saspect = getAspect();
                cout << ", " << getClass() << " of " << saspect;
            }
            if (sign == 1){
                cout << ", " << getSign(sblood, saspect, smoon);
            }


            cout << ".\n";


    }

    return;

}


string getSign(string blood, string aspect, string moon){

    if (blood == "Rustblood"){ //Rust signs
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Aries, Sign of the Excavator";
            }
            if (aspect == "Life"){
                return "Arsces, Sign of the Pilgrim";
            }
            if (aspect == "Hope"){
                return "Arrius, Sign of the Visualiser";
            }
            if (aspect == "Rage"){
                return "Ariborn, Sign of the Escapee";
            }
            if (aspect == "Void"){
                return "Arittarius, Sign of the Astronaut";
            }
            if (aspect == "Light"){
                return "Arpia, Sign of the Examiner";
            }
            if (aspect == "Mind"){
                return "Arza, Sign of the Inevitable";
            }
            if (aspect == "Space"){
                return "Arga, Sign of the Trailblazer";
            }
            if (aspect == "Heart"){
                return "Aro, Sign of the Lost";
            }
            if (aspect == "Blood"){
                return "Arcen, Sign of the Companion";
            }
            if (aspect == "Doom"){
                return "Armini, Sign of the Reconciler";
            }
            if (aspect == "Breath"){
                return "Arun, Sign of the Impetuous";
            }
        } else {
            if (aspect == "Time"){
                return "Arist, Sign of the Headstrong";
            }
            if (aspect == "Life"){
                return "Arsci, Sign of the Medic";
            }
            if (aspect == "Hope"){
                return "Arnius, Sign of the Heedless";
            }
            if (aspect == "Rage"){
                return "Aricorn, Sign of the Runaway";
            }
            if (aspect == "Void"){
                return "Arittanius, Sign of the Voyager";
            }
            if (aspect == "Light"){
                return "Arpio, Sign of the Seeker";
            }
            if (aspect == "Mind"){
                return "Arra, Sign of the Wayward";
            }
            if (aspect == "Space"){
                return "Argo, Sign of the Zenith";
            }
            if (aspect == "Heart"){
                return "Arlo, Sign of the Mirage";
            }
            if (aspect == "Blood"){
                return "Arcer, Sign of the Officer";
            }
            if (aspect == "Doom"){
                return "Armino, Sign of the Static";
            }
            if (aspect == "Breath"){
                return "Arus, Sign of the Wanderer";
            }
        }
    }

       if (blood == "Bronzeblood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Tauries, Sign of the Unsatisfied";
            }
            if (aspect == "Space"){
                return "Taurga, Sign of the Guardian";
            }
            if (aspect == "Void"){
                return "Taurittarius, Sign of the Skydiver";
            }
            if (aspect == "Light"){
                return "Taurpia, Sign of the Aesthete";
            }
            if (aspect == "Mind"){
                return "Taurza, Sign of the Revealer";
            }
            if (aspect == "Heart"){
                return "Tauro, Sign of the Withdrawn";
            }
            if (aspect == "Rage"){
                return "Tauriborn, Sign of the Covetous";
            }
            if (aspect == "Hope"){
                return "Taurrius, Sign of the Unmapped";
            }
            if (aspect == "Doom"){
                return "Taurmini, Sign of the Hermit";
            }
            if (aspect == "Life"){
                return "Taursces, Sign of the Recovered";
            }
            if (aspect == "Blood"){
                return "Taurcen, Sign of the Connected";
            }
             if (aspect == "Breath"){
                return "Taurun, Sign of the Liberated";
            }
        } else {
              if (aspect == "Time"){
                return "Taurist, Sign of the Prosperous";
            }
            if (aspect == "Space"){
                return "Taurgo, Sign of the Divine";
            }
            if (aspect == "Void"){
                return "Taurittanius, Sign of the Utopian";
            }
            if (aspect == "Light"){
                return "Taurpio, Sign of the Student";
            }
            if (aspect == "Mind"){
                return "Taurra, Sign of the Transient";
            }
            if (aspect == "Heart"){
                return "Taurlo, Sign of the Extravagant";
            }
            if (aspect == "Rage"){
                return "Tauricon, Sign of the Gratified";
            }
            if (aspect == "Hope"){
                return "Taurnius, Sign of the Entrepeneur";
            }
            if (aspect == "Doom"){
                return "Taurmino, Sign of the Lonely";
            }
            if (aspect == "Life"){
                return "Taursci, Sign of the Convalescent";
            }
            if (aspect == "Blood"){
                return "Taurcer, Sign of the Cherished";
            }
             if (aspect == "Breath"){
                return "Taurus, Sign of the Unfledged";
            }
        }
    }
     if (blood == "Goldblood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Gemries, Sign of the Savvy";
            }
            if (aspect == "Space"){
                return "Gemga, Sign of the Ascetic";
            }
            if (aspect == "Void"){
                return "Gemittarius, Sign of the Sapient";
            }
            if (aspect == "Light"){
                return "Gempia, Sign of the Perspicacious";
            }
            if (aspect == "Mind"){
                return "Gemza, Sign of the Shrewd";
            }
            if (aspect == "Heart"){
                return "Gemo, Sign of the Wit";
            }
            if (aspect == "Rage"){
                return "Gemiborn, Sign of the Uproarious";
            }
            if (aspect == "Hope"){
                return "Gemrius, Sign of the Perceptive";
            }
            if (aspect == "Doom"){
                return "Gemini, Sign of the Cynic";
            }
            if (aspect == "Life"){
                return "Gemsces, Sign of the Prudent";
            }
            if (aspect == "Blood"){
                return "Gemcen, Sign of the Entertainer";
            }
             if (aspect == "Breath"){
                return "Gemun, Sign of the Unbridled";
            }
        } else {
              if (aspect == "Time"){
                return "Gemrist, Sign of the Streetwise";
            }
            if (aspect == "Space"){
                return "Gemgo, Sign of the Original";
            }
            if (aspect == "Void"){
                return "Gemittanius, Sign of the Shipwright";
            }
            if (aspect == "Light"){
                return "Gempio, Sign of the Concise";
            }
            if (aspect == "Mind"){
                return "Gemra, Sign of the Pilot";
            }
            if (aspect == "Heart"){
                return "Gemlo, Sign of the Internal";
            }
            if (aspect == "Rage"){
                return "Gemicorn, Sign of the Anarchic";
            }
            if (aspect == "Hope"){
                return "Gemnius, Sign of the Canny";
            }
            if (aspect == "Doom"){
                return "Gemino, Sign of the Condemned";
            }
            if (aspect == "Life"){
                return "Gemsci, Sign of the Temperer";
            }
            if (aspect == "Blood"){
                return "Gemcer, Sign of the Intimate";
            }
             if (aspect == "Breath"){
                return "Gemus, Sign of the Alert";
            }
        }
    }

 if (blood == "Limeblood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Canries, Sign of the Scrapper";
            }
            if (aspect == "Space"){
                return "Canga, Sign of the Playwright";
            }
            if (aspect == "Void"){
                return "Canittarius, Sign of the Striking";
            }
            if (aspect == "Light"){
                return "Canpia, Sign of the Informer";
            }
            if (aspect == "Mind"){
                return "Canza, Sign of the Producer";
            }
            if (aspect == "Heart"){
                return "Cano, Sign of the Translucent";
            }
            if (aspect == "Rage"){
                return "Caniborn, Sign of the Tumultuous";
            }
            if (aspect == "Hope"){
                return "Canrius, Sign of the Helper";
            }
            if (aspect == "Doom"){
                return "Camini, Sign of the Commiserator";
            }
            if (aspect == "Life"){
                return "Cansces, Sign of the Mover";
            }
            if (aspect == "Blood"){
                return "Cancen, Sign of the Nexus";
            }
             if (aspect == "Breath"){
                return "Canun, Sign of the Vociferous";
            }
        } else {
              if (aspect == "Time"){
                return "Canrist, Sign of the Vehement";
            }
            if (aspect == "Space"){
                return "Cango, Sign of the Opus";
            }
            if (aspect == "Void"){
                return "Canittanius, Sign of the Romantic";
            }
            if (aspect == "Light"){
                return "Canpio, Sign of the Effervescent";
            }
            if (aspect == "Mind"){
                return "Canra, Sign of the Constrained";
            }
            if (aspect == "Heart"){
                return "Canlo, Sign of the Thespian";
            }
            if (aspect == "Rage"){
                return "Canicorn, Sign of the Storm";
            }
            if (aspect == "Hope"){
                return "Cannius, Sign of the Theatrical";
            }
            if (aspect == "Doom"){
                return "Camino, Sign of the Consoler";
            }
            if (aspect == "Life"){
                return "Cansci, Sign of the Reliever";
            }
            if (aspect == "Blood"){
                return "Cancer, Sign of the Signless";
            }
             if (aspect == "Breath"){
                return "Canus, Sign of the Unbound";
            }
        }
    }

     if (blood == "Oliveblood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Leries, Sign of the Tenacious";
            }
            if (aspect == "Space"){
                return "Lega, Sign of the Stoic";
            }
            if (aspect == "Void"){
                return "Leittarius, Sign of the Ardent";
            }
            if (aspect == "Light"){
                return "Lepia, Sign of the Synthesizer";
            }
            if (aspect == "Mind"){
                return "Leza, Sign of the Pliant";
            }
            if (aspect == "Heart"){
                return "Leo, Sign of the Disciple";
            }
            if (aspect == "Rage"){
                return "Leiborn, Sign of the Paradox";
            }
            if (aspect == "Hope"){
                return "Lerius, Sign of the Staunch";
            }
            if (aspect == "Doom"){
                return "Lemini, Sign of the Trusted";
            }
            if (aspect == "Life"){
                return "Lesces, Sign of the Instructor";
            }
            if (aspect == "Blood"){
                return "Lecen, Sign of the Provident";
            }
             if (aspect == "Breath"){
                return "Leun, Sign of the Migrant";
            }
        } else {
              if (aspect == "Time"){
                return "Lerist, Sign of the Advancer";
            }
            if (aspect == "Space"){
                return "Lego, Sign of the Nomad";
            }
            if (aspect == "Void"){
                return "Leittanius, Sign of the Emphatic";
            }
            if (aspect == "Light"){
                return "Lepio, Sign of the Fortunate";
            }
            if (aspect == "Mind"){
                return "Lera, Sign of the Chameleon";
            }
            if (aspect == "Heart"){
                return "Lelo, Sign of the Steadfast";
            }
            if (aspect == "Rage"){
                return "Leicorn, Sign of the Unforgiving";
            }
            if (aspect == "Hope"){
                return "Lenius, Sign of the Restless";
            }
            if (aspect == "Doom"){
                return "Lemino, Sign of the Sympathetic";
            }
            if (aspect == "Life"){
                return "Lesci, Sign of the Polisher";
            }
            if (aspect == "Blood"){
                return "Lecer, Sign of the Loyalist";
            }
             if (aspect == "Breath"){
                return "Leus, Sign of the Flexible";
            }
        }
    }

     if (blood == "Jadeblood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Viries, Sign of the Mother";
            }
            if (aspect == "Space"){
                return "Virga, Sign of the Pure";
            }
            if (aspect == "Void"){
                return "Virattarius, Sign of the Patient";
            }
            if (aspect == "Light"){
                return "Virpia, Sign of the Perfectionist";
            }
            if (aspect == "Mind"){
                return "Virza, Sign of the Puzzle";
            }
            if (aspect == "Heart"){
                return "Viro, Sign of the Redemptive";
            }
            if (aspect == "Rage"){
                return "Viriborn, Sign of the Stringent";
            }
            if (aspect == "Hope"){
                return "Virrius, Sign of the Vindicated";
            }
            if (aspect == "Doom"){
                return "Virmini, Sign of the Abiding";
            }
            if (aspect == "Life"){
                return "Virsces, Sign of the Roborant";
            }
            if (aspect == "Blood"){
                return "Vircen, Sign of the Liable";
            }
             if (aspect == "Breath"){
                return "Virun, Sign of the Eager";
            }
        } else {
              if (aspect == "Time"){
                return "Virist, Sign of the Protector";
            }
            if (aspect == "Space"){
                return "Virgo, Sign of the Fruitful";
            }
            if (aspect == "Void"){
                return "Virittanius, Sign of the Deliverate";
            }
            if (aspect == "Light"){
                return "Virpio, Sign of the Hearth";
            }
            if (aspect == "Mind"){
                return "Virra, Sign of the Sage";
            }
            if (aspect == "Heart"){
                return "Virlo, Sign of the Foundation";
            }
            if (aspect == "Rage"){
                return "Viricorn, Sign of the Lethal";
            }
            if (aspect == "Hope"){
                return "Virnius, Sign of the Fierce";
            }
            if (aspect == "Doom"){
                return "Virmino, Sign of the Inexhaustible";
            }
            if (aspect == "Life"){
                return "Virsci, Sign of the Alchemist";
            }
            if (aspect == "Blood"){
                return "Vircer, Sign of the Accountable";
            }
             if (aspect == "Breath"){
                return "Virus, Sign of the Adaptable";
            }
        }
    }

     if (blood == "Tealblood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Libries, Sign of the Executive";
            }
            if (aspect == "Space"){
                return "Liga, Sign of the Dogged";
            }
            if (aspect == "Void"){
                return "Libittarius, Sign of the Hidden";
            }
            if (aspect == "Light"){
                return "Lipia, Sign of the Networker";
            }
            if (aspect == "Mind"){
                return "Libza, Sign of the Acute";
            }
            if (aspect == "Heart"){
                return "Libo, Sign of the Militant";
            }
            if (aspect == "Rage"){
                return "Libiborn, Sign of the Finale";
            }
            if (aspect == "Hope"){
                return "Librius, Sign of the Seamstress";
            }
            if (aspect == "Doom"){
                return "Limini, Sign of the Abider";
            }
            if (aspect == "Life"){
                return "Libsces, Sign of the Enhancer";
            }
            if (aspect == "Blood"){
                return "Licen, Sign of the Worshipper";
            }
             if (aspect == "Breath"){
                return "Libun, Sign of the Escapist";
            }
        } else {
              if (aspect == "Time"){
                return "Librist, Sign of the Guerrilla";
            }
            if (aspect == "Space"){
                return "Ligo, Sign of the Circumscribed";
            }
            if (aspect == "Void"){
                return "Libittanius, Sign of the Skeptic";
            }
            if (aspect == "Light"){
                return "Lipio, Sign of the Initiate";
            }
            if (aspect == "Mind"){
                return "Libra, Sign of the Watcher";
            }
            if (aspect == "Heart"){
                return "Liblo, Sign of the Inescapable";
            }
            if (aspect == "Rage"){
                return "Libicorn, Sign of the Dismantler";
            }
            if (aspect == "Hope"){
                return "Libnius, Sign of the Certain";
            }
            if (aspect == "Doom"){
                return "Limino, Sign of the Endurer";
            }
            if (aspect == "Life"){
                return "Libsci, Sign of the Absolver";
            }
            if (aspect == "Blood"){
                return "Licer, Sign of the Charmer";
            }
             if (aspect == "Breath"){
                return "Libus, Sign of the Vibrant";
            }
        }
    }
     if (blood == "Blueblood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Scories, Sign of the Redeemer";
            }
            if (aspect == "Space"){
                return "Scorga, Sign of the Deviser";
            }
            if (aspect == "Void"){
                return "Scorittarius, Sign of the Doubtful";
            }
            if (aspect == "Light"){
                return "Scorpia, Sign of the Emperor";
            }
            if (aspect == "Mind"){
                return "Scorza, Sign of the Strategist";
            }
            if (aspect == "Heart"){
                return "Scoro, Sign of the Wondrous";
            }
            if (aspect == "Rage"){
                return "Scoribon, Sign of the Dangerous";
            }
            if (aspect == "Hope"){
                return "Scorrius, Sign of the Cunning";
            }
            if (aspect == "Doom"){
                return "Scormini, Sign of the Martyr";
            }
            if (aspect == "Life"){
                return "Scorsces, Sign of the Alleviator";
            }
            if (aspect == "Blood"){
                return "Scorcen, Sign of the Uniter";
            }
             if (aspect == "Breath"){
                return "Scorun, Sign of the Insurgent";
            }
        } else {
              if (aspect == "Time"){
                return "Scorist, Sign of the Mutineer";
            }
            if (aspect == "Space"){
                return "Scorgo, Sign of the Crusader";
            }
            if (aspect == "Void"){
                return "Scorittanius, Sign of the Righteous";
            }
            if (aspect == "Light"){
                return "Scorpio, Sign of the Conqueror";
            }
            if (aspect == "Mind"){
                return "Scorra, Sign of the Impromptu";
            }
            if (aspect == "Heart"){
                return "Scorlo, Sign of the Crusader";
            }
            if (aspect == "Rage"){
                return "Scoricon, Sign of the Destructive";
            }
            if (aspect == "Hope"){
                return "Scornius, Sign of the Radical";
            }
            if (aspect == "Doom"){
                return "Scormino, Sign of the Fatalistic";
            }
            if (aspect == "Life"){
                return "Scorsci, Sign of the Fixer";
            }
            if (aspect == "Blood"){
                return "Scorcer, Sign of the Champion";
            }
             if (aspect == "Breath"){
                return "Scorus, Sign of the Victorious";
            }
        }
    }

     if (blood == "Indigoblood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Sagiries, Sign of the Revolutionary";
            }
            if (aspect == "Space"){
                return "Sagiga, Sign of the Builder";
            }
            if (aspect == "Void"){
                return "Sagittarius, Sign of the Engineer";
            }
            if (aspect == "Light"){
                return "Sagipia, Sign of the Empirical";
            }
            if (aspect == "Mind"){
                return "Sagiza, Sign of the Inventor";
            }
            if (aspect == "Heart"){
                return "Sagio, Sign of the Ego";
            }
            if (aspect == "Rage"){
                return "Sagiborn, Sign of the Rampant";
            }
            if (aspect == "Hope"){
                return "Saigirus, Sign of the Bardic";
            }
            if (aspect == "Doom"){
                return "Sagmini, Sign of the Lurid";
            }
            if (aspect == "Life"){
                return "Sagisces, Sign of the Fervent";
            }
            if (aspect == "Blood"){
                return "Sagicen, Sign of the Teacher";
            }
             if (aspect == "Breath"){
                return "Sagiun, Sign of the Journeyman";
            }
        } else {
              if (aspect == "Time"){
                return "Sagirist, Sign of the Rebel";
            }
            if (aspect == "Space"){
                return "Sagigo, Sign of the Creator";
            }
            if (aspect == "Void"){
                return "Sagittanius, Sign of the Nascent";
            }
            if (aspect == "Light"){
                return "Sagipio, Sign of the Detective";
            }
            if (aspect == "Mind"){
                return "Sagira, Sign of the Tenable";
            }
            if (aspect == "Heart"){
                return "Sagilo, Sign of the Lofty";
            }
            if (aspect == "Rage"){
                return "Sagicorn, Sign of the Wild";
            }
            if (aspect == "Hope"){
                return "Saginius, Sign of the Believer";
            }
            if (aspect == "Doom"){
                return "Sagimino, Sign of the Penitent";
            }
            if (aspect == "Life"){
                return "Sagisci, Sign of the Genuine";
            }
            if (aspect == "Blood"){
                return "Sagicer, Sign of the Hostess";
            }
             if (aspect == "Breath"){
                return "Sagius, Sign of the Traveler";
            }
        }
    }

     if (blood == "Purpleblood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Capries, Sign of the Bold";
            }
            if (aspect == "Space"){
                return "Capriga, Sign of the Surveyor";
            }
            if (aspect == "Void"){
                return "Caprittarius, Sign of the Rift";
            }
            if (aspect == "Light"){
                return "Caripia, Sign of the Brusque";
            }
            if (aspect == "Mind"){
                return "Capriza, Sign of the Rigid";
            }
            if (aspect == "Heart"){
                return "Caprio, Sign of the Opaque";
            }
            if (aspect == "Rage"){
                return "Capriborn, Sign of the Malignant";
            }
            if (aspect == "Hope"){
                return "Capririus, Sign of the Contender";
            }
            if (aspect == "Doom"){
                return "Caprimini, Sign of the Perilous";
            }
            if (aspect == "Life"){
                return "Caprisces, Sign of the Uplifted";
            }
            if (aspect == "Blood"){
                return "Capricen, Sign of the Taskmaster";
            }
             if (aspect == "Breath"){
                return "Capriun, Sign of the Cartographer";
            }
        } else {
              if (aspect == "Time"){
                return "Carpist, Sign of the Audacious";
            }
            if (aspect == "Space"){
                return "Caprigo, Sign of the Lacuna";
            }
            if (aspect == "Void"){
                return "Caprittanius, Sign of the Brazen";
            }
            if (aspect == "Light"){
                return "Capripio, Sign of the Risk-taker";
            }
            if (aspect == "Mind"){
                return "Caprira, Sign of the Unwavering";
            }
            if (aspect == "Heart"){
                return "Caprilo, Sign of the Multifaceted";
            }
            if (aspect == "Rage"){
                return "Capricorn, Sign of the Capricious";
            }
            if (aspect == "Hope"){
                return "Caprinius, Sign of the Credulous";
            }
            if (aspect == "Doom"){
                return "Caprimino, Sign of the Enduring";
            }
            if (aspect == "Life"){
                return "Caprisci, Sign of the Mendicant";
            }
            if (aspect == "Blood"){
                return "Capricer, Sign of the Defender";
            }
             if (aspect == "Breath"){
                return "Caprius, Sign of the Climber";
            }
        }
    }

     if (blood == "Violetblood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Aquaries, Sign of the Heroic";
            }
            if (aspect == "Space"){
                return "Aquaga, Sign of the Campaigner";
            }
            if (aspect == "Void"){
                return "Aquittarius, Sign of the Enigma";
            }
            if (aspect == "Light"){
                return "Aquapia, Sign of the Eccentric";
            }
            if (aspect == "Mind"){
                return "Aquaza, Sign of the Politic";
            }
            if (aspect == "Heart"){
                return "Aquo, Sign of the Obsessive";
            }
            if (aspect == "Rage"){
                return "Aquiborn, Sign of the Hedonist";
            }
            if (aspect == "Hope"){
                return "Aquarius, Sign of the Zealous";
            }
            if (aspect == "Doom"){
                return "Aquamini, Sign of the Idiosyncratic";
            }
            if (aspect == "Life"){
                return "Aquasces, Sign of the Offbeat";
            }
            if (aspect == "Blood"){
                return "Aquacen, Sign of the Avant-Garde";
            }
             if (aspect == "Breath"){
                return "Aquiun, Sign of the Spontaneous";
            }
        } else {
              if (aspect == "Time"){
                return "Aquarist, Sign of the Renegade";
            }
            if (aspect == "Space"){
                return "Aquago, Sign of the Esoteric";
            }
            if (aspect == "Void"){
                return "Aquittanius, Sign of the Elegant";
            }
            if (aspect == "Light"){
                return "Aquapio, Sign of the Maverick";
            }
            if (aspect == "Mind"){
                return "Aquara, Sign of the Contrarian";
            }
            if (aspect == "Heart"){
                return "Aqualo, Sign of the Puppeteer";
            }
            if (aspect == "Rage"){
                return "Aquicorn, Sign of the Tempest";
            }
            if (aspect == "Hope"){
                return "Aquanius, Sign of the Magician";
            }
            if (aspect == "Doom"){
                return "Aquamino, Sign of the Tilted";
            }
            if (aspect == "Life"){
                return "Aquasci, Sign of the Charitable";
            }
            if (aspect == "Blood"){
                return "Aquacer, Sign of the Foretold";
            }
             if (aspect == "Breath"){
                return "Aquius, Sign of the Whimsical";
            }
        }
    }

     if (blood == "Fuschiablood"){
        if (moon == "Derse"){
            if (aspect == "Time"){
                return "Piries, Sign of the Dissenter";
            }
            if (aspect == "Space"){
                return "Piga, Sign of the Designer";
            }
            if (aspect == "Void"){
                return "Pittarius, Sign of the Philosopher";
            }
            if (aspect == "Light"){
                return "Pipia, Sign of the Inquiring";
            }
            if (aspect == "Mind"){
                return "Piza, Sign of the Conjurer";
            }
            if (aspect == "Heart"){
                return "Pio, Sign of the Pathfinder";
            }
            if (aspect == "Rage"){
                return "Piborn, Sign of the Albatross";
            }
            if (aspect == "Hope"){
                return "Pirius, Sign of the Storyteller";
            }
            if (aspect == "Doom"){
                return "Pimini, Sign of the Adjuster";
            }
            if (aspect == "Life"){
                return "Pisces, Sign of the Cleric";
            }
            if (aspect == "Blood"){
                return "Picen, Sign of the Compatriot";
            }
             if (aspect == "Breath"){
                return "Picen, Sign of the Unconfined";
            }
        } else {
              if (aspect == "Time"){
                return "Pirist, Sign of the Apostate";
            }
            if (aspect == "Space"){
                return "Pigo, Sign of the Artisan";
            }
            if (aspect == "Void"){
                return "Pittanius, Sign of the Quixotic";
            }
            if (aspect == "Light"){
                return "Pipio, Sign of the Searcher";
            }
            if (aspect == "Mind"){
                return "Pira, Sign of the Visionary";
            }
            if (aspect == "Heart"){
                return "Pilo, Sign of the Spirited";
            }
            if (aspect == "Rage"){
                return "Picorn, Sign of the Hurricane";
            }
            if (aspect == "Hope"){
                return "Pinius, Sign of the Sensational";
            }
            if (aspect == "Doom"){
                return "Pimino, Sign of the Empathetic";
            }
            if (aspect == "Life"){
                return "Pisci, Sign of the Druid";
            }
            if (aspect == "Blood"){
                return "Picer, Sign of the Confidante";
            }
             if (aspect == "Breath"){
                return "Pius, Sign of the the Free";
            }
        }
    }

    return "This is a placeholder.";

}


