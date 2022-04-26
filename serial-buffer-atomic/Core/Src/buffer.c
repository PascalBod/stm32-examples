/**
 * Copyright 2020 Pascal Bodin
 */

#include "stm32l4xx_hal.h"
#include "buffer.h"

#define BUFFER_LENGTH 64

static uint16_t inIndex;
static uint16_t outIndex;
static uint16_t dataLength;
static uint8_t ringBuffer[BUFFER_LENGTH];

void initBuffer(void) {
	inIndex = 0;
	outIndex = 0;
	dataLength = 0;
}

void putData(uint8_t data) {
	ringBuffer[inIndex] = data;
	// Move inIndex forward.
	inIndex++;
	if (inIndex == BUFFER_LENGTH) {
		inIndex = 0;
	}
	dataLength++;
	if (dataLength == BUFFER_LENGTH + 1) {
		// Overflow. Move outIndex forward.
		outIndex++;
		if (outIndex == BUFFER_LENGTH) {
			outIndex = 0;
		}
		dataLength--;
	}
}

int getData(void) {
	HAL_NVIC_DisableIRQ(USART2_IRQn);
	if (dataLength == 0) {
		HAL_NVIC_EnableIRQ(USART2_IRQn);
		return BUFFER_EMPTY;
	}
	uint8_t dataToReturn = ringBuffer[outIndex];
	dataLength--;
	// Move outIndex forward.
	outIndex++;
	if (outIndex == BUFFER_LENGTH) {
		outIndex = 0;
	}
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	return dataToReturn;
}

