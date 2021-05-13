#pragma once

#include <string>
#include <cstring>
#include <vector>

// This absolute god of a person made the string to char * conversion possible: https://www.daniweb.com/posts/jump/1886516
// You have no idea how long I spent trying to figure this out
// Nevermind, it was as simple as just adding .c_str() to the end of a string variable. Horray for me :')
const char* stringToChar (std::string str) {
    const char* out = strdup(str.c_str());

    return out;
};

char* intToChar (int theInt) {
    char integer_string[32];

    sprintf(integer_string, "%d", theInt);

    return integer_string;
};