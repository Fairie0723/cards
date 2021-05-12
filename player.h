

#ifndef PLAYER_H
#define PLAYER_H

//#include <iostream>
//#include <string>
#include "deck.h"
#include "card.h"

using std::ostream;
using std::string;

class Player
{
public:
    static const int Max_Cards = 26; // # of cards a player can have in a hand

    // constructor - player's name defaults to "unknown" if not supplied
	Player(string pname="unknown");

    // draw top card from the deck to fill the hand
	void drawCard(Deck& dk);

    // Simulates player playing a card - returns the top card in player's hand
	Card playCard();

    // add the point value of the card to the player's score
	void addScore(Card acard);

    // return the score the player has earned so far
	int getScore() const;

    // return the name of the player
    string getName() const; 

    // return true if the player's hand is out of cards
	bool emptyHand() const;


private:
	string  name;					// the player's name
	int     score;					// the player's score
	Card    hand[Max_Cards];		// array holding the cards in the player's hand
	int     topCard;				// the index of top card in the player's hand
};

#endif



