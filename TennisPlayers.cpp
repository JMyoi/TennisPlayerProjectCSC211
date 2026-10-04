//TennisPlayer.cpp
#include "TennisPlayers.hpp"
#include <string>
#include <iostream>
using namespace std;

TennisPlayer::TennisPlayer() {
    lastName = "  ";
    firstName = " ";
    country = " ";
    rank = 0;
    points = 0;
}

TennisPlayer::TennisPlayer(int rank, string lastName, string firstName, string country, int points)
    : rank(rank), lastName(lastName), firstName(firstName), country(country), points(points) {}

void TennisPlayer::display() const {
    cout << rank << ": " << firstName << "," << lastName << " " << points << " " << country << endl;
}
bool TennisPlayer::operator == (const string& rhs) const {
    if (this->lastName == rhs)
        return true;
    else
        return false;

}
bool TennisPlayer::operator <= (const string& rhs) const {
    if (this->lastName <= rhs)
        return true;
    else
        return false;

}
bool TennisPlayer::operator >= (const string& rhs) const {
    if (this->lastName >= rhs)
        return true;
    else
        return false;

}
