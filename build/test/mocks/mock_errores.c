/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_errores.h"

static const char* CMockString_RegistrarMensaje = "RegistrarMensaje";
static const char* CMockString_funcion = "funcion";
static const char* CMockString_gravedad = "gravedad";
static const char* CMockString_linea = "linea";
static const char* CMockString_mensaje = "mensaje";

typedef struct _CMOCK_RegistrarMensaje_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  gravedad_t Expected_gravedad;
  const char* Expected_funcion;
  int Expected_linea;
  const char* Expected_mensaje;
  char IgnoreArg_gravedad;
  char IgnoreArg_funcion;
  char IgnoreArg_linea;
  char IgnoreArg_mensaje;

} CMOCK_RegistrarMensaje_CALL_INSTANCE;

static struct mock_erroresInstance
{
  char RegistrarMensaje_IgnoreBool;
  char RegistrarMensaje_CallbackBool;
  CMOCK_RegistrarMensaje_CALLBACK RegistrarMensaje_CallbackFunctionPointer;
  int RegistrarMensaje_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE RegistrarMensaje_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_errores_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.RegistrarMensaje_CallInstance;
  if (Mock.RegistrarMensaje_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_RegistrarMensaje);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.RegistrarMensaje_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_errores_Init(void)
{
  mock_errores_Destroy();
}

void mock_errores_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void RegistrarMensaje(gravedad_t gravedad, const char* funcion, int linea, const char* mensaje, ...)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_RegistrarMensaje_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_RegistrarMensaje);
  cmock_call_instance = (CMOCK_RegistrarMensaje_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.RegistrarMensaje_CallInstance);
  Mock.RegistrarMensaje_CallInstance = CMock_Guts_MemNext(Mock.RegistrarMensaje_CallInstance);
  if (Mock.RegistrarMensaje_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.RegistrarMensaje_CallbackBool &&
      Mock.RegistrarMensaje_CallbackFunctionPointer != NULL)
  {
    Mock.RegistrarMensaje_CallbackFunctionPointer(gravedad, funcion, linea, mensaje, Mock.RegistrarMensaje_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->IgnoreArg_gravedad)
  {
    UNITY_SET_DETAILS(CMockString_RegistrarMensaje,CMockString_gravedad);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_gravedad), (void*)(&gravedad), sizeof(gravedad_t), cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_funcion)
  {
    UNITY_SET_DETAILS(CMockString_RegistrarMensaje,CMockString_funcion);
    UNITY_TEST_ASSERT_EQUAL_STRING(cmock_call_instance->Expected_funcion, funcion, cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_linea)
  {
    UNITY_SET_DETAILS(CMockString_RegistrarMensaje,CMockString_linea);
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_linea, linea, cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_mensaje)
  {
    UNITY_SET_DETAILS(CMockString_RegistrarMensaje,CMockString_mensaje);
    UNITY_TEST_ASSERT_EQUAL_STRING(cmock_call_instance->Expected_mensaje, mensaje, cmock_line, CMockStringMismatch);
  }
  if (Mock.RegistrarMensaje_CallbackFunctionPointer != NULL)
  {
    Mock.RegistrarMensaje_CallbackFunctionPointer(gravedad, funcion, linea, mensaje, Mock.RegistrarMensaje_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}

void CMockExpectParameters_RegistrarMensaje(CMOCK_RegistrarMensaje_CALL_INSTANCE* cmock_call_instance, gravedad_t gravedad, const char* funcion, int linea, const char* mensaje);
void CMockExpectParameters_RegistrarMensaje(CMOCK_RegistrarMensaje_CALL_INSTANCE* cmock_call_instance, gravedad_t gravedad, const char* funcion, int linea, const char* mensaje)
{
  memcpy((void*)(&cmock_call_instance->Expected_gravedad), (void*)(&gravedad),
         sizeof(gravedad_t[sizeof(gravedad) == sizeof(gravedad_t) ? 1 : -1])); /* add gravedad_t to :treat_as_array if this causes an error */
  cmock_call_instance->IgnoreArg_gravedad = 0;
  cmock_call_instance->Expected_funcion = funcion;
  cmock_call_instance->IgnoreArg_funcion = 0;
  cmock_call_instance->Expected_linea = linea;
  cmock_call_instance->IgnoreArg_linea = 0;
  cmock_call_instance->Expected_mensaje = mensaje;
  cmock_call_instance->IgnoreArg_mensaje = 0;
}

void RegistrarMensaje_CMockIgnore(void)
{
  Mock.RegistrarMensaje_IgnoreBool = (char)1;
}

void RegistrarMensaje_CMockStopIgnore(void)
{
  Mock.RegistrarMensaje_IgnoreBool = (char)0;
}

void RegistrarMensaje_CMockExpect(UNITY_LINE_TYPE cmock_line, gravedad_t gravedad, const char* funcion, int linea, const char* mensaje)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_RegistrarMensaje_CALL_INSTANCE));
  CMOCK_RegistrarMensaje_CALL_INSTANCE* cmock_call_instance = (CMOCK_RegistrarMensaje_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.RegistrarMensaje_CallInstance = CMock_Guts_MemChain(Mock.RegistrarMensaje_CallInstance, cmock_guts_index);
  Mock.RegistrarMensaje_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_RegistrarMensaje(cmock_call_instance, gravedad, funcion, linea, mensaje);
}

void RegistrarMensaje_AddCallback(CMOCK_RegistrarMensaje_CALLBACK Callback)
{
  Mock.RegistrarMensaje_IgnoreBool = (char)0;
  Mock.RegistrarMensaje_CallbackBool = (char)1;
  Mock.RegistrarMensaje_CallbackFunctionPointer = Callback;
}

void RegistrarMensaje_Stub(CMOCK_RegistrarMensaje_CALLBACK Callback)
{
  Mock.RegistrarMensaje_IgnoreBool = (char)0;
  Mock.RegistrarMensaje_CallbackBool = (char)0;
  Mock.RegistrarMensaje_CallbackFunctionPointer = Callback;
}

void RegistrarMensaje_CMockIgnoreArg_gravedad(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_RegistrarMensaje_CALL_INSTANCE* cmock_call_instance = (CMOCK_RegistrarMensaje_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.RegistrarMensaje_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_gravedad = 1;
}

void RegistrarMensaje_CMockIgnoreArg_funcion(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_RegistrarMensaje_CALL_INSTANCE* cmock_call_instance = (CMOCK_RegistrarMensaje_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.RegistrarMensaje_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_funcion = 1;
}

void RegistrarMensaje_CMockIgnoreArg_linea(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_RegistrarMensaje_CALL_INSTANCE* cmock_call_instance = (CMOCK_RegistrarMensaje_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.RegistrarMensaje_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_linea = 1;
}

void RegistrarMensaje_CMockIgnoreArg_mensaje(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_RegistrarMensaje_CALL_INSTANCE* cmock_call_instance = (CMOCK_RegistrarMensaje_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.RegistrarMensaje_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_mensaje = 1;
}

