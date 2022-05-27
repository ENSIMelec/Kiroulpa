#include <iostream>
#include <unistd.h>

#include "base/controller/MotorManager.h"
#include "base/utility/Clock.h"
#include "base/odometry/Odometry.h"
#include "base/strategy/Point.h"
#include "base/controller/Controller.h"
#include "base/actuators/ActionManager.h"
#include "base/strategy/StrategyParser.h"
#include "base/strategy/Strategy.h"
#include "base/utility/Initializer.h"
#include "base/Lidar.h"
#include "ResistanceReader.h"
#include "KiroulpaInitializer.h"
#include "MatchManager.h"
#include "base/ui/UI.h"
#include "base/utility/Utils.h"

using namespace std;

// Constants for all the possible exits
#define EXIT_SUCCESS    0
#define EXIT_FAIL_I2C   1

int main(int argc, char **argv) {

    if(argc >= 2) {
        printf("Kiroulpa %s", argv[1]);
        if(string(argv[1]) == string("yellow")) {
            Initializer::setColor(YELLOW);
            printf("Yellow");
        } else {
            Initializer::setColor(PURPLE);
            printf("purple");
        }
    } else {
        printf("USAGE: ./kiroulpa COLOR\n * COLOR: yellow/purple");
        exit(0);
     }

    Configuration *configuration = KiroulpaInitializer::start(false);
    Controller * controller = KiroulpaInitializer::getController();
    Odometry * odometry = KiroulpaInitializer::getOdometry();
    MatchManager * matchManager = KiroulpaInitializer::getMatchManager();

    UI::initModules();

    unsigned int updateTime = configuration->getInt("global.update_time");
    bool stopMotors = false;

    // Waiting for JACK to be removed
    UI::logAndRefresh("Waiting for jack to be removed");
    while(!Utils::isJackRemoved()) {}

    UI::logAndRefresh("Starting the match !");
    Initializer::startLidar();
    matchManager->startTimer();

    Clock updateTimer;
    while(!matchManager->isMatchDone()) {

        if(updateTimer.elapsed_ms() >= updateTime) {
            UI::update();
            UI::display();

//            if(Lidar::isActive()){
//                printf("Warning : %d | Danger : %d\n", Lidar::isWarning(), Lidar::isDanger());
//            }
            odometry->update();

            // All the case we should stop the motors
            stopMotors = false;
            if(Initializer::isLidarActivated() && Lidar::isDanger()) {
                stopMotors = true;
            }

            // Update the controller and set the motor commands (unless the motors should be stopped)
            if(stopMotors) {
                controller->stopMotors();
            } else {
                controller->update();
            }

            if(controller->isTargetReached()) {
                matchManager->next();
//                controller->setNextPoint(nextPoint);
            }

            updateTimer.restart();
        }
    }

    // Quitting the application
    Initializer::end();

	return EXIT_SUCCESS;
}