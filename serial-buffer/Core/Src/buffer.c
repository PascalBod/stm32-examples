/**
 * Copyright 2020 Pascal Bodin
 */

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
	if (dataLength == 0) {
		return BUFFER_EMPTY;
	}
	uint8_t dataToReturn = ringBuffer[outIndex];
	dataLength--;
	// Move outIndex forward.
	outIndex++;
	if (outIndex == BUFFER_LENGTH) {
		outIndex = 0;
	}
	return dataToReturn;
}

