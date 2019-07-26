/* 
 * File:   main.cpp
 * Author: Gabriella Ciacchella
 * Created on July 23, 2019, 9:53 PM
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

//Function Prototypes - None

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare game variables
    string fileIn;  
    int rndSum, dice, power;  //number of rounds, the round sum, and the amount of dice
    int maxGame, numGame, totGame;    //Max amount of games and how many games you have played
    int d1, d2, d3, d4, d5;  // Will display what number value the dice got
    static int gameSum;  //Total points accumulated through the rounds
    char re, game;  //Ability to re-roll and to play the game again
    
    //Initialize variables
    int nRounds = 6, die = 0;  //There are 6 rounds in a game of Kismet
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
    
    //Play the game with the right amount of rounds
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
        out<<"Total time to play this game in integer seconds = "<<end - beg<<" seconds.\n";
        out<<"Your total amount of points for the whole game is "<<gameSum<<" points.\n";
        out<<"Number of Games Played = "<<totGame<<endl;
    }
    while (power);

    //Exit stage right!
    in.close();
    out.close();

    return 0;
}  