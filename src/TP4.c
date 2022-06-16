#include <stdint.h>
/******************************************************************************
 * TP4 - CESE 16Co - Testing de Software en Sistemas Embebidos.
 * Autor: Jorge Gabriel Schmidt.
 * 
 * El modulo TP4.c - TP4.h contine funciones que son utilizadas en el desarrollo
 * del trabajo final de la especializacion de sistemas embebidos. Las mismas se 
 * utilizan para determinar el nivel de ruido presente en el canal acustico por 
 * el cual se recibira una señal. Tambien contiene funciones que son utilizadas
 * para controlar la ganancia del canal acustico.
 *****************************************************************************/
 
/******************************************************************************
 * Includes
 *****************************************************************************/
#include "TP4.h"
#include "math.h"
#include "errores.h"
/******************************************************************************
 * Definiciones
 *****************************************************************************/

#define PIN_1_MUX 0x01
#define PIN_2_MUX 0x02
#define PIN_3_MUX 0x04
#define PORCENTAJE_DE_MEDIA 0.1

/******************************************************************************
 * Variables privadas
 *****************************************************************************/

canal_acustico_t canal;

/******************************************************************************
 * Prototipo de funciones
 *****************************************************************************/

void inicializar_variables_canal_acustico(void);
void modificar_ganancia(tipo_accion_ganancia accion_ganancia);
void establecer_ganancia(tipo_valores_ganancia ganancia);
void seleccionar_canal_demux(void);
void canal_acustico_libre_media_calcular( uint16_t * mediciones );
void comenzar_ADC1(void);
void finalizar_ADC1(void);
uint16_t valor_ADC(void);
void delay_bloqueante_us(uint8_t tiempo);
uint8_t canal_acustico_libre_medir( uint16_t * mediciones );

/******************************************************************************
 * Codigo de funciones
 ******************************************************************************/

/**
 * @brief Inicializa la estructura de variables del canal acustico
 * 
 */
void inicializar_variables_canal_acustico(void){
    canal.ganancia = GMIN;
    canal.valor_canal_acustico_libre_media = 0;
    canal.valor_canal_acustico_libre_desvio = 0;
    canal.cantidad_muestras_ruido = 6;
	canal.ruido_veces_desvio_de_margen = 2;
    canal.gmux = 0x00;
}

/**
 * @brief Modifica la ganancia del canal de recepcion. La puede subir, bajar o
 * 		  mantener.
 * 
 * @param accion_ganancia : Accion a efectuar sobre la ganancia: SUBIR, BAJAR
 * 							o MANTENER. 
 */
void modificar_ganancia(tipo_accion_ganancia accion_ganancia){
	
	switch(accion_ganancia){
		
        case GMANTENER:
		            canal.ganancia = canal.ganancia;
        break;
		
        case GSUBIR:
					if(GMAX == canal.ganancia){
                        // Esta al limite superior
                    }
                    else{
						canal.ganancia++;
					}
		break;
		
        case GBAJAR:
					if(GMIN == canal.ganancia){
                        // Esta al limite inferior
                    }
					else{
						canal.ganancia--;
					}
		break;

		default:
					Alerta("Accion sobre ganancia desconocida !!!");
		break;

	}
}

/**
 * @brief Fija un valor a la ganancia del canal de recepcion.
 * 		  Su valor puede ser: GMIN, G1, G2, G3, G4, G5, G6, GMAX.
 * 
 * @param ganancia Valor de ganancia a establecer en el canal.
 */
void establecer_ganancia(tipo_valores_ganancia ganancia){
	if(GMIN <= ganancia && GMAX >= ganancia){
		canal.ganancia = ganancia;
	}else{
		Alerta("Valor de ganancia desconocida !!!");
	}
}

/**
 * @brief Selecciona un canal de amplificacion segun la ganancia establecida.
 * 		  Las macros: PIN_1_MUX, PIN_2_MUX y PIN_3_MUX se refieren a los pines
 * 		  del multiplexor analogico presente en el canal de recepcion.
 * 
 */
void seleccionar_canal_demux(void){

	if(canal.ganancia & PIN_1_MUX){
        canal.gmux |= PIN_1_MUX;
    }
	else{
        canal.gmux &= ~PIN_1_MUX;
    }

	if(canal.ganancia & PIN_2_MUX){
        canal.gmux |= PIN_2_MUX;
    }
	else{
        canal.gmux &= ~PIN_2_MUX;
    }

	if(canal.ganancia & PIN_3_MUX){
        canal.gmux |= PIN_3_MUX;
    }
	else{
        canal.gmux &= ~PIN_3_MUX;
    } 
}

/**
 * @brief Calcula la media aritmetica de las mediciones hechas por un ADC.
 * 
 * @param mediciones : Vector que contiene las mediciones hechas por un ADC.
 */
void canal_acustico_libre_media_calcular( uint16_t * mediciones ){
    for(uint8_t i = 0; i < canal.cantidad_muestras_ruido; i++){
        canal.valor_canal_acustico_libre_media += mediciones[i];
    }
	canal.valor_canal_acustico_libre_media /= canal.cantidad_muestras_ruido;
}

/**
 * @brief Calcula el desvio de las mediciones hechas por un ADC.
 * 
 * @param mediciones : Vector que contiene las mediciones hechas por un ADC.
 */
void canal_acustico_libre_desvio_calcular( uint16_t *mediciones ){
    for(int i = 0; i < canal.cantidad_muestras_ruido; i++){
        canal.valor_canal_acustico_libre_desvio += pow((double)( (float)mediciones[i] - canal.valor_canal_acustico_libre_media), 2.0);
    }
	canal.valor_canal_acustico_libre_desvio = sqrt(canal.valor_canal_acustico_libre_desvio/((float)canal.cantidad_muestras_ruido));
}

/**
 * @brief 
 * 
 * @return uint8_t 
 */
uint8_t canal_acustico_libre_medir( uint16_t * mediciones ){

    // Calculo la media y el desvio del canal
	canal_acustico_libre_media_calcular( mediciones );
	canal_acustico_libre_desvio_calcular( mediciones );

	// Fijo los limites dentro de los que debe estar el nivel de ruido
	canal.tolerancia_max_sobre_media = canal.valor_canal_acustico_libre_media + 
									   canal.valor_canal_acustico_libre_media * 
									   PORCENTAJE_DE_MEDIA;

	canal.tolerancia_min_bajo_media = canal.valor_canal_acustico_libre_media - 
									  canal.valor_canal_acustico_libre_media * 
									  PORCENTAJE_DE_MEDIA;

	// Estimo hasta donde considero que llega el ruido medido segun el desvio
	canal.margen_ruido_sup = canal.valor_canal_acustico_libre_media + 
							 canal.ruido_veces_desvio_de_margen * 
							 canal.valor_canal_acustico_libre_desvio;

	canal.margen_ruido_inf = canal.valor_canal_acustico_libre_media - 
							 canal.ruido_veces_desvio_de_margen * 
							 canal.valor_canal_acustico_libre_desvio;

	// Chequeo que los niveles de ruido medido esten dentro del margen aceptable
	if( canal.margen_ruido_sup <= canal.tolerancia_max_sobre_media && 
		canal.margen_ruido_inf >= canal.tolerancia_min_bajo_media ){
		// Valores de ruido aceptables
		return 1;
	}else{
		// Valores de ruido altos
		canal.valor_canal_acustico_libre_media = -1;
		canal.valor_canal_acustico_libre_desvio = -1;
		canal.margen_ruido_sup = -1;
		canal.margen_ruido_inf = -1;
		return 0; 
	}
}
