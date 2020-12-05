#include "recipeBuf.hpp"
#include <cstring>

recipeBuf::recipeBuf() {
    memset(name, '\0', MAX_DATA_LENGTH + 1);
    memset(difficulty, '\0', MAX_DATA_LENGTH + 1);
    time = 0;
}

recipeBuf::recipeBuf(const string &name, const string &diff, int time) {
    memcpy(this->name, name.c_str(), MAX_DATA_LENGTH);
    memcpy(difficulty, diff.c_str(), MAX_DATA_LENGTH);
    this->time = time;
}

void recipeBuf::setName(const string &name) {
    memcpy(this->name, name.c_str(), MAX_DATA_LENGTH);
}

void recipeBuf::setDifficulty(const string &diff) {
    memcpy(difficulty, diff.c_str(), MAX_DATA_LENGTH);
}

void recipeBuf::setTime(int time) { this->time = time; }

string recipeBuf::getName() { return string(name); }

string recipeBuf::getDifficulty() { return string(difficulty); }

int recipeBuf::getTime() { return time; }
