# Proyecto DSP - FCEFyN

## Tabla de Contenidos
1. [Descripción del Proyecto](#descripción-del-proyecto)
2. [Plataforma y Requisitos](#plataforma-y-requisitos)
3. [Configuración del Entorno](#configuración-del-entorno)
4. [Estructura del Proyecto](#estructura-del-proyecto)
5. [Funcionalidades Clave](#funcionalidades-clave)
6. [Protocolo de Comandos USB](#protocolo-de-comandos-usb)
7. [Diagrama de Flujo](#diagrama-de-flujo)
8. [Historial de Versiones](#historial-de-versiones)
9. [Trabajo Futuro](#trabajo-futuro)
10. [Referencias](#referencias)

---

## Descripción del Proyecto
Sistema embebido para procesamiento digital de señales en tiempo real implementado en STM32F407-DISCOVERY. Incluye:
- Muestreo adaptable (8k-196k Hz)
- Filtrado FIR configurable
- Cálculo de FFT
- Interfaz USB con osciloscopio virtual en Python

**Objetivos Académicos:**
- Implementar técnicas de DSP en hardware embebido
- Optimizar recursos computacionales
- Diseñar protocolos de comunicación personalizados

---

## Plataforma y Requisitos
### Hardware
- Placa: STM32F407-DISCOVERY
- Microcontrolador: STM32F407VGT6 @ 168 MHz
- Periféricos utilizados:
  - ADC1 (PA1)
  - TIM2 (Trigger ADC)
  - USB_OTG_FS (CDC)
  - GPIOs para LEDs de estado

### Software
- Entorno: STM32CubeIDE 1.11+
- Librerías:
  - CMSIS-DSP v1.14+
  - STM32F4 HAL v1.27+
- Osciloscopio Virtual (Python 3.10+)

---
