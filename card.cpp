

#include "card.h"

//constructor that takes a card's face value (an integer) and its suit
// card face example: Ace=0, 2=1, 3=2, ... Q=11, K=12
Card::Card (int face, suit st)
{
    cardFace = face;
    cardSuit = st;


    if (face == 0)
        pointValue = 15;
    if (face >= 1 && face <= 9)
        pointValue = face + 1;
    if (face >= 10 && face <= 12)
        pointValue = 10;

}

// overload the << operator to display the card
ostream& operator << (ostream& os, const Card& cd)
{
    if (cd.pointValue == 15)
        os << "A";
    else if (cd.cardFace == 12)
        os << "K";
    else if (cd.cardFace == 11)
        os << "Q";
    else if (cd.cardFace == 10)
        os << "J";
    else
        os << cd.pointValue;


    if (cd.cardSuit == diamonds)
        os << "D";
    else if (cd.cardSuit == clubs)
        os << "C";
    else if (cd.cardSuit == hearts)
        os << "H";
    else if (cd.cardSuit == spades)
        os << "S";
    
    os << "[" << cd.pointValue << "]";
    return os;
}

// compare and return true if *this has a lesser point value than cd, false otherwise
bool Card::operator< (const Card& cd) const
{
    if (pointValue < cd.pointValue)
        return true;
    else
        return false;
}

// compare and return true if *this has a larger point value than cd, false otherwise
bool Card::operator>(const Card &cd) const
{
    if (pointValue > cd.pointValue)
        return true;
    else
        return false;
}

// compare and return true if *this has the same point value as cd, false otherwise
bool Card::operator==(const Card &cd) const
{
    if (pointValue == cd.pointValue)
        return true;
    else
        return false;

}

// return the point value of the card: Ace: 15, Faces: 10, Numbers: the number
int Card::getPointValue() const
{
    return pointValue;
}

// return the face value of the card: Ace: 0, 2: 1, 3:2, .... Queen:11, King:12
int Card::getFaceValue() const
{
    return cardFace;
}

// return the card's suit: diamonds, clubs, hearts, spades
suit Card::getSuit() const
{
    return cardSuit;
}


