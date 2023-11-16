#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Database.h"
using namespace std;




int main() {
    Database data;
    data.readfile("music.csv");
    data.printTop();

}