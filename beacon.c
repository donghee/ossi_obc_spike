#include "beacon.h"

int get_health_data(uint8_t* data)
{
   uint16_t temp = 0x0a0a;
   uint16_t temp2 = 0x0a0b;
   data[0] = (temp >> 8) & 0xff; 
   data[1] = (temp) & 0xff; 
   data[2] = (temp2 >> 8) & 0xff; 
   data[3] = (temp2) & 0xff; 
   return 4; // TODO: sizeof data
}
int build_msg_bytes(uint8_t* cmd_buf, uint8_t cmd, const uint8_t* buf, int buf_size)
{
    unsigned char cmd_buf_count = 0;
    volatile int i;
    cmd_buf[cmd_buf_count] = cmd;
    for (i = 0; i < buf_size; i++)
    {
        cmd_buf_count++;
        cmd_buf[cmd_buf_count] = buf[i];
    }
}

void I2C_write(char* b, uint8_t buf_size)
{
  volatile int i;

  while (I2CDCTL&I2CBB);
  I2CWriteInit();

  PtrTransmit = buf_size-1;

  for(i = buf_size-1; i >= 0; i--) {
    I2CBuffer[i] = *b++;
    }

   I2CNDAT = buf_size;
   I2CTCTL |= I2CSTT + I2CSTP;
   while ((~I2CIFG)&ARDYIFG);  // wait untill transmission is finished
}

void Beacon_init(void)
{
    char beacon_address = 0x48;
    char PCA9548A_ADDR = 0x49;
    PCA9548A_Init(PCA9548A_ADDR);
    PCA9548A_SetChannel(2);

    _EINT();
    InitI2C(beacon_address);
}

void Beacon_ioctl(void){}
void Beacon_read(void) {}

void Beacon_write(char* cmd, uint8_t buf_size)
{
    I2C_write(cmd, buf_size);
}

void Beacon_send_health_data(uint8_t* health_buf, int health_buf_size )
{
    char cmd_buf[5];
    build_msg_bytes(cmd_buf, EXEC_MORSE, health_buf, health_buf_size);
    Beacon_write(cmd_buf, 5);
}

void Beacon_close()
{

}
