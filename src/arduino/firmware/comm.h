/**
 * DMX-84
 * Communication header
 *
 * This file contains the external defines and prototypes for communicating
 * with the calculator and the serial port.
 *
 * Last modified July 13, 2014
 */

#ifndef COMM_H
#define COMM_H

/******************************************************************************
 * Includes
 ******************************************************************************/

#include <inttypes.h>

/******************************************************************************
 * External constants
 ******************************************************************************/

//Some of the valid TI packet commands
#define CMD_CTS               0x09
#define CMD_DATA              0x15
#define CMD_SKIP_EXIT         0x36
#define CMD_ACK               0x56
#define CMD_ERR               0x5A
#define CMD_RDY               0x68
#define CMD_EOT               0x92

//Buffer lengths
#define HEADER_LENGTH         4
#define PACKET_DATA_LENGTH    513
#define CHECKSUM_LENGTH       2

/******************************************************************************
 * External global variables
 ******************************************************************************/

/* These communication buffers are external so they can be reused as temporary
 * buffers by other files. Collectively, they use over a quarter of the SRAM.
 */
extern uint8_t packetHead[HEADER_LENGTH];
extern uint8_t packetData[PACKET_DATA_LENGTH];
extern uint8_t packetChecksum[CHECKSUM_LENGTH];

/******************************************************************************
 * External function prototypes
 ******************************************************************************/

void initComm(void);
void send(const uint8_t *data, uint16_t length);
void sendTICommand(uint8_t commandID);
void receive(uint8_t *data, uint16_t length);
uint8_t getPacket(void);

#endif