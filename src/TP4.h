#ifndef _TP4_H
#define _TP4_H

#include <stdint.h>

/******************************************************************************
 * Tipos enumerativos
 *****************************************************************************/

typedef enum {GMIN, G1, G2, G3, G4, G5, G6, GMAX}tipo_valores_ganancia;

typedef enum {GSUBIR, GBAJAR, GMANTENER}tipo_accion_ganancia;

typedef struct
{
	tipo_valores_ganancia ganancia;
    
    uint16_t valor_canal_acustico_libre_media;
    
    uint8_t cantidad_muestras_ruido,
            gmux,
            tiempo_entre_muestras_ruido,
            ruido_veces_desvio_de_margen;

    float valor_canal_acustico_libre_desvio,
          tolerancia_max_sobre_media,
          tolerancia_min_bajo_media,
          margen_ruido_sup,
          margen_ruido_inf;

}canal_acustico_t;


/******************************************************************************
 * Prototipo de funciones
 *****************************************************************************/

void inicializar_variables_canal_acustico(void);

void modificar_ganancia(tipo_accion_ganancia accion_ganancia);

void establecer_ganancia(tipo_valores_ganancia ganancia);

void seleccionar_canal_demux(void);

void canal_acustico_libre_media_calcular( uint16_t * mediciones );

void canal_acustico_libre_desvio_calcular( uint16_t *mediciones );

uint8_t canal_acustico_libre_medir( uint16_t * mediciones );

#endif