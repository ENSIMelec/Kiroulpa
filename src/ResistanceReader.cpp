//
// Created by cleme on 26/04/2022.
//
#include "ResistanceReader.h"

using namespace std;

#include <iostream>
#include <wiringPiI2C.h>

ResistanceReader::ResistanceReader(int address) {
    // Setup I2C communication
    fd = address;
}

int ResistanceReader::getValue(){
    // Read data from arduino
    int received_data = wiringPiI2CRead(fd);

    std::cout << "Data received: " << received_data << "\n";

    if(received_data == 0) {
        std::cout<<"no res detected!\n";
    } else if(received_data == 1) {
        std::cout<<"Purple team!\n";
    } else if(received_data == 2) {
        std::cout<<"Yellow team!\n";
    } else if(received_data == 3) {
        std::cout<<"don't turn this one!\n";
    }

    return 0;
}
