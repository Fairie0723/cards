
//check playcard it is not reading values with the for loop now

#include "player.h"
#include <algorithm>

// constructor - player's name defaults to "unknown" if not supplied
Player::Player(string name)
{
    this->name = name;
    score = 0;
    topCard = -1;


}

// draw top card from the deck to fill the hand
void Player::drawCard(Deck& dk)
{   
    
    topCard++;
    hand[topCard] = dk.dealCard();
    //topCard++;

}

// Simulates player playing a card - returns the top card in player's hand
Card Player::playCard()
{

    return hand[topCard--];
}

// add the point value of the card to the player's score
void Player::addScore(Card acard)
{
    score += acard.getPointValue();
}

// return the score the player has earned so far
int Player::getScore() const
{
    return score;
}

// return the name of the player
string Player::getName() const
{
    return name;
}

//return true if the player's hand is out of cards
bool Player::emptyHand() const
{
    if (topCard == -1)
        return true;
    else 
        return false;

}



