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

/*
This Arduino example code reads the raw high-low-byte data stream 
from an EMG-Shield and sends it via the Serial Port to the PC.
*/

// HEADERS
//--------------------------------------------------------------------

#include <EMG.h>      // Includes the EMG-Shield-Class


// DECLARATIONS
//--------------------------------------------------------------------
byte data;


// SETUP
//--------------------------------------------------------------------
void setup()
{

  EMG.begin();          // initialization
  Serial.begin(9600);
  
}

// MAIN-LOOP
//--------------------------------------------------------------------
void loop()
{
  
  data = EMG.readRawDataStream();  
  Serial.write(data);    // sending the raw hi-lo-data-bytes via serial port

}
