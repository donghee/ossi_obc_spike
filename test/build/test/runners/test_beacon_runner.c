/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      CMock_Init(); \
      setUp(); \
      TestFunc(); \
      CMock_Verify(); \
  } \
  CMock_Destroy(); \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "mock_i2c.h"
#include "mock_in430.h"
#include "mock_msp430f1611.h"
#include "mock_pca9548a.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_beacon_init(void);
extern void test_beacon_write(void);
extern void test_beacon_exec_build_msg_bytes(void);
extern void test_beacon_send_health_data(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_i2c_Init();
  mock_in430_Init();
  mock_msp430f1611_Init();
  mock_pca9548a_Init();
}
static void CMock_Verify(void)
{
  mock_i2c_Verify();
  mock_in430_Verify();
  mock_msp430f1611_Verify();
  mock_pca9548a_Verify();
}
static void CMock_Destroy(void)
{
  mock_i2c_Destroy();
  mock_in430_Destroy();
  mock_msp430f1611_Destroy();
  mock_pca9548a_Destroy();
}

//=======Test Reset Option=====
void resetTest()
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_beacon.c";
  UnityBegin();
  RUN_TEST(test_beacon_init, 17);
  RUN_TEST(test_beacon_write, 28);
  RUN_TEST(test_beacon_exec_build_msg_bytes, 45);
  RUN_TEST(test_beacon_send_health_data, 64);

  return (UnityEnd());
}
