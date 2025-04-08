#ifndef BUFFER_AND_USB_H__
#define BUFFER_AND_USB_H__


#include <stdint.h>
#include "main.h"
#include "arm_math.h"


typedef struct {
    volatile q15_t buf[MAX_CIRCULAR_BUFFER_SIZE];  // Arreglo con tamaño máximo
    volatile uint16_t head, tail;                    // Índices de escritura/lectura
    volatile uint16_t effective_size;                // Tamaño del buffer en uso (por defecto, 512)
} circularBuffer_t;

void sendBuffer2usb(circularBuffer_t *buf);
void bufferWrite(circularBuffer_t *buf, q15_t *data);
void bufferRead(circularBuffer_t *buf, q15_t *data);



#endif
