/* USER CODE BEGIN Header */
/* USER CODE BEGIN Header */
/**
  *********************************************************************************************************************************************************************************************************************************************************************
  * @file           : main.c
  * @brief          : DSP - FCEFYN
  *********************************************************************************************************************************************************************************************************************************************************************
  * @attention
  * Trabajo práctico N° 1, 2 y 3 de Procesamiento Digital de Señales de la Facultad de Ciencias Exactas, Fìsicas y Naturales
  *
  * Docentes:		Ing. Parlanti Gustavo
  * 		 		Dr. Molina German
  * 		 		Ing. Mgter. Rossi Roberto
  *
  *
  *	Este proyecto fue creado para completar los 4 trabajos prácticos de la materia. Se utiliza la placa STM32F407-DISCOVERY, a la frecuencia máxima de clock de 168MHz
  *	El mismo fue creado a la par del proyecto "Osciloscopio Virtual", programado en Python, por lo que esta pensado para cumplir las consignas de diseño utilizando este
  *	osciloscopio virtual como principal herramienta de interacción y visualización de datos. Estos se envían mediante el periférico USB_OTG en modo Full Speed. Se configura
  *	el middleware como Virtual Com Port (Comunication Device Class). Para la lógica de envío, se llena un buffer con 64 muestras antes de ser enviadas. Esto para lograr
  *	eficiencia en altas velocidades.
  *
  *	Utilizando ADC1, se muestrea la señal que ingresa al pin PA1 a frecuencias de muestreo variables de 8, 16, 22, 44, 48, 96 y 196 K/S. Para conseguir las frecuencias
  *	de muestreo se utiliza el periférico ADC1 configurado por trigger del timer 2. El mismo se encuentra en el bus Advanced Peripheria Bus 2 (APB2), y en el mismo
  *	la frecuencia maxima de trabajo es 84MHz. Dinámicamente se cambia la frecuencia de disparo del trigger del timer, al cambiar el valor del ARR y recargando el mismo
  *	Fs = 84e6 / ((PSC + 1) * (ARR + 1)) con prescaler en 0, y despejando obtengo ARR = (84000000 / Fs) - 1.
  *
  *	A las señales muestreadas se las almacena en un buffer, definiendose el mismo en la libreria de desarrollo propio adjunta al proyecto "buffer_and_usb.h" y
  *	"buffer_and_usb.h". La estructura de datos utilizada es el  buffer circular, el cual implementa un indice de lectura (tail) y un indice de escritura (head). Para escribir
  *	un dato en el buffer circular se utiliza bufferWrite(), y para leer un dato del mismo se utiliza bufferRead(). Esta estructura de datos es la mas optima en DSP ya que
  *	permite gestionar de forma eficiente la memoria sin necesidad de desplazar datos tras cada adquisición, logrando latencias mínimas y sincronización facilitada entre
  *	adquisición y procesamiento en tiempo real.
  *	Dinaminacamente se puede cambiar el tamaño de estos buffer circulares, pudiendo seleccionar valores de N = 64(no funciona), 128, 256, 512, 1024, 2048 y 4096. Al actualizar
  *	estos valores, cambia el tamaño de los buffer tanto de adquisición como de procesamiento en todas las aplicaciones.
  *
  * Para cambiar cualquier variable dinámicamente, se ha implementado la recepción de arrays mediante la función "CDC_Receive_FS()" de "usbd_cdc_if.c", en donde se guarda el
  * dato recibido a usb command buffer "usbCmdBuffer" mediante memory copy "memcpy()". Se definen las variables necesarias en "usbd_cdc_if.h". En el while loop del main, se implementa la lectura en polling
  * del flag "newCommandFlag" y si  se encuentra un comando se decodifica el mismo.
  *
  *
  *
  * Historial de cambios:
  * v1.0.0		Creción del proyecto
  * v1.1.0		Se implementa lectura de datos con usb otg. Se implementaron cambios en la funcion "CDC_Receive_FS()" de "usbd_cdc_if.c", en donde se guarda el dato recibido a "usbCmdBuffer" mediante
  * 			"memcpy()". Se definen las variables necesarias en "usbd_cdc_if.h". En "while(1)" del main, se implementa la lectura en polling del flag "newCommandFlag" y se decodifica el comando recibido. Se cambia la
  * 			frecuencia de sampling con la formula "ARR = (84000000 / newFS) - 1". El LED AZUL confirma que la placa recibó el comando. Frecuencias disponibles: 8k, 16k, 22k, 44k, 48k, 96k y 196k (tengo problemas para llegar a esa velocidad).
  * v1.2.0		Se comienza a implementar una diferenciación entre el envío de la señal muestreada y la fft de la misma. Para esto se utiliza la palabra reservada "0xFF", la cual indica que a partir del envio de la misma se
  * 			enviará la fft de effective_buffer_size/2 muestras (solo enviamos la magnitud).
  * v1.3.0		Se elimina el dc offset antes de calcular la fft. Esto se hace en "processFFT"
  * v1.4.0		Se implementa el cambio del tamaño del buffer mediante comandos recibidos en "CDC_Receive_FS()".
  *	v1.5.0		Se implementa el cambio de velocidad de envio de la fft con interrupcion por timer 5, con frecuencia de interrupcion dada por los milisegundos enviados a "CDC_Receive_FS()".
  *				Se implementa funcion "checkUSBRecive()" para diferenciar los comandos recibidos.
  *	v1.6.0		Se implementa la posibilidad de detener el computo y envio de la fft mediante comandos recibidos en "CDC_Receive_FS()".
  * v1.6.1		Se emprolija el codigo. Se agrupan algoritmos ùtiles en funciones para ser reutilizados.
  * v1.6.2		Se comentan todas las funciones.
  * v1.7.0		Se cambia la estructura de datos del buffer circular. Me gusta mas como esta ahora, aunque hay que ver como se comporta.
  *
  *
  * A realizar:
  * REALIZADO EN v1.1.0			Implementar lectura de datos con usb otg. Esto para poder cambiar fsampling y tamaño del buffer desde python. La idea es enviar comandos desde la pc, y que el microcontrolador lo lea y decodifique.
  * REALIZADO EN v1.2.0			Enviar a la vez la fft y los datos muestreados. Ver la forma de diferenciarlos.
  * REALIZADO EN v1.3.0		    Quitar el offset de la señal muestreada.
  * REALIZADO EN v1.4.0			Implementar cambio de tamaño de buffer mediante lectura de datos recibidos en usb otg.
  * REALIZADO EN v1.5.0			Implementar el cambio de velocidad de envio de la fft.
  * TODO Cambiar el tratamiento de datos de float32 a q15 en la fft.
  * TODO Buscar maneras de aumentar la velocidad de transmision. (Implementar DMA)
  * TODO Implementar filtros fir.
  * TODO Quitar todos los perifericos del main.c para facilitar lectura del codigo.
  *
  *
  *
  * Font Julian - julian.font@mi.unc.edu.ar - 2025
  *********************************************************************************************************************************************************************************************************************************************************************
  */

