//TennisTeam.h
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "TennisPlayers.hpp"

using namespace std;

class TennisTeam {
public:
    
    //default constructor with default parameters
    TennisTeam(string cntry = "NoCountry", int size = 0, TennisPlayer* players = nullptr);

    //Constructor that creates the dynamically allocated array of tennis players.
    TennisTeam(vector<TennisPlayer> Vec, string CountryName );

    //Copy constructor
    TennisTeam(const TennisTeam& origTeam);

    //destructor
    ~TennisTeam();

    //Overloaded assignment operator
    TennisTeam& operator=(const TennisTeam& TeamToCopy);

    void print();
    
    void updatePoints(int point){
        for(int i=0; i<numPlayers; ++i){
            players[i].addpoints(point);
        }
    };
    

private:
    string country;
    int numPlayers;
    TennisPlayer* players;
};
