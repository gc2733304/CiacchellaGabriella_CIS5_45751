/* 
 * File:   main.cpp
 * Author: Gabriella Ciacchella
 * Created on July 25, 2019, 12:13 AM
 * Purpose: Write out logic of code through just words/comments
 */

//System Libraries
    //Input Output Library
    //Random numbers
    //Time to set the Seed
    //Format Library
    //File Library
    //String Library
    //Math Library
//Namespace std of system libraries

//User Libraries - None

//Global Constants - None

//Function Prototypes 
    //Integer function for displaying instructions and to see play with computer or not
    //Void function do display who won the game
    //Void function to set dice
    //Void function to print sorted round sums
    //Void function to sort the round sums
    //Bool function to find a specific number

//Main -> Executable code begins here!!!
    //Set the random number seed

    //Declare and Initialize Game Variables
    //File that will have the inputs
    //number of rounds, the round sum, round sum for each player, and the amount of dice
    //Max amount of games and total amount of games played
    //Will display what number value the dice got
    //Integer used for bool function
    //Variable to sum the game value of either game form chosen
    //Ability to re-roll and to play the game again 
    
    //Array values
    //2D Array used for table
    //1D Array used for sorting
    //Set the amount of rounds in one game
    //Keeps track of how many games played during run of code
    //Specific values for functions
    //Array for setting dice in function
    //Keeps track of wins/loses when playing against computer
    //Sets maximum amount of games 
    //Used for calculation of percentages

    //Setting up inputting and outputting file

    //Output title of game

    //opening and writing into a file
    //opening and outputting a file

    //Put variable to start time game play

    //Function come in with instructions, playing the game at all, and playing alone or not 

    //Input validation

    //If Play the Game by yourself -> Looping statements
        //Set up while loop to count how many games you play
        //Loop for 6 rounds
            //Function for random generator and dice
            //Set up variables to display value of dice
            //Output the values for the 5 dice and if to re-roll
            //Input y/n for re-roll

            //Input validation

            //if player wants to re-roll
                //Loop re-roll if player wants to re-roll
                    //Output what dice to re-roll (only one dice per re-roll)
                    //Input what dice to re-roll
                    //if they want to re-roll the first dice
                        //Reset random number generator for dice 1
                        //Re-setup variable to display value of dice 1
                        //Output new value of dice 1
                    //if they want to re-roll the second dice
                        //Reset random number generator for dice 2
                        //Re-setup variable to display value of dice 2
                        //Output new value of dice 2
                    //if they want to re-roll the third dice
                        //Reset random number generator for dice 3
                        //Re-setup variable to display value of dice 3
                        //Output new value of dice 3
                    //if they want to re-roll the fourth dice
                        //Reset random number generator for dice 4
                        //Re-setup variable to display value of dice 4
                        //Output new value of dice 4
                    //if they want to re-roll the fifth dice
                        //Reset random number generator for dice 5
                        //Re-setup variable to display value of dice 5
                        //Output new value of dice 5
                //Output whether the player wants to re-roll again
                //Input y/n to re-rolling again
            //Add up all the dice value to display the round total
            //Output the round and the round total
            //Set it to add up all the round totals into the game total
        //Put variable to end time game play 

        //Output how long the game took, your game total of points, and if want to play again
        //Input y/n to wanting to play the game again

        //Input validation

        //if yes to another game
            //Set power to 1 to start back from the beginning loop
            //Reset game total to zero 
        //if no to another game
            //Set power to 0 to end the program/game
            //Output how many games played
            //Output thanks for playing

        //Output information from the game to file

    //If Play the Game against computer -> Looping statements
        //Set up while loop to count how many games you play
        //Loop for 6 rounds
            //Function for random number generator and dice
            //Set up variables to display value of dice
            //Your turn
            //Output the values for the 5 dice and if to re-roll
            //Input y/n for re-roll

            //Input validation

            //if player wants to re-roll
                //Loop re-roll if player wants to re-roll
                    //Output what dice to re-roll (only one dice per re-roll)
                    //Input what dice to re-roll
                    //if they want to re-roll the first dice
                        //Reset random number generator for dice 1
                        //Re-setup variable to display value of dice 1
                        //Output new value of dice 1
                    //if they want to re-roll the second dice
                        //Reset random number generator for dice 2
                        //Re-setup variable to display value of dice 2
                        //Output new value of dice 2
                    //if they want to re-roll the third dice
                        //Reset random number generator for dice 3
                        //Re-setup variable to display value of dice 3
                        //Output new value of dice 3
                    //if they want to re-roll the fourth dice
                        //Reset random number generator for dice 4
                        //Re-setup variable to display value of dice 4
                        //Output new value of dice 4
                    //if they want to re-roll the fifth dice
                        //Reset random number generator for dice 5
                        //Re-setup variable to display value of dice 5
                        //Output new value of dice 5
                //Output whether the player wants to re-roll again
                //Input y/n to re-rolling again
            //Add up all the dice value to display the round total for you

            //Loop for 6 rounds
                //Function for random number generator and dice
                //Set up variables to display value of dice
                //Computers turn
                //Output the values for the 5 dice
            //Add up all the dice value to display the round total for the computer
            //Output the round and the round total for you and the computer
            //Set it to add up all the round totals into the game total for each player
        //Put variable to end time game play 

        //Output how long the game took, your game total of points, and the computer total points

        //Function come in with who won the game

        //Table displaying round totals for you and computer

        //Output if want to play again
        //Input y/n to wanting to play the game again

        //Input validation

        //if yes to another game
            //Set power to 1 to start back from the beginning loop
            //Reset game totals to zero 
        //if no to another game
            //Set power to 0 to end the program/game
            //Output how many games played, wins, losses, % of wins, and % of losses
            //Have loop to turn 2D array to 1D array
            //Function to sort round totals
            //Function to print the sorted totals
            //Function to find specific value in index
            //Output whether 15 is in the index or not
            //Output thanks for playing
        
        //Output information from the game to file

    //Close both files and exit stage right!

//Integer function called display
    //Display instructions to the game
    //Choose to play by self or against computer
    //Input validation

//Void function called whoWon
    //Displays who won the game

//Void function called diceSet
    //Sets random number seed for dice

//Void function called prntTbl
    //Display the sorted round totals

//Void function called bublSrt
    //Sort round totals

//Bool function called binSrch
    //Find 15 in the round totals