/*
 * Copyright Nils Minor, c 2016
 *
 * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * REGISTER START
 *
 * REGISTER WRITE BORDER
 *
 * REGISTER END
 */


#ifndef _PSOM_REGISTER_H_
#define _PSOM_REGISTER_H_

#include "stdint.h"

#define mset_bit(REG, BIT)      ((REG) |= (1 << BIT))
#define mclear_bit(REG, BIT)    ((REG) &= ~(1 << BIT ))


// Version 1.0.0
#define PSOM_VERSION					1
#define PSOM_SVERSION1				2
#define PSOM_SVERSION2				3

#define PSOM_SYNC							0xAA


typedef enum 		PSOM_COM_STATE  {
    PSOM_COM_UART_OK,
    PSOM_COM_UART_ERR
} PSOM_COM_STATE;


typedef enum
{	PSOM_STATE_OK = 0,
    PSOM_STATE_ERROR = 1,
    PSOM_STATE_WRONG_VALUE = 2,
    PSOM_STATE_SENSOR_NR = 3,
    PSOM_STATE_HEADER_NOSYNC = 4,
    PSOM_STATE_WRONG_CHECKSUM = 5,
    PSOM_STATE_WRONG_REG_ADDR = 6,
    PSOM_STATE_WRONG_CMD = 7
} PSOM_State;

typedef enum  {
    PSOM_READ_CMD = 0x01,
    PSOM_WRITE_CMD = 0x10,
    PSOM_GET_STATE_CMD = 0x20
} PSOM_COMMANDS;

typedef enum  {
    POS_SYNC_HEADER = 0,
    POS_DATA_COUNT = 1,
    POS_SUB_ID = 2,
    POS_COMMAND = 3,
    POS_REG_ADDR_MSB = 4,
    POS_REG_ADDR_LSB = 5,
    POS_DATA_START = 6,
    PSOM_CRC = 10
} PSOM_PACKET_STYLE;

typedef union PSOM_BigEndianMemory {
    float       floatData;
    uint32_t    uint32Data;
    uint8_t     byteData[4];
    char        charData[4];
}PSOM_BigEndianMemory;

/* ************ PSOM REGISTER SETUP ************* ************** **/
#define PSOM_REG_START          	0x0000                  // uint32 - start address of the PSOM registers
#define PSOM_REG_WRITE_BORDER			PSOM_FREE4   						// uint32 - start address of the read/write registers of the PSOM register
#define PSOM_REG_QUANTITY       	(HARM_L3_H11 + 4)       // uint32 - amount of regitsers used by the PSOM register, equals to the last read only register
#define PSOM_REGISTER_COUNT       110 										// uint32 -

/* ************ PSOM COMMANDS *********************************** */
#define	PSOM_SCMD_DEFAULT					0x00000000
#define PSOM_SCMD_RESTART					0x00000001
#define PSOM_SCMD_CLR_ENERGY_ALL  0x00000010
#define PSOM_SCMD_CLR_ENERGY_L1   0x00000011
#define PSOM_SCMD_CLR_ENERGY_L2   0x00000012
#define PSOM_SCMD_CLR_ENERGY_L3   0x00000013
#define PSOM_SCMD_CALLIB_V1				0X00000101
#define PSOM_SCMD_CALLIB_V2				0X00000102
#define PSOM_SCMD_CALLIB_V3				0X00000103
#define PSOM_SCMD_CALLIB_I1				0X00000201
#define PSOM_SCMD_CALLIB_I2				0X00000202
#define PSOM_SCMD_CALLIB_I3				0X00000203
#define PSOM_SCMD_CALLOAD					0X00000204
#define PSOM_SCMD_CALLIB_OFF1			0X00000301
#define PSOM_SCMD_CALLIB_OFF2			0X00000302
#define PSOM_SCMD_CALLIB_OFF3			0X00000303
#define PSOM_SCMD_CALLIB_T				0X00000500
#define PSOM_SCMD_CALLIB_F   			0X00000501
#define PSOM_SCMD_HARM_V 	  			0X00001000
#define PSOM_SCMD_HARM_I 	  			0X00001001
#define PSOM_SCMD_HARM_P 	  			0X00001002
#define PSOM_SCMD_HARM_Q 	  			0X00001003

#define PSOM_SCMD_EVSE_MAX_I


/* ************ PSOM SAMPLE STYLES ******** */
#define PSOM_SAMPLE_STYLE_NORM  	0x00000000 	// uint32 - - sampling style for normal operations
#define PSOM_SAMPLE_STYLE_MEAN  	0x00000001  // uint32 - - sampling style for building the average over the amount of samples specified in the PSOM_SAMPLES_QUANTITY register

