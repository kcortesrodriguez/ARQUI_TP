#ifndef __CLOCK_H__
#define __CLOCK_H__

#define CLOCK_REGA					0x0a

#define CLOCK_ATTR_PORT			0x70
#define CLOCK_GETSET_PORT		0x71

typedef enum {
	SECONDS 				= 0x00,
	MINUTES 				= 0X02,
	HOURS 				= 0X04,
	WEEKDAY 				= 0X06,
	DAY_OF_MONTH 		= 0X07,
	MONTH 				= 0X08,
	YEAR 					= 0X09
} clock_attr;

uint8_t clock_get(clock_attr attr);
void clock_set(clock_attr attr, uint8_t value);

#endif