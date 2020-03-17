
// Include Libraries
#include "Arduino.h"
#include "DCMDriverL298.h"


// Pin Definitions
#define DCMOTORDRIVERL298_1_PIN_INT1	2
#define DCMOTORDRIVERL298_1_PIN_ENB	6
#define DCMOTORDRIVERL298_1_PIN_INT2	3
#define DCMOTORDRIVERL298_1_PIN_ENA	5
#define DCMOTORDRIVERL298_1_PIN_INT3	4
#define DCMOTORDRIVERL298_1_PIN_INT4	7
#define DCMOTORDRIVERL298_2_PIN_INT1	8
#define DCMOTORDRIVERL298_2_PIN_ENB	10
#define DCMOTORDRIVERL298_2_PIN_INT2	11
#define DCMOTORDRIVERL298_2_PIN_ENA	9
#define DCMOTORDRIVERL298_2_PIN_INT3	12
#define DCMOTORDRIVERL298_2_PIN_INT4	13



// Global variables and defines

// object initialization
DCMDriverL298 dcMotorDriverL298_1(DCMOTORDRIVERL298_1_PIN_ENA,DCMOTORDRIVERL298_1_PIN_INT1,DCMOTORDRIVERL298_1_PIN_INT2,DCMOTORDRIVERL298_1_PIN_ENB,DCMOTORDRIVERL298_1_PIN_INT3,DCMOTORDRIVERL298_1_PIN_INT4);
DCMDriverL298 dcMotorDriverL298_2(DCMOTORDRIVERL298_2_PIN_ENA,DCMOTORDRIVERL298_2_PIN_INT1,DCMOTORDRIVERL298_2_PIN_INT2,DCMOTORDRIVERL298_2_PIN_ENB,DCMOTORDRIVERL298_2_PIN_INT3,DCMOTORDRIVERL298_2_PIN_INT4);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // L298N Motor Driver with Dual Micro DC Motors (Geared) #1 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    dcMotorDriverL298_1.setMotorA(200,1);
    dcMotorDriverL298_1.setMotorB(200,0);
    delay(2000);
    //Stop both motors
    dcMotorDriverL298_1.stopMotors();
    delay(2000);

    }
    else if(menuOption == '2') {
    // L298N Motor Driver with Dual Micro DC Motors (Geared) #2 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    dcMotorDriverL298_2.setMotorA(200,1);
    dcMotorDriverL298_2.setMotorB(200,0);
    delay(2000);
    //Stop both motors
    dcMotorDriverL298_2.stopMotors();
    delay(2000);

    }
    else if(menuOption == '3')
    {
    // Disclaimer: The SparkFun Line Follower Array is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) L298N Motor Driver with Dual Micro DC Motors (Geared) #1"));
    Serial.println(F("(2) L298N Motor Driver with Dual Micro DC Motors (Geared) #2"));
    Serial.println(F("(3) SparkFun Line Follower Array"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing L298N Motor Driver with Dual Micro DC Motors (Geared) #1"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing L298N Motor Driver with Dual Micro DC Motors (Geared) #2"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing SparkFun Line Follower Array - note that this component doesn't have a test code"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/