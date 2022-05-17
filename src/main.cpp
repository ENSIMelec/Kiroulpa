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
#include "base/ui/UI.h"

using namespace std;

// Constants for all the possible exits
#define EXIT_SUCCESS    0
#define EXIT_FAIL_I2C   1

#define MAX_TIME 10     // The maximum time the robot will run (in seconds)

int main(int argc, char **argv) {

    Strategy strategy("../res/strategies/", "Forward");
    Initializer::setStrategy(&strategy);

    Configuration *configuration = KiroulpaInitializer::start(false);

    Controller * controller = KiroulpaInitializer::getController();
    Odometry * odometry = KiroulpaInitializer::getOdometry();
    ActionManager * actionManager = KiroulpaInitializer::getActionManager();

    unsigned int updateTime = configuration->getInt("global.update_time");
    timer totalTime;

    Point * currentPoint = strategy.getCurrentPoint();  // The current point destination

    // Set the initial location
    odometry->setPosition(currentPoint->getX(), currentPoint->getY(), currentPoint->getTheta());

    // Set first target
    currentPoint = strategy.getNextPoint();
    controller->setNextPoint(currentPoint);

    timer updateTimer;
    while(!strategy.isDone() && totalTime.elapsed_s() < configuration->getInt("global.match_time")) {

        if(updateTimer.elapsed_ms() >= updateTime) {

            UI::display();

//            if(Lidar::isActive()){
//                printf("Warning : %d | Danger : %d\n", Lidar::isWarning(), Lidar::isDanger());
//            }

            odometry->update();
//            odometry->debug();

            if(Initializer::isLidarActivated() && Lidar::isDanger()) {
                controller->stopMotors();
            } else {
                controller->update();
            }

//            controller->debug();

            if(controller->isTargetReached()) {
//                cout << endl << "Point reached !" << endl;
                controller->stopMotors();

                // Execute the action
                if(currentPoint->isActionAfterMovement()) {
                    string actionFile = currentPoint->getAction();
                    if(actionFile != "null") actionManager->action(actionFile);
                }

                // Go to the next point
                currentPoint = strategy.getNextPoint();

                if(!strategy.isDone()) {
                    controller->setNextPoint(currentPoint);
                }
            }
            updateTimer.restart();

        }
    }

    odometry->update();
    UI::display();
    delay(2000);

    // Quitting the application
    Initializer::end();

	return EXIT_SUCCESS;
}