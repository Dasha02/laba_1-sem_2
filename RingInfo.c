
#include "RingInfo.h"


//RingInfo.c

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
  )
{
  struct RingInfo* ringInfo = malloc(sizeof(struct RingInfo));
    
    
    //struct RingInfo * ringInfo;
    //ringInfo =(struct RingInfo*)calloc(1,sizeof(struct RingInfo));
    ringInfo->size = size;
    ringInfo->Sum = Sum;
    ringInfo->Dif = Dif;
    ringInfo->zero = zero;
    ringInfo->Minus = Minus;
    ringInfo->Mult = Mult;
    ringInfo->one = one;
    ringInfo->Mult_Dif = Mult_Dif;
    ringInfo->Mult_Sum = Mult_Sum;
    ringInfo->Free_item = Free_item;
    return ringInfo;
}

void Free_RingInfo(struct RingInfo * ringinfo)
{
    free(ringinfo);
    return;
}




// арифметика RingInfo в действительных числах


void * Sum_real(void* real_a, void* real_b)
{
    float * r_a = (float *) real_a;
    float * r_b = (float *) real_b;
    float * result = malloc(sizeof(float));
    *result = *r_a + *r_b;
    return (void*)result;
}

void * Dif_real(void* real_a, void* real_b)
{
    float * r_a = (float *) real_a;
    float * r_b = (float *) real_b;
    float * result = malloc(sizeof(float));
    *result = *r_a - *r_b;
    return (void*)result;
}

void * zero_real(void)
{
    float * result = malloc(sizeof(float));
    *result = 0.0;
    return (void*)result;
}

void * Minus_real(void* real_a)
{
    float * r_a = (float *) real_a;
    float * result = malloc(sizeof(float));
    *result = ((*r_a) * (-1));
    return (void*)result;
}

void * Mult_real(void* real_a, void* real_b)
{
    float * r_a = (float *) real_a;
    float * r_b = (float *) real_b;
    float * result = malloc(sizeof(float));
    *result = ((*r_a) * (*r_b));
    return (void*)result;
}

void * Mult_Dif_a_b_c_d_real(void* real_a, void* real_b, void* real_c, void* real_d)
{
    float * r_a = (float *) real_a;
    float * r_b = (float *) real_b;
    float * r_c = (float *) real_c;
    float * r_d = (float *) real_d;
    float * result = malloc(sizeof(float));
    *result = (((*r_a) * (*r_b))-((*r_c) * (*r_d)));
    return (void*)result;
}

void * Mult_Sum_a_b_c_d_e_f_real(void* real_a, void* real_b, void* real_c, void* real_d, void* real_e, void* real_f)
{
    float * r_a = (float *) real_a;
    float * r_b = (float *) real_b;
    float * r_c = (float *) real_c;
    float * r_d = (float *) real_d;
    float * r_e = (float *) real_e;
    float * r_f = (float *) real_f;
    float * result = malloc(sizeof(float));
    *result = (((*r_a) * (*r_b))+((*r_c) * (*r_d))+((*r_e) * (*r_f)));
    return (void*)result;
}

void * one_real(void)
{
    float * result = malloc(sizeof(float));
    *result = 1.0;
    return (void*)result;
}

void Free_real(void* real_a)
{
    float * r_a = (float *) real_a;
    free(r_a);
    return;
}

// арифметика RingInfo в комплексных числах


void * Sum_complex(void* complex_a, void* complex_b)
{
    complex_float * c_a = (complex_float *) complex_a;
    complex_float * c_b = (complex_float *) complex_b;
    complex_float * result = malloc(sizeof(complex_float));
    result->real = c_a->real + c_b->real;
    result->imag = c_a->imag + c_b->imag;
    return (void*)result;
}

void * Dif_complex(void* complex_a, void* complex_b)
{
    complex_float * c_a = (complex_float *) complex_a;
    complex_float * c_b = (complex_float *) complex_b;
    complex_float * result = malloc(sizeof(complex_float));
    result->real = c_a->real - c_b->real;
    result->imag = c_a->imag - c_b->imag;
    return (void*)result;
}

void * zero_complex(void)
{
    complex_float * result = malloc(sizeof(complex_float));
    result->real = 0.0;
    result->imag = 0.0;
    return (void*)result;
}

void * Minus_complex(void* complex_a)
{
    complex_float * c_a = (complex_float *) complex_a;
    complex_float * result = malloc(sizeof(complex_float));
    result->real = c_a->real * (-1);
    result->imag = c_a->imag * (-1);
    return (void*)result;
}

void * Mult_complex(void* complex_a, void* complex_b)
{
    complex_float * c_a = (complex_float *) complex_a;
    complex_float * c_b = (complex_float *) complex_b;
    complex_float * result = malloc(sizeof(complex_float));
    result->real = (((c_a->real) * (c_b->real)) - ((c_a->imag) * (c_b->imag)));
    result->imag = (((c_a->real) * (c_b->imag)) + ((c_a->imag) * (c_b->real)));
    return (void*)result;
}

void * one_complex(void)
{
    complex_float * result = malloc(sizeof(complex_float));
    result->real = 1.0;
    result->imag = 1.0;
    return (void*)result;
}

void * Mult_Dif_a_b_c_d_complex(void* complex_a, void* complex_b, void* complex_c, void* complex_d)
{
    complex_float * c_a = (complex_float *) complex_a;
    complex_float * c_b = (complex_float *) complex_b;
    complex_float * c_c = (complex_float *) complex_c;
    complex_float * c_d = (complex_float *) complex_d;
    complex_float * result = malloc(sizeof(complex_float));
    result->real = ((((c_a->real)*(c_b->real))-((c_a->imag)*(c_b->imag)))-(((c_c->real)*(c_d->real))-((c_c->imag)*(c_d->imag))));
    result->imag = ((((c_a->real)*(c_b->imag))+((c_a->imag)*(c_b->real)))-(((c_c->real)*(c_d->imag))+((c_c->imag)*(c_d->real))));
    return (void*)result;
}

void * Mult_Sum_a_b_c_d_e_f_complex(void* complex_a, void* complex_b, void* complex_c, void* complex_d, void* complex_e, void* complex_f)
{
    complex_float * c_a = (complex_float *) complex_a;
    complex_float * c_b = (complex_float *) complex_b;
    complex_float * c_c = (complex_float *) complex_c;
    complex_float * c_d = (complex_float *) complex_d;
    complex_float * c_e = (complex_float *) complex_e;
    complex_float * c_f = (complex_float *) complex_f;
    complex_float * result = malloc(sizeof(complex_float));
    result->real = ((((c_a->real)*(c_b->real))-((c_a->imag)*(c_b->imag)))+
                    (((c_c->real)*(c_d->real))-((c_c->imag)*(c_d->imag)))+
                    (((c_e->real)*(c_f->real))-((c_e->imag)*(c_f->imag))));
    result->imag = ((((c_a->real)*(c_b->imag))+((c_a->imag)*(c_b->real)))+
                    (((c_c->real)*(c_d->imag))+((c_c->imag)*(c_d->real)))+
                    (((c_e->real)*(c_f->imag))+((c_e->imag)*(c_f->real))));
    return (void*)result;
}

void Free_complex(void* complex_a)
{
    complex_float * c_a = (complex_float *) complex_a;
    free(c_a);
    return;
}
  
