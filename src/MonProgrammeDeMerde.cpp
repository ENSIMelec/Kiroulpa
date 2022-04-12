#include <iostream>
#include <stdlib.h> //The function abs() is in the example code, and it needs stdlib.h to be included.
#include <stdio.h> //The example shows Dynamixel status in sequence by the function printf(). So here stdio.h is needed.

#include "dynamixel_sdk/group_bulk_read.h"

#include "dynamixel_sdk/dynamixel_sdk.h"                                  // Uses Dynamixel SDK library
//All libraries of Dynamixel SDK are linked with the header file dynamixel_sdk.h.

// Control table address
#define ADDR_AX_TORQUE_ENABLE           24                  // Control table address is different in Dynamixel model
#define ADDR_AX_GOAL_POSITION           30
#define ADDR_AX_PRESENT_POSITION        36
#define ADDR_AX_PRESENT_VOLTAGE         42
#define ADDR_AX_SPEED_VALUE             32
#define ADDR_AX_TORQUE_LIMIT            34
#define ADDR_AX_PRESENT_LOAD            40
//Dynamixel series have their own control tables: Addresses and Byte Length in each items. To control one of the items, its address (and length if necessary) is required. Find your requirements in http://support.robotis.com/.

// Protocol version
#define PROTOCOL_VERSION                1.0                 // See which protocol version is used in the Dynamixel
#define COMM_SUCCESS                    0
// Default setting
#define BAUDRATE                        1000000
#define DEVICENAME                      "/dev/ttyACM0"      // Check which port is being used on your controller
// ex) Windows: "COM1"   Linux: "/dev/ttyUSB0"

#define TORQUE_ENABLE                   1                   // Value for enabling the torque
#define TORQUE_DISABLE                  0                   // Value for disabling the torque


#define DXL_MINIMUM_POSITION_VALUE      100                 // Dynamixel will rotate between this value
#define DXL_MAXIMUM_POSITION_VALUE      1000                // and this value (note that the Dynamixel would not move when the position value is out of movable range. Check e-manual about the range of the Dynamixel you use.)
#define DXL_MOVING_STATUS_THRESHOLD     20                 // Dynamixel moving status threshold
#define DXL_LOAD_THRESHOLD                800


using namespace std;

// Constants for all the possible exits
#define EXIT_SUCCESS    0
#define EXIT_FAIL_I2C   1

// This folder is used to load all the external resources (like configuration files)
const string RES_PATH = "/home/pi/Documents/Kiroulpa/res/";


int main(int argc, char **argv) {
    cout << "Hello world" << endl;

    dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler(DEVICENAME);
    dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

    dynamixel::GroupBulkRead reader = dynamixel::GroupBulkRead(portHandler, packetHandler);

    int dxl_comm_result = COMM_TX_FAIL;         // Communication result
    uint8_t dxl_error = 0;                        // Dynamixel error

    int DXL_ID = 0x01;
    int dxl_goal_position = 512;
    int speed = 800;
    int force = 800;

    int sens = 1;

    uint16_t dxl_present_position = 0;          // Present position
    uint16_t dxl_present_load = 0;                // Present load

    if (portHandler->openPort()) {
        printf("Succeeded to open the port!\n");
    } else {
        printf("Failed to open the port!\n");
        return 1;
    }
    if (portHandler->setBaudRate(BAUDRATE)) {
        printf("Succeeded to change the baudrate!\n");
    } else {
        printf("Failed to change the baudrate!\n");
        return 1;
    }


    // Infos of servos

    cout << "Numéro AX12 ID : " << DXL_ID << endl;

    dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID, ADDR_AX_TORQUE_ENABLE, TORQUE_ENABLE,
                                                    &dxl_error);
    if (dxl_comm_result != COMM_SUCCESS) {
        //cout << "Erreur COMM init Dyna " << DXL_ID << endl;
        printf("%s\n", packetHandler->getTxRxResult(dxl_comm_result));
    } else if (dxl_error != 0) {
        //cout << "Erreur init Dyna " << DXL_ID << endl;
        printf("%s\n", packetHandler->getRxPacketError(dxl_error));
    } else {
        printf("Dynamixel %i has been successfully connected \n", DXL_ID);
    }

    dxl_comm_result = COMM_TX_FAIL;
    dxl_error = 0;


    // Set movement speed in ADD of speed value
    if (speed != 0) {
        dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID, ADDR_AX_SPEED_VALUE, speed, &dxl_error);
        cout << "On est la : " << speed << endl;
        cout << "ADDR_AX_SPEED_VALUE : " << ADDR_AX_SPEED_VALUE << endl;
    } else {
        cout << "Vitesse ecrite" << endl;
    }

    dxl_comm_result = COMM_TX_FAIL;
    cout <<"dxl comm result : " << dxl_comm_result << endl;
    dxl_error = 0;


    // Set force (Torque Limits)
    dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID, ADDR_AX_TORQUE_LIMIT, force, &dxl_error);
    cout << "Force : " << force << endl;
    cout <<"dxl comm result : " << dxl_comm_result << endl;

    if (dxl_comm_result != COMM_SUCCESS) {
        cout << "Erreur COMM limitation couple " << DXL_ID << endl;
    }

    dxl_comm_result = COMM_TX_FAIL;
    dxl_error = 0;


    // Goal position

    dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID, ADDR_AX_GOAL_POSITION, dxl_goal_position,
                                                    &dxl_error);
    cout << "dxl goal position : " << dxl_goal_position << endl;
    int status = reader.rxPacket();
    uint32_t actualPosition = reader.getData(DXL_ID, ADDR_AX_PRESENT_POSITION, 32);
    cout << "dxl actual position : " << actualPosition << endl;
    if (dxl_comm_result != COMM_SUCCESS) {
        cout << "Erreur COMM ecriture angle " << DXL_ID << endl;
    }
}