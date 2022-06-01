

#ifndef Print_h
#define Print_h

#include <stdio.h>
#include "RingInfo.h"
#include "Vector3.h"

// print.h
void print_complex(complex_float *value);
void print_real(float * value);
void Print_Vector3 (struct Vector3 *vector);
//печать операций над векторами
//печать суммы
void Print_Sum_Vector3(struct Vector3 * a,struct Vector3 * b,struct Vector3 * result);
void Print_Sum_Vector3_test(struct Vector3 * a,struct Vector3 * b,struct Vector3 * result, struct Vector3 * test);
// печать векторного произведения
void Print_Vector_Mult_Vector3(struct Vector3 * a,struct Vector3 * b,struct Vector3 * result);
void Print_Vector_Mult_Vector3_test(struct Vector3 * a,struct Vector3 * b,struct Vector3 * result, struct Vector3 * test);
//печать скалярного произведения
void Print_Scalar_Mult_Vector3(struct Vector3 * a, struct Vector3 * b, void * result);
void Print_Scalar_Mult_Vector3_test(struct Vector3 * a,struct Vector3 * b,void * result, void * test);



#endif /* Print_h */
