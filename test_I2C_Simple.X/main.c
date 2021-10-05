/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC32MM0064GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "stdio.h"
#include "delay.h"
#include "i2c1_driver.h"
#include "mcc_generated_files/drivers/i2c_simple_master.h"
//#include "mcc_generated_files/drivers/i2c_master.h"
#include "mcc_generated_files/watchdog.h"
#include <xc.h>
//#include "i2c_simple_master.h"
/*
                         Main application
 */

void I2C_Scan_Multi(void);
void I2C_Scan_Multi(void){
    
    
    uint8_t reg_index = 0x00;
    uint8_t num, add = 0;
    //WATCHDOG_TimerClear();
    for(add=0; add<255; add++)
    {    
        //I2C1_MasterWrite(&reg_index, 1, add, &status);
        i2c_writeNBytes(add, &reg_index, 1);
        DELAY_milliseconds(5);
        printf("Device: %d Address: %x\n", ++num, add);
    }          

}
//i2c_writeNBytes(i2c_address_t address, void* data, size_t len);
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    I2C_Scan_Multi();
    while (1)
    {
        // Add your application code
//        printf("Device: %d Address: \n");
//        DELAY_microseconds(50);
    }
    return 1; 
}

/**
 End of File
*/

