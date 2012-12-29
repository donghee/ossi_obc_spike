#include "msp430f1611.h"
#include "in430.h"
#include "i2c.h"
#include "types.h"
#include "pca9548a.h"

// void Beacon_init(void);
void Beacon_ioctl(void);
void Beacon_read(void);
void Beacon_write(char* cmd, uint8_t buf_size);
void Beacon_close(void);

enum {EXEC_MORSE = 0x10};
