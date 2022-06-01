
#include "Print.h"



// print.c
//  печать комплексных и действительных чисел
void print_complex(complex_float *value)
{
    printf("[%8.2f  +  (%8.2f)i]",value->real,value->imag);
    return;
}

void print_real(float * value)
{
    printf("[%8.2f]",*value);
    return;
}

// печать векторов в комплексных и действительных числах
void Print_Vector3 (struct Vector3 *vector)
{
    if (vector->ringInfo->size == sizeof(float))
    {
        printf("вектор:\n");
        printf("x"); print_real((float*)vector->x); printf("\n");
        printf("y"); print_real((float*)vector->y); printf("\n");
        printf("z"); print_real((float*)vector->z); printf("\n");
        return;
    }
    if (vector->ringInfo->size == sizeof(complex_float))
    {
        printf("вектор:\n");
        printf("x"); print_complex((complex_float*)vector->x); printf("\n");
        printf("y"); print_complex((complex_float*)vector->y); printf("\n");
        printf("z"); print_complex((complex_float*)vector->z); printf("\n");
       return;
    }
    if ((vector->ringInfo->size != sizeof(complex_float)) && (vector->ringInfo->size != sizeof(float)))
    {
        printf ("вывод для данного типа данных не определен!");
    }
    return;
}

//печать операций над векторами
//печать суммы
void Print_Sum_Vector3(struct Vector3 * a,struct Vector3 * b,struct Vector3 * result)
{
    if ((a->ringInfo != b->ringInfo) || (a->ringInfo != result->ringInfo))
    {
        printf("Oшибка несовместимости типов!\n");
        return;
    }
    if (a->ringInfo->size == sizeof(float))
    {
        printf ("******    ВЕКТОРНОЕ СЛОЖЕНИЕ    ******\n");
        printf ("  вектор А   +  вектор В  =  RESULT\n");
        printf ("--------------------------------------\n");
        printf ("x:");print_real(a->x);printf("   ");print_real(b->x);printf(" = ");print_real(result->x);printf("\n");
        printf ("y:");print_real(a->y);printf(" + ");print_real(b->y);printf(" = ");print_real(result->y);printf("\n");
        printf ("z:");print_real(a->z);printf("   ");print_real(b->z);printf(" = ");print_real(result->z);printf("\n");
        printf ("--------------------------------------\n");
        return;
    }
    if (a->ringInfo->size == sizeof(complex_float))
    {
        printf ("**************************      ВЕКТОРНОЕ СЛОЖЕНИЕ       *****************************\n");
        printf ("         вектор А            +          вектор В          =      вектор RESULT\n");
        printf ("--------------------------------------------------------------------------------------\n");
        printf ("x:");print_complex(a->x);printf("   ");print_complex(b->x);printf(" = ");print_complex(result->x);printf("\n");
        printf ("y:");print_complex(a->y);printf(" + ");print_complex(b->y);printf(" = ");print_complex(result->y);printf("\n");
        printf ("z:");print_complex(a->z);printf("   ");print_complex(b->z);printf(" = ");print_complex(result->z);printf("\n");
        printf ("--------------------------------------------------------------------------------------\n");
        return;
    }
    if ((a->ringInfo->size != sizeof(complex_float)) && (a->ringInfo->size != sizeof(float)))
    {
        printf ("вывод для данного типа данных не определен!");
    }
    return;
}

void Print_Sum_Vector3_test(struct Vector3 * a,struct Vector3 * b,struct Vector3 * result, struct Vector3 * test)
{
    if ((a->ringInfo->size != b->ringInfo->size) || (a->ringInfo->size != result->ringInfo->size) || (a->ringInfo->size != test->ringInfo->size))
    {
        printf("Oшибка несовместимости типов!\n");
        return;
    }
    if (a->ringInfo->size == sizeof(float))
    {
        printf ("******    ВЕКТОРНОЕ СЛОЖЕНИЕ    ******||############\n");
        printf ("  вектор А   +  вектор В  =  RESULT   || вектор тест\n");
        printf ("--------------------------------------||------------\n");
        printf ("x:");print_real(a->x);printf("   ");print_real(b->x);printf(" = ");print_real(result->x);
        printf("||");print_real(test->x);printf("\n");
        printf ("y:");print_real(a->y);printf(" + ");print_real(b->y);printf(" = ");print_real(result->y);
        printf("||");print_real(test->y);printf("\n");
        printf ("z:");print_real(a->z);printf("   ");print_real(b->z);printf(" = ");print_real(result->z);
        printf("||");print_real(test->z);printf("\n");
        printf ("-----------------------------------------------------\n");
        return;
    }
    if (a->ringInfo->size == sizeof(complex_float))
    {
        printf ("**************************      ВЕКТОРНОЕ СЛОЖЕНИЕ       *****************************||###########################\n");
        printf ("         вектор А            +          вектор В          =      вектор RESULT        ||    вектор тест            \n");
        printf ("--------------------------------------------------------------------------------------||---------------------------\n");
        printf ("x:");print_complex(a->x);printf("   ");print_complex(b->x);printf(" = ");print_complex(result->x);
        printf("||");print_complex(test->x);printf("\n");
        printf ("y:");print_complex(a->y);printf(" + ");print_complex(b->y);printf(" = ");print_complex(result->y);
        printf("||");print_complex(test->y);printf("\n");
        printf ("z:");print_complex(a->z);printf("   ");print_complex(b->z);printf(" = ");print_complex(result->z);
        printf("||");print_complex(test->z);printf("\n");
        printf ("--------------------------------------------------------------------------------------------------------------------\n");
        return;
    }
    if ((a->ringInfo->size != sizeof(complex_float)) && (a->ringInfo->size != sizeof(float)))
    {
        printf ("вывод для данного типа данных не определен!");
    }
    return;
}

