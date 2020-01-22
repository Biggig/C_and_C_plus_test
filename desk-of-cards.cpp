#include"desk-of-cards.hpp"
#include<iostream>
#include<vector>
using namespace std;

DeckOfCards::DeckOfCards()
{
	currentCard=0;
}

Card DeckOfCards::dealCard()
{
	int aaa=currentCard/13;
	int bbb=currentCard%13;
	Card ccc(bbb,aaa);
	deck.push_back(ccc);
	currentCard++;
	return ccc;
}

bool DeckOfCards::moreCards() const
{
	if(currentCard<52)
	return true;
	else
	return false;
}
