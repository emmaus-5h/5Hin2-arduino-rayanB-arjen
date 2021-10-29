/*****************************************
   Stoplicht Startcode
   met toestansdiagrammen
   Emmauscollege
   v20201114GEE
 *****************************************/

/*****************************************
   variabelen die je gebruikt maken
 *****************************************/
// gebruikte pinnen
const int pin1Rood   = 28; // pin van stoplicht 1 rood
const int pin1Oranje = 30; // pin van stoplicht 1 oranje
const int pin1Groen  = 32; // pin van stoplicht 1 groen
const int pin2Rood   = 23; // pin van stoplicht 2 rood
const int pin2Oranje = 25; // pin van stoplicht 2 oranje
const int pin2Groen  = 27; // pin van stoplicht 2 groen
const int pin3Rood   = 34; // pin van stoplicht 3 rood
const int pin3Oranje = 36; // pin van stoplicht 3 oranje
const int pin3Groen  = 38; // pin van stoplicht 3 groen
const int pin4Rood   = 29; // pin van stoplicht 4 rood
const int pin4Oranje = 31; // pin van stoplicht 4 oranje
const int pin4Groen  = 33; // pin van stoplicht 4 groen
const int pin5Rood   = 35; // pin van stoplicht 5 rood
const int pin5Oranje = 37; // pin van stoplicht 5 oranje
const int pin5Groen  = 39; // pin van stoplicht 5 groen
const int pin6Rood   = 22; // pin van stoplicht 6 rood
const int pin6Oranje = 24; // pin van stoplicht 6 oranje
const int pin6Groen  = 26; // pin van stoplicht 6 groen

const int pin7Rood  = 46; // pin van voetgangersstoplicht 7 rood
const int pin7Groen = 44; // pin van voetgangersstoplicht 7 groen
const int pin8Rood  = 42; // pin van voetgangersstoplicht 8 rood
const int pin8Groen = 40; // pin van voetgangersstoplicht 8 groen

const int pin7Knop  = 41; // pin van knop naast licht 7
const int pin8Knop  = 43; // pin van knop naast licht 8

// variabelen om waarden van sensoren en actuatoren te onthouden
int knop7 = 0;
int knop8 = 0;

// variabelen voor de toestanden
const int BORING = 1; // alle stoplichten ROOD
const int EXCITING = 2; // alle stoplichten ORANJE
const int KAMIKAZE = 3; // alle stoplicht GROEN
int toestand = BORING;
unsigned long toestandStartTijd = 0;

/*****************************************
   functies die je gebruikt maken
 *****************************************/
// geef kleuren naam, om je code leesbaarder te maken
const int ROOD   = 1;
const int ORANJE = 2;
const int GROEN  = 3;

void stoplicht(int welke, int kleur) {
  int pinRood   = 0;
  int pinOranje = 0;
  int pinGroen  = 0;

void setup() {


void loop() {
  // put your main code here, to run repeatedly:

}
