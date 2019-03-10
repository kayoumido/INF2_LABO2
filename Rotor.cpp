//
// Created by deekay on 07/03/19.
//

#include "Rotor.h"

using namespace std;

const string Rotor::DEFAULT_CONFIG[][2] = {
    {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "R"},
    {"AJDKSIRUXBLHWTMCQGZNPYFVOE", "F"},
    {"BDFHJLCPRTXVZNYEIWGAKMUSQO", "W"},
    {"ESOVPZJAYQUIRHXLNFTGKDCMWB", "K"},
    {"VZBRGITYUPSDNHLXAWMJQOFECK", "A"}
};

const string Rotor::ENTRY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string Rotor::getWiring(const string &ID) {

    if (ID == "I") return Rotor::DEFAULT_CONFIG[0][0];

    if (ID == "II") return Rotor::DEFAULT_CONFIG[1][0];

    if (ID == "III") return Rotor::DEFAULT_CONFIG[2][0];

    if (ID == "IV") return Rotor::DEFAULT_CONFIG[3][0];

    if (ID == "V") return Rotor::DEFAULT_CONFIG[4][0];

}

char Rotor::getNotch(const string &ID) {
    if (ID == "I") return Rotor::DEFAULT_CONFIG[0][1].at(0);

    if (ID == "II") return Rotor::DEFAULT_CONFIG[1][1].at(0);

    if (ID == "III") return Rotor::DEFAULT_CONFIG[2][1].at(0);

    if (ID == "IV") return Rotor::DEFAULT_CONFIG[3][1].at(0);

    if (ID == "V") return Rotor::DEFAULT_CONFIG[4][1].at(0);
}


Rotor::Rotor(const string &ID, char position) :
    wiring(Rotor::getWiring(ID)), notch(Rotor::getNotch(ID)), position(position) {}

bool Rotor::justPassedNotched() const {
    return this->position == this->notch + 1;
}

void Rotor::turn() {

    if (this->position == 'Z')
        this->position = 'A';
    else
        ++this->position;
}

char Rotor::convert(char toConvert) const {

    size_t toConvertPos = Rotor::ENTRY.find(toConvert);
    size_t rotorPos     = Rotor::ENTRY.find(this->position);

    return this->wiring.at((rotorPos + toConvertPos) % 26);
}