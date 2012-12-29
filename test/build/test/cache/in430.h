void _enable_interrupts(void);

void _disable_interrupts(void);

unsigned short _bic_SR_register(unsigned short mask);

unsigned short _bic_SR_register_on_exit(unsigned short mask);

unsigned short _bis_SR_register(unsigned short mask);

unsigned short _bis_SR_register_on_exit(unsigned short mask);

unsigned short _get_SR_register(void);

unsigned short _get_SR_register_on_exit(void);

unsigned short _swap_bytes(unsigned short src);

void _nop(void);

void _never_executed(void);