#define __author__ = "Font Julián"
#define __version__ = "5.x.x"
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"
#include "arm_math.h"
#include "buffer_and_usb.h"
#include "filters.h"
#include "ecg.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t timer6_value = 0;
volatile uint32_t newFS = RESET_SAMPLING_FREQUENCY; //Reset = 8000Hz
volatile uint32_t tim2_ARR = (84000000/RESET_SAMPLING_FREQUENCY) - 1; //Reset = 10499

volatile uint8_t FIR_flag = 0; //Flag de aplicacion de filtro fir
volatile uint8_t ECG_flag = 0; //Flag de modo ecg
volatile uint8_t FFT_flag = 0; //Flag de calculo y envio de fft
volatile uint8_t SEND_flag = 1; //Flag de envio de señal muestreada
uint8_t fft_send_flag = 0;
uint8_t fft_word = 0xFF;

q15_t aux = 0;

uint16_t adcIndex = 0;
circularBuffer_t adcBuffer = {{0}, 0, 0, 512};
circularBuffer_t filteredBuffer = {{0}, 0, 0, 512};
extern circularBuffer_t ecgBuffer;
q15_t filterInput[MAX_CIRCULAR_BUFFER_SIZE];
q15_t filterOutput[MAX_CIRCULAR_BUFFER_SIZE];

