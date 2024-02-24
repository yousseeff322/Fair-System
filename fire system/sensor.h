#include "STD_type.h"


#ifndef SENSOR_H_
#define SENSOR_H_


f32 ConvertToGasConcentration(u16 gasValue) ;
f32 ConvertToLPG(f32 gasConcentration) ;
u16 ConvertToTemp(u16 adc_value) ;



#endif /* SENSOR_H_ */
