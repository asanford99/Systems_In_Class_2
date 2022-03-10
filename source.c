#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool squareCheck (int squarePar[3][3]){

    int sumCompare;
    int row;
    int column;

    sumCompare = squarePar[0][0] + squarePar[0][1] + squarePar[0][2];

    for (row = 1; row < 3; row++){

        if ((squarePar[row][0] + squarePar[row][1] + squarePar[row][2]) != sumCompare){

            return false;

        }

    }

    for (column = 0; column < 3; column++){

        if ((squarePar[0][column] + squarePar[1][column] + squarePar[2][column]) != sumCompare){

            return false;

        }

    }

    if ((squarePar[0][0] + squarePar[1][1] + squarePar[2][2]) != sumCompare){

        return false;

    }

    if ((squarePar[0][2] + squarePar[1][1] + squarePar[2][0]) != sumCompare){

        return false;

    }

    return true;

}

int main (){

    int square[3][3];
    long long squaresGenerated = 0;
    int squareNum;
    int row;
    int column;

    
    bool oneUsed = false;
    bool twoUsed = false;
    bool threeUsed = false;
    bool fourUsed = false;
    bool fiveUsed = false;
    bool sixUsed = false;
    bool sevenUsed = false;
    bool eightUsed = false;
    bool nineUsed = false;

    time_t t;

    srand((unsigned) time(&t));

    GenerateSquare:

    oneUsed = false;
    twoUsed = false;
    threeUsed = false;
    fourUsed = false;
    fiveUsed = false;
    sixUsed = false;
    sevenUsed = false;
    eightUsed = false;
    nineUsed = false;

    for (row = 0; row < 3; row++){

        for (column = 0; column < 3; column++){

            GenerateNumber:

            squareNum = ((rand() % 9) + 1);

            switch (squareNum){

                case 1:
                    if (oneUsed == true){
                        goto GenerateNumber;
                    }
                    
                    oneUsed = true;

                    square[row][column] = 1;

                    break;

                case 2:
                    if (twoUsed == true){
                        goto GenerateNumber;
                    }
                    
                    twoUsed = true;

                    square[row][column] = 2;

                    break;

                case 3:
                    if (threeUsed == true){
                        goto GenerateNumber;
                    }
                    
                    threeUsed = true;

                    square[row][column] = 3;

                    break;

                case 4:
                    if (fourUsed == true){
                        goto GenerateNumber;
                    }
                    
                    fourUsed = true;

                    square[row][column] = 4;

                    break;

                case 5:
                    if (fiveUsed == true){
                        goto GenerateNumber;
                    }
                    
                    fiveUsed = true;

                    square[row][column] = 5;

                    break;

                case 6:
                    if (sixUsed == true){
                        goto GenerateNumber;
                    }
                    
                    sixUsed = true;

                    square[row][column] = 6;

                    break;

                case 7:
                    if (sevenUsed == true){
                        goto GenerateNumber;
                    }
                    
                    sevenUsed = true;

                    square[row][column] = 7;

                    break;

                case 8:
                    if (eightUsed == true){
                        goto GenerateNumber;
                    }
                    
                    eightUsed = true;

                    square[row][column] = 8;

                    break;

                case 9:
                    if (nineUsed == true){
                        goto GenerateNumber;
                    }
                    
                    nineUsed = true;

                    square[row][column] = 9;

                    break;

            }

           

        }

    }


    squaresGenerated++;

    if (squareCheck(square) == true){

        printf ("[%d %d %d]\n", square[0][0], square[0][1], square[0][2]);
        printf ("[%d %d %d]\n", square[1][0], square[1][1], square[1][2]);
        printf ("[%d %d %d]\n", square[2][0], square[2][1], square[2][2]);
        printf ("Success after %d squares generated.", squaresGenerated);

    }
    else{

        goto GenerateSquare;

    }
    




    return 0;
}