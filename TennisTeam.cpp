//TennisTeam.cpp
#include "TennisTeam.hpp"
#include <string>
#include <iostream>

TennisTeam::TennisTeam(string cntry, int size, TennisPlayer* players) {
    country = cntry;
    numPlayers = size;
    this->players = players;
}

TennisTeam::TennisTeam(vector<TennisPlayer> Vec, string CountryName) {
    //get the number of people from country
        int numFromCountry = 0;
        for (int i = 0; i < Vec.size(); i++) {
            if ((Vec.at(i)).getCountry() == CountryName) {
                numFromCountry++;
            }
        }

    //get the first index apperance of player from that country.
        int firstApperance = 0;
        for (int i = 0; i < Vec.size(); i++) {
            if ((Vec.at(i)).getCountry() == CountryName) {
                firstApperance = i;
                break;
            }
        }
    

     //Creation of the dynamic TennisPlayer array
        TennisPlayer* playersArray;
        playersArray = new TennisPlayer[numFromCountry];
    
    //populating dynamic array of tennis players with all the players from said country.
        for (int i = 0; i < numFromCountry; i++) {
            playersArray[i] = Vec.at(i + firstApperance);
        }

        country = CountryName;
        numPlayers = numFromCountry;
        players = playersArray;


}


//Copy constructor
TennisTeam::TennisTeam(const TennisTeam& origTeam) {
    cout << "copy constructor called\n";
    country = origTeam.country;
    numPlayers = origTeam.numPlayers;
    players = new TennisPlayer[origTeam.numPlayers];
    for (int i = 0; i < origTeam.numPlayers; ++i) {
        players[i] = origTeam.players[i];
    }
}

//destructor
TennisTeam::~TennisTeam() {
    cout << "destructor called\n";
    delete[] players;
}

//Overloaded assignment operator
TennisTeam& TennisTeam::operator=(const TennisTeam& TeamToCopy) {
    cout << "overloaded assignment operator called\n";
    if (this != &TeamToCopy) {
        country = TeamToCopy.country;
        numPlayers = TeamToCopy.numPlayers;
        delete[] players;
        players = new TennisPlayer[TeamToCopy.numPlayers];
        for (int i = 0; i < TeamToCopy.numPlayers; ++i) {
            players[i] = TeamToCopy.players[i];
        }
    }
    return *this;
}

void TennisTeam::print() {
    cout << "Country: " << country << endl;
    cout << "Number of players: " << numPlayers << endl;
    for (int i = 0; i < numPlayers; i++) {
        players[i].display();
    }
    cout << endl;
}
