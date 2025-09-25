#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ULTRASONIC_TRIGGER_PORT_ID PORTD_ID
#define ULTRASONIC_TRIGGER_PIN_ID  PIN7_ID

#define ULTRASONIC_ECHO_PORT_ID    PORTD_ID
#define ULTRASONIC_ECHO_PIN_ID     PIN6_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description: Initializes the ultrasonic sensor by:
 * 1. Initializing the ICU driver.
 * 2. Setting up the trigger pin direction.
 * 3. Setting the ICU callback to Ultrasonic_edgeProcessing.
 */
void Ultrasonic_init(void);

/*
 * Description: Sends a 10us pulse on the trigger pin to start the measurement.
 */
void Ultrasonic_trigger(void);

/*
 * Description: Returns the measured distance in cm.
 */

uint16 Ultrasonic_readDistance(void);

/*
 * Description: Called by ICU ISR to process rising/falling edge timings.
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
