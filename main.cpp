
#include "TennisPlayers.hpp"
#include "TennisTeam.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

template <typename theType> void findNameBinaryRecursive(const vector<theType>& Vector, string find, int low, int high);

template <typename theType> void SelectionSort(vector<theType>& Vector, int numbersSize);

int main(int argc, char* argv[]) {
    ifstream fin;
    fin.open(argv[1]);

    if (!fin.is_open()) {
        cout << "File not found!" << endl;
        return 0;
    }
    
    string lastName, firstName, country, bestName;
    int rank, points;
    vector<TennisPlayer> TennisPlayerVector;
    int sizeVec;
    while (fin >> rank >> lastName >> firstName >> country >> points) {
        TennisPlayer myTennisPlayer(rank, lastName, firstName, country, points);
        TennisPlayerVector.push_back(myTennisPlayer);
    }
    
    sizeVec = TennisPlayerVector.size();
   
    //can we not just set sortedTennisPlayerVector = TennisplayerVector or do we need to overload the assignment operator?
    vector<TennisPlayer> sortedTennisPlayerVector = TennisPlayerVector;
    // for(int i = 0; i<sizeVec; ++i){
    //     sortedTennisPlayerVector.push_back(TennisPlayerVector.at(i));
    // }

    SelectionSort(sortedTennisPlayerVector, sizeVec);
    
    int input=1;
    
    while (input != 0 ){
        cout<<"**************  MENU  ********************\n\n";
        cout<<"Option 1: Find Player\n"<<"Option 2: Display team from a country\n"<<"Option 3: Update points for a team\n"
        <<"Option 4: Test overloaded assignment\n"<<"Option 5: Test Copy Constructor\n"<<"\nEnter an option number(0 to exit program): "<<endl;
        cin>>input;
        cout<<"----------------------------------------------------------------------------------------\n";
        
    switch (input){
        case 1:
            while (true) {
                string findName;
                cout << "Enter player name to be found(e to eixt): ";
                cin >> findName;
                if (findName == "e") break;
                int low = 0;
                int high = TennisPlayerVector.size() - 1;
                findNameBinaryRecursive(TennisPlayerVector, findName, low, high);
            }
            break;
        case 2:
            while (true) {
             string CountryCode;
                cout << "Enter a country code(e to eixt): ";
                cin >> CountryCode;
                if (CountryCode == "e")break;
                TennisTeam Team(sortedTennisPlayerVector, CountryCode);
                cout<<endl;
                Team.print();
            }
            break;
        case 3:
            while(true){
                cout<<"Enter the country to update points for: \n";
                cin>>country;
                TennisTeam TeamUpdate(sortedTennisPlayerVector, country);
                cout<<"enter the amount of points to update by: ";
                int points;
                cin>>points;
                TeamUpdate.updatePoints(points);
                TeamUpdate.print();
                break;
            }
            break;
        case 4:
            while(true){
                cout<<"Testing overloaded assignment: \n";
                TennisTeam TeamJPN(sortedTennisPlayerVector, "JPN");
                TennisTeam TeamITA(sortedTennisPlayerVector,"ITA");
                cout<<"Assigning team Italy to team Japan \n\n";
                TeamITA = TeamJPN;
                cout<<"Now printing team Italy:\n";
                TeamITA.print();
                cout<<"Now printing team Japan: \n";
                TeamJPN.print();
            break;
            }
            break;
        case 5:
            while(true){
                cout<<"Testing Copy Constructor: \n";
                TennisTeam TeamPOL(sortedTennisPlayerVector, "POL");
                cout<<"Team poland Created\n";
                cout<<"Now initializing and declaring a Team USA to Team Poland: \n";
                TennisTeam TeamUSA = TeamPOL;
                cout<<"Now printing Team Poland: \n";
                TeamPOL.print();
                cout<<"Now printing Team USA: \n";
                TeamUSA.print();
                
            break;
            }
            break;
        default :
            if(input!=0){cout<<"invalid input\n";}
            break;
    }
        cout<<"----------------------------------------------------------------------------------------\n";
    }
    
    
    fin.close();
    return 0;
}

template <typename theType> void findNameBinaryRecursive(const vector<theType>& Vector, string find, int low, int high){

    int mid;

    while (high >= low) {
        mid = (low + high) / 2;
        
        if (Vector.at(mid) == find) {
            cout << "FOUND\n";
            Vector.at(mid).display();
            break;
        }
        else if (Vector.at(mid) >= find) {
            return findNameBinaryRecursive(Vector, find, low, mid-1);
        }
        else if (Vector.at(mid) <= find) {
            return findNameBinaryRecursive(Vector, find, mid+1, high);
        }
    }
    if (high < low) {
        cout << "NOT FOUND\n";
    }
}

template <typename theType> 
void SelectionSort(vector<theType>& Vector, int numbersSize) {
   theType Temp;
    int indexSmall;
    
    for(int i=0; i<numbersSize-1; i++){
        indexSmall = i;
        
        for(int j = i+1; j<numbersSize; ++j){
            if(Vector.at(j).getCountry() < Vector.at(indexSmall).getCountry()){
                indexSmall = j;
            }
        }
        
        Temp = Vector.at(i);
        Vector.at(i) = Vector.at(indexSmall);
        Vector.at(indexSmall) = Temp;
        
    }
}

