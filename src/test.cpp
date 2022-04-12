#include <cstdlib>
#include <math.h>
#include <iostream>

#include <unistd.h>
#include "dynamixel_sdk/dynamixel_sdk.h"



void	waitAndPrint(DxlServo &servo)
{
    int	presentPos = 0;
    int	prevPos = 0;

    while (servo.moving())
    {
        if (servo.error())
            printDxlError(servo);
        presentPos = servo.presentPos();
        if (servo.error())
            printDxlError(servo);
        if (presentPos != prevPos)
        {
            std::cout << "Present pos: " << presentPos << std::endl;
            prevPos = presentPos;
        }
    }
}

int	main(int argc, char **argv)
{
    int servoId = 1;

    if (!DxlServo::devInit(0))
    {
        std::cout << "Failed to initialize serial device" << std::endl;
        return EXIT_FAILURE;
    }
    else
        std::cout << "serial device successfully initialized" << std::endl;

    if (argc > 1)
        servoId = ::atoi(argv[1]);

    DxlServo	servo(servoId);

    if (!servo.init())
    {
        std::cout << "Failed to initialize dxl servo " << servo.id() << std::endl;
        return EXIT_FAILURE;
    }
    else
        std::cout << "Dxl servo " << servo.id() << " successfully initialized" << std::endl;
    servo.setCWAngleLimit(0);
    servo.setCCWAngleLimit(1);
    servo.setMovingSpeed(0.25);
    while (42)
    {
        servo.setGoalPos(0);
        if (servo.error())
            printDxlError(servo);
        waitAndPrint(servo);
        servo.setGoalPos(1);
        if (servo.error())
            printDxlError(servo);
        waitAndPrint(servo);
    }
    return 0;
}