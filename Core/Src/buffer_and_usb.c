/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    buffer_and_usb.c
  * @brief   Funciones para manejar datos utilizando la estructura buffer circular
  *y enviar los mismos por Virtual Com Port USB_OTG
  *
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#define __author__ = "Font Julián"
#define __version__ = "1.0.0"

#include "buffer_and_usb.h"
#include <string.h>
#include "usbd_cdc_if.h"
#include "arm_math.h"
#include "main.h"


extern uint8_t FFT_flag;
/* Función auxiliar para determinar si el buffer está vacío */
static inline int isBufferEmpty(circularBuffer_t *buf) {
    return (buf->head == buf->tail);
}

/* Escribe un dato en el buffer circular */
void bufferWrite(circularBuffer_t *buf, q15_t *data) {
    uint16_t next = (buf->head + 1) % buf->effective_size;
    if (next == buf->tail) {
        // Buffer lleno: aquí podrías decidir sobrescribir, bloquear o simplemente ignorar el dato.
        return;
    }
    buf->buf[buf->head] = *data;
    buf->head = next;
}

/* Lee un dato del buffer circular */
void bufferRead(circularBuffer_t *buf, q15_t *data) {
    if (isBufferEmpty(buf)) {
        // Buffer vacío: no hay nada que leer.
        return;
    }
    *data = buf->buf[buf->tail];
    buf->tail = (buf->tail + 1) % buf->effective_size;
}

/* Calcula el número de bytes disponibles en el buffer */
uint16_t availableBytes(circularBuffer_t *buf) {
    if (buf->head >= buf->tail)
        return buf->head - buf->tail;
    else
        return (buf->effective_size - buf->tail) + buf->head;
}

/* Envía datos leídos desde el buffer circular a través del USB */
void sendBuffer2usb(circularBuffer_t *buf)
{
    q15_t tempBufferInput[USB_BUFFER_SIZE];
    uint8_t tempBufferOutput[USB_BUFFER_SIZE];
    uint16_t count = 0;
    uint16_t available = availableBytes(buf);

    // Si hay datos disponibles, extraer hasta USB_BUFFER_SIZE o hasta que se vacíe el buffer
    if(available >= USB_BUFFER_SIZE) {
        while ((count < USB_BUFFER_SIZE) && (!isBufferEmpty(buf))) {
            bufferRead(buf, &tempBufferInput[count]);
            tempBufferOutput[count] = (uint8_t)(((uint32_t)(tempBufferInput[count] + 32768)) >> 8);
            if(tempBufferOutput[count] == 255){tempBufferOutput[count] = 254;}
            count++;
        }
        // Se transmiten los datos disponibles vía USB, aunque sean menos de USB_BUFFER_SIZE
        if (CDC_Transmit_FS(tempBufferOutput, count) != USBD_OK) {
            // Manejo de error: aquí podrías reintentar la transmisión o registrar el error.
        }
    }
}
