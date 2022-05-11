//
// Created by Clement on 26/04/2022.
//
#include <iostream>
#include <wiringPiI2C.h>

#define DEVICE_ID 0x08
#ifndef KIROULPA_VALEURSRESISTANCES_H
#define KIROULPA_VALEURSRESISTANCES_H


class ResistanceReader {
public :
    explicit ResistanceReader(int address);
    int getValue();

private:
    int fd = 0;

};


#endif //KIROULPA_VALEURSRESISTANCES_H
