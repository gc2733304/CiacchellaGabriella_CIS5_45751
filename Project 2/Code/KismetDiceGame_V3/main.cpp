/* 
 * File:   main.cpp
 * Author: Gabriella Ciacchella
 * Created on July 24, 2019, 7:38 PM
 * Purpose: Create the dice game Kismet
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //Srand to set the seed
#include <iomanip>   //Format the output
#include <ctime>     //Time for rand
#include <fstream>   //File I/O
#include <string>    //String library
using namespace std; //Name-space under which system libraries exist

//User Libraries - None

//Global Constants - None

//Function Prototypes 
int display(int);
void whoWon(int, int);

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare game variables
    string fileIn;  
    int rndSum, dice, power, rndSum1, rndSum2;  //number of rounds, the round sum, and the amount of dice
    int maxGame, totGame, play;    //Max amount of games and total amount of games played
    int d1, d2, d3, d4, d5;  // Will display what number value the dice got
    static int gameSum, gameSum1, gameSum2;  //Total points accumulated through the rounds
    char re, game;  //Ability to re-roll and to play the game again
    
    //Initialize variables
    int nRounds = 6, die = 0;  //There are 6 rounds in a game of Kismet
    int numGame = 2;  //Keeps track of how many games played during run of code
    int die1 = 1, die2 = 1, die3 = 1, die4 = 1, die5 = 1;
    const int MAXNUMB = 1000;
    
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
    
    play = display(play);
    
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
                char die1 = rand() % 6 + 1;  //[1,6]
                char die2 = rand() % 6 + 1;  //[1,6]
                char die3 = rand() % 6 + 1;  //[1,6]
                char die4 = rand() % 6 + 1;  //[1,6]
                char die5 = rand() % 6 + 1;  //[1,6]

                //Displays the dice value
                d1 = die1 + 0;  
                d2 = die2 + 0;  
                d3 = die3 + 0;  
                d4 = die4 + 0;
                d5 = die5 + 0;

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
                rndSum = die1 + die2 + die3 + die4 + die5;
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

            for (int round = 1; round <= nRounds; round++)
            { 
                //sets dice up to produce random number for you 
                char die1 = rand() % 6 + 1;  //[1,6]
                char die2 = rand() % 6 + 1;  //[1,6]
                char die3 = rand() % 6 + 1;  //[1,6]
                char die4 = rand() % 6 + 1;  //[1,6]
                char die5 = rand() % 6 + 1;  //[1,6]

                //Displays the dice value for you
                d1 = die1 + 0;  
                d2 = die2 + 0;  
                d3 = die3 + 0;  
                d4 = die4 + 0;
                d5 = die5 + 0;

                cout<<endl;
                cout<<setw(35)<<"Round "<<round<<endl;
                
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
                rndSum1 = die1 + die2 + die3 + die4 + die5;
                cout<<"Round "<<round<<" Total for You: "<<rndSum1<<endl;
                gameSum1 += rndSum1;
                
                //Computer's turn
                //sets dice up to produce random number for Computer 
                die1 = rand() % 6 + 1;  //[1,6]
                die2 = rand() % 6 + 1;  //[1,6]
                die3 = rand() % 6 + 1;  //[1,6]
                die4 = rand() % 6 + 1;  //[1,6]
                die5 = rand() % 6 + 1;  //[1,6]

                //Displays the dice value for Computer
                d1 = die1 + 0;  
                d2 = die2 + 0;  
                d3 = die3 + 0;  
                d4 = die4 + 0;
                d5 = die5 + 0;

                cout<<"\nComputer: \n";
                cout<<"* Round Results: "<<endl;
                cout<<"* Dice 1: "<<d1<<endl;
                cout<<"* Dice 2: "<<d2<<endl;
                cout<<"* Dice 3: "<<d3<<endl;
                cout<<"* Dice 4: "<<d4<<endl;
                cout<<"* Dice 5: "<<d5<<endl;
                cout<<endl;
            
                rndSum2 = die1 + die2 + die3 + die4 + die5;
                cout<<"Round "<<round<<" Total for Computer: "<<rndSum2<<endl;
                gameSum2 += rndSum2;
            } 
            int end = time(0);  //End time of Game play

            //Output the total game points 
            cout<<"\n-------------------------------------------------------------------\n";
            cout<<"Total time to play this game in integer seconds = "<<end - beg<<" seconds.\n";
            cout<<"You: Total points of the game = "<<gameSum1<<endl;
            cout<<"Computer: Total points of the game = "<<gameSum2<<endl;
            
            whoWon(gameSum1, gameSum2);
            
            cout<<"Would you like to play again? <y/n>"<<endl;
            cin>>game;
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
            out<<"Play against computer: \n";
            out<<"Total time to play this game in integer seconds = "<<end - beg<<" seconds.\n";
            out<<"You: Total amount of points for the whole game is "<<gameSum1<<" points.\n";
            out<<"Computer: Total amount of points for the whole game is "<<gameSum2<<" points.\n";
            out<<"Number of Games Played = "<<totGame<<endl;
        }
        while (power);
    }

    //Exit stage right!
    in.close();
    out.close();

    return 0;
}  

int display(int play)
{
    cout<<setw(35)<<"Basic Rules of the Game\n";
    cout<<"- Five dice will be thrown and you will have the option of re-rolling";
    cout<<"any dice and infinite amount of times\n";
    cout<<"- There are 6 rounds in a single game of Kismet\n";
    cout<<"- Each round, after any re-rolling, the round total will be displayed\n";
    cout<<"- The goal is to get the highest amount of points\n";
    
    cout<<"\nWould you like to play alone or play against the computer?";
    cout<<"\n(Enter 1 for playing by yourself, 2 for playing against the computer)\n";
    cin>>play;
    
    if (play == 1)
    {
        cout<<"You chose to play by yourself!\n";
        return play;
    }
    else if (play == 2)
    {
        cout<<"You chose to play against the computer!\n";
        return play;
    }
}

void whoWon(int gameSum1, int gameSum2)
{
    if (gameSum1 > gameSum2)
    {
        cout<<"Congratulations!!!  You won the game!\n";
        cout<<"Better luck next time computer!\n";
    }
    else
    {
        cout<<"Congratulations computer!!!  It won the game!\n";
        cout<<"Better luck next time!\n";
    }
}