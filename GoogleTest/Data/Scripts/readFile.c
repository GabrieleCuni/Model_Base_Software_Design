#include <stdio.h>
#include <stdlib.h>

unsigned char* readVect(char *fileName, int n){
    int count = 0; // 4800001
    unsigned char number, *array;
    
    FILE *fr;
    fr = fopen(fileName, "r");

    if( fr == NULL ) {
        printf("Errore in apertura del file");
        fflush(stdout);
        exit(1);
    }

    array = (unsigned char*) malloc((sizeof(unsigned char)*n));

    while( fscanf(fr, "%hhu", &number) != EOF ){
        array[count] = number;
        count++;
    }    
    fclose(fr);

    return array;
}

int countLines(){
    int count=0;
    unsigned char number;
    FILE *fr;
    fr = fopen("input_stimuli.txt", "r");

    if( fr == NULL ) {
        printf("Errore in apertura del file");
        fflush(stdout);
        exit(1);
    }

    while( fscanf(fr, "%hhu", &number) != EOF ){
        count++;
    }    
    fclose(fr);
    // printf("Lines: %d", count);
    return count;
}


int main(int argc, char **argv) {
    int i, n = countLines();
    unsigned char *array;
    
    array = readVect("input_stimuli.txt", n);

    for(i=0; i < n; i++){
        printf("Number(%d): %hhu\n",i, array[i]);
        fflush(stdout);
    }
    
    free(array);
    
    
}