//
// Created by Tom on 20/05/2022.
//

#include "MatchManager.h"
#include "base/utility/Initializer.h"
#include "base/ui/UI.h"

MatchManager::MatchManager() {
    currentStrategyIndex = 0;
    strategy_0 = new Strategy("../res/strategies/Resistances/", "strategy0");
    strategy_1 = new Strategy("../res/strategies/Resistances/", "strategy1");
    strategy_2 = new Strategy("../res/strategies/Resistances/", "strategy2");
    strategy_3 = new Strategy("../res/strategies/Resistances/", "strategy3");

    startingStrategy = new Strategy("../res/strategies/", "Test");
    Initializer::setStrategy(startingStrategy);

    // Setting the first point
    controller = Initializer::getController();
    controller->setNextPoint(startingStrategy->getNextPoint());

    actionManager = Initializer::getActionManager();

    Configuration * configuration = Initializer::getConfiguration();
    matchTime = configuration->getInt("global.match_time");

    timer.restart();
}

bool MatchManager::isMatchDone() {
    return matchIsDone;

//    int totalTime = (int) timer.elapsed_s();
//    if(totalTime >= matchTime) {
//        return true;
//    }

    return false;
}

void MatchManager::next() {
    UI::logAndRefresh("Point reached !");

    // Stop the motors
    controller->stopMotors();

    // Execute the action (if there is one)
    if(currentPoint->isActionAfterMovement()) {
        string actionFile = currentPoint->getAction() + ".as";
        if(actionFile != "null") actionManager->action(actionFile);
    }

    // Strategy is done is updated when asking for next point
    gettingCurrentPoint();

    // Check if all strategies are done
    if(currentPoint != nullptr) {
        UI::log("Going to next point");
        controller->setNextPoint(currentPoint);
    } else {
        UI::log("End of the match (maybe?)");
        matchIsDone = true;
    }
}

void MatchManager::gettingCurrentPoint() {
    if(!firstPartIsDone) {
        currentPoint = startingStrategy->getNextPoint();
        if(currentPoint == nullptr) {
            UI::log("Going to part 2 of the match :)");
            firstPartIsDone = true;

            // Reading the resistance value

            // Getting the first point of the next strategy
            currentPoint = strategy_0->getNextPoint();
            if(currentPoint == nullptr) {
                UI::logAndRefresh("Point is null :(");
            }
        }
    } else {
        currentPoint = strategy_0->getNextPoint();
    }
}

Point *MatchManager::getNextMatchPoint() {
    return nullptr;
}
