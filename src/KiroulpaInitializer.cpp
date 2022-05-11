//
// Created by Tom on 11/05/2022.
//

#include "KiroulpaInitializer.h"

Configuration * KiroulpaInitializer::start(bool log) {

    Initializer::allowLogging = log;
    Initializer::start(log);

    // Kiroulpa specific initialization
    initResistanceReader();

    return Initializer::configuration;
}

void KiroulpaInitializer::initResistanceReader() {
    if(allowLogging) cout << "Initializing the resistance reader ... ";

    // Get the file descriptor for the arduino
    int address = Initializer::configuration->getInt("i2c.ohmmeter");
    resistanceReader_fd = wiringPiI2CSetup(address);
    resistanceReader = new ResistanceReader(resistanceReader_fd);

    if(allowLogging) cout << "done";
}

void KiroulpaInitializer::end() {
    Initializer::end();
}

