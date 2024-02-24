#include "STD_type.h"
#include "BIT_math.h"
#include "sensor.h"
#include <util/delay.h>
#include <avr/io.h>


#define Ro 10.0

f32 ConvertToGasConcentration(u16 gasValue) {
    float Rs_Ro_Ratio;
    float gasConcentration;

    Rs_Ro_Ratio = (float)gasValue / Ro;

    float sensitivity = 0.6;

    gasConcentration = Rs_Ro_Ratio * sensitivity;

    return gasConcentration;
}

f32 ConvertToLPG(f32 gasConcentration) {
    float lpgValue = gasConcentration * 1.5; // Exemplary relation, modify this according to specifications
    return lpgValue;
}


//=====================================================================

u16 ConvertToTemp(u16 adc_value) {
	u16 temp_celsius ;
    temp_celsius = ((u32)adc_value * 5000ul) / (1024.0 * 10.0);
    return temp_celsius;
}



