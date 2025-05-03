# Proyecto de Procesamiento Digital de Señales (DSP) - FCEFyN

**Autor**: Julián Font  
**Contacto**: julian.font@mi.unc.edu.ar  
**Año**: 2025  
**Plataforma**: STM32F407-DISCOVERY @ 168MHz  
**Docentes**:  
- Ing. Gustavo Parlanti  
- Dr. Germán Molina  
- Ing. Mgter. Roberto Rossi  

## Descripción General
Proyecto académico desarrollado para los Trabajos Prácticos de la materia Procesamiento Digital de Señales. Implementa un sistema completo de adquisición, procesamiento y transmisión de señales analógicas con las siguientes funcionalidades:

- Muestreo con frecuencias configurables (8k-196k Hz)
- Filtrado FIR en tiempo real
- Cálculo y envío de FFT
- Interfaz USB para control remoto
- Visualización mediante osciloscopio virtual en Python

## Estructura del Proyecto
| Versión | Funcionalidades Principales |
|---------|-----------------------------|
| v1.x.x  | Muestreo y transmisión USB |
| v2.x.x  | Implementación de filtros FIR |
| v3.x.x  | Cálculo de FFT |
| v4.x.x  | Filtro adaptativo para cancelación de ruido |

## Hardware Utilizado
- **Microcontrolador**: STM32F407VGT6 @ 168MHz
- **Periféricos principales**:
  - ADC1 con trigger por TIM2
  - USB OTG en modo Full Speed (CDC)
  - GPIO para LEDs de estado

graph TD
    A[Inicio] --> B[Configurar periféricos]
    B --> C[Esperar comandos USB]
    C --> D{Muestrear ADC}
    D -->|Interrupción| E[Escribir en buffer]
    E --> F[Procesar FIR]
    F --> G[Calcular FFT]
    G --> H[Enviar por USB]
    H --> C