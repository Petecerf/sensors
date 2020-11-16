
#include "power.h"
#include <math.h>
#include "../mcc_generated_files/mcc.h"
#include "../mcc_generated_files/adcc.h"


#ifdef SENSOR_TYPE
#if (SENSOR_TYPE == POWER)
#warning "Compiling for Power sensor"

#define SOL_VOLT   0x13
#define BAT_VOLT   0x14 //Channel ANC4 -> RC4
#define VOLT_REF   0x83 //Voltage Reference for ADC -> 4.096 V

void measureVolt(void);
void initializePowerModule(void);
uint16_t GetSingleConversion(uint8_t channel);
void generateIntPower(void);





bool startMeasurement = false;
bool measurementRunning = false;
volatile uint8_t measurementData[2* M_NR];
float floatsolvoltage;
float floatbatvoltage;
uint16_t solvoltage = 0;
uint16_t tempValue = 0;
uint16_t batvoltage = 0;
uint8_t batteryundervoltage = 0;



void Power_Init(){
    // Enable Fixed voltage reference
    FVRCON = VOLT_REF;
    // set the ADCC to the options selected in the User Interface
    // ADLTH 0; 
    ADLTHL = 0x00;
    // ADLTH 0; 
    ADLTHH = 0x00;
    // ADUTH 0; 
    ADUTHL = 0x00;
    // ADUTH 0; 
    ADUTHH = 0x00;
    // ADSTPT 0; 
    ADSTPTL = 0x00;
    // ADSTPT 0; 
    ADSTPTH = 0x00;
    // ADACC 0; 
    ADACCU = 0x00;
    // ADRPT 0; 
    ADRPT = 0x00;
    // ADPCH ANA0; 
    ADPCH = 0x00;
    // ADACQ 0; 
    ADACQL = 0x00;
    // ADACQ 0; 
    ADACQH = 0x00;
    // ADCAP Additional uC disabled; 
    ADCAP = 0x00;
    // ADPRE 0; 
    ADPREL = 0x00;
    // ADPRE 0; 
    ADPREH = 0x00;
    // ADDSEN disabled; ADGPOL digital_low; ADIPEN disabled; ADPPOL Vss; 
    ADCON1 = 0x00;
    // ADCRS 0; ADMD Basic_mode; ADACLR disabled; ADPSIS RES; 
    ADCON2 = 0x00;
    // ADCALC First derivative of Single measurement; ADTMD disabled; ADSOI ADGO not cleared; 
    ADCON3 = 0x00;
    // ADMATH registers not updated; 
    ADSTAT = 0x00;
    // ADNREF VSS; ADPREF FVR; 
    ADREF = 0x03;
    // ADACT disabled; 
    ADACT = 0x00;
    // ADCS FOSC/16; 
    ADCLK = 0x07;
    // ADGO stop; ADFM right; ADON enabled; ADCS FOSC/ADCLK; ADCONT disabled; 
    ADCON0 = 0x84;
    
    FVRCON = 0x00; // Disable fixed voltage reference
    
    
    SOL_MEAS_EN_SetDigitalOutput();
    BAT_MEAS_EN_SetDigitalOutput();

    LED0_SetDigitalOutput();
    LED1_SetDigitalOutput();
    
    
    LED0_SetLow();
    LED1_SetLow();

    SOL_MEAS_EN_SetLow();
    BAT_MEAS_EN_SetLow();
    
    
    SOL_VOLT_SetDigitalInput();
    SOL_VOLT_SetAnalogMode();
    
    BAT_VOLT_SetDigitalInput(); 
    BAT_VOLT_SetAnalogMode();
}

void Power_Measure(){
    startMeasurement = true;
}



void Power_Loop(){
    FVRCON = VOLT_REF;                                          // Enable Fixed voltage reference
    //startMeasurement = true;
    if(startMeasurement && !measurementRunning){
        startMeasurement = false;
        measurementRunning = true;

        SOL_MEAS_EN_SetHigh();                              // Enable loadswitch to measure voltage
        BAT_MEAS_EN_SetHigh();                              // Enable loadswitch to measure voltage

        LED1_SetHigh();
        LED0_SetHigh();

        __delay_ms(50);                                     // Delay for settling voltages

    
        ADCC_GetSingleConversion(SOL_VOLT);                 // first measurement afte rreset seems to be fixed and need to be rejected
        solvoltage = ADCC_GetSingleConversion(SOL_VOLT);
        __delay_ms(2000);
        
        tempValue = ADCC_GetSingleConversion(SOL_VOLT);
        if(tempValue < solvoltage){                         // To make sure it is the lowest/ stable voltage that is captured
            solvoltage = tempValue;
        }
        floatsolvoltage = ((float)solvoltage /4096) * 2 * 4.096;
        
        
        ADCC_GetSingleConversion(BAT_VOLT); 
        batvoltage = ADCC_GetSingleConversion(BAT_VOLT);
        floatbatvoltage = ((float)batvoltage /4096) * 2 * 4.096;
        
        
        SOL_MEAS_EN_SetLow();                               // Disable loadswitch to measure voltage
        BAT_MEAS_EN_SetLow();                               // Disable loadswitch to measure voltage
        
        LED0_SetLow();
        LED1_SetLow();
        
        if(floatbatvoltage < 3.3){
            batteryundervoltage = 1;
        }
        
        if(batteryundervoltage == 1){
            if(floatbatvoltage>3.5){
                batteryundervoltage = 0;
            }
        }
        
        // prepare data for I2C transmission
        uint16_t databatvoltage = (uint16_t)(round(floatbatvoltage * 600));
        uint16_t datasolvoltage = (uint16_t)(round(floatsolvoltage * 600));
        
        
    
        measurementData[0] = (uint8_t)(databatvoltage>>8);
        measurementData[1] = (uint8_t)(databatvoltage);
        
        measurementData[2] = (uint8_t)(datasolvoltage>>8);
        measurementData[3] = (uint8_t)(datasolvoltage);
        
        measurementData[4] = (uint8_t)(batteryundervoltage);
        measurementData[5] = 0x00;
        
        generateIntPower();
        measurementRunning = false;
    }
    
    FVRCON = 0x00;                                          // Disable the Fixed voltage reference
}
void Power_GetData(uint8_t * data, uint8_t  * length){
    *length = 2; // this is fixed (M_NR = 2)
    data[0] = measurementData[0];
    data[1] = measurementData[1];
}


void Power_SetThreshold(uint8_t metric, uint8_t * thresholdData){


}




void generateIntPower(void){
    READY_SetLow();
    __delay_ms(5);                          
    READY_SetHigh();
}


#endif
#endif