/*
Assignment #2 LOTTO
This Program will allow the user to play a lotto game. They will be shown a menu which gives them many different options.
Option 1 will allow the user to input 6 different numbers  ranging from 1-42 which will be stored into an array. Using functions the numbers will be
sorted and shown on screen. The user can then win the game depending on how many matches with the winning numbers they have.
In the menu the user will have the option to see how many times they have chosen a certain number. The user will also have the option
to outright end the program. 

Owen Jones C21377551 TU857/1
11/03/2022 
*/
#include <stdio.h>
#include <stdlib.h>

#define LOTTO 6
#define LIM 42
#define FIRST 1
#define SECOND 2
#define THIRD 3
#define FOURTH 4
#define FIFTH 5
#define SIXTH 6
#define C1 1
#define C2 3
#define C3 5
#define C4 7
#define C5 9
#define C6 11


//Declaring functions for menu option 1-5.
int Numbers(int[],int[],int);
int Display(int[]);
int Bubble(int[]);
int Win(int[]);
int Counter(int[]);

int main(void)
{
    int Lottery[LOTTO] = {0};
    int counts[LIM+1] = {0};
    int i;
    int menu = 0;
    int correct;
    int allow = 0;
    int let = 0;

    //do while loop for menu and selections
    do
    {
        menu = 0;

        //displaying the menu for the user
        printf("\n================LOTTO GAME=================\n");
        printf("| 1.Enter 6 Numbers for the Lottery(1-42) |\n");
        printf("|-----------------------------------------|\n");
        printf("| 2. Display your chosen 6 lotto numbers  |\n");
        printf("|-----------------------------------------|\n");
        printf("| 3. Sort your Numbers in order.          |\n");
        printf("|-----------------------------------------|\n");
        printf("| 4. See if your numbers have won         |\n");
        printf("|-----------------------------------------|\n");
        printf("| 5. Display the frequency of your choices|\n");
        printf("|-----------------------------------------|\n");
        printf("| 6. End the Game                         |\n");
        printf("===========================================\n");
    
        //user input menu selection
        scanf("%d",&menu);

        //clears blanks space character inputs.
        while(getchar() != '\n');

        switch(menu)
        {
            
            //Option 1 in menu
            case FIRST:
            {
                allow = Numbers(Lottery,counts,let);
                break;
            }//end case 1

            //option 2 in menu
            case SECOND:
            {
                if(allow < 5)
                {
                    printf("\nERROR complete menu section 1 first!\n");
                    break;
                }

                else
                {
                    Display(Lottery);
                    break;
                }
            }  //end case 2
                
            //option 3 in menu
            case THIRD:
            {   
                
                if(allow < 5)
                {
                    printf("\nERROR complete menu section 1 first!\n");
                    break;
                }

                else
                {
                   Bubble(Lottery);
                    break;
                }
                
            }//end case 3

            //option 4 in menu
            case FOURTH:
            {
                if(allow < 5)
                {
                    printf("\nERROR complete menu section 1 first!\n");
                    break;
                }

                else
                {
                    Win(Lottery);
                    break;
                }
            }//end case 4

            //option 5 in menu
            case FIFTH:
            {
                if(allow < 5)
                {
                    printf("\nERROR complete menu section 1 first!\n");
                    break;
                }

                else
                {
                    Counter(counts);
                    break;
                }
                
            }//end case 5

        }//end switch
        

    }//end do while
    while(menu!=SIXTH);

    //error checking menu
    if (menu > SIXTH || menu < FIRST)   
    {
        printf("\nERROR you must select an option between 1-6\n");
    }  //end if

    //option 6 in menu
    if(menu = SIXTH)
    {
        printf("\n !Thank you for Playing!");
    }//end if

    return 0;
}//end main


//Function for menu option 1
int Numbers(int *(nums),int *(counts),int Allow)
{
    int i;
   
    printf("\n Enter 6 different numbers\n");

    for ( i = 0; i < LOTTO; i++)
    {
        //input lotto numbers
        scanf("%d", & *(nums + i));

        //error checking input        
        if (*(nums + i) >LIM || *(nums + i) < 0)
        {
            printf("\n Incorrect Number input! ENTER 1-42 ONLY. \n");
            Allow = 0;
            break;
        }//end if

        //shows the users number.
        if (*(nums + i) < LIM || *(nums + i) > 1)
        {
            counts[nums[i]]++;
            Allow++;
        }//end if

        //error checking input
        if(*(nums + i) == *(nums + i -FIRST) || *(nums + i) == *(nums + i -SECOND) || *(nums + i) == *(nums + i -THIRD) || *(nums + i) == *(nums + i -FOURTH) || *(nums + i) == *(nums + i -FIFTH))
        {
            printf("\n ERROR you can only enter the same number once RESTART!");
            Allow = 0;
            break;
        }//end if

    }//end for
    
    return Allow;
}//end function numbers

//function to display the users lottery numbers
int Display(int *(disp))
{
    int i;

    printf("\n The numbers you entered were :\n");

    //displays array with users numbers
    for( i = 0; i < LOTTO; i++)
    {
        printf("%d ", *(disp + i));
    }//end for

}//end function display

//function to sort users numbers in ascending order
int Bubble(int *(Bub))
{
    int j;
    int i;
    int temp;

    printf("\nI Will Now magically sort your Numbers in order\n");

    //bubble sort algorithm
    for ( i = 0; i < LOTTO-1 ; i++)
    {
        for ( j = 0; j < LOTTO-1 ; j++)
        {
            if(*(Bub + j) > *(Bub +j+1))
            {

                temp = *(Bub+j);
                *(Bub+j) = *(Bub +j+1);
                *(Bub +j+1) = temp;
            }//end if

        }//end for

    }//end for

    for( i = 0; i < LOTTO; i++)
    {
        printf("%d ", *(Bub+i));
    }//end for

}//end bubble function

//function to show if the user has won
int Win(int *(wins))
{
    int correct = 0;
    int i;

    //deciding how many correct numbers the user has got.
    for ( i = 0; i < LOTTO; i++)
    {
        if(*(wins + i) == C1 || *(wins + i) == C2 || *(wins + i) == C3)
        {
            correct++;
        }// end if

        if(*(wins + i) == C4 ||*(wins + i) == C5 || *(wins + i) == C6)
        {
            correct++;
        }//end if
    }//end for

    //switch statment to show users prize.
    switch(correct)
    {
        case FIRST: 
        {
            printf("\n Im sorry you didn't win this time\n");
            break;
                        
        }//end case 1

        case SECOND:
        {
            printf("\n Im sorry you didn't win this time\n");
            break;
                        
        }//end case
                    
        case THIRD:
        {
            printf("\n Congratulations You got 3 right!, You have won: A CINEMA PASS \n");
            break;
                        
        }//end case 3
                    
        case FOURTH:
        {
            printf("\n Congratulations You got 4 right!, You have won: A WEEKEND AWAY \n");
            break;
                        
        }//end case 4

        case FIFTH:
        {
            printf("\n Congratulations You got 5 right!, You have won: A NEW CAR \n");
            break;
                        
        }//end case 5

        case SIXTH:
        {
            printf("\n Congratulations You got 6 right!, You have won: THE JACKPOT!!!! \n");
            break;
                        
        }//end case 6
    }//end switch
}//end function win

//function to count number frequency
int Counter(int *(counts))
{
    int i;

    //displays number frequency
    for ( i = 0; i < LIM; i++)
    {
        printf("%d has been chosen %d times \n ", i+1 ,counts[i+1]);
    }//end for
    

}//end counter function



