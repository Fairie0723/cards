
#include <iostream>
#include "player.h"
#include <fstream>


int main()
{
    int randSeed;
    string player1;
    string player2;
    //open file
    std::ifstream inFile;
    inFile.open("cardgame.txt");

    //Reads an input configuration file named cardgame.txt
    //First line: Player 1’s name (a single word)
    //2. Second line: Player 2’s name (a single word)
    //3. Third line: A positive integer to be used as the random number seed
    inFile >> player1 >> player2 >> randSeed;

    //Must contain the line srand(x);
    srand(randSeed);

    //Must instantiate the players
    Player play;
    //std::cout << player << std::endl;

    Player play1(player1);
    Player play2(player2);

    //Must instantiate the card deck (Diamonds, Clubs, Hearts, Spades)
    //Display the entire deck of cards after it is instantiated. top first
    Deck deck;
    std::cout << deck << std::endl;

    //The deck array must be shuffled using std::random_shuffle
    //Display the shuffled deck top first
    deck.Shuffle();
    std::cout << deck << std::endl;

    //Game play //Play continues until all card have been played.
    int counter = 1;

    while (!deck.isEmpty())
    {
        play1.drawCard(deck);
        play2.drawCard(deck);

    }
   while (!play1.emptyHand())
    { 
        // play1.drawCard(deck);
        // play2.drawCard(deck);
       
        //Each player plays the top card in their hand
        Card card1 = play1.playCard();
        Card card2 = play2.playCard();
        


        //The player playing the card with the highest point value wins and collects both cards, adding their
        //point values to their score. If both cards played have the same point value, the hand is a draw (tie)
        //and no points are accumulated by either player.
        if (card1 > card2)
        {
            play1.addScore(card1);
            play1.addScore(card2);

            std::cout << counter << ") " << play1.getName() << "*" << "  " <<
                        card1 << " " << "(" << play1.getScore() << ") - "
                         << play2.getName() << "  " << card2 << " ("
                         << play2.getScore() << ")" << std::endl;
        }
        else if (card1 < card2)
        {
            play2.addScore(card2);
            play2.addScore(card1);

            std::cout << counter << ") " << play1.getName() <<  "  " <<
                        card1 << " " << "(" << play1.getScore() << ") - "
                         << play2.getName() << "*" << "  " << card2 << " ("
                         << play2.getScore() << ")" << std::endl;

        }
        else if (card1 == card2)
        {
           //play2.addScore(card2);
           // play1.addScore(card1);
            std::cout << counter << ") " << play1.getName() << "  " <<
                        card1 << " " << "(" <<  play1.getScore() << ") - "
                         << play2.getName()  << "  " << card2 << " ("
                         << play2.getScore() << ")" << std::endl;
        }
        
        counter++;

    }

    if (play1.getScore () > play2.getScore())
        std::cout << "Winner! " << play1.getName() << "  " << play1.getScore() << std::endl;
    else if (play1.getScore () < play2.getScore())
        std::cout << "Winner! " << play2.getName() << "  " << play2.getScore() << std::endl;
    else
        std::cout << "Tie! " << play1.getScore() << std::endl;

    return 0;
}
