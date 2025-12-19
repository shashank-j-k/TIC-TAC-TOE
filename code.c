#include <stdio.h>
#include <stdlib.h>

char arNumbers[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void ShowBoard(void);
int CheckForWin(void);

int main(void)
{
    // system("cls");

    int iPlayer = 1;
    int iResult;
    int iInput;
    char chPut;

    do
    {
        ShowBoard();
        iPlayer = iPlayer % 2 ? 1 : 2;
        printf("\nPlayer %d turn : ", iPlayer);
        scanf("%d", &iInput);

        chPut = (iPlayer == 1) ? 'X' : 'O';
        if(arNumbers[iInput] - '0' == iInput)
            arNumbers[iInput] = chPut;
        else
        {    
            printf("Invalid Input\n");
            iPlayer --;

        }
        iResult = CheckForWin();
        if(iResult == 1)
            break;
        iPlayer ++;
        
    } while (iResult != -1);

    ShowBoard();
    if(iResult == 1)
        printf("Player %d wins!\n", iPlayer);
    else 
        printf("Game is Draw\n");
    return 0;
}

void ShowBoard(void)
{
    printf("\t\t\t\t\t\t\t    TIC TAC TOE\n\n");
    printf("Player 1 is X\nPlayer 2 is O\n");

    printf("\t\t\t\t\t\t\t       |       |       \n");
    printf("\t\t\t\t\t\t\t   %c   |   %c   |    %c   \n", arNumbers[1], arNumbers[2], arNumbers[3]);
    printf("\t\t\t\t\t\t\t       |       |       \n");
    printf("\t\t\t\t\t\t\t-------|-------|-------\n");
    printf("\t\t\t\t\t\t\t       |       |       \n");
    printf("\t\t\t\t\t\t\t   %c   |   %c   |    %c   \n", arNumbers[4], arNumbers[5], arNumbers[6]);
    printf("\t\t\t\t\t\t\t       |       |       \n");
    printf("\t\t\t\t\t\t\t-------|-------|-------\n");
    printf("\t\t\t\t\t\t\t       |       |       \n");
    printf("\t\t\t\t\t\t\t   %c   |   %c   |    %c   \n", arNumbers[7], arNumbers[8], arNumbers[9]);
    printf("\t\t\t\t\t\t\t       |       |       \n");

}

int CheckForWin(void)
{
    int iCounter;

    for(iCounter = 1; iCounter <= 9; iCounter ++)
    {
        if(iCounter == 1 || iCounter == 4 || iCounter == 7)
            if (arNumbers[iCounter] == arNumbers[iCounter + 1] && arNumbers[iCounter + 1] == arNumbers[iCounter + 2])
                return 1;

        if(iCounter == 1 || iCounter == 2 || iCounter == 3)
            if(arNumbers[iCounter] == arNumbers[iCounter + 3] && arNumbers[iCounter + 3] == arNumbers[iCounter + 6])
                return 1;
        
        if(iCounter == 1)
            if(arNumbers[iCounter] == arNumbers[iCounter + 4] && arNumbers[iCounter] == arNumbers[iCounter + 8])
                return 1;

        if(iCounter == 3)
            if(arNumbers[iCounter] == arNumbers[iCounter + 2] && arNumbers[iCounter] == arNumbers[iCounter + 4])
                return 1;
    }

    for(iCounter = 1; iCounter <= 9; iCounter ++)
    {
        if(arNumbers[iCounter] - '0' != iCounter)
            return 0;
    }

    return -1;
}