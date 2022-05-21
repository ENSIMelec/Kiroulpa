//
// Created by cleme on 26/04/2022.
//
#include "ResistanceReader.h"
#include "base/ui/UI.h"
#include <unistd.h>

using namespace std;


ResistanceReader::ResistanceReader(int address) {
    // Setup I2C communication
    fd = address;
}

int ResistanceReader::getValue(){

    // Read data from arduino
    byte buffer[4];
    read(fd, buffer, 4);

    int startByte = (int) buffer[0];
    int rightRes = (int) buffer[1];
    int leftRes = (int) buffer[2];
    int endByte = (int) buffer[3];

//    int startByte = wiringPiI2CRead(fd);
//    int rightRes = wiringPiI2CRead(fd);
//    int leftRes = wiringPiI2CRead(fd);
//    int endByte = wiringPiI2CRead(fd);

    printf("%d\n", startByte);
    printf("%d\n", rightRes);
    printf("%d\n", leftRes);
    printf("%d\n", endByte);

    if(startByte != START_BYTE || endByte != END_BYTE) {
        UI::logAndRefresh("[RESISTANCE READER] Incorrect message");
        return EXIT_FAILURE;
    }

    switch (rightRes) {
        case RED:
            UI::logAndRefresh("[RIGHT] red");
            break;
        case PURPLE:
            UI::logAndRefresh("[RIGHT] purple");
            break;
        case YELLOW:
            UI::logAndRefresh("[RIGHT] yellow");
            break;
        default:
            UI::logAndRefresh("[RIGHT] undefined");
            break;
    }

//    if(received_data == 0) {
//        std::cout<<"no res detected!\n";
//    } else if(received_data == 1) {
//        std::cout<<"Purple team!\n";
//    } else if(received_data == 2) {
//        std::cout<<"Yellow team!\n";
//    } else if(received_data == 3) {
//        std::cout<<"don't turn this one!\n";
//    }

    return 0;
}

void ResistanceReader::printBuffer(const byte *buffer) const {
    printf("Printing buffer : ");
    printf("%");
}
