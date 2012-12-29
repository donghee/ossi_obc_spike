/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_i2c.h"

typedef struct _CMOCK_InitI2C_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;
  uint8_t Expected_address;

} CMOCK_InitI2C_CALL_INSTANCE;

typedef struct _CMOCK_I2CWriteInit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int CallOrder;

} CMOCK_I2CWriteInit_CALL_INSTANCE;

static struct mock_i2cInstance
{
  int InitI2C_IgnoreBool;
  CMOCK_InitI2C_CALLBACK InitI2C_CallbackFunctionPointer;
  int InitI2C_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE InitI2C_CallInstance;
  int I2CWriteInit_IgnoreBool;
  CMOCK_I2CWriteInit_CALLBACK I2CWriteInit_CallbackFunctionPointer;
  int I2CWriteInit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE I2CWriteInit_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_i2c_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.InitI2C_IgnoreBool)
    Mock.InitI2C_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.InitI2C_CallInstance, cmock_line, "Function 'InitI2C' called less times than expected.");
  if (Mock.InitI2C_CallbackFunctionPointer != NULL)
    Mock.InitI2C_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.I2CWriteInit_IgnoreBool)
    Mock.I2CWriteInit_CallInstance = CMOCK_GUTS_NONE;
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.I2CWriteInit_CallInstance, cmock_line, "Function 'I2CWriteInit' called less times than expected.");
  if (Mock.I2CWriteInit_CallbackFunctionPointer != NULL)
    Mock.I2CWriteInit_CallInstance = CMOCK_GUTS_NONE;
}

void mock_i2c_Init(void)
{
  mock_i2c_Destroy();
}

void mock_i2c_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.InitI2C_CallbackFunctionPointer = NULL;
  Mock.InitI2C_CallbackCalls = 0;
  Mock.I2CWriteInit_CallbackFunctionPointer = NULL;
  Mock.I2CWriteInit_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

void InitI2C(uint8_t address)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_InitI2C_CALL_INSTANCE* cmock_call_instance = (CMOCK_InitI2C_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.InitI2C_CallInstance);
  Mock.InitI2C_CallInstance = CMock_Guts_MemNext(Mock.InitI2C_CallInstance);
  if (Mock.InitI2C_IgnoreBool)
  {
    return;
  }
  if (Mock.InitI2C_CallbackFunctionPointer != NULL)
  {
    Mock.InitI2C_CallbackFunctionPointer(address, Mock.InitI2C_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'InitI2C' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'InitI2C' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'InitI2C' called later than expected.");
  UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_address, address, cmock_line, "Function 'InitI2C' called with unexpected value for argument 'address'.");
}

void CMockExpectParameters_InitI2C(CMOCK_InitI2C_CALL_INSTANCE* cmock_call_instance, uint8_t address)
{
  cmock_call_instance->Expected_address = address;
}

void InitI2C_CMockIgnore(void)
{
  Mock.InitI2C_IgnoreBool = (int)1;
}

void InitI2C_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t address)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_InitI2C_CALL_INSTANCE));
  CMOCK_InitI2C_CALL_INSTANCE* cmock_call_instance = (CMOCK_InitI2C_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.InitI2C_CallInstance = CMock_Guts_MemChain(Mock.InitI2C_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_InitI2C(cmock_call_instance, address);
}

void InitI2C_StubWithCallback(CMOCK_InitI2C_CALLBACK Callback)
{
  Mock.InitI2C_CallbackFunctionPointer = Callback;
}

void I2CWriteInit(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_I2CWriteInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2CWriteInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.I2CWriteInit_CallInstance);
  Mock.I2CWriteInit_CallInstance = CMock_Guts_MemNext(Mock.I2CWriteInit_CallInstance);
  if (Mock.I2CWriteInit_IgnoreBool)
  {
    return;
  }
  if (Mock.I2CWriteInit_CallbackFunctionPointer != NULL)
  {
    Mock.I2CWriteInit_CallbackFunctionPointer(Mock.I2CWriteInit_CallbackCalls++);
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "Function 'I2CWriteInit' called more times than expected.");
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'I2CWriteInit' called earlier than expected.");
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, "Function 'I2CWriteInit' called later than expected.");
}

void I2CWriteInit_CMockIgnore(void)
{
  Mock.I2CWriteInit_IgnoreBool = (int)1;
}

void I2CWriteInit_CMockExpect(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_I2CWriteInit_CALL_INSTANCE));
  CMOCK_I2CWriteInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_I2CWriteInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, "CMock has run out of memory. Please allocate more.");
  Mock.I2CWriteInit_CallInstance = CMock_Guts_MemChain(Mock.I2CWriteInit_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
}

void I2CWriteInit_StubWithCallback(CMOCK_I2CWriteInit_CALLBACK Callback)
{
  Mock.I2CWriteInit_CallbackFunctionPointer = Callback;
}

