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

// lampjes op de knoppen, die zitten niet op elk stoplichtenplein
const int pin7Wit   = 48; // pin van lamp in knop7 wit
const int pin8Wit   = 50; // pin van lamp in knop8 wit

// variabelen om waarden van sensoren en actuatoren te onthouden
int knop7 = 0;
int knop8 = 0;

// variabelen voor de toestanden
const int een = 1; // alle stoplichten in eerste toestand
const int twee = 2; // alle stoplichten in tweede toestand
const int drie = 3; // alle stoplicht in derde toestand
const int vier = 4; // alle stoplichten in vierde toestand
const int vijf = 5; // alle stoplichten in vijfde toestand
const int zes = 6; // alle stoplicht in zesde toestand
const int zeven = 7; // alle stoplichten in zevende toestand
const int acht = 8; // alle stoplichten in achtste toestand
const int negen = 9; // alle stoplicht in negende toestand
int toestand = een;
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

  switch (welke) {
    case 1:
      pinRood   = pin1Rood;
      pinOranje = pin1Oranje;
      pinGroen  = pin1Groen;
      break;
    case 2:
      pinRood   = pin2Rood;
      pinOranje = pin2Oranje;
      pinGroen  = pin2Groen;
      break;
    case 3:
      pinRood   = pin3Rood;
      pinOranje = pin3Oranje;
      pinGroen  = pin3Groen;
      break;
    case 4:
      pinRood   = pin4Rood;
      pinOranje = pin4Oranje;
      pinGroen  = pin4Groen;
      break;
    case 5:
      pinRood   = pin5Rood;
      pinOranje = pin5Oranje;
      pinGroen  = pin5Groen;
      break;
    case 6:
      pinRood   = pin6Rood;
      pinOranje = pin6Oranje;
      pinGroen  = pin6Groen;
      break;
    case 7:
      pinRood   = pin7Rood;
      pinGroen  = pin7Groen;
      break;
    case 8:
      pinRood   = pin8Rood;
      pinGroen  = pin8Groen;
      break;
    default:
      Serial.println("FOUT: stoplicht " + String(welke) + " bestaat niet");
      break;
  }
  if (kleur ==  ROOD) {
    digitalWrite(pinRood  , HIGH);
    digitalWrite(pinOranje, LOW );
    digitalWrite(pinGroen , LOW );
  }
  if (kleur ==  ORANJE) {
    if (welke == 7 || welke == 8) {
      Serial.println("FOUT: Voetgangerslicht kan niet op oranje");
    } else {
      digitalWrite(pinRood  , LOW );
      digitalWrite(pinOranje, HIGH);
      digitalWrite(pinGroen , LOW );
    }
  }
  if (kleur ==  GROEN) {
    digitalWrite(pinRood  , LOW );
    digitalWrite(pinOranje, LOW );
    digitalWrite(pinGroen , HIGH);
  }
}

/*****************************************
   setup() en loop()  [VOOR PSEUDOCODE ZIE STAP 4 PROJECTCODE]
 *****************************************/

void setup() {
  // enable console en stuur opstartbericht
  Serial.begin(9600);
  Serial.println("Stoplicht start");

  // zet pinmode voor leds
  pinMode(pin1Rood, OUTPUT);
  pinMode(pin1Oranje, OUTPUT);
  pinMode(pin1Groen, OUTPUT);
  pinMode(pin2Rood, OUTPUT);
  pinMode(pin2Oranje, OUTPUT);
  pinMode(pin2Groen, OUTPUT);
  pinMode(pin3Rood, OUTPUT);
  pinMode(pin3Oranje, OUTPUT);
  pinMode(pin3Groen, OUTPUT);
  pinMode(pin4Rood, OUTPUT);
  pinMode(pin4Oranje, OUTPUT);
  pinMode(pin4Groen, OUTPUT);
  pinMode(pin5Rood, OUTPUT);
  pinMode(pin5Oranje, OUTPUT);
  pinMode(pin5Groen, OUTPUT);
  pinMode(pin6Rood, OUTPUT);
  pinMode(pin6Oranje, OUTPUT);
  pinMode(pin6Groen, OUTPUT);
  pinMode(pin7Rood, OUTPUT);
  pinMode(pin7Groen, OUTPUT);
  pinMode(pin8Rood, OUTPUT);
  pinMode(pin8Groen, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pin7Knop, INPUT);
  pinMode(pin8Knop, INPUT);
  pinMode(pin7Wit, OUTPUT);
  pinMode(pin8Wit, OUTPUT);
  // witte lamp in knoppen aan (zit niet op elke versie van het stoplichtenplein)
  digitalWrite(pin8Wit, HIGH);
  digitalWrite(pin7Wit, HIGH);
}

