
#ifndef Hand_input_h
#define Hand_input_h

#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <string.h>

#include "RingInfo.h"
#include "Vector3.h"
#include "main.h"


//hand_input.h
float Hand_input_real(void);
float Hand_input_int(void);
complex_float Hand_input_complex(void);
struct Vector3 * Hand_input_Vector3_complex(struct RingInfo * complex_Ring);
struct Vector3 * Hand_input_Vector3_real(struct RingInfo * real_Ring);


#endif /* Hand_input_h */
