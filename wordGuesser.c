#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h> //comment this line out to make the game work on mac or linux
//constant for chances
#define CHANCES 5

//This clears thew input buffer after each input
void emptyInputBuffer() {
    int c;
    while ((c = getchar()) != '\n');
}
//This function creates a random number between 0 to 4
int random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

//This function returns a random word from the array, 
//using the random number generated for index
char* randomWord(){
    char *words[29] = {"PROGRAMMING", "SOFTWARE", "HARDWARE", "DATABASE", "ALGORITHM", 
"NETWORK", "CYBERSECURITY", "PYTHON", "JAVASCRIPT", "LINUX",
"OPERATING", "PERIPHERAL", "INTERFACE", "VIRTUALISATION", "DEBUGGING",
 "COMPILER", "FIRMWARE", "CRYPTOGRAPHY", "CACHE", "FLOPPY","HACKATHON", "RANSOMWARE", "BIOMETRICS", 
 "FIBEROPTIC", "TELECOMM", "CRYPTOCURRENCY", "SUPERCOMPUTER", "INTERNET", "MALWARE"};
    int rindex = random_number(0,28);
    return words[rindex];
    
}


//This is the main function
//it sets the game up, gets the inputs and compares arrays.
int main(){
    //seed the random number generator with the current time. 
    //This ensures that the sequence of random numbers is different
    // each time the program is run.
    srand(time(NULL));

    char* word = randomWord();
    
    //int chances = 5;
    
    int length = strlen(word);
    char fullWordList[length];
    char sy[1] = {"_"};

    //COPY WORD TO LIST
    for(int i = 0; i < length; i++){
        fullWordList[i] = word[i];
    } 
    char fullWord[length];
    char missingWord[length];
    //CREATE FULL WORD
    for(int i = 0; i < length; i++){
        fullWord[i] = fullWordList[i];
    } 
    //CREATE MISSING WORD
    for(int i = 0; i < length; i++){
        missingWord[i] = fullWordList[i];
    } 

    //REMOVE RANDOM LETTERS FROM WORD
    for(int i=0; i < 5; i++)
    {
        int min = 0; 
        int max = length -1;

        
        int rannum =  rand() % length-1;
        missingWord[rannum] = sy[0];//REPLACE WITH UNDERSORE
    }

    int chance = 5;
    for (int k=0; k<CHANCES; k++) {
        //PRINT MISSING LETTER WORD
        printf("----------------\n");
        for (int l=0; l<length; l++) {
            printf("%c", missingWord[l]);
        
        }
        //INPUT CHARACTER
        char letter;
        char uletter;
        printf("\n");
        printf("> ");
        letter = getchar();
        emptyInputBuffer();
        system("cls");     //comment this line to make the game work on linux and mac
        uletter = toupper(letter);
        for(int j=0; j<length;j++){
            if (fullWord[j]==uletter) {
                missingWord[j]=fullWord[j];          
            }
        }
        chance = chance -1;
        

        printf("----------------\n");
        printf("%d chances left \n", chance);

       int result = memcmp(fullWord, missingWord,length);
       //printf("----------%d-------\n",result );
       if(result==0){
        printf("----------------\nYOU WIN\n----------------\n");
        break;
       }    
    }

    for (int x =0;x< length; x++) {
        if (missingWord[x]==sy[0]) {
            printf("----------------\nYOU LOOSE\n----------------\n");
            break;
        }
    
    }

    printf("WORD:");
     for (int l=0; l<length; l++) {
            printf("%c", fullWord[l]);        
        }

    //keeps the app open
    char open;
    scanf("%c", &open);

    return 0;
}   
