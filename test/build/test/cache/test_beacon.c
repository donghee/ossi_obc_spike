#include "unity.h"
#include "types.h"
#include "mock_pca9548a.h"
#include "mock_msp430f1611.h"
#include "mock_in430.h"
#include "mock_i2c.h"
#include "beacon.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_beacon_init(void) {

    char beacon_address = 0x48;

    char PCA9548A_ADDR = 0x49;

    PCA9548A_Init_CMockExpect(20, PCA9548A_ADDR);

    PCA9548A_SetChannel_CMockExpect(21, 2);

    _enable_interrupts_CMockExpect(22);

    InitI2C_CMockExpect(23, beacon_address);



    Beacon_init();

}



void test_beacon_write(void) {

    char beacon_address = 0x48;

    unsigned char cmd[5] = {0xaa, 0xab, 0xac, 0xad, 0xae};

    int i, cmd_len = 0;

    I2CDCTL = 0;

    I2CDCTL &= ~(0x01);

    I2CIFG = 0xff;

    I2CWriteInit_CMockExpect(35);



    Beacon_write(cmd, 5);

    UnityAssertEqualNumber((_U_SINT)((5-1)), (_U_SINT)((PtrTransmit)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

    cmd_len = sizeof(cmd);

    for (i = cmd_len-1; i >= 0; i--) {

        UnityAssertEqualNumber((_U_SINT)((cmd[cmd_len-1-i])), (_U_SINT)((I2CBuffer[i])), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

    }

}



void test_beacon_exec_build_msg_bytes(void) {

    enum {EXEC_MORSE = 0x10};

    unsigned char data[] = {0x0a, 0x0a, 0x0a, 0x0b};



    char cmd_buffer[5];

    I2CDCTL = 0;

    I2CDCTL &= ~(0x01);

    I2CIFG = 0xff;



    build_msg_bytes(cmd_buffer, EXEC_MORSE, data, sizeof data);



    UnityAssertEqualNumber((_U_SINT)((EXEC_MORSE)), (_U_SINT)((cmd_buffer[0])), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((data[0])), (_U_SINT)((cmd_buffer[1])), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((data[1])), (_U_SINT)((cmd_buffer[2])), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((data[2])), (_U_SINT)((cmd_buffer[3])), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((data[3])), (_U_SINT)((cmd_buffer[4])), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

}





void test_beacon_send_health_data(void) {

    unsigned char health_buf[5];

    int health_buf_size;



    I2CDCTL = 0;

    I2CDCTL &= ~(0x01);

    I2CIFG = 0xff;

    I2CWriteInit_CMockExpect(71);



    health_buf_size = get_health_data(health_buf);

    Beacon_send_health_data(&health_buf, health_buf_size);



    UnityAssertEqualNumber((_U_SINT)((0x0a)), (_U_SINT)((health_buf[0])), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x0a)), (_U_SINT)((health_buf[1])), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x0a)), (_U_SINT)((health_buf[2])), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x0b)), (_U_SINT)((health_buf[3])), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((health_buf[3])), (_U_SINT)((I2CBuffer[0])), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((health_buf[2])), (_U_SINT)((I2CBuffer[1])), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((health_buf[1])), (_U_SINT)((I2CBuffer[2])), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((health_buf[0])), (_U_SINT)((I2CBuffer[3])), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((EXEC_MORSE)), (_U_SINT)((I2CBuffer[4])), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

}
