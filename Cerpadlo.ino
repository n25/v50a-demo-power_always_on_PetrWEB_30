//pin23 na zapinaní-vypínání čerpadla
#define vccPin 5
const int cerpadlo_motor = 23;
const int hladinoMer = 36;

int cerpadloStav = 0;
int hladinoMerStav = 0;
unsigned long cas = 0;

void Cerpadlo_setup() {
  
  pinMode(hladinoMer, INPUT);
  pinMode(cerpadlo_motor, OUTPUT);
  pinMode(vccPin, OUTPUT);
  digitalWrite(cerpadlo_motor, LOW);
  digitalWrite(vccPin, LOW);
 

  
}

void Cerpadlo_loop() {
  
  // pokud je rozdíl mezi aktuálním časem a posledním
  // uloženým větší než 3000 ms, proveď měření
  if (millis() - cas > 10000) {
    // zapneme napájecí napětí pro modul s krátkou pauzou
    // pro ustálení
    digitalWrite(vccPin, HIGH);
    delay(200);
    // načtení digitální hodnoty do proměnných
    hladinoMerStav = digitalRead(hladinoMer);
    // ukončení řádku na sériové lince
    Serial.println();
    // vypnutí napájecího napětí pro modul
    digitalWrite(vccPin, LOW);
    // uložení aktuálního času do proměnné pro další kontrolu
    cas = millis();
  }

  if (hladinoMerStav == LOW) {
    digitalWrite(cerpadlo_motor, LOW);
    Serial.println();
    Serial.println("nízká hladina, čerpadlo vypínám");
    Serial.println();
  } else {
    
    digitalWrite(cerpadlo_motor, HIGH);
    Serial.println();
    Serial.println("čerpadlo zapínám");
    Serial.println();
  }

  cerpadloStav = digitalRead(cerpadlo_motor);   

  if (cerpadloStav == HIGH) {
    //napiš na display a na web čerpadlo běží
    Serial.println("čerpadlo běží-on");
    
    
    }

}
