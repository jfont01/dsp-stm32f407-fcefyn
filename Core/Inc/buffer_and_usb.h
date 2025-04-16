/*******************************************************************************
 * @file buffer_and_usb.h
 * @brief Manejo de buffer circular y comunicación USB
 *
 * @author  Font Julián
 * @version 1.0.0
 *******************************************************************************
 * @attention
 * Este archivo define la estructura y funciones para un búfer circular utilizado
 * en aplicaciones de DSP, junto con funciones para comunicación USB.
 *******************************************************************************
 *	HISTORIAL DE CAMBIOS:
 *	v1.0.0		Creación del header
 *******************************************************************************
 */

#ifndef BUFFER_AND_USB_H__
#define BUFFER_AND_USB_H__

#include <stdint.h>
#include "main.h"
#include "arm_math.h"

/**
 * @defgroup BufferCircular Estructura del Búfer Circular
 * @{
 */

/**
 * @brief Estructura de búfer circular para datos Q15
 *
 * Búfer de almacenamiento temporal para operaciones de lectura/escritura no bloqueantes.
 * Utiliza índices de head y tail para acceso concurrente seguro.
 */
typedef struct {
    volatile q15_t buf[MAX_CIRCULAR_BUFFER_SIZE];  /**< Almacenamiento de datos en formato Q15 */
    volatile uint16_t head;                        /**< Índice de escritura */
    volatile uint16_t tail;                        /**< Índice de lectura */
    volatile uint16_t effective_size;              /**< Tamaño real utilizado del búfer (ajustable dinamicamente) */
} circularBuffer_t;
/** @} */

/**
 * @defgroup FuncionesUSB Funciones de manejo USB
 * @{
 */

/**
 * @brief Envía el contenido del buffer por USB al almacenarse 64 muestras
 * @param buf Puntero al buffer circular a transmitir
 * @note Bloquea hasta completar la transmisión
 * @return None
 */
void sendBuffer2usb(circularBuffer_t *buf);

/**
 * @brief Escribe datos en el buffer circular
 * @param buf Puntero al búfer destino
 * @param data Datos a escribir (formato Q15)
 * @note Maneja sobreescritura automática de datos no leídos
 * @return None
 */
void bufferWrite(circularBuffer_t *buf, q15_t *data);

/**
 * @brief Lee datos del buffer circular
 * @param buf Puntero al buffer fuente
 * @param data Destino para los datos leídos (formato Q15)
 * @return None
 */
void bufferRead(circularBuffer_t *buf, q15_t *data);
/** @} */

#endif /* BUFFER_AND_USB_H__ */
