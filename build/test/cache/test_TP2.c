#include "build/test/mocks/mock_errores.h"
#include "src/TP2.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


extern canal_acustico_t canal;



uint16_t mediciones[] = {1, 1, 1, 1, 1, 1};

void setUp(void){

    inicializar_variables_canal_acustico();

}













void test_inicializar_variables_canal_acustico(void){

    canal.ganancia = G1;

    inicializar_variables_canal_acustico();



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((GMIN)), (UNITY_INT)(UNITY_INT16)((canal.ganancia)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_HEX16);

}











void test_subir_modificar_ganancia(void){



    modificar_ganancia(GSUBIR);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((G1)), (UNITY_INT)(UNITY_INT16)((canal.ganancia)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_HEX16);

}











void test_bajar_modificar_ganancia(void){

    modificar_ganancia(GSUBIR);

    modificar_ganancia(GSUBIR);

    modificar_ganancia(GBAJAR);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((G1)), (UNITY_INT)(UNITY_INT16)((canal.ganancia)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_HEX16);

}













void test_establecer_ganancia(void){



    establecer_ganancia(G3);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((G3)), (UNITY_INT)(UNITY_INT16)((canal.ganancia)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_HEX16);

}













void test_ganancia_invalida_establecer_ganancia(void){

    RegistrarMensaje_CMockExpect(74, ALERTA, "establecer_ganancia", 0, "Valor de ganancia desconocida !!!");

    RegistrarMensaje_CMockIgnoreArg_linea(75);

    establecer_ganancia(GMAX + 1);

}













void test_seleccionar_canal_demux(void){



    establecer_ganancia(GMAX);



    seleccionar_canal_demux();



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x07)), (UNITY_INT)(UNITY_INT16)((canal.gmux)), (

   ((void *)0)

   ), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_HEX16);

}













void test_canal_acustico_libre_media_calcular(void){



    canal_acustico_libre_media_calcular(mediciones );



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((canal.valor_canal_acustico_libre_media)), (

   ((void *)0)

   ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_HEX16);

}











void test_canal_acustico_libre_desvio_calcular(void){



    uint16_t mediciones_variadas[] = {1, 3, 1, 3, 1, 3};



    canal_acustico_libre_media_calcular(mediciones_variadas);



    canal_acustico_libre_desvio_calcular(mediciones_variadas);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((canal.valor_canal_acustico_libre_desvio)), (

   ((void *)0)

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_HEX16);

}













void test_canal_acustico_libre_medir(void){



    uint16_t mediciones_variadas[] = {2008, 2148, 1948, 2148, 1948, 2088};



    uint8_t res = canal_acustico_libre_medir( mediciones_variadas );



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((res)), (

   ((void *)0)

   ), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_HEX16);

}
