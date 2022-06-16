#include "unity.h"
#include "TP4.h"
#include "mock_errores.h"

extern canal_acustico_t canal;

uint16_t mediciones[] = {1, 1, 1, 1, 1, 1}; // resultado media = 1

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

/**
 * @brief Set the Up object
 * 
 */
void setUp(void){
    inicializar_variables_canal_acustico();
}

/**
 * @brief Test para probar la inicializacion de las variables del canal
 *        acustico.
 * 
 */
void test_inicializar_variables_canal_acustico(void){
    canal.ganancia = G1;
    inicializar_variables_canal_acustico();
    // Chequeo el valor de la ganancia del canal
    TEST_ASSERT_EQUAL_HEX16(GMIN, canal.ganancia);
}

/**
 * @brief Test para probar subir la ganancia del canal acustico.
 * 
 */
void test_subir_modificar_ganancia(void){
    // Modifico la ganancia segun el comando GSUBIR
    modificar_ganancia(GSUBIR);
    // Chequeo el valor de la ganancia del canal
    TEST_ASSERT_EQUAL_HEX16(G1, canal.ganancia);
}

/**
 * @brief Test para probar bajar la ganancia del canal acustico.
 * 
 */
void test_bajar_modificar_ganancia(void){
    modificar_ganancia(GSUBIR); //G1
    modificar_ganancia(GSUBIR); //G2
    modificar_ganancia(GBAJAR); //G1
    // Chequeo el valor de la ganancia del canal
    TEST_ASSERT_EQUAL_HEX16(G1, canal.ganancia);
}

/**
 * @brief Test para probar establecer un valor para la ganancia del canal
 *        acustico.
 * 
 */
void test_establecer_ganancia(void){
    // Fijo un valor de ganancia
    establecer_ganancia(G3);
    // Chequeo el valor de la ganancia del canal
    TEST_ASSERT_EQUAL_HEX16(G3, canal.ganancia);
}

/**
 * @brief Test para verificar que si le paso un valor desconocido de ganancia
 *        avisa con un error.
 * 
 */
void test_ganancia_invalida_establecer_ganancia(void){
    RegistrarMensaje_Expect(ALERTA, "establecer_ganancia", 0, "Valor de ganancia desconocida !!!");
    RegistrarMensaje_IgnoreArg_linea();
    establecer_ganancia(GMAX + 1);
}

/**
 * @brief Test para probar la seleccion de canal del multiplexor analogico
 *        segun la ganancia seleccionada.
 * 
 */
void test_seleccionar_canal_demux(void){
    // Fijo un valor de ganancia
    establecer_ganancia(GMAX);
    // Selecciono el canal del multiplexor analogico segun la ganancia
    seleccionar_canal_demux();
    // Chequeo el estado de los pines del multiplexor analogico
    TEST_ASSERT_EQUAL_HEX16(0x07, canal.gmux);
}

/**
 * @brief Test para probar el calculo de la media aritmetica sobre varias
 *        muestras del ADC.
 * 
 */
void test_canal_acustico_libre_media_calcular(void){
    // Calculo la media de las medciciones
    canal_acustico_libre_media_calcular(mediciones );
    // Chequeo el valor de la media
    TEST_ASSERT_EQUAL_HEX16(1, canal.valor_canal_acustico_libre_media);
}

/**
 * @brief Test para probar el calculo del desvio sobre varias muestras del ADC.
 * 
 */
void test_canal_acustico_libre_desvio_calcular(void){
    // Armo un vector con valores tales que el desvio de 1
    uint16_t mediciones_variadas[] = {1, 3, 1, 3, 1, 3};
    // Calculo la media de las medciciones
    canal_acustico_libre_media_calcular(mediciones_variadas);
    // Calculo el desvio de las medciciones
    canal_acustico_libre_desvio_calcular(mediciones_variadas);
    // Chequeo el valor del desvio en las medicines del canal acustico
    TEST_ASSERT_EQUAL_HEX16(1, canal.valor_canal_acustico_libre_desvio);
}

/**
 * @brief Test para probar si el canal acustico esta libre de interferencias o
 *        niveles altos de ruido.
 * 
 */
void test_canal_acustico_libre_medir(void){
    // Armo un vector con valores simulando una medicion
    uint16_t mediciones_variadas[] = {2008, 2148, 1948, 2148, 1948, 2088};
    // 
    uint8_t res = canal_acustico_libre_medir( mediciones_variadas );

    TEST_ASSERT_EQUAL_HEX16(1, res);
}