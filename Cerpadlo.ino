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
<<<<<<< HEAD
    delay(200);
=======
    delay(200); // delay se pokuž možno vyhni, zastaví celý procesor a nic nedělá
>>>>>>> 0b9c47b5d8f8a02fedcce397a8ac25f5f77a4d75
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
<<<<<<< HEAD
    
=======
    delay(60000); // to samé 60s se nebude nic dít, proč to tu máš
>>>>>>> 0b9c47b5d8f8a02fedcce397a8ac25f5f77a4d75
    digitalWrite(cerpadlo_motor, HIGH);
    Serial.println();
    Serial.println("čerpadlo zapínám");
    Serial.println();
  }

  cerpadloStav = digitalRead(cerpadlo_motor);   

  if (cerpadloStav == HIGH) {
    //napiš na display a na web čerpadlo běží
    Serial.println("čerpadlo běží-on");
<<<<<<< HEAD
    
=======
    delay (20000); // a zase čekáme a hovno děláme :D
>>>>>>> 0b9c47b5d8f8a02fedcce397a8ac25f5f77a4d75
    
    }

}