arm_fir_instance_q15 fir_instance_ECG;
arm_fir_instance_q15 fir_instance[NUMBER_OF_SAMPLING_FREQUENCYS][NUMBER_OF_FILTERS];
uint8_t filtro = lp; //filtro lowpass iniciado en el reset
uint8_t fs = fs_8k; //fsampling 8kHz en el reset

arm_rfft_instance_q15 fftInstance;
circularBuffer_t fftBuffer = {{0}, 0, 0, 512};
volatile uint16_t effective_buffer_size = 512;

extern uint8_t ecg_uint8_t[ecg_size];
uint16_t ecg_index = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void checkUSBRecive(void);
void computeFFT(circularBuffer_t *in, circularBuffer_t *out, uint16_t buffer_size);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USB_DEVICE_Init();
  MX_TIM2_Init();
  MX_TIM6_Init();
  MX_TIM5_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start(&htim2);
  HAL_TIM_Base_Start(&htim6);

  initFiltros();
  initECG();
  arm_rfft_init_q15(&fftInstance, effective_buffer_size, 0, 1);
  HAL_GPIO_WritePin(GPIOD, LED_VERDE, 1);

  HAL_TIM_Base_Start_IT(&htim5);
  HAL_ADC_Start_IT(&hadc1);
  HAL_NVIC_SetPriority(TIM5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM5_IRQn);
  /********************************MEDIR TIEMPO DE EJECUCION DE INSTRUCCIONES*******************************************
    if (!(DWT->CTRL & DWT_CTRL_CYCCNTENA_Msk))
    {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;  // Habilita el trazador
        DWT->CYCCNT = 0;                                   // Reinicia el contador
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;               // Habilita el contador de ciclos
    }

    uint32_t start_cycles = DWT->CYCCNT;
    uint32_t end_cycles = DWT->CYCCNT;
    uint32_t ciclos_totales = end_cycles - start_cycles;
    float tiempo_us = (ciclos_totales / 168000000.0f) * 1e6f;
  *********************************************************************************************************************/
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  checkUSBRecive();

	if(ECG_flag == 1){
		if(ecg_index == ecg_size - 1){ecg_index = 1;}
		HAL_Delay(0.5);

		ecg_index++;


	CDC_Transmit_FS(&ecg_uint8_t[ecg_index], 1);

	}
