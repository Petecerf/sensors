
#ifndef __POWER_H__
#define __POWER_H__

/* Header includes */
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "../global.h"



#define TYPE_BYTE   POWER
#define M_NR        0x03

#define SLAVE_ADDRESS I2C_ADDRESS


#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED0 aliases
#define LED0_TRIS                           TRISBbits.TRISB6
#define LED0_LAT                            LATBbits.LATB6
#define LED0_PORT                           PORTBbits.RB6
#define LED0_WPU                            WPUBbits.WPUB6
#define LED0_OD                             ODCONBbits.ODCB6
#define LED0_ANS                            ANSELBbits.ANSB6
#define LED0_SetHigh()                      do { LATBbits.LATB6 = 1; } while(0)
#define LED0_SetLow()                       do { LATBbits.LATB6 = 0; } while(0)
#define LED0_Toggle()                       do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define LED0_GetValue()                     PORTBbits.RB6
#define LED0_SetDigitalInput()              do { TRISBbits.TRISB6 = 1; } while(0)
#define LED0_SetDigitalOutput()             do { TRISBbits.TRISB6 = 0; } while(0)
#define LED0_SetPullup()                    do { WPUBbits.WPUB6 = 1; } while(0)
#define LED0_ResetPullup()                  do { WPUBbits.WPUB6 = 0; } while(0)
#define LED0_SetPushPull()                  do { ODCONBbits.ODCB6 = 0; } while(0)
#define LED0_SetOpenDrain()                 do { ODCONBbits.ODCB6 = 1; } while(0)
#define LED0_SetAnalogMode()                do { ANSELBbits.ANSB6 = 1; } while(0)
#define LED0_SetDigitalMode()               do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set SOL_MEAS_EN aliases
#define SOL_MEAS_EN_TRIS                    TRISCbits.TRISC0
#define SOL_MEAS_EN_LAT                     LATCbits.LATC0
#define SOL_MEAS_EN_PORT                    PORTCbits.RC0
#define SOL_MEAS_EN_WPU                     WPUCbits.WPUC0
#define SOL_MEAS_EN_OD                      ODCONCbits.ODCC0
#define SOL_MEAS_EN_ANS                     ANSELCbits.ANSC0
#define SOL_MEAS_EN_SetHigh()               do { LATCbits.LATC0 = 1; } while(0)
#define SOL_MEAS_EN_SetLow()                do { LATCbits.LATC0 = 0; } while(0)
#define SOL_MEAS_EN_Toggle()                do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SOL_MEAS_EN_GetValue()              PORTCbits.RC0
#define SOL_MEAS_EN_SetDigitalInput()       do { TRISCbits.TRISC0 = 1; } while(0)
#define SOL_MEAS_EN_SetDigitalOutput()      do { TRISCbits.TRISC0 = 0; } while(0)
#define SOL_MEAS_EN_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define SOL_MEAS_EN_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define SOL_MEAS_EN_SetPushPull()           do { ODCONCbits.ODCC0 = 0; } while(0)
#define SOL_MEAS_EN_SetOpenDrain()          do { ODCONCbits.ODCC0 = 1; } while(0)
#define SOL_MEAS_EN_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define SOL_MEAS_EN_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SOL_MEAS_EN aliases
#define BAT_MEAS_EN_TRIS                    TRISCbits.TRISC6
#define BAT_MEAS_EN_LAT                     LATCbits.LATC6
#define BAT_MEAS_EN_PORT                    PORTCbits.RC6
#define BAT_MEAS_EN_WPU                     WPUCbits.WPUC6
#define BAT_MEAS_EN_OD                      ODCONCbits.ODCC6
#define BAT_MEAS_EN_ANS                     ANSELCbits.ANSC6
#define BAT_MEAS_EN_SetHigh()               do { LATCbits.LATC6 = 1; } while(0)
#define BAT_MEAS_EN_SetLow()                do { LATCbits.LATC6 = 0; } while(0)
#define BAT_MEAS_EN_Toggle()                do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define BAT_MEAS_EN_GetValue()              PORTCbits.RC6
#define BAT_MEAS_EN_SetDigitalInput()       do { TRISCbits.TRISC6 = 1; } while(0)
#define BAT_MEAS_EN_SetDigitalOutput()      do { TRISCbits.TRISC6 = 0; } while(0)
#define BAT_MEAS_EN_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define BAT_MEAS_EN_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define BAT_MEAS_EN_SetPushPull()           do { ODCONCbits.ODCC6 = 0; } while(0)
#define BAT_MEAS_EN_SetOpenDrain()          do { ODCONCbits.ODCC6 = 1; } while(0)
#define BAT_MEAS_EN_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define BAT_MEAS_EN_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                           TRISCbits.TRISC1
#define LED1_LAT                            LATCbits.LATC1
#define LED1_PORT                           PORTCbits.RC1
#define LED1_WPU                            WPUCbits.WPUC1
#define LED1_OD                             ODCONCbits.ODCC1
#define LED1_ANS                            ANSELCbits.ANSC1
#define LED1_SetHigh()                      do { LATCbits.LATC1 = 1; } while(0)
#define LED1_SetLow()                       do { LATCbits.LATC1 = 0; } while(0)
#define LED1_Toggle()                       do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LED1_GetValue()                     PORTCbits.RC1
#define LED1_SetDigitalInput()              do { TRISCbits.TRISC1 = 1; } while(0)
#define LED1_SetDigitalOutput()             do { TRISCbits.TRISC1 = 0; } while(0)
#define LED1_SetPullup()                    do { WPUCbits.WPUC1 = 1; } while(0)
#define LED1_ResetPullup()                  do { WPUCbits.WPUC1 = 0; } while(0)
#define LED1_SetPushPull()                  do { ODCONCbits.ODCC1 = 0; } while(0)
#define LED1_SetOpenDrain()                 do { ODCONCbits.ODCC1 = 1; } while(0)
#define LED1_SetAnalogMode()                do { ANSELCbits.ANSC1 = 1; } while(0)
#define LED1_SetDigitalMode()               do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SOL_VOLT aliases
#define SOL_VOLT_TRIS                       TRISCbits.TRISC3
#define SOL_VOLT_LAT                        LATCbits.LATC3
#define SOL_VOLT_PORT                       PORTCbits.RC3
#define SOL_VOLT_WPU                        WPUCbits.WPUC3
#define SOL_VOLT_OD                         ODCONCbits.ODCC3
#define SOL_VOLT_ANS                        ANSELCbits.ANSC3
#define SOL_VOLT_SetHigh()                  do { LATCbits.LATC3 = 1; } while(0)
#define SOL_VOLT_SetLow()                   do { LATCbits.LATC3 = 0; } while(0)
#define SOL_VOLT_Toggle()                   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SOL_VOLT_GetValue()                 PORTCbits.RC3
#define SOL_VOLT_SetDigitalInput()          do { TRISCbits.TRISC3 = 1; } while(0)
#define SOL_VOLT_SetDigitalOutput()         do { TRISCbits.TRISC3 = 0; } while(0)
#define SOL_VOLT_SetPullup()                do { WPUCbits.WPUC3 = 1; } while(0)
#define SOL_VOLT_ResetPullup()              do { WPUCbits.WPUC3 = 0; } while(0)
#define SOL_VOLT_SetPushPull()              do { ODCONCbits.ODCC3 = 0; } while(0)
#define SOL_VOLT_SetOpenDrain()             do { ODCONCbits.ODCC3 = 1; } while(0)
#define SOL_VOLT_SetAnalogMode()            do { ANSELCbits.ANSC3 = 1; } while(0)
#define SOL_VOLT_SetDigitalMode()           do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set BAT_VOLT aliases
#define BAT_VOLT_TRIS                       TRISCbits.TRISC4
#define BAT_VOLT_LAT                        LATCbits.LATC4
#define BAT_VOLT_PORT                       PORTCbits.RC4
#define BAT_VOLT_WPU                        WPUCbits.WPUC4
#define BAT_VOLT_OD                         ODCONCbits.ODCC4
#define BAT_VOLT_ANS                        ANSELCbits.ANSC4
#define BAT_VOLT_SetHigh()                  do { LATCbits.LATC4 = 1; } while(0)
#define BAT_VOLT_SetLow()                   do { LATCbits.LATC4 = 0; } while(0)
#define BAT_VOLT_Toggle()                   do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define BAT_VOLT_GetValue()                 PORTCbits.RC4
#define BAT_VOLT_SetDigitalInput()          do { TRISCbits.TRISC4 = 1; } while(0)
#define BAT_VOLT_SetDigitalOutput()         do { TRISCbits.TRISC4 = 0; } while(0)
#define BAT_VOLT_SetPullup()                do { WPUCbits.WPUC4 = 1; } while(0)
#define BAT_VOLT_ResetPullup()              do { WPUCbits.WPUC4 = 0; } while(0)
#define BAT_VOLT_SetPushPull()              do { ODCONCbits.ODCC4 = 0; } while(0)
#define BAT_VOLT_SetOpenDrain()             do { ODCONCbits.ODCC4 = 1; } while(0)
#define BAT_VOLT_SetAnalogMode()            do { ANSELCbits.ANSC4 = 1; } while(0)
#define BAT_VOLT_SetDigitalMode()           do { ANSELCbits.ANSC4 = 0; } while(0)


