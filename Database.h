#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



class Database {
    private:

    struct Artist {
        vector<string> people;
        string artist;
        int favorites;
        void addFavorite() {favorites++;}

        bool operator<(const Artist other) const noexcept{
            if (this->favorites >= other.favorites) {
                return true;
            }
            return false;
        }
    };

    struct People {
        vector<string> artists;
        string name;
        double uniquenessIndex;
    };

    std::vector<Artist> artistList;
    std::vector<People> peopleList;
    int totalPeople;


    public:

    void readfile(string filename);
    void printFavoriteSongs(string name);
    void printFans(string artist_name);

    int getTotalPeople() {return totalPeople;}
    double getPercentFans(Artist item);
    double getUniqueness(string name);
    void printTop();


};
#endif