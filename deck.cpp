
#include "deck.h"
#include <algorithm>

// default constructor
Deck::Deck()
{
    int j = 0;
    for(int i = 0; i < 13; i++)
    {
        theDeck[j] = Card(i, diamonds);
        j++;
    }
    for(int i = 0; i < 13; i++)
    {
        theDeck[j] = Card(i, clubs);
        j++;
    }
    for(int i = 0; i < 13; i++)
    {
        theDeck[j] = Card(i, hearts);
        j++;
    }
    for(int i=0; i < 13; i++)
    {
        theDeck[j] = Card(i, spades);
        j++;
    }
    topOfDeck = 51;
}
// Remove the top card from the deck and return it.
Card Deck::dealCard()
{
        return theDeck[topOfDeck--];

}
// Shuffle the cards in the deck
void Deck::Shuffle()
{
    //begin and end need to be used
    std::random_shuffle(std::begin(theDeck), std::end(theDeck));
}

// return true if there are no more cards in the deck, false otherwise
 bool Deck::isEmpty()
 {
    if (topOfDeck == -1)
        return true;
    else
        return false;

 }

//overload << operator to display the deck
ostream& operator << (ostream& os, const Deck& deck)
{

    for (int j = 3; j >= 0; j--)
    {
        for (int i = 12; i >= 0; i--)
        {
            std::cout << " ";
            os << deck.theDeck[i + (j * 13)];
        }
        os << std::endl;
    }
    return os;
}