void loop() {
  // lees sensorwaarden
  knop7 = digitalRead(pin7Knop);
  knop8 = digitalRead(pin8Knop);

  // bepaal toestand
  if (toestand == een) {
    if (millis() - toestandStartTijd > 5000) {
      toestandStartTijd = millis();
      toestand = twee;
      Serial.println("Nieuwe toestand: twee");
    }

  }
  
  if (toestand == twee) {
    if (millis() - toestandStartTijd > 1000) {
      toestandStartTijd = millis();
      toestand = drie;
      Serial.println("Nieuwe toestand: drie");
    }
  }

  if (toestand == drie) {
    if (millis() - toestandStartTijd > 5000) {
      toestandStartTijd = millis();
      toestand = vier;
      Serial.println("Nieuwe toestand: vier");
    }
    if (knop7 == HIGH || knop8 == HIGH) {
      toestand = zeven;
      Serial.println("Nieuwe toestand: zeven");
    }
  }

  if (toestand == vier) {
    if (millis() - toestandStartTijd > 1000) {
      toestandStartTijd = millis();
      toestand = vijf;
      Serial.println("Nieuwe toestand: vijf");
    }
  }

  if (toestand == vijf) {
    if (millis() - toestandStartTijd > 5000) {
      toestandStartTijd = millis();
      toestand = zes;
      Serial.println("Nieuwe toestand: zes");
    }
  }

  if (toestand == zes) {
    if (millis() - toestandStartTijd > 1000) {
      toestandStartTijd = millis();
      toestand = een;
      Serial.println("Nieuwe toestand: een");
    }
  }

  if (toestand == zeven) {
    if (millis() - toestandStartTijd > 1000) {
      toestandStartTijd = millis();
      toestand = acht;
      Serial.println("Nieuwe toestand: acht");
    }
  }

  if (toestand == acht) {
    if (millis() - toestandStartTijd > 5000) {
      toestandStartTijd = millis();
      toestand = negen;
      Serial.println("Nieuwe toestand: negen");
    }
  }
  
  if (toestand == negen) {
    if (millis() - toestandStartTijd > 1000) {
      toestandStartTijd = millis();
      toestand = vijf;
      Serial.println("Nieuwe toestand: vijf");
    }
  }

  // zet stoplichten conform toestand
  if (toestand == een) {
      stoplicht(1, ROOD); 
      stoplicht(2, ROOD); 
      stoplicht(3, ROOD); 
      stoplicht(4, GROEN); 
      stoplicht(5, GROEN); 
      stoplicht(6, ROOD); 
      stoplicht(7, GROEN); 
      stoplicht(8, GROEN); 
  }
  
  if (toestand == twee) {
      stoplicht(1, ROOD); 
      stoplicht(2, ROOD); 
      stoplicht(3, ROOD); 
      stoplicht(4, ORANJE); 
      stoplicht(5, ORANJE); 
      stoplicht(6, ROOD); 
      stoplicht(7, GROEN); 
      stoplicht(8, GROEN); 
  }
  
  if (toestand == drie) {
      stoplicht(1, GROEN); 
      stoplicht(2, GROEN); 
      stoplicht(3, GROEN); 
      stoplicht(4, ROOD); 
      stoplicht(5, ROOD); 
      stoplicht(6, ROOD); 
      stoplicht(7, ROOD); 
      stoplicht(8, ROOD); 
  }
  
  if (toestand == vier) {
      stoplicht(1, GROEN); 
      stoplicht(2, ORANJE); 
      stoplicht(3, ORANJE); 
      stoplicht(4, ROOD); 
      stoplicht(5, ROOD); 
      stoplicht(6, ROOD); 
      stoplicht(7, ROOD); 
      stoplicht(8, ROOD); 
  }
  
  if (toestand == vijf) {
      stoplicht(1, GROEN); 
      stoplicht(2, ROOD); 
      stoplicht(3, ROOD); 
      stoplicht(4, ROOD); 
      stoplicht(5, GROEN); 
      stoplicht(6, GROEN); 
      stoplicht(7, ROOD); 
      stoplicht(8, ROOD); 
  }
  
  if (toestand == zes) {
      stoplicht(1, ORANJE); 
      stoplicht(2, ROOD); 
      stoplicht(3, ROOD); 
      stoplicht(4, ROOD); 
      stoplicht(5, GROEN); 
      stoplicht(6, ROOD); 
      stoplicht(7, ROOD); 
      stoplicht(8, ROOD); 
  }
  
  if (toestand == zeven) {
      stoplicht(1, ORANJE); 
      stoplicht(2, ORANJE); 
      stoplicht(3, ORANJE); 
      stoplicht(4, ROOD); 
      stoplicht(5, ROOD); 
      stoplicht(6, ROOD); 
      stoplicht(7, ROOD); 
      stoplicht(8, ROOD); 
  }
  
  if (toestand == acht) {
      stoplicht(1, ROOD); 
      stoplicht(2, ROOD); 
      stoplicht(3, ROOD); 
      stoplicht(4, GROEN); 
      stoplicht(5, GROEN); 
      stoplicht(6, ROOD); 
      stoplicht(7, GROEN); 
      stoplicht(8, GROEN); 
  }
  
  if (toestand == negen) {
      stoplicht(1, ROOD); 
      stoplicht(2, ROOD); 
      stoplicht(3, ROOD); 
      stoplicht(4, ORANJE); 
      stoplicht(5, GROEN); 
      stoplicht(6, ROOD); 
      stoplicht(7, GROEN); 
      stoplicht(8, GROEN); 
  }

  // vertraging om te zorgen dat berichten op de seriele monitor leesbaar blijven
  delay(100);
}
