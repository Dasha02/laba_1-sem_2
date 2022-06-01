#include "Vector3.h"


//Vector3.c



// создание


list_errors * Errors_list=NULL;//
struct Vector3 * zero_vector3;

struct Vector3 * Zero (struct RingInfo * ringinfo)
{
    if (!zero_vector3)
    {
        struct Vector3 * zero_vector3=malloc(sizeof(struct Vector3));
        zero_vector3->ringInfo = ringinfo;
        zero_vector3->x = ringinfo->zero;
        zero_vector3->y = ringinfo->zero;
        zero_vector3->z = ringinfo->zero;
    }
    return zero_vector3;
}

struct Vector3 * New (struct RingInfo * ringinfo, void * x, void * y, void *z, list_errors * l_errors)
{
    
    if (((sizeof(*x))!=(ringinfo->size)) || ((sizeof(*y))!=(ringinfo->size)) || ((sizeof(*z))!=(ringinfo->size)))
    {
        if (Errors_list==NULL)
            l_errors=init_list(1);
        else
            add_error_list_end(1, l_errors);
        return NULL;
    }
    
    struct Vector3 * result=malloc(sizeof(struct Vector3));
    result->ringInfo=ringinfo;
    if (result->ringInfo->size == sizeof(float))
    {
        float * x_real = (float *) x;
        float * y_real = (float *) y;
        float * z_real = (float *) z;
        printf("%f   %f   %f\n",*x_real,*y_real,*z_real);
        
        result->x = (float*) x_real;
        result->y = (float*) y_real;
        result->z = (float*) z_real;
        
    }
    if (result->ringInfo->size == sizeof(complex_float))
    {
        complex_float * x_complex = (complex_float *) x;
        complex_float * y_complex = (complex_float *) y;
        complex_float * z_complex = (complex_float *) z;
        result->x=x_complex;
        result->y=y_complex;
        result->z=z_complex;
    }
    Print_Vector3(result);
    return result;
}

struct Vector3 * New_real (struct RingInfo * ringinfo, float xf, float yf, float zf, list_errors * l_errors)
{
    
    if (((sizeof(xf))!=(ringinfo->size)) || ((sizeof(yf))!=(ringinfo->size)) || ((sizeof(zf))!=(ringinfo->size)))
    {
        if (Errors_list==NULL)
            l_errors=init_list(1);
        else
            add_error_list_end(1, l_errors);
        return NULL;
    }
    
    struct Vector3 * result=malloc(sizeof(struct Vector3));
    result->ringInfo=ringinfo;
    
    result->x = (float*)malloc(ringinfo->size);
    result->y = (float*)malloc(ringinfo->size);
    result->z = (float*)malloc(ringinfo->size);
    *((float*) result->x) = xf;
    *((float*) result->y) = yf;
    *((float*) result->z) = zf;
    
    return result;
}

struct Vector3 * New_complex (struct RingInfo * ringinfo, complex_float xc, complex_float yc, complex_float zc, list_errors * l_errors)
{
  
    if (((sizeof(xc))!=(ringinfo->size)) || ((sizeof(yc))!=(ringinfo->size)) || ((sizeof(zc))!=(ringinfo->size)))
    {
        if (Errors_list==NULL)
            l_errors=init_list(1);
        else
            add_error_list_end(1, l_errors);
        return NULL;
    }
    
    struct Vector3 * result=malloc(sizeof(struct Vector3));
    result->ringInfo=ringinfo;
    
    result->x = (complex_float*)malloc(ringinfo->size);
    result->y = (complex_float*)malloc(ringinfo->size);
    result->z = (complex_float*)malloc(ringinfo->size);
    *((complex_float*) result->x) = xc;
    *((complex_float*) result->y) = yc;
    *((complex_float*) result->z) = zc;
    
    return result;
}

struct Vector3 * New2 (struct RingInfo * ringinfo, void * x, void * y, void *z, list_errors * l_errors)
{
    if (((sizeof(*x))!=(ringinfo->size)) || ((sizeof(*y))!=(ringinfo->size)) || ((sizeof(*z))!=(ringinfo->size)))
    {
        if (Errors_list==NULL)
            l_errors=init_list(1);
        else
            add_error_list_end(1, l_errors);
        return NULL;
    }
    struct Vector3 * result=NULL;
    if (ringinfo->size == sizeof(float))
    {
        float xf = *((float*) x);
        float yf = *((float*) y);
        float zf = *((float*) z);
        result = New_real(ringinfo, xf, yf, zf, l_errors);
    }
    if (ringinfo->size == sizeof(complex_float))
    {
        complex_float xc = *((complex_float*) x);
        complex_float yc = *((complex_float*) y);
        complex_float zc = *((complex_float*) z);
        result = New_complex(ringinfo, xc, yc, zc,  l_errors);
    }
    return result;
}

//декомпозиция
void * Get_x(struct Vector3 * vector_a)
{
    return vector_a->x;
};
void * Get_y(struct Vector3 * vector_a)
{
    return vector_a->y;
};
void * Get_z(struct Vector3 * vector_a)
{
    return vector_a->z;
};

