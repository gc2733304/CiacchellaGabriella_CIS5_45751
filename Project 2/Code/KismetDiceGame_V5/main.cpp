/* 
 * File:   main.cpp
 * Author: Gabriella Ciacchella
 * Created on July 26, 2019, 4:40 PM
 * Purpose: Create the dice game Kismet
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //Srand to set the seed
#include <iomanip>   //Format the output
#include <ctime>     //Time for rand
#include <fstream>   //File I/O
#include <string>    //String library
#include <cmath>     //Math library
using namespace std; //Name-space under which system libraries exist

//User Libraries - None

//Global Constants - None

//Function Prototypes 
int display(int);
void whoWon(int, int, float&, float&);
void diceSet(int[], int);
void prntTbl(int[], int);
void bublSrt(int[], int);
bool binSrch(int[], int, int, int &);

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare game variables
    string fileIn;  //File that will have inputs
    int rndSum, power, rndSum1, rndSum2;  //number of rounds, the round sum, round sum for each player, and the amount of dice
    int maxGame, play;    //Max amount of games 
    int d1, d2, d3, d4, d5;  // Will display what number value the dice got
    int index;  //Used for bool function
    float totGame, ratio;  //Total games played
    static int gameSum, gameSum1, gameSum2;  //Total points accumulated through the rounds
    char re, game;  //Ability to re-roll and to play the game again
    
    //Initialize variables
    const int ROWS = 6, COLS = 2, SIZE = 12;  //Sizes for arrays
    int tbl[ROWS][COLS];  //2D Array used for table
    int tbl2[SIZE];  //1D Array used for sorting
    int nRounds = 6, die = 0;  //There are 6 rounds in a game of Kismet
    int numGame = 2;  //Keeps track of how many games played during run of code
    int die1 = 1, die2 = 1, die3 = 1, die4 = 1, die5 = 1;  //Set dice
    int N = 5, val = 15;  //Specific values for functions
    int dice[N];  //Array for setting dice in function
    float wins = 0, losses = 0;  //Keeps track of wins/loses when playing against computer
    const int MAXNUMB = 1000;  //Sets maximum amount of games 
    const float PERCENT = 100.0f;  //Used for calculation of percentages
    
    //opening and writing into files
    ifstream in;  //Input file
    ofstream out;  //Output file
    char fileOut[] = {"stats.dat"};
    maxGame = MAXNUMB;  //More than enough for a maximum of games to be played
    fileIn = "nGames.dat";  //File with inputs of keeping track of how many games
    
    cout<<setw(35)<<"Kismet\n";
    cout<<"-------------------------------------------------------------------\n";
    
    in.open(fileIn.c_str());  //opening and writing into a file
    out.open(fileOut);  //opening and outputting a file
    
    int beg = time(0);  //Time game play
    
    play = display(play);  //First function
    
    //Input Validation
    while (play != 1 && play != 2)
    {
        cout<<"\nError! You must choose 1 or 2!\n";
        cout<<"(Enter 1 for playing by yourself, 2 for playing against the computer)\n";
        cin>>play;
    }
    
    //Play the game with the right amount of rounds by yourself
    if (play == 1)
    {
        do
        {
            while(in>>numGame);
            numGame = numGame > maxGame?maxGame:numGame;  //keeps from going over limit of max games

            totGame += (numGame / 2);  //Displays how many games played in one run of code

            for (int round = 1; round <= nRounds; round++)
            { 
                //sets dice up to produce random number 
                diceSet(dice, N);

                //Displays the dice value
                d1 = dice[0] + 0;  
                d2 = dice[1] + 0;  
                d3 = dice[2] + 0; 
                d4 = dice[3] + 0;
                d5 = dice[4] + 0;

                cout<<endl;
                cout<<setw(35)<<"Round "<<round<<endl;
                cout<<"* Round Results: "<<endl;
                cout<<"* Dice 1: "<<d1<<endl;
                cout<<"* Dice 2: "<<d2<<endl;
                cout<<"* Dice 3: "<<d3<<endl;
                cout<<"* Dice 4: "<<d4<<endl;
                cout<<"* Dice 5: "<<d5<<endl;
                cout<<endl;
                cout<<"Would you like to re-roll any dice? <y/n>"<<endl;
                cin>>re;
                
                //Input Validation
                while (re != 'y' && re != 'Y' && re != 'n' && re != 'N')
                {
                    cout<<"\nError! You must choose y or n!\n";
                    cout<<"Would you like to re-roll any dice? <y/n>"<<endl;
                    cin>>re;
                }

                if (re == 'y' || re == 'Y')
                {
                    while (re == 'y' || re == 'Y')
                    {
                        cout<<"What dice would you like to re-roll? (Input only one dice)"<<endl;
                        cin>>die;
                        if (die == 1)
                        {
                            die1 = rand() % 6 + 1;  //[1,6]
                            d1 = die1 + 0;  //Displays the dice value
                            cout<<"Dice 1: "<<d1<<endl;
                        }
                        else if (die == 2)
                        {
                            die2 = rand() % 6 + 1;  //[1,6]
                            d2 = die2 + 0;  //Displays the dice value
                            cout<<"Dice 2: "<<d2<<endl;
                        }
                        else if (die == 3)
                        {
                            die3 = rand() % 6 + 1;  //[1,6]
                            d3 = die3 + 0;  //Displays the dice value
                            cout<<"Dice 3: "<<d3<<endl;
                        }
                        else if (die == 4)
                        {
                            die4 = rand() % 6 + 1;  //[1,6]
                            d4 = die4 + 0;  //Displays the dice value
                            cout<<"Dice 4: "<<d4<<endl;
                        }
                        else if (die == 5)
                        {
                            die5 = rand() % 6 + 1;  //[1,6]
                            d5 = die5 + 0;  //Displays the dice value
                            cout<<"Dice 5: "<<d5<<endl;
                        }   
                        cout<<"Would you like to re-roll any other dice? <y/n>"<<endl;
                        cin>>re;
                    }
                } 
                rndSum = d1 + d2 + d3 + d4 + d5;
                cout<<"Round "<<round<<" Total: "<<rndSum<<endl;
                gameSum += rndSum;
            } 
            int end = time(0);  //End time of Game play

            //Output the total game points 
            cout<<"\n-------------------------------------------------------------------\n";
            cout<<"Total time to play this game in integer seconds = "<<end - beg<<" seconds.\n";
            cout<<"Your total amount of points for the whole game is "<<gameSum<<" points.\n";
            cout<<"Would you like to play again? <y/n>"<<endl;
            cin>>game;
            
            //Input Validation
            while (game != 'y' && game != 'Y' && game != 'n' && game != 'N')
            {
                cout<<"\nError! You must choose y or n!\n";
                cout<<"Would you like to play again? <y/n>"<<endl;
                cin>>game;
            }
            
            //Game stays on or turns off
            if (game == 'y' || game == 'Y')
            {
                power = 1;  //Game stays on and repeats
                gameSum = 0;  //Resets the game sum
            }
            else 
            {
                power = 0;  //Game ends
                cout<<"\n-------------------------------------------------------------------\n";
                cout<<"Number of Games Played = "<<totGame<<endl;
                cout<<"\nThank you for playing!"<<endl;
                totGame = 1;
            }

            //Output to file
            out<<"Playing by yourself: \n";
            out<<"Total time to play this game in integer seconds = "<<end - beg<<" seconds.\n";
            out<<"Your total amount of points for the whole game is "<<gameSum<<" points.\n";
            out<<"Number of Games Played = "<<totGame<<endl;
        }
        while (power);
    }
    else if (play == 2)  //Play the game against the computer
    {
        do
        {
            while(in>>numGame);
            numGame = numGame > maxGame?maxGame:numGame;  //keeps from going over limit of max games

            totGame += (numGame / 2);  //Displays how many games played in one run of code

            for (int round = 0; round <= nRounds - 1; round++)
            { 
                //sets dice up to produce random number for you 
                diceSet(dice, N);
                
                //Displays the dice value for you
                d1 = dice[0] + 0;
                d2 = dice[1] + 0;
                d3 = dice[2] + 0;
                d4 = dice[3] + 0;
                d5 = dice[4] + 0;

                cout<<endl;
                cout<<setw(35)<<"Round "<<round + 1<<endl;
                
                //Your turn
                cout<<"You: \n";
                cout<<"* Round Results: "<<endl;
                cout<<"* Dice 1: "<<d1<<endl;
                cout<<"* Dice 2: "<<d2<<endl;
                cout<<"* Dice 3: "<<d3<<endl;
                cout<<"* Dice 4: "<<d4<<endl;
                cout<<"* Dice 5: "<<d5<<endl;
                cout<<endl;
                cout<<"Would you like to re-roll any dice? <y/n>"<<endl;
                cin>>re;

                //Input Validation
                while (re != 'y' && re != 'Y' && re != 'n' && re != 'N')
                {
                    cout<<"\nError! You must choose y or n!\n";
                    cout<<"Would you like to re-roll any dice? <y/n>"<<endl;
                    cin>>re;
                }
                
                if (re == 'y' || re == 'Y')
                {
                    while (re == 'y' || re == 'Y')
                    {
                        cout<<"What dice would you like to re-roll? (Input only one dice)"<<endl;
                        cin>>die;
                        if (die == 1)
                        {
                            die1 = rand() % 6 + 1;  //[1,6]
                            d1 = die1 + 0;  //Displays the dice value
                            cout<<"Dice 1: "<<d1<<endl;
                        }
                        else if (die == 2)
                        {
                            die2 = rand() % 6 + 1;  //[1,6]
                            d2 = die2 + 0;  //Displays the dice value
                            cout<<"Dice 2: "<<d2<<endl;
                        }
                        else if (die == 3)
                        {
                            die3 = rand() % 6 + 1;  //[1,6]
                            d3 = die3 + 0;  //Displays the dice value
                            cout<<"Dice 3: "<<d3<<endl;
                        }
                        else if (die == 4)
                        {
                            die4 = rand() % 6 + 1;  //[1,6]
                            d4 = die4 + 0;  //Displays the dice value
                            cout<<"Dice 4: "<<d4<<endl;
                        }
                        else if (die == 5)
                        {
                            die5 = rand() % 6 + 1;  //[1,6]
                            d5 = die5 + 0;  //Displays the dice value
                            cout<<"Dice 5: "<<d5<<endl;
                        }   
                        cout<<"Would you like to re-roll any other dice? <y/n>"<<endl;
                        cin>>re;
                    }
                }            
                rndSum1 = d1 + d2 + d3 + d4 + d5;
                cout<<"Round "<<round + 1<<" Total for You: "<<rndSum1<<endl;
                tbl[round][0] = rndSum1;
                gameSum1 += rndSum1;
                
                //Computer's turn
                //sets dice up to produce random number for computer
                diceSet(dice, N);
                
                //Displays the dice value for Computer
                d1 = dice[0] + 0;  
                d2 = dice[1] + 0;  
                d3 = dice[2] + 0;  
                d4 = dice[3] + 0;
                d5 = dice[4] + 0;

                cout<<"\nComputer: \n";
                cout<<"* Round Results: "<<endl;
                cout<<"* Dice 1: "<<d1<<endl;
                cout<<"* Dice 2: "<<d2<<endl;
                cout<<"* Dice 3: "<<d3<<endl;
                cout<<"* Dice 4: "<<d4<<endl;
                cout<<"* Dice 5: "<<d5<<endl;
                cout<<endl;           
                rndSum2 = d1 + d2 + d3 + d4 + d5;
                cout<<"Round "<<round + 1<<" Total for Computer: "<<rndSum2<<endl;
                tbl[round][1] = rndSum2;
                cout<<"--------------------------------\n";
                gameSum2 += rndSum2;
            } 
            int end = time(0);  //End time of Game play

            //Output the total game points 
            cout<<"\n-------------------------------------------------------------------\n";
            cout<<"Total time to play this game in integer seconds = "<<end - beg<<" seconds.\n";
            cout<<"You: Total points of the game = "<<gameSum1<<endl;
            cout<<"Computer: Total points of the game = "<<gameSum2<<endl;
            
            whoWon(gameSum1, gameSum2, wins, losses);  //Second function
            
            //Table to display the round totals of the game
            int n = 1;
            cout<<"\nHere is a table displaying the round totals\n";
            cout<<"     | You  Computer\n";
            cout<<"----------------------------------\n";
            for (int i = 0; i < ROWS; ++i)
            {
                switch (n)
                {
                    case 1: cout<<"R  "<<n<<" |"; break;
                    case 2: cout<<"O  "<<n<<" |"; break;
                    case 3: cout<<"U  "<<n<<" |"; break;
                    case 4: cout<<"N  "<<n<<" |"; break;
                    case 5: cout<<"D  "<<n<<" |"; break;
                    case 6: cout<<"S  "<<n<<" |"; break;
                }
                n++;
                for (int j = 0; j < COLS; ++j)
                {
                    cout<<"  "<<tbl[i][j];
                }
                cout<<endl;
            }
            
            cout<<"Would you like to play again? <y/n>"<<endl;
            cin>>game;
            
            //Input Validation
            while (game != 'y' && game != 'Y' && game != 'n' && game != 'N')
            {
                cout<<"\nError! You must choose y or n!\n";
                cout<<"Would you like to play again? <y/n>"<<endl;
                cin>>game;
            }
            
            //Game stays on or turns off
            if (game == 'y' || game == 'Y')
            {
                power = 1;  //Game stays on and repeats
                gameSum1 = 0;  //Resets game sum for you
                gameSum2 = 0; //Resets game sum for computer
            }
            else 
            {
                power = 0;  //Game ends
                cout<<"\n-------------------------------------------------------------------\n";
                cout<<"Number of Games Played = "<<totGame<<endl;
                cout<<"Your Wins: "<<wins<<endl;
                cout<<"Your Losses: "<<losses<<endl;
                cout<<showpoint<<setprecision(1)<<fixed;
                cout<<"The percentage of wins = "
                    <<static_cast<float>(wins) / totGame * PERCENT<<"%"<<endl;
                cout<<"The percentage of losses = "
                    <<static_cast<float>(losses) / totGame * PERCENT<<"%"<<endl;
                cout<<"\nRatio of longest to shorter game: "<<log10(end - beg)<<endl;

                int n = 0;
                for (int i = 0; i < ROWS; i++)
                {
                    for (int j = 0; j < COLS; j++)
                    {
                        tbl2[n] = tbl[i][j];
                        n++;
                    }
                }
                bublSrt(tbl2, SIZE);  //Sort the round totals from smallest to largest
                prntTbl(tbl2, SIZE);  //Print the sorted totals
                binSrch(tbl2, SIZE, val, index);  //Search for value 15
                if (tbl2[index] == 15)
                {
                    cout<<val<<", half of the max points you could get, was found in index ";
                    cout<<index<<".\n";
                }
                else if (tbl2[index] != 15)
                {
                    cout<<"15, half of the max points you could get, is not in the round totals.\n";
                }
                cout<<"\nThank you for playing!"<<endl;
                totGame = 1;
            }

            //Output to file
            out<<"Play against computer: \n";
            out<<"Total time to play this game in integer seconds = "<<end - beg<<" seconds.\n";
            out<<"You: Total amount of points for the whole game is "<<gameSum1<<" points.\n";
            out<<"Computer: Total amount of points for the whole game is "<<gameSum2<<" points.\n";
            out<<"Your Wins: "<<wins<<endl;
            out<<"Your Losses: "<<losses<<endl;
            out<<"Number of Games Played = "<<totGame<<endl;
        }
        while (power);
    }

    //Exit stage right!
    in.close();
    out.close();

    return 0;
}  

int display(int play)  //Function displays instructions and choices in beginning
{
    char power;
    
    cout<<setw(43)<<"Basic Rules of the Game\n";
    cout<<"- Five dice will be thrown and you will have the option of \n";
    cout<<"re-rolling any dice an infinite amount of times\n";
    cout<<"- There are 6 rounds in a single game of Kismet\n";
    cout<<"- Each round, after any re-rolling, the round total will be displayed\n";
    cout<<"- The goal is to get the highest amount of points\n";
    
    cout<<"\nWould you like to play? <Y/N> \n";
    cin>>power;
    
    //Input validation
    while(power != 'Y' && power != 'y' && power != 'N' && power != 'n')
    {
        cout<<"\nError! You must choose y or n!\n";
        cout<<"Would you like to play? <Y/N> \n";
        cin>>power;
    }
    
    if (power == 'Y' || power == 'y')
    {
    cout<<"\nWould you like to play alone or play against the computer?";
    cout<<"\n(Enter 1 for playing by yourself, 2 for playing against the computer)\n";
    cin>>play;
    
        switch (play)
        {
            case 1: cout<<"You chose to play by yourself!\n"; break;
            case 2: cout<<"You chose to play against the computer!\n"; break;
        }
        return play;
    }
    else if (power == 'N' || power == 'n')
    {
        cout<<"You've decided not to play\n Have a nice day!\n";
        exit(0);
    }
}

void whoWon(int gameSum1, int gameSum2, float& wins, float& losses)  //Function displays who won 
{
    if (gameSum1 > gameSum2)
    {
        cout<<"Congratulations!!!  You won the game!\n";
        cout<<"Better luck next time computer!\n";
        wins++;
    }
    else
    {
        cout<<"Congratulations computer!!!  It won the game!\n";
        cout<<"Better luck next time!\n";
        losses++;
    }
}

void diceSet(int d[], int N)  //Sets dice
{
    for (int i = 0; i < N; i++)
    {
        d[i] = rand() % 6 + 1;
    }
}

void prntTbl(int tbl2[], int SIZE)  //Prints sorted totals
{
    cout<<"\nHere is the round totals sorted:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout<<tbl2[i]<<" ";
    }
    cout<<endl;
}

void bublSrt(int tbl2[], int SIZE)  //Sorts round totals
{
   bool swap;
    do
    {
        swap = false;
        for(int i = 0; i < SIZE - 1; i++)
        {
            if(tbl2[i] > tbl2[i + 1])
            {
                int numb = tbl2[i];
                tbl2[i] = tbl2[i + 1];
                tbl2[i + 1] = numb;
                swap = true;
            }
        }
    }
    while(swap); 
}

bool binSrch(int tbl2[], int SIZE, int val, int &part)  //Searches for specific value
{
    int first = 0, last = SIZE - 1;
    do 
    {
        part = (last + first) / 2;
        if (tbl2[part] == val)
        {
            return true;
        }
        if (tbl2[part] < val)
        {
            first = part + 1;
        }
        else
        {
            last = part - 1;
        }
    }
    while (first <= last);
    return false;
}