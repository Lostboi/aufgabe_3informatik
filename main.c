/* U5-Funktionen.c
 Programm zur Berechnung von der Oberflaeche,Volumen,Diagonale eines Würfels
 Autor/Autorin: Stephan Schmidt
 Datum: 16.01.2021
 Kontakt: stephan.schmidt@htwsaar.de
 Compile: gcc -Wall -pedantic main.c -o U5-funktionen -std=c99
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30

void init_random_number(void){
    long sec = 0L;
    time(&sec);
    srand(sec);
}

int get_random_number (int min, int max){
    int value = 0;
    int tmp = 0;
    if (min > max) { // min und max tauschen
        tmp = min; min = max; max = tmp;
    }
    value = rand();
    // auf min-max-Intervall abbilden
    value = (value % (max-min+1)) + min;
    return value;
}

void fuellen (int randomZahlen[], int anzahl){
    int min = 1;
    int max = 49;
    for(int i = 0 ; i<=anzahl; i++){
        randomZahlen[i] = get_random_number(min, max);
    }
}

int feld_ausgeben (int randomZahlen[], int anzahl){
    int minwert = 0;
    int zaehler = 0;
    for (int i = 0; i<=anzahl; i++){
        zaehler++;
        if (i == 0) {
            minwert=randomZahlen[i];
        }
        if (randomZahlen[i] < minwert){
            minwert=randomZahlen[i];
        }
        printf("%6.d", randomZahlen[i]);
        if (zaehler == 10){
            printf("\n");
            zaehler = 0;
        }
    }
    return minwert;
}

int anzahl_min (int randomZahl[], int anzahl, int minwert){
    int anzahlMinwert = 0;
    for (int i = 0; i<=anzahl; i++){
        if (randomZahl[i]==minwert){
            anzahlMinwert++;
        }
    }
    return anzahlMinwert;
}


int main() {
int randomZahlen[MAX] ={0};
int anzahlDesFeldes = 29;
int minwert = 0;
int anzahlMinwert = 0;
init_random_number();
printf("Zufallswerte zwischen 1 und 49\n");
fuellen(randomZahlen, anzahlDesFeldes);
minwert = feld_ausgeben(randomZahlen, anzahlDesFeldes);
anzahlMinwert = anzahl_min(randomZahlen, anzahlDesFeldes, minwert);
printf ("Kleinste Zufallszahl: %d kommt %d mal vor\n", minwert, anzahlMinwert);
return 0;
}
