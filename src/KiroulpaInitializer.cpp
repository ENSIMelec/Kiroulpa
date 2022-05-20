//
// Created by Tom on 11/05/2022.
//

#include <wiringPiI2C.h>
#include "KiroulpaInitializer.h"
#include "base/ui/UI.h"

Configuration * KiroulpaInitializer::start(bool log) {

    Initializer::allowLogging = log;
    Initializer::start(log);

    // Kiroulpa specific initialization
    initResistanceReader();

    UI::logAndRefresh("End of initialization");
    return Initializer::configuration;
}

void KiroulpaInitializer::initResistanceReader() {
    // Get the file descriptor for the arduino
    int address = Initializer::configuration->getInt("i2c.ohmmeter");
    resistanceReader_fd = wiringPiI2CSetup(address);
    resistanceReader = new ResistanceReader(resistanceReader_fd);

    UI::logAndRefresh(" -- Ohmmeter done");
}

void KiroulpaInitializer::end() {
    Initializer::end();
}