// get/set INT aliases
#define READY_TRIS                          TRISAbits.TRISC7
#define READY_LAT                           LATAbits.LATC7
#define READY_PORT                          PORTAbits.RC7
#define READY_WPU                           WPUAbits.WPUC7
#define READY_OD                            ODCONAbits.ODCC7
#define READY_ANS                           ANSELAbits.ANSC7
#define READY_SetHigh()                     do { LATAbits.LATC7 = 1; } while(0)
#define READY_SetLow()                      do { LATAbits.LATC7 = 0; } while(0)
#define READY_Toggle()                      do { LATAbits.LATC7 = ~LATAbits.LATC7; } while(0)
#define READY_GetValue()                    PORTAbits.RC7
#define READY_SetDigitalInput()             do { TRISAbits.TRISC7 = 1; } while(0)
#define READY_SetDigitalOutput()            do { TRISAbits.TRISC7 = 0; } while(0)
#define READY_SetPullup()                   do { WPUAbits.WPUC7 = 1; } while(0)
#define READY_ResetPullup()                 do { WPUAbits.WPUC7 = 0; } while(0)
#define READY_SetPushPull()                 do { ODCONAbits.ODCC7 = 0; } while(0)
#define READY_SetOpenDrain()                do { ODCONAbits.ODCC7 = 1; } while(0)
#define READY_SetAnalogMode()               do { ANSELAbits.ANSC7 = 1; } while(0)
#define READY_SetDigitalMode()              do { ANSELAbits.ANSC7 = 0; } while(0)


#define SENSOR_API { \
    Power_Init, \
    Power_Measure, \
    Power_Loop, \
    Power_GetData, \
    Power_SetThreshold \
}  

/* Sensor API prototypes ******************************************************/

void Power_Init(void);
void Power_Measure(void);
void Power_Loop(void);
void Power_GetData(uint8_t * data, uint8_t  * length);
void Power_SetThreshold(uint8_t metric, uint8_t * thresholdData);



void generateIntPower(void);








#endif /* POWER_H_ */
/** @}*/
