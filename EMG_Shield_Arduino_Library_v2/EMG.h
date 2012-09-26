/*
* CADET - Center for Advances in Digital Entertainment Technologies
* Copyright 2012 University of Applied Science Salzburg / MultiMediaTechnology & Ars Electronica Futurelab
*
* http://www.cadet.at
* http://multimediatechnology.at
* http://research.aec.at
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
* http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
* 
* CADET - Center for Advances in Digital Entertainment Technologies
* funded by the Austrian Research Promotion Agency (http://www.ffg.at)
*/

#ifndef _EMG_H_INCLUDED
#define _EMG_H_INCLUDED




#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <avr\pgmspace.h>
#include <util/delay.h>
#include <Arduino.h>
#include <pins_arduino.h>


#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06
//#define SPI_CLOCK_DIV64 0x07

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR

#define EMG_MAX_CHANNELS 2

class EMG_Class 
{
	public:

	EMG_Class();     // Declaring a constructor
  
	// DECLARATION of METHODS
	void begin();
	void begin(int filterValue = 1);
	void end();
    void update();
	uint16_t read(int channel);
	byte readRawDataStream();
    
    void rawData(byte &LowByte, byte &HighByte, uint16_t &EMG_data, byte &channel);

    uint16_t dataMissCount;    
    
	private:
	
	class EMG_Channel
	{
		public:
		
		EMG_Channel();
        
        uint16_t moving_average(uint16_t input);
        
        uint16_t latestValue;
		int filter_value;               // filter_value (1-100)
		uint16_t index;	                // index for samples-filter-array
		uint16_t samples_EMG[101];      // samples-filter-array  
	};
	
	void setClockDivider(byte rate);
	byte master_Receive(void);
	
	// DECLARATION of VARIABLES
	EMG_Channel channels[EMG_MAX_CHANNELS];
};

extern EMG_Class EMG;

#endif
