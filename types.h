#ifndef _TYPES_H_
#define _TYPES_H_

#ifndef __uint32_t_defined 
        typedef unsigned long int uint32_t;
#endif
#ifndef __int32_t_defined 
        /* typedef signed long int int32_t; */
#endif

#ifndef __uint16_t_defined 
    typedef unsigned short uint16_t;
#endif
#ifndef __int16_t_defined 
    typedef short int16_t;
#endif
#ifndef __uint8_t_defined 
    typedef unsigned char uint8_t;
#endif
#ifndef __int8_t_defined 
    typedef char int8_t;
#endif

#ifdef TEST
        #define uint32_t unsigned long int
#endif

typedef char bool;

enum IoDirection {INPUT = 0, OUTPUT = 1};
enum IoState {LOW = 0, HIGH = 1, TOGGLE = 2};
enum {OFF = 0,ON = 1};

#endif