// печать векторного произведения
void Print_Vector_Mult_Vector3(struct Vector3 * a,struct Vector3 * b,struct Vector3 * result)
{
    if ((a->ringInfo->size != b->ringInfo->size) || (a->ringInfo->size != result->ringInfo->size))
    {
        printf("Oшибка несовместимости типов!\n");
        return;
    }
    if (a->ringInfo->size == sizeof(float))
    {
        printf ("******    ВЕКТОРНОЕ УМНОЖЕНИЕ   ******\n");
        printf ("  вектор А   Х  вектор В  = вектор RES\n");
        printf ("--------------------------------------\n");
        printf ("x:");print_real(a->x);printf("   ");print_real(b->x);printf(" = ");print_real(result->x);printf("\n");
        printf ("y:");print_real(a->y);printf(" X ");print_real(b->y);printf(" = ");print_real(result->y);printf("\n");
        printf ("z:");print_real(a->z);printf("   ");print_real(b->z);printf(" = ");print_real(result->z);printf("\n");
        printf ("--------------------------------------\n");
        return;
    }
    if (a->ringInfo->size == sizeof(complex_float))
    {
        printf ("*************************      ВЕКТОРНОЕ  УМНОЖЕНИЕ       ****************************\n");
        printf ("         вектор А            Х            вектор В        =        вектор RESULT\n");
        printf ("--------------------------------------------------------------------------------------\n");
        printf ("x:");print_complex(a->x);printf("   ");print_complex(b->x);printf(" = ");print_complex(result->x);printf("\n");
        printf ("y:");print_complex(a->y);printf(" X ");print_complex(b->y);printf(" = ");print_complex(result->y);printf("\n");
        printf ("z:");print_complex(a->z);printf("   ");print_complex(b->z);printf(" = ");print_complex(result->z);printf("\n");
        printf ("--------------------------------------------------------------------------------------\n");
        return;
    }
    if ((a->ringInfo->size != sizeof(complex_float)) && (a->ringInfo->size != sizeof(float)))
    {
        printf ("вывод для данного типа данных не определен!");
    }
    return;
}

void Print_Vector_Mult_Vector3_test(struct Vector3 * a,struct Vector3 * b,struct Vector3 * result, struct Vector3 * test)
{
    if ((a->ringInfo->size != b->ringInfo->size) || (a->ringInfo->size != result->ringInfo->size) || (a->ringInfo->size != test->ringInfo->size))
    {
        printf("Oшибка несовместимости типов!\n");
        return;
    }
    if (a->ringInfo->size == sizeof(float))
    {
        printf ("******    ВЕКТОРНОЕ УМНОЖЕНИЕ   ******||############\n");
        printf ("  вектор А   Х  вектор В  = вектор RES|| вектор тест\n");
        printf ("--------------------------------------||------------\n");
        printf ("x:");print_real(a->x);printf("   ");print_real(b->x);printf(" = ");print_real(result->x);
        printf("||");print_real(test->x);printf("\n");
        printf ("y:");print_real(a->y);printf(" X ");print_real(b->y);printf(" = ");print_real(result->y);
        printf("||");print_real(test->y);printf("\n");
        printf ("z:");print_real(a->z);printf("   ");print_real(b->z);printf(" = ");print_real(result->z);
        printf("||");print_real(test->z);printf("\n");
        printf ("-----------------------------------------------------\n");
        return;
    }
    if (a->ringInfo->size == sizeof(complex_float))
    {
        printf ("*************************      ВЕКТОРНОЕ  УМНОЖЕНИЕ       ****************************||#################№№№#######\n");
        printf ("         вектор А            Х            вектор В        =        вектор RESULT      ||   вектор тест             \n");
        printf ("--------------------------------------------------------------------------------------||---------------------------\n");
        printf ("x:");print_complex(a->x);printf("   ");print_complex(b->x);printf(" = ");print_complex(result->x);
        printf("||");print_complex(test->x);printf("\n");
        printf ("y:");print_complex(a->y);printf(" X ");print_complex(b->y);printf(" = ");print_complex(result->y);
        printf("||");print_complex(test->y);printf("\n");
        printf ("z:");print_complex(a->z);printf("   ");print_complex(b->z);printf(" = ");print_complex(result->z);
        printf("||");print_complex(test->z);printf("\n");
        printf ("--------------------------------------------------------------------------------------------------------------------\n");
        return;
    }
    if ((a->ringInfo->size != sizeof(complex_float)) && (a->ringInfo->size != sizeof(float)))
    {
        printf ("вывод для данного типа данных не определен!");
    }
    return;
}

