/**
 * @file filtrostp2.h
 * @brief Configuración de filtros de segundo orden y función de inicialización.
 *
 * @author  Font Julián
 * @version 1.0.0
 *
 * @note	Este archivo define constantes para configuraciones de filtros digitales, incluyendo frecuencias
 * de muestreo, tipos de filtros y órdenes de los mismos. También declara la función de inicialización.
 ******************************************************************************
 *	HISTORIAL DE CAMBIOS:
 *	v1.0.0		Creación del header
 *******************************************************************************
 */

#ifndef FILTROSTP2_H_
#define FILTROSTP2_H_

/**
 * @defgroup ConfigBloque Configuración de procesamiento por bloques para la funcion de CMSIS-DSP
 * @{
 */
#define BLOCK_SIZE 1 /**< @brief Número de muestras procesadas por bloque (tiempo real). */
/** @} */

/**
 * @defgroup FrecuenciasMuestreo Frecuencias de muestreo utilizadas
 * @brief Índices para las frecuencias de muestreo utilizadas
 *  * @{
 */
#define NUMBER_OF_SAMPLING_FREQUENCYS 7 /**< @brief Cantidad total de frecuencias configuradas */
#define fs_96k  6 /**< @brief Índice para frecuencia de 96 kHz */
#define fs_48k  5 /**< @brief Índice para frecuencia de 48 kHz */
#define fs_44k  4 /**< @brief Índice para frecuencia de 44 kHz */
#define fs_22k  3 /**< @brief Índice para frecuencia de 22 kHz */
#define fs_16k  2 /**< @brief Índice para frecuencia de 16 kHz */
#define fs_8k   1 /**< @brief Índice para frecuencia de 8 kHz */
#define fs_1k   0 /**< @brief Índice para frecuencia de 1 kHz */
/** @} */

/**
 * @defgroup TiposFiltro Tipos de filtros utilizados
 * @brief Índices para los diferentes tipos de filtros utilizados
 * @{
 */
#define NUMBER_OF_FILTERS 4 /**< @brief Cantidad total de tipos de filtro */
#define lp 0 /**< @brief Filtro pasa bajos (Low-pass) */
#define hp 1 /**< @brief Filtro pasa altos (High-pass) */
#define bp 2 /**< @brief Filtro pasa banda (Band-pass) */
#define n  3 /**< @brief Filtro notch (rechazo de banda) */
/** @} */

/**
 * @defgroup OrdenFiltros Órdenes de filtros
 * @brief Define el orden de cada filtro según frecuencia y tipo crados en MATLAB
 * @{
 */
// Configuraciones para Fs = 96 kHz
#define lowpass_96k_orden   100  /**< Orden filtro pasa bajos 96kHz */
#define bandpass_96k_orden  100  /**< Orden filtro pasa banda 96kHz */
#define highpass_96k_orden 100   /**< Orden filtro pasa altos 96kHz */
#define notch_96k_orden    102   /**< Orden filtro notch 96kHz */

// Configuraciones para Fs = 48 kHz
#define lowpass_48k_orden   150  /**< Orden filtro pasa bajos 48kHz */
#define bandpass_48k_orden  150  /**< Orden filtro pasa banda 48kHz */
#define highpass_48k_orden 151   /**< Orden filtro pasa altos 48kHz */
#define notch_48k_orden    152   /**< Orden filtro notch 48kHz */

// Configuraciones para Fs = 44 kHz
#define lowpass_44k_orden   200  /**< Orden filtro pasa bajos 44kHz */
#define bandpass_44k_orden  200  /**< Orden filtro pasa banda 44kHz */
#define highpass_44k_orden 201   /**< Orden filtro pasa altos 44kHz */
#define notch_44k_orden    202   /**< Orden filtro notch 44kHz */

// Configuraciones para Fs = 22 kHz
#define lowpass_22k_orden   320  /**< Orden filtro pasa bajos 22kHz */
#define bandpass_22k_orden  320  /**< Orden filtro pasa banda 22kHz */
#define highpass_22k_orden 321   /**< Orden filtro pasa altos 22kHz */
#define notch_22k_orden    322   /**< Orden filtro notch 22kHz */

// Configuraciones para Fs = 16 kHz
#define lowpass_16k_orden   400  /**< Orden filtro pasa bajos 16kHz */
#define bandpass_16k_orden  400  /**< Orden filtro pasa banda 16kHz */
#define highpass_16k_orden 400   /**< Orden filtro pasa altos 16kHz */
#define notch_16k_orden    402   /**< Orden filtro notch 16kHz */

// Configuraciones para Fs = 8 kHz
#define lowpass_8k_orden   800  /**< Orden filtro pasa bajos 8kHz */
#define bandpass_8k_orden  800  /**< Orden filtro pasa banda 8kHz */
#define highpass_8k_orden 800   /**< Orden filtro pasa altos 8kHz */
#define notch_8k_orden    802   /**< Orden filtro notch 8kHz */

// Configuraciones para Fs = 1 kHz
#define lowpass_1k_orden   1500 /**< Orden filtro pasa bajos 1kHz */
#define bandpass_1k_orden  800  /**< Orden filtro pasa banda 1kHz */
#define highpass_1k_orden 1500  /**< Orden filtro pasa altos 1kHz */
#define notch_1k_orden    1502  /**< Orden filtro notch 1kHz */
/** @} */

/**
 * @brief Función de inicialización de filtros
 * @details Configura los filtros según las definiciones de orden y tipo especificadas
 */
void initFiltros(void);

#endif /* FILTROSTP2_H_ */
