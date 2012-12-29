#include "unity.h"
#include "types.h"
#include "beacon.h"
#include "mock_pca9548a.h"
#include "mock_i2c.h"
#include "mock_msp430f1611.h"
#include "mock_in430.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_beacon_init(void) {
    char beacon_address = 0x48;
    char PCA9548A_ADDR = 0x49;
    PCA9548A_Init_Expect(PCA9548A_ADDR);
    PCA9548A_SetChannel_Expect(2);
    _enable_interrupts_Expect(); //EINT();
    InitI2C_Expect(beacon_address);

    Beacon_init();
}

void test_beacon_write(void) {
    char beacon_address = 0x48;
    unsigned char cmd[5] = {0xaa, 0xab, 0xac, 0xad, 0xae};
    int i, cmd_len = 0;
    I2CDCTL = 0;
    I2CDCTL &= ~I2CBB;
    I2CIFG = 0xff;
    I2CWriteInit_Expect();

    Beacon_write(cmd, 5);
    TEST_ASSERT_EQUAL(5-1, PtrTransmit);
    cmd_len = sizeof(cmd);
    for (i = cmd_len-1; i >= 0; i--) {
        TEST_ASSERT_EQUAL(cmd[cmd_len-1-i], I2CBuffer[i]);
    }
}

void test_beacon_exec_build_msg_bytes(void) {
    enum {EXEC_MORSE = 0x10};
    unsigned char data[] = {0x0a, 0x0a, 0x0a, 0x0b};

    char cmd_buffer[5];
    I2CDCTL = 0;
    I2CDCTL &= ~I2CBB;
    I2CIFG = 0xff;

    build_msg_bytes(cmd_buffer, EXEC_MORSE, data, sizeof data);

    TEST_ASSERT_EQUAL(EXEC_MORSE, cmd_buffer[0]);
    TEST_ASSERT_EQUAL(data[0], cmd_buffer[1]);
    TEST_ASSERT_EQUAL(data[1], cmd_buffer[2]);
    TEST_ASSERT_EQUAL(data[2], cmd_buffer[3]);
    TEST_ASSERT_EQUAL(data[3], cmd_buffer[4]);
}


void test_beacon_send_health_data(void) {
    unsigned char health_buf[5];
    int health_buf_size;

    I2CDCTL = 0;
    I2CDCTL &= ~I2CBB;
    I2CIFG = 0xff;
    I2CWriteInit_Expect();

    health_buf_size = get_health_data(health_buf);
    Beacon_send_health_data(&health_buf, health_buf_size);

    TEST_ASSERT_EQUAL(0x0a, health_buf[0]);
    TEST_ASSERT_EQUAL(0x0a, health_buf[1]);
    TEST_ASSERT_EQUAL(0x0a, health_buf[2]);
    TEST_ASSERT_EQUAL(0x0b, health_buf[3]);
    TEST_ASSERT_EQUAL(health_buf[3], I2CBuffer[0]);
    TEST_ASSERT_EQUAL(health_buf[2], I2CBuffer[1]);
    TEST_ASSERT_EQUAL(health_buf[1], I2CBuffer[2]);
    TEST_ASSERT_EQUAL(health_buf[0], I2CBuffer[3]);
    TEST_ASSERT_EQUAL(EXEC_MORSE, I2CBuffer[4]);
}


