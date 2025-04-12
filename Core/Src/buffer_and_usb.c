/* USER CODE BEGIN Header */
/*
  ******************************************************************************
  * @file    buffer_and_usb.c
  * @brief   Implementación de buffer circular y envío de datos por USB.
  *
  * @author  Font Julián
  * @version 1.0.1
  ******************************************************************************
  * @note    Funciones asociadas a la utilización de la estructura de datos buffer
  * circular y la transmisión de datos por USB OTG casteados a Q15.
  ******************************************************************************
  *	HISTORIAL DE CAMBIOS:
  *	v1.0.0		Creación de la librería
  *	v1.0.1		Comentarios de la librería en formato Doxygen
  *******************************************************************************
*/

/* USER CODE END Header */
#include "buffer_and_usb.h"
#include <string.h>
#include "usbd_cdc_if.h"
#include "arm_math.h"
#include "main.h"


extern uint8_t FFT_flag;

/*
  * @brief  Verifica si el buffer circular está vacío
  * @param  buf Puntero a la estructura del buffer circular
  * @retval int Devuelve 1 si el buffer está vacío, 0 en caso contrario
  * @note   Función helper estática inline
  */
static inline int isBufferEmpty(circularBuffer_t *buf) {
    return (buf->head == buf->tail);
}

/*
  * @brief  Escribe datos en el buffer circular
  * @param  buf  Puntero a la estructura del buffer circular
  * @param  data Puntero a los datos a escribir
  * @retval None
  * @note   Descarta silenciosamente los datos si el buffer está lleno (sin sobreescritura)
  */

void bufferWrite(circularBuffer_t *buf, q15_t *data) {
    uint16_t next = (buf->head + 1) % buf->effective_size;
    if (next == buf->tail) {
        // Buffer lleno: aquí podrías decidir sobrescribir, bloquear o simplemente ignorar el dato.
        return;
    }
    buf->buf[buf->head] = *data;
    buf->head = next;
}

/**
  * @brief  Lee datos del buffer circular
  * @param  buf  Puntero a la estructura del buffer circular
  * @param  data Puntero donde almacenar el dato leído
  * @retval None
  * @note   No realiza acción si el buffer está vacío
  */
void bufferRead(circularBuffer_t *buf, q15_t *data) {
    if (isBufferEmpty(buf)) {
        // Buffer vacío: no hay nada que leer.
        return;
    }
    *data = buf->buf[buf->tail];
    buf->tail = (buf->tail + 1) % buf->effective_size;
}

/**
  * @brief  Calcula los bytes disponibles en el buffer
  * @param  buf Puntero a la estructura del buffer circular
  * @retval uint16_t Número de bytes disponibles para lectura
  */
uint16_t availableBytes(circularBuffer_t *buf) {
    if (buf->head >= buf->tail)
        return buf->head - buf->tail;
    else
        return (buf->effective_size - buf->tail) + buf->head;
}

/**
  * @brief  Transmite el contenido del buffer por interfaz USB CDC
  * @param  buf Puntero a la estructura del buffer circular
  * @retval None
  * @note   Realiza conversión de formato q15_t a 8 bits sin signo
  * @note   Evita enviar valores 0xFF (reemplazados por 0xFE) por posibles conflictos de protocolo
  * @note   Usa transmisión USB no bloqueante con detección básica de errores
  */
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
