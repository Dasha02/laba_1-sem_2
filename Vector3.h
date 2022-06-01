
#ifndef Vector3_h
#define Vector3_h

#include <stdio.h>
#include <stdlib.h>
#include "RingInfo.h"
#include "Errors.h"

//функции, шаблоны структур, определения типов
//Vector3.h


struct Vector3
{
    struct RingInfo * ringInfo;
    void * x;
    void * y;
    void * z;
};

// создание
struct Vector3 * Zero(struct RingInfo * ringinfo);
struct Vector3 * New (struct RingInfo * ringinfo, void * x, void * y, void *z, list_errors * l_errors);
struct Vector3 * New2(struct RingInfo * ringinfo, void * x, void * y, void *z, list_errors * l_errors);

//декомпозиция
void * Get_x(struct Vector3 * vector);
void * Get_y(struct Vector3 * vector);
void * Get_z(struct Vector3 * vector);

//арифметика
struct Vector3 * Sum_Vectors(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors);
struct Vector3 * Dif_Vectors(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors);

struct Vector3 * Vector_Mult_Vectors2(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors);
struct Vector3 * Vector_Mult_Vectors1(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors);

void * Scalar_Mult_Vectors2(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors);
void * Scalar_Mult_Vectors1(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors);

// освобождение памяти
void Free_Vector3(struct Vector3 * vector_a);

// печать вектора
void Print_Vector3 (struct Vector3 *vector);


struct Vector3 * New_real (struct RingInfo * ringinfo, float xf, float yf, float zf, list_errors * l_errors);
struct Vector3 * New_complex (struct RingInfo * ringinfo, complex_float xc, complex_float yc, complex_float zc, list_errors * l_errors);


#endif /* Vector3_h */