//печать скалярного произведения
void Print_Scalar_Mult_Vector3(struct Vector3 * a, struct Vector3 * b, void * result)
{
    if ((a->ringInfo->size != b->ringInfo->size))          //?????
    {
        printf("Oшибка несовместимости типов!\n");
        return;
    }
    if (a->ringInfo->size == sizeof(float))
    {
        float * res_real = (float *) result;
        printf ("** СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ ВЕКТОРОВ  **\n");
        printf ("  вектор А   *  вектор В  =  RESULT\n");
        printf ("--------------------------------------\n");
        printf ("x:");print_real(a->x);printf("   ");print_real(b->x);printf("\n");
        printf ("y:");print_real(a->y);printf(" * ");print_real(b->y);printf(" = ");print_real(res_real);printf("\n");
        printf ("z:");print_real(a->z);printf("   ");print_real(b->z);printf("\n");
        printf ("--------------------------------------\n");
        return;
    }
    if (a->ringInfo->size == sizeof(complex_float))
    {
        complex_float * res_complex = (complex_float *) result;
        printf ("************************  СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ ВЕКТОРОВ   **************************\n");
        printf ("         вектор А            *            вектор В        =       скаляр RESULT\n");
        printf ("--------------------------------------------------------------------------------------\n");
        printf ("x:");print_complex(a->x);printf("   ");print_complex(b->x);printf("\n");
        printf ("y:");print_complex(a->y);printf(" * ");print_complex(b->y);printf(" = ");print_complex(res_complex);printf("\n");
        printf ("z:");print_complex(a->z);printf("   ");print_complex(b->z);printf("\n");
        printf ("-------------------------------------------------------------------------------------\n");
        return;
    }
    if ((a->ringInfo->size != sizeof(complex_float)) && (a->ringInfo->size != sizeof(float)))
    {
        printf ("вывод для данного типа данных не определен!");
    }
    return;
}

void Print_Scalar_Mult_Vector3_test(struct Vector3 * a,struct Vector3 * b,void * result, void * test)
{
    if ((a->ringInfo != b->ringInfo))          //?????
    {
        printf("Oшибка несовместимости типов!\n");
        return;
    }
    if (a->ringInfo->size == sizeof(float))
    {
        float * res_real = (float *) result;
        float * test_real = (float *) test;
        printf ("** СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ ВЕКТОРОВ  **||############\n");
        printf ("  вектор А   *  вектор В  =  RESULT   || скаляр тест\n");
        printf ("--------------------------------------||------------\n");
        printf ("x:");print_real(a->x);printf("   ");print_real(b->x);printf("\n");
        printf ("y:");print_real(a->y);printf(" * ");print_real(b->y);printf(" = ");print_real(res_real);
        printf("||");print_real(test_real);printf("\n");
        printf ("z:");print_real(a->z);printf("   ");print_real(b->z);printf("\n");
        printf ("----------------------------------------------------\n");
        return;
    }
    if (a->ringInfo->size == sizeof(complex_float))
    {
        complex_float * res_complex = (complex_float *) result;
        complex_float * test_complex = (complex_float *) test;
        printf ("************************  СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ ВЕКТОРОВ   **************************||##############################\n");
        printf ("         вектор А            *            вектор В        =       скаляр RESULT       ||  скаляр тест          \n");
        printf ("--------------------------------------------------------------------------------------||------------------------------\n");
        printf ("x:");print_complex(a->x);printf("   ");print_complex(b->x);printf("\n");
        printf ("y:");print_complex(a->y);printf(" * ");print_complex(b->y);printf(" = ");print_complex(res_complex);
        printf("||");print_complex(test_complex);printf("\n");
        printf ("z:");print_complex(a->z);printf("   ");print_complex(b->z);printf("\n");
        printf ("----------------------------------------------------------------------------------------------------------------------\n");
        return;
    }
    if ((a->ringInfo->size != sizeof(complex_float)) && (a->ringInfo->size != sizeof(float)))
    {
        printf ("вывод для данного типа данных не определен!");
    }
    return;
}