//арифметика
struct Vector3 * Sum_Vectors(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors)
{
    if (vector_a->ringInfo != vector_b->ringInfo)
    {
        if (Errors_list==NULL)
            l_errors=init_list(1);
        else
            add_error_list_end(1, l_errors);
        return NULL;
    }
    struct Vector3 * result=malloc(sizeof(struct Vector3));
    result->ringInfo = vector_a->ringInfo;
    result->x = result->ringInfo->Sum(vector_a->x,vector_b->x);
    result->y = result->ringInfo->Sum(vector_a->y,vector_b->y);
    result->z = result->ringInfo->Sum(vector_a->z,vector_b->z);
    return result;
}

struct Vector3 * Dif_Vectors(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors)
{
    if (vector_a->ringInfo != vector_b->ringInfo)
    {
        if (Errors_list==NULL)
            l_errors=init_list(1);
        else
            add_error_list_end(1, l_errors);
        return NULL;
    }
    struct Vector3 * result=malloc(sizeof(struct Vector3));
    result->ringInfo = vector_a->ringInfo;
    result->x = result->ringInfo->Dif(vector_a->x,vector_b->x);
    result->y = result->ringInfo->Dif(vector_a->y,vector_b->y);
    result->z = result->ringInfo->Dif(vector_a->z,vector_b->z);
    return result;
}

struct Vector3 * Vector_Mult_Vectors1(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors)
{
    if (vector_a->ringInfo != vector_b->ringInfo)
    {
        if (Errors_list==NULL)
            l_errors=init_list(1);
        else
            add_error_list_end(1, l_errors);
        return NULL;
    }
    struct Vector3 * result=malloc(sizeof(struct Vector3));
    result->ringInfo = vector_a->ringInfo;
    result->x = result->ringInfo->Mult_Dif(vector_a->y,vector_b->z,vector_b->y,vector_a->z);
    result->y = result->ringInfo->Mult_Dif(vector_b->x,vector_a->z,vector_a->x,vector_b->z);
    result->z = result->ringInfo->Mult_Dif(vector_a->x,vector_b->y,vector_b->x,vector_a->y);
    return result;
}

struct Vector3 * Vector_Mult_Vectors2(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors)
{
    void * f1;
    void * f2;
    if (vector_a->ringInfo != vector_b->ringInfo)
    {
        if (Errors_list==NULL)
            l_errors=init_list(1);
        else
            add_error_list_end(1, l_errors);
        return NULL;
    }
    struct Vector3 * result=malloc(sizeof(struct Vector3));
    result->ringInfo = vector_a->ringInfo;
    
    f1 = result->ringInfo->Mult(vector_a->y,vector_b->z);
    f2 = result->ringInfo->Mult(vector_b->y,vector_a->z);
    result->x = result->ringInfo->Dif(f1,f2);
    result->ringInfo->Free_item(f1);
    result->ringInfo->Free_item(f2);
    
    f1 = result->ringInfo->Mult(vector_b->x,vector_a->z);
    f2 = result->ringInfo->Mult(vector_a->x,vector_b->z);
    result->y = result->ringInfo->Dif(f1,f2);
    result->ringInfo->Free_item(f1);
    result->ringInfo->Free_item(f2);
    
    f1 = result->ringInfo->Mult(vector_a->x,vector_b->y);
    f2 = result->ringInfo->Mult(vector_b->x,vector_a->y);
    result->z = result->ringInfo->Dif(f1,f2);
    result->ringInfo->Free_item(f1);
    result->ringInfo->Free_item(f2);
    
    return result;
}

void * Scalar_Mult_Vectors1(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors)
{
    if (vector_a->ringInfo->size != vector_b->ringInfo->size)
    {
        if (Errors_list==NULL)
            l_errors=init_list(1);
        else
            add_error_list_end(1, l_errors);
        return NULL;
    }
    return vector_a->ringInfo->Mult_Sum(vector_a->x,vector_b->x,vector_a->y,vector_b->y,vector_a->z,vector_b->z);
}

void * Scalar_Mult_Vectors2(struct Vector3 * vector_a, struct Vector3 * vector_b, list_errors * l_errors)
{
    void * f1;
    void * f2;
    void * f3;
    void * f12sum;
    void * result;
    if (vector_a->ringInfo->size != vector_b->ringInfo->size)
    {
        if (Errors_list==NULL)
            l_errors=init_list(1);
        else
            add_error_list_end(1, Errors_list);
        return NULL;
    }
    f1=vector_a->ringInfo->Mult(vector_a->x,vector_b->x);
    f2=vector_a->ringInfo->Mult(vector_a->y,vector_b->y);
    f3=vector_a->ringInfo->Mult(vector_a->z,vector_b->z);
    f12sum=vector_a->ringInfo->Sum(f1,f2);
    result=vector_a->ringInfo->Sum(f12sum,f3);
    
    vector_a->ringInfo->Free_item(f1);
    vector_a->ringInfo->Free_item(f2);
    vector_a->ringInfo->Free_item(f3);
    vector_a->ringInfo->Free_item(f12sum);
    
    return result;
}

void Free_Vector3(struct Vector3 * vector_a)
{
    free(vector_a->x);
    free(vector_a->y);
    free(vector_a->z);
    free(vector_a);
    return;
}