/* ************ GENERAL ************ ************ ************** **/
#define PSOM_STATE                0x0000  		// uint32  - - Represents the state of the PSOM module
#define PSOM_SCOMMAND             0x0004  		// uint32  - - The command register can setup additional functionality of the PSOM module
#define PSOM_SCOMMAND_VALUE       0x0008  		// uint32  - - Value to use as data by the software command
#define PSOM_FW_VERSION           0x000C  		// uint32  - - PSOM firmeware version
#define PSOM_ACTIVE_HARM          0x0010  		// uint32  - - Selects/represents the measured harmonic phase (eg. 1,2,3 ...)
#define ENERGY_COSTS							0x0014  		// uint32  - - Represents the costs per kWh - default = 0.25€
#define PSOM_SAMPLE_STYLE        	0x0018  		// uint32  - - Set the samples style for better filtering
#define PSOM_SAMPLES_QUANTITY    	0x001C  		// uint32  - - Set the filter size / data quantity
#define PSOM_SUB_ID     					0x0020  		// uint32  - - The SUB-ID of the module
#define PSOM_PWM1				  				0x0024  		// uint32  - - PWM Output (1 Khz) in percantage (0 - 100%)
#define PSOM_MODE				     			0x0028  		// uint32  - - Represents the operating mode
#define PSOM_EVSE_STATE						0x002C  		// uint32  - - Represents the actual state of the EVSE state machine
#define PSOM_EVSE_MAX_CURRENT    	0x0030  		// uint32  - - Determines the maximum current (defualt 16A)
#define PSOM_FREE3   							0x0034  		//
#define PSOM_FREE4   							0x0038  		//
#define PSOM_UUID_H 							0x003C  		//
#define PSOM_UUID_MH   						0x0040  		//
#define PSOM_UUID_ML   						0x0044  		//
#define PSOM_UUID_L	   						0x0048  		//
#define PSOM_FREE									0x004C  		//
#define ADC1_VOLTAGE 							0x0050  		//
#define ADC2_VOLTAGE   						0x0054  		//
#define ADC3_VOLTAGE   						0x0058  		//
#define ADC4_VOLTAGE 							0x005C			//
/* ************ COMMON  ************ ************ ************** **/
#define MODULE_TEMPERATURE_F      0x0060   		// float - °C- die temperature of the chip
#define LINE_FREQUENCY_F          0x0064   		// float - Hz- frequency of all phases
/* ************ VOLTAGE ************ ************ ************** **/
#define L1_VOLTAGE_RMS					  0x0068   		// float - V - RMS voltage of phase 1
#define L2_VOLTAGE_RMS           	0x006C   		// float - V - RMS voltage of phase 2
#define L3_VOLTAGE_RMS				    0x0070   		// float - V - RMS voltage of phase 3
#define LT_VOLTAGE_RMS            0x0074   		// float - V - RMS voltage of total phase
#define L1_VOLTAGE_PEAK           0x0078   		// float - V - peak voltage of phase 1
#define L2_VOLTAGE_PEAK           0x007C   		// float - V - peak voltage of phase 2
#define L3_VOLTAGE_PEAK           0x0080   		// float - V - peak voltage of phase 3
#define L1_VOLTAGE_THD           	0x0084   		// float - V - THD of voltage of phase 1
#define L2_VOLTAGE_THD           	0x0088   		// float - V - THD of voltage of phase 2
#define L3_VOLTAGE_THD           	0x008C   		// float - V - THD of voltage of phase 3
#define L1_VOLTAGE_FREE           0x0090   		// float - V -
#define L2_VOLTAGE_FREE          	0x0094   		// float - V -
#define L3_VOLTAGE_FREE           0x0098   		// float - V -
/* ************ CURRENT ************ ************ ************** **/
#define L1_CURRENT_RMS            0x009C   		// float - A - RMS current of phase 1
#define L2_CURRENT_RMS            0x00A0   		// float - A - RMS current of phase 2
#define L3_CURRENT_RMS            0x00A4   		// float - A - RMS current of phase 3
#define LT_CURRENT_RMS            0x00A8   		// float - A - RMS current of total phase
#define L1_CURRENT_PEAK           0x00AC   		// float - A - peak current of phase 1
#define L2_CURRENT_PEAK           0x00B0   		// float - A - peak current of phase 2
#define L3_CURRENT_PEAK           0x00B4   		// float - A - peak current of phase 3
#define L1_CURRENT_THD            0x00B8   		// float - A - THD of current of phase 1
#define L2_CURRENT_THD            0x00BC   		// float - A - THD of current of phase 1
#define L3_CURRENT_THD            0x00C0   		// float - A - THD of current of phase 1
#define L1_CURRENT_FREE           0x00C4   		// float - A -
#define L2_CURRENT_FREE           0x00C8   		// float - A -
#define L3_CURRENT_FREE           0x00CC   		// float - A -
/* ************ POWER   ************ ************ ************** **/
#define L1_POWER_ACTIVE           0x00D0   		// float - W - active power of phase 1
#define L2_POWER_ACTIVE           0x00D4   		// float - W - active power of phase 2
#define L3_POWER_ACTIVE           0x00D8   		// float - W - active power of phase 3
#define LT_POWER_ACTIVE           0x00DC   		// float - W - average active power of all phases
#define L1_POWER_REACTIVE         0x00E0   		// float - VAR - reactive power of phase 1
#define L2_POWER_REACTIVE         0x00E4   		// float - VAR - reactive power of phase 2
#define L3_POWER_REACTIVE         0x00E8   		// float - VAR - reactive power of phase 3
#define LT_POWER_REACTIVE         0x00EC   		// float - VAR - average reactive power of all phases
#define L1_POWER_APPARENT         0x00F0   		// float - VA - apparent power of phase 1
#define L2_POWER_APPARENT         0x00F4   		// float - VA - apparent power of phase 2
#define L3_POWER_APPARENT         0x00F8   		// float - VA - apparent power of phase 3
#define LT_POWER_APPARENT         0x00FC   		// float - VA - average apparent power of all phases
#define L1_POWER_FACTOR           0x0100   		// float - °  - power factor of phase 1
#define L2_POWER_FACTOR           0x0104   		// float - °  - power factor of phase 2
#define L3_POWER_FACTOR           0x0108   		// float - °  - power factor of phase 3
#define LT_POWER_FACTOR           0x010C   		// float - °  - average power factor of all phases
/* ************ ENERGY  ************ ************ ************** **/
#define L1_ENERGY_ACTIVE       		0x0110   		// float - Wh - positive energy counter of phase 1
#define L2_ENERGY_ACTIVE    	    0x0114   		// float - Wh - positive energy counter of phase 2
#define L3_ENERGY_ACTIVE 		     	0x0118   		// float - Wh - positive energy counter of phase 3
#define L1_ENERGY_REACTIVE 		 		0x011C   		// float - Wh - negatvie energy counter of phase 1
#define L2_ENERGY_REACTIVE        0x0120   		// float - Wh - negatvie energy counter of phase 2
#define L3_ENERGY_REACTIVE        0x0124   		// float - Wh - negatvie energy counter of phase 3
#define L1_ENERGY_COST            0x0128   		// float - $/€ - energy costs of phase 1
#define L2_ENERGY_COST            0x012C   		// float - $/€ - energy costs of phase 2
#define L3_ENERGY_COST            0x0130   		// float - $/€ - energy costs of phase 3
/* ************ ENERGY  ************ ************ ************** **/
#define HARM_L1_H1            		0x0134   		// float - ?? - harmonic 1
#define HARM_L1_H2            		0x0138			// float - ?? - harmonic 2
#define HARM_L1_H3            		0x013C   		// float - ?? - harmonic 3
#define HARM_L1_H4            		0x0140   		// float - ?? - harmonic 4
#define HARM_L1_H5            		0x0144   		// float - ?? - harmonic 5
#define HARM_L1_H6            		0x0148   		// float - ?? - harmonic 6
#define HARM_L1_H7            		0x014C   		// float - ?? - harmonic 7
#define HARM_L1_H8            		0x0150   		// float - ?? - harmonic 8
#define HARM_L1_H9            		0x0154   		// float - ?? - harmonic 9
#define HARM_L1_H10            		0x0158   		// float - ?? - harmonic 10
#define HARM_L1_H11            		0x015C   		// float - ?? - harmonic 11
#define HARM_L2_H1            		0x0160   		// float - ?? - harmonic 1
#define HARM_L2_H2            		0x0164   		// float - ?? - harmonic 2
#define HARM_L2_H3            		0x0168   		// float - ?? - harmonic 3
#define HARM_L2_H4            		0x016C   		// float - ?? - harmonic 4
#define HARM_L2_H5            		0x0170   		// float - ?? - harmonic 5
#define HARM_L2_H6            		0x0174   		// float - ?? - harmonic 6
#define HARM_L2_H7            		0x0178   		// float - ?? - harmonic 7
#define HARM_L2_H8            		0x017C   		// float - ?? - harmonic 8
#define HARM_L2_H9            		0x0180   		// float - ?? - harmonic 9
#define HARM_L2_H10            		0x0184      // float - ?? - harmonic 10
#define HARM_L2_H11            		0x0188   		// float - ?? - harmonic 11
#define HARM_L3_H1            		0x018C   		// float - ?? - harmonic 1
#define HARM_L3_H2            		0x0190   		// float - ?? - harmonic 2
#define HARM_L3_H3            		0x0194   		// float - ?? - harmonic 3
#define HARM_L3_H4            		0x0198   		// float - ?? - harmonic 4
#define HARM_L3_H5            		0x019C   		// float - ?? - harmonic 5
#define HARM_L3_H6            		0x01A0   		// float - ?? - harmonic 6
#define HARM_L3_H7            		0x01A4   		// float - ?? - harmonic 7
#define HARM_L3_H8            		0x01A8   		// float - ?? - harmonic 8
#define HARM_L3_H9            		0x01AC   		// float - ?? - harmonic 9
#define HARM_L3_H10            		0x01B0   		// float - ?? - harmonic 10
#define HARM_L3_H11            		0x01B4   		// float - ?? - harmonic 11


#endif /* [] END OF FILE */
