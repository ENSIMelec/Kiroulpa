//
// Created by Clement on 26/04/2022.
//
#include <iostream>
#include <wiringPiI2C.h>

#define DEVICE_ID 0x08
#ifndef KIROULPA_VALEURSRESISTANCES_H
#define KIROULPA_VALEURSRESISTANCES_H

#define START_BYTE  0xA5
#define END_BYTE    0x5A

#define RED     0x00
#define YELLOW  0x01
#define PURPLE  0x02

class ResistanceReader {
public :
    explicit ResistanceReader(int address);
    int getValue();

private:
    int fd = 0;

    void printBuffer(const std::byte *buffer) const;
};


#endif //KIROULPA_VALEURSRESISTANCES_H
