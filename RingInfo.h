

#ifndef RingInfo_h
#define RingInfo_h

#include <stdio.h>
#include <stdlib.h>


//функции, шаблоны структур, определения типов
//RingInfo.h
struct RingInfo
{
    size_t size;
    void* (*Sum)(void*, void*);
    void* (*Dif)(void*, void*);
    void* (*zero)(void);
    void* (*Minus)(void*);
    void* (*Mult)(void*, void*);
    void* (*one)(void);
    void* (*Mult_Dif)(void*, void*, void*, void*);
    void* (*Mult_Sum)(void*, void*, void*, void*, void*, void*);
    void (*Free_item)(void*);
};

struct RingInfo * Create_RingInfo
 (
    size_t size,
    void* (*Sum)(void*, void*),
    void* (*Dif)(void*, void*),
    void* (*zero)(void),
    void* (*Minus)(void*),
    void* (*Mult)(void*, void*),
    void* (*one)(void),
    void* (*Mult_Dif)(void*, void*, void*, void*),
    void* (*Mult_Sum)(void*, void*, void*, void*, void*, void*),
    void (*Free_item)(void*)
  );

void Free_RingInfo(struct RingInfo * ringinfo);

// //арифметика RingInfo в действительных числах

void * Sum_real(void* real_a, void* real_b);
void * Dif_real(void* real_a, void* real_b);
void * zero_real(void);
void * Minus_real(void* real_a);
void * Mult_real(void* real_a, void* real_b);
void * one_real(void);
void Free_real(void* real_a);

void * Mult_Dif_a_b_c_d_real(void* real_a, void* real_b, void* real_c, void* real_d);
void * Mult_Sum_a_b_c_d_e_f_real(void* real_a, void* real_b, void* real_c, void* real_d, void* real_e, void* real_f);

// // арифметика RingInfo в комплексных числах
typedef struct complex
{
    float real;
    float imag;
}complex_float;


void * Sum_complex(void* complex_a, void* complex_b);
void * Dif_complex(void* complex_a, void* complex_b);
void * zero_complex(void);
void * Minus_complex(void* complex_a);
void * Mult_complex(void* complex_a, void* complex_b);
void * one_complex(void);
void Free_complex(void* complex_a);

void * Mult_Dif_a_b_c_d_complex(void* complex_a, void* complex_b, void* complex_c, void* complex_d);
void * Mult_Sum_a_b_c_d_e_f_complex(void* complex_a, void* complex_b, void* complex_c, void* complex_d, void* complex_e, void* complex_f);


#endif /* RingInfo_h */
