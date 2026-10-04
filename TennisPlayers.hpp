//TennisPlayers.h
#pragma once
#include <string>

using namespace std;

class TennisPlayer {
public:
    TennisPlayer();
    TennisPlayer(int, string, string, string, int);
    string getCountry() { return country; };
    bool operator == (const string& rhs) const;
    bool operator >= (const string& rhs) const;
    bool operator <= (const string& lhs) const;
    void display() const;
    
    void addpoints(int point){
        points = points + point;
    }
private:
    string lastName;
    string firstName;
    string country;
    int rank, points;
};
