//
// Created by jalb2 on 02/10/2022.
//

#include <string>
#include <sstream>

using namespace std;

#ifndef TRABAJOFINALALESIS_CONVERSORES_H
#define TRABAJOFINALALESIS_CONVERSORES_H

int stringToInt(const string& value){
    int num;
    istringstream(value) >> num;

    return num;
}

string intToString(int value){
    stringstream ss;
    ss << value;

    return ss.str();
}

#endif //TRABAJOFINALALESIS_CONVERSORES_H