else{
	  if(FFT_flag == 1 && FIR_flag == 1){
		  if(SEND_flag == 1) sendBuffer2usb(&filteredBuffer);
		  if(fft_send_flag == 1) computeFFT(&filteredBuffer, &fftBuffer, effective_buffer_size);
	  }
	  else if(FFT_flag == 1 && FIR_flag == 0){
		  if(SEND_flag == 1)sendBuffer2usb(&adcBuffer);
		  if(fft_send_flag == 1) computeFFT(&adcBuffer, &fftBuffer, effective_buffer_size);
	  }
	  else if(FFT_flag == 0 && FIR_flag == 1){
		  if(SEND_flag == 1) sendBuffer2usb(&filteredBuffer);
	  }
	  else if(FFT_flag == 0 && FIR_flag == 0){
		  if(SEND_flag == 1) sendBuffer2usb(&adcBuffer);
	  }
	}

  }
  /* USER CODE END 3 */
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	uint16_t adcValue = HAL_ADC_GetValue(hadc);

	// Escalar el valor ADC de 0–4095 a Q15 (–32768 a 32767)
	q15_t adcValueFix = (adcValue << 4) - 32768; // Escala 12 bits -> Q15

	bufferWrite(&adcBuffer, &adcValueFix); //Cargo el valor muestreado en el buffer circular adcBuffer



	if(FIR_flag == 1){

			bufferRead(&adcBuffer, &filterInput[adcIndex]); //Leo el valor muestreado desde adcBuffer y lo coloco en el auxiliar dataIn

			if(ECG_flag == 1){
			arm_fir_q15(&fir_instance_ECG, &filterInput[0] + adcIndex, &filterOutput[0] + adcIndex, BLOCK_SIZE);
			}

			//htim6.Instance->CNT=0;
			arm_fir_q15(&fir_instance[fs][filtro], &filterInput[0] + adcIndex, &filterOutput[0] + adcIndex, BLOCK_SIZE);
			//timer6_value = __HAL_TIM_GET_COUNTER(&htim6);

			bufferWrite(&filteredBuffer, &filterOutput[adcIndex]); //Cargo el auxiliar dataOut en el buffer circular filteredBuffer

		}

	if(adcIndex == effective_buffer_size){
		adcIndex = 0;
	}

	adcIndex++;

}

void checkUSBRecive(void)
{
    if (newCommandFlag)
    {
		HAL_TIM_Base_Stop(&htim2);
		HAL_ADC_Stop_IT(&hadc1);

		newCommandFlag = 0;

		HAL_GPIO_WritePin(GPIOD, LED_AZUL, 1);
		HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, LED_AZUL, 0);

        		/*	Cambiar Fsampling	*/
        if (strncmp((char*)usbCmdBuffer, "FS:", 3) == 0) {
            newFS = atoi((char*)(usbCmdBuffer + 3));
            tim2_ARR = (84000000 / newFS) - 1;
            if (newFS == 1000){fs = fs_1k;}
            else if(newFS == 8000){fs = fs_8k;}
            else if(newFS == 16000){fs = fs_16k;}
            else if(newFS == 22000){fs = fs_22k;}
            else if(newFS == 44000){fs = fs_44k;}
            else if(newFS == 48000){fs = fs_48k;}
            else if(newFS == 96000){fs = fs_96k;}
            adcIndex = 0;
            __HAL_TIM_SET_AUTORELOAD(&htim2, tim2_ARR);
        }

        if(strncmp((char*)usbCmdBuffer, "BS:", 3) == 0){
      	  effective_buffer_size = atoi((char*)(usbCmdBuffer + 3));
      	  adcBuffer.effective_size = effective_buffer_size;
		  filteredBuffer.effective_size = effective_buffer_size;
		  fftBuffer.effective_size = effective_buffer_size;
		  adcBuffer.head = adcBuffer.tail = 0;
		  filteredBuffer.head = filteredBuffer.tail = 0;
		  fftBuffer.head = fftBuffer.tail = 0;
		   // Re-inicializar la FFT con el nuevo tamaño
		  arm_rfft_init_q15(&fftInstance, effective_buffer_size, 0, 1);
          	  }

        		/*	Cambiar filtro fir	*/
		if (strncmp((char*)usbCmdBuffer, "f_fir:", 6) == 0) {
			uint8_t rx = atoi((char*)(usbCmdBuffer + 6));
			adcIndex = 0;
			if (rx == lp){filtro = lp;}
			else if(rx == hp){filtro = hp;}
			else if(rx == n){filtro = n;}
			else if(rx == bp){filtro = bp;}

		}

		/*	Activar/desactivar adquisición en modo ECG	*/
		if (strncmp((char*)usbCmdBuffer, "ECG:", 4) == 0) {
			ECG_flag = atoi((char*)(usbCmdBuffer + 4));
			if(ECG_flag == 1){
				HAL_GPIO_WritePin(GPIOD, LED_ROJO, 1);
				tim2_ARR = 1000;
				fs = fs_1k;
				__HAL_TIM_SET_AUTORELOAD(&htim2, tim2_ARR);
			}
			else if(ECG_flag == 0){HAL_GPIO_WritePin(GPIOD, LED_ROJO, 0);}
		}

			/*	Activar/desactivar filtrado FIR	*/
		if (strncmp((char*)usbCmdBuffer, "FIR:", 4) == 0) {
			FIR_flag = atoi((char*)(usbCmdBuffer + 4));
			if(FIR_flag == 1){HAL_GPIO_WritePin(GPIOD, LED_ROJO, 1);}
			else{HAL_GPIO_WritePin(GPIOD, LED_ROJO, 0);}
		}

			/*	Activar/desactivar calculo de FFT	*/
		if (strncmp((char*)usbCmdBuffer, "FFT:", 4) == 0) {
			FFT_flag = atoi((char*)(usbCmdBuffer + 4));
			if(FFT_flag == 1){HAL_GPIO_WritePin(GPIOD, LED_NARANJA, 1);}
			else{HAL_GPIO_WritePin(GPIOD, LED_NARANJA, 0);}
		}

			/*	Activar/desactivar envio de señal muestreda	*/
		if (strncmp((char*)usbCmdBuffer, "SEND:", 5) == 0) {
			SEND_flag = atoi((char*)(usbCmdBuffer + 5));
			if(SEND_flag == 1){HAL_GPIO_WritePin(GPIOD, LED_VERDE, 1);}
			else{HAL_GPIO_WritePin(GPIOD, LED_VERDE, 0);}
		}

		if (strncmp((char*)usbCmdBuffer, "ECG:", 4) == 0) {
			ECG_flag = atoi((char*)(usbCmdBuffer + 4));
		}

    }

		HAL_TIM_Base_Start(&htim2);
		HAL_ADC_Start_IT(&hadc1);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)

