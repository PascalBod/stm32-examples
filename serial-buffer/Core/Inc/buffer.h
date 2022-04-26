/**
 * Copyright 2022 Pascal Bodin
 */
#ifndef INC_BUFFER_H_
#define INC_BUFFER_H_

#include <stdint.h>

#define BUFFER_EMPTY -1

void initBuffer(void);
void putData(uint8_t data);
int getData(void);

#endif /* INC_BUFFER_H_ */
