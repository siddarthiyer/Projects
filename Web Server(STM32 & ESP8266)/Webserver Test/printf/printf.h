/*
 * printf.h
 *
 *  Created on: Jun 2, 2022
 *      Author: sidiyer27
 */

#ifndef PRINTF_H_
#define PRINTF_H_

#include "string.h"
#include "stdlib.h"
#include "stdarg.h"
#include "stdint.h"
#include "main.h"

void serialPrintInit(int baud);
void serialPrint(char *msg, ...);



#endif /* PRINTF_H_ */
