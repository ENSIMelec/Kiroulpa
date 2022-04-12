//
// Created by cleme on 31/03/2022.
//
#include <stdio.h>
#include <iostream>
using namespace std;

#include <dynamixel_sdk/dynamixel_sdk.h>
using namespace dynamixel;

#include "dynamixel_sdk/port_handler_linux.h"
#include "dynamixel_sdk/protocol1_packet_handler.h"

// Control table address
#define ADDR_AX_BAUD_RATE                  4
#define ADDR_AX_TORQUE_ENABLE           24                  // Control table address is different in Dynamixel model
#define ADDR_AX_GOAL_POSITION           30
#define ADDR_AX_PRESENT_POSITION        36
#define ADDR_AX_PRESENT_VOLTAGE         42
#define ADDR_AX_SPEED_VALUE             32
#define ADDR_AX_TORQUE_LIMIT            34
#define ADDR_AX_PRESENT_LOAD            40

#define READ_DATA   0x02
#define HEADER      0xFF
//Dynamixel series have their own control tables: Addresses and Byte Length in each items. To control one of the items, its address (and length if necessary) is required. Find your requirements in http://support.robotis.com/.

// Protocol version
#define PROTOCOL_VERSION                1.0                 // See which protocol version is used in the Dynamixel
// Default setting
#define BAUDRATE                        1000000
#define DEVICENAME                      "/dev/ttyACM0"      // Check which port is being used on your controller
#define DXL_ID 1
#define TORQUE_ENABLE 1

int main(int argc, char **argv) {
    PortHandler *portHandler = PortHandler::getPortHandler(DEVICENAME);
    // Open the port
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

    PacketHandler * packetHandler = PacketHandler::getPacketHandler(PROTOCOL_VERSION);

    uint16_t model_number;
    uint8_t error;
    int dxl_comm_result;

    dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID, ADDR_AX_TORQUE_ENABLE, TORQUE_ENABLE, &error);

    int forceAction = 1024;
    dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID, ADDR_AX_TORQUE_LIMIT, forceAction, &error);
    if (dxl_comm_result != COMM_SUCCESS)
    {
        //packetHandler->printTxRxResult(dxl_comm_result);
        std::cout << "Erreur COMM limitation couple " << DXL_ID << std::endl;
    }
    else if (error != 0)
    {
        //packetHandler->printRxPacketError(dxl_error);
        std::cout << "Erreur limitation couple " << DXL_ID << std::endl;
    }


    // Write goal position
    int dxl_goal_position = 0;
    dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID, ADDR_AX_GOAL_POSITION, dxl_goal_position, &error);
    if (dxl_comm_result != COMM_SUCCESS)
    {
        //packetHandler->printTxRxResult(dxl_comm_result);
        std::cout << "Erreur COMM ecriture angle " << DXL_ID << std::endl;
    }
    else if (error != 0)
    {
        //packetHandler->printRxPacketError(dxl_error);
        std::cout << "Erreur ecriture angle " << DXL_ID << std::endl;
    }
}
