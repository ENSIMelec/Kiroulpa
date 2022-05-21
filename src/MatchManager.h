//
// Created by Tom on 20/05/2022.
//

#ifndef KIROULPA_MATCHMANAGER_H
#define KIROULPA_MATCHMANAGER_H


#include "base/strategy/Strategy.h"
#include "base/actuators/ActionManager.h"

class MatchManager {

public:
    explicit MatchManager();
    void update();

    [[nodiscard]] bool isMatchDone();

    Point *getNextPoint();

    void next();

    Point *getNextMatchPoint();

private:
    Strategy * startingStrategy;

    Strategy * strategy_0;
    Strategy * strategy_1;
    Strategy * strategy_2;
    Strategy * strategy_3;
    int currentStrategyIndex;

    bool firstPartIsDone = false;

    int matchTime = 0;
    Clock timer;

    Point *currentPoint;
    ActionManager *actionManager;
    Controller * controller;
    bool matchIsDone = false;

    void gettingCurrentPoint();
};


#endif //KIROULPA_MATCHMANAGER_H
