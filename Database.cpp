#include "Database.h"
#include <algorithm>
#include <sstream>

void Database::readfile(string filename) {
    std::ifstream stats;
    stats.open(filename);
    std::string line;
    int i = 0;
    while(getline(stats, line)) {
        std::istringstream stream = istringstream(line);
        getline(stream, line, ',');
        string person = line;
        // std::cout << line << std::endl;
        People named;
        named.name = person;

        for (int i = 0; i < 5; i++) {
            getline(stream, line, ',');
            named.artists.push_back(line);
            // std::cout << line << std::endl;
            bool found = false;
            for (auto &iter : artistList) {


                if (iter.artist == line) {
                    // std::cout << line << std::endl;
                    iter.favorites = iter.favorites + 1;
                    iter.people.push_back(person);
                    found = true;
                }
                
            }
            if (!found) {
                Artist another;
                another.artist = line;
                another.favorites = 1;
                another.people.push_back(person);
                artistList.push_back(another);
            }
            // std::cout << artistList.size() << " ";
        }
        peopleList.push_back(named);
    }
}

void Database::printFavoriteSongs(string name) {

}
void Database::printFans(string artist_name) {

}

double Database::getPercentFans(Artist item) {
    return item.favorites/(totalPeople*.01);
}

double Database::getUniqueness(string name) {
    return 7.7;
}

void Database::printTop() {
    // First sort ascending, which will actually be good for the program in general
    std::sort(artistList.begin(), artistList.end());

    for (auto iter : artistList) {
        std::cout << iter.artist << ": " << iter.favorites << std::endl;
    }
}

