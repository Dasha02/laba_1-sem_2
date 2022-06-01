
#include "Hand_input.h"

//hand_input.c
//ручной ввод

extern list_errors * Errors_list;

float Hand_input_real(void)
{
    float result=0.0;
    char s[20];
    printf("=>");
    scanf("%12s",s);
    int i=sscanf(s, "%12f", &result);
    while (i!=1  || result > MAX_REAL ||result < MIN_REAL)
    {
        printf("ошибка, попробйте еще раз=>");
        scanf("%12s",s);
        i=sscanf(s, "%12f", &result);
    }
    return result;
}

float Hand_input_int(void)
{
    int result=0;
    char s[20];
    printf("=>");
    scanf("%3s",s);
    int i=sscanf(s, "%3d", &result);
    while (i!=1  || result > 100 ||result < 1L)
    {
        printf("ошибка, попробйте еще раз=>");
        scanf("%3s",s);
        i=sscanf(s, "%3d", &result);
    }
    return result;
}

complex_float Hand_input_complex(void)
{
    complex_float result={0.0,0.0};
    printf("real");
    result.real=Hand_input_real();
    printf("imag");
    result.imag=Hand_input_real();
    return result;
}

struct Vector3 * Hand_input_Vector3_complex(struct RingInfo * complex_Ring)
{
    struct Vector3 *result;
    //char s[1];
    
    complex_float xc;
    complex_float yc;
    complex_float zc;
    
 //   do
 //   {
    
        printf("Введите вектор в комплексных числах:\n");
        printf("введите вектор.x:\n");
        xc=Hand_input_complex();
        printf("введите вектор.y:\n");
        yc=Hand_input_complex();
        printf("введите вектор.z:\n");
        zc=Hand_input_complex();
    
        result=New_complex(complex_Ring, xc, yc, zc, Errors_list);
        
        printf("введен вектор:");
        Print_Vector3(result);
    
    //    printf("вектор введен корректно?(y/n)=>");
   //     scanf("%1s",s);
   // }while((s[0]!='y') || (s[0]!='Y'));
    return result;
}

struct Vector3 * Hand_input_Vector3_real(struct RingInfo * real_Ring)
{
    struct Vector3 *result;
    //char s[1];
    
    float xf;
    float yf;
    float zf;
    

    // do
   // {
        printf("Введите вектор в действительных числах:\n");
        printf("[_.x]=");
        xf=Hand_input_real();
        printf("[_.y]=");
        yf=Hand_input_real();
        printf("[_.z]=");
        zf=Hand_input_real();
        
        result=New_real(real_Ring, xf, yf, zf,  Errors_list);
        
        printf("введен ");
        Print_Vector3(result);
    
        //printf("вектор введен корректно?(y/n)=>");
        //scanf("%c",s);
    //}while((s!='y') || (s!='Y'));
    return result;
}