{
    if (GPIO_Pin == GPIO_PIN_0)
    {

    }
}

void computeFFT(circularBuffer_t *in, circularBuffer_t *out, uint16_t buffer_size) {
    // Se definen arreglos locales para almacenar los datos intermedios
    q15_t fftInputAux[buffer_size];
    q15_t fftOutputAux[buffer_size*2];
    q15_t fftMagnitudeAux[buffer_size];

    uint16_t currentTail = in->tail;
    for (int i = 0; i < buffer_size; i++) {
        fftInputAux[i] = in->buf[(currentTail + i) % in->effective_size];
    }

    q15_t dc = 0;
    arm_mean_q15(fftInputAux, buffer_size, &dc);

    // Resta el DC a cada muestra
    for (int i = 0; i < buffer_size; i++) {
        fftInputAux[i] = fftInputAux[i] - dc;
    }

    // Ejecuta la FFT sobre el bloque de datos sin DC
    arm_rfft_q15(&fftInstance, fftInputAux, fftOutputAux);
    // Calcula la magnitud del espectro FFT
    arm_abs_q15(fftOutputAux, fftMagnitudeAux, buffer_size);

    q15_t maxVal = 0;
    arm_max_q15(fftMagnitudeAux, buffer_size, &maxVal, 0);
    if (maxVal == 0) maxVal = 1; // Evitar división por cero

    for (int i = 0; i < buffer_size; i++) {
    	fftMagnitudeAux[i] = (q15_t)((((int32_t)fftMagnitudeAux[i] * 0xFFFF ) / maxVal) - 0x8000);
    }


    CDC_Transmit_FS(&fft_word, 1);
    for(int i = 0; i < buffer_size; i++){
        bufferWrite(out, &fftMagnitudeAux[i]);
        sendBuffer2usb(out);
    }




    fft_send_flag = 0;


}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM5)
    {
        fft_send_flag = 1;
    }

}

















/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
