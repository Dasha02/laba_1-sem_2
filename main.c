
#include "main.h"

const size_t real_size=sizeof(float);
const size_t complex_size=sizeof(complex_float);


extern list_errors * Errors_list;

int main(int argc, const char * argv[])
{
    //инициализирум арифметики для двух типов данных
    struct RingInfo *real_Ring=Create_RingInfo(
                                                real_size,
                                                &Sum_real,
                                                &Dif_real,
                                                &zero_real,
                                                &Minus_real,
                                                &Mult_real,
                                                &one_real,
                                                &Mult_Dif_a_b_c_d_real,
                                                &Mult_Sum_a_b_c_d_e_f_real,
                                                &Free_real
                                                );

    
    struct RingInfo *complex_Ring=Create_RingInfo(
                                                    complex_size,
                                                    &Sum_complex,
                                                    &Dif_complex,
                                                    &zero_complex,
                                                    &Minus_complex,
                                                    &Mult_complex,
                                                    &one_complex,
                                                    &Mult_Dif_a_b_c_d_complex,
                                                    &Mult_Sum_a_b_c_d_e_f_complex,
                                                    &Free_complex
                                                    );

    
    
    
    
    int col_test=0;

    FILE *output = NULL;
    FILE *input = NULL;
    
    char file_name_test_r[]="test_real_01";
    char file_name_test_c[]="test_complex_01";
    
    char f_name_test_r[]="test_real_01";
    char f_name_test_c[]="test_complex_01";

    //определение перемннвх для ручного ввода и расчетов
    struct Vector3 * vector_a;
    struct Vector3 * vector_b;
    struct Vector3 * vector_sum;
    struct Vector3 * vector_mult;
    complex_float * scalar_complex_mult;
    float * scalar_real_mult;
    
    //определение переменных для  файлового ввода/вывода и тестов
    struct Vector3 * vector_a_test;
    struct Vector3 * vector_b_test;
    struct Vector3 * vector_sum_test;
    struct Vector3 * vector_mult_test;
    complex_float * scalar_complex_mult_test;
    float * scalar_real_mult_test;
    
    //определение переменных для проверки корректности выполнения тестов
    struct Vector3 * vector_test;
    complex_float * complex_test;
    float * real_test;
    float test=0.0;
    complex_float test_complex1={0.0,0.0};
    complex_float test_complex2={0.0,0.0};
    complex_float test_complex3={0.0,0.0};
    complex_float zero_complex={0.0,0.0};
    
    float xf,yf,zf;
    complex_float xc,yc,zc;
    
    // определение структуры дпннных для тестов для записи в файл и считывания
    //struct test_Vector3_real struct_test_Vector3_real;
    //struct test_Vector3_complex struct_test_Vector3_complex;
    
    int qwe=1,c;
    
    while (qwe==1)
    {
        c=main_menu();
        switch (c)
        {
            case 0:
                print_list_errors(Errors_list);
                Errors_list = free_list(Errors_list);
                Free_RingInfo(real_Ring);
                Free_RingInfo(complex_Ring);
            return 0;
                
            case 1: //ввод данных и расчет в действительных числах
                printf("****** РАСЧЕТ в действительных числах ******\n");
                printf("ВЕКТОР <A>:\n");
                vector_a=Hand_input_Vector3_real(real_Ring);
                printf("\nВЕКТОР <B>:\n");
                vector_b=Hand_input_Vector3_real(real_Ring);
                printf("************ РАСЧЕТЫ *****************\n");
                
                vector_sum=Sum_Vectors(vector_a, vector_b,Errors_list);
                Print_Sum_Vector3(vector_a, vector_b, vector_sum);
                
                vector_mult=Vector_Mult_Vectors2(vector_a, vector_b,Errors_list);
                Print_Vector_Mult_Vector3(vector_a, vector_b, vector_mult);
                
                scalar_real_mult=Scalar_Mult_Vectors2(vector_a, vector_b,Errors_list);
                Print_Scalar_Mult_Vector3(vector_a, vector_b, scalar_real_mult);
                
                Free_Vector3(vector_a);
                Free_Vector3(vector_b);
                Free_Vector3(vector_sum);
                Free_Vector3(vector_mult);
                real_Ring->Free_item(scalar_real_mult);
                
                break;
                
            case 2: //ввод данных и расчет в комплексных числах
                printf("****** РАСЧЕТ в комплексных числах ******\n");
                printf("ВЕКТОР <A>:\n");
                vector_a=Hand_input_Vector3_complex(complex_Ring);
                printf("\nВЕКТОР <B>:\n");
                vector_b=Hand_input_Vector3_complex(complex_Ring);
                printf("************ РАСЧЕТЫ *****************\n");
                vector_sum=Sum_Vectors(vector_a, vector_b,Errors_list);
                Print_Sum_Vector3(vector_a, vector_b, vector_sum);
                
                vector_mult=Vector_Mult_Vectors2(vector_a, vector_b,Errors_list);
                Print_Vector_Mult_Vector3(vector_a, vector_b, vector_mult);
                
                scalar_complex_mult=Scalar_Mult_Vectors2(vector_a, vector_b,Errors_list);
                Print_Scalar_Mult_Vector3(vector_a, vector_b, scalar_complex_mult);
                
                Free_Vector3(vector_a);
                Free_Vector3(vector_b);
                Free_Vector3(vector_sum);
                Free_Vector3(vector_mult);
                complex_Ring->Free_item(scalar_complex_mult);
                break;
                
            case 3: //загрузить тесты из файла и провести тесты

                printf("#### ОТКРЫВАЕМ ФАЙЛ ТЕСТОВ В ДЕЙСТВИТЕЛЬНЫХ ЧИСЛАХ (%s)\n", f_name_test_r);

                scalar_real_mult_test = (float *)malloc(sizeof(float));
                
                input = fopen(file_name_test_r,"rb");
                    if (input == NULL)
                    {
                        printf("Ошибка, невозможно открыть файл на чтение\n");
                        break;
                    }
                fread(&col_test,sizeof(int),1,input);
                printf("##### ПРОВОДИМ ТЕСТЫ ВЕКТОРНОЙ АЛГЕБРЫ, считанные из файла\n");
                printf("----------------------------------------------------------\n");
                for (int i=0;i<col_test; i++)
                {
                    test=0.0;
                    printf("##### ТЕСТ № %d #####:\n",i+1);
                    fread(&xf, sizeof(float), 1, input);
                    fread(&yf, sizeof(float), 1, input);
                    fread(&zf, sizeof(float), 1, input);
                    vector_a_test=New_real(real_Ring, xf, yf, zf,Errors_list);
                    
                    fread(&xf, sizeof(float), 1, input);
                    fread(&yf, sizeof(float), 1, input);
                    fread(&zf, sizeof(float), 1, input);
                    vector_b_test=New_real(real_Ring, xf, yf, zf,Errors_list);
                    
                    fread(&xf, sizeof(float), 1, input);
                    fread(&yf, sizeof(float), 1, input);
                    fread(&zf, sizeof(float), 1, input);
                    vector_sum_test=New_real(real_Ring, xf, yf, zf,Errors_list);
                    
                    fread(&xf, sizeof(float), 1, input);
                    fread(&yf, sizeof(float), 1, input);
                    fread(&zf, sizeof(float), 1, input);
                    vector_mult_test=New_real(real_Ring, xf, yf, zf,Errors_list);
                    
                    fread(scalar_real_mult_test,sizeof(float),1, input);
                    
                    vector_sum=Sum_Vectors(vector_a_test, vector_b_test,Errors_list);
                    
                    vector_mult=Vector_Mult_Vectors2(vector_a_test, vector_b_test,Errors_list);
                    
                    scalar_real_mult=Scalar_Mult_Vectors2(vector_a_test, vector_b_test,Errors_list);
                    
                    Print_Sum_Vector3_test(vector_a_test, vector_b_test, vector_sum, vector_sum_test);
                    Print_Vector_Mult_Vector3_test(vector_a_test, vector_b_test, vector_mult, vector_mult_test);
                    Print_Scalar_Mult_Vector3_test(vector_a_test, vector_b_test, scalar_real_mult, scalar_real_mult_test);
                    
                    vector_test = Dif_Vectors(vector_sum, vector_sum_test,Errors_list);
                    real_test = Scalar_Mult_Vectors2(vector_test, vector_test,Errors_list);
                    test = (*real_test);
                    Free_Vector3(vector_test);
                    real_Ring->Free_item(real_test);
                    
                    vector_test = Dif_Vectors(vector_mult, vector_mult_test,Errors_list);
                    real_test = Scalar_Mult_Vectors2(vector_test, vector_test,Errors_list);
                    test = test + (*real_test);
                    Free_Vector3(vector_test);
                    real_Ring->Free_item(real_test);
                    
                    real_test = real_Ring->Dif(scalar_real_mult, scalar_real_mult_test);
                    test = test + (*real_test);
                    real_Ring->Free_item(real_test);
                    
                    Free_Vector3(vector_sum);
                    Free_Vector3(vector_mult);
                    real_Ring->Free_item(scalar_real_mult);
                    
                    Free_Vector3(vector_a_test);
                    Free_Vector3(vector_b_test);
                    Free_Vector3(vector_sum_test);
                    Free_Vector3(vector_mult_test);
                    
                    
                    if (test==0)
                        printf("тест № %d пройден корректно!\n", i+1);
                    else
                        printf("тест № %d не пройден-ОШИБКА!\n", i+1);
                    printf("----------------------------\n");

                }
                real_Ring->Free_item(scalar_real_mult_test);
                fclose(input);
                
                break;
                
                
            case 4: //загрузить тесты из файла и провести тесты
                printf("#### ОТКРЫВАЕМ ФАЙЛ ТЕСТОВ В КОМПЛЕКСНЫХ ЧИСЛАХ (%s)\n", f_name_test_r);

                scalar_complex_mult_test = (complex_float *)malloc(sizeof(complex_float));
                
                input = fopen(file_name_test_c,"rb");
                    if (input == NULL)
                    {
                        printf("Ошибка, невозможно открыть файл на чтение\n");
                        break;
                    }
                fread(&col_test,sizeof(int),1,input);
                printf("##### ПРОВОДИМ ТЕСТЫ ВЕКТОРНОЙ АЛГЕБРЫ, считанные из файла\n");
                printf("----------------------------------------------------------\n");
                for (int i=0;i<col_test; i++)
                {
                    test_complex1.real = 0.0;
                    test_complex1.imag = 0.0;
                    test_complex2.real = 0.0;
                    test_complex2.imag = 0.0;
                    test_complex3.real = 0.0;
                    test_complex3.imag = 0.0;
                    
                    
                    test=0.0;
                    printf("##### ТЕСТ № %d #####:\n",i+1);
                    fread(&xc, sizeof(complex_float), 1, input);
                    fread(&yc, sizeof(complex_float), 1, input);
                    fread(&zc, sizeof(complex_float), 1, input);
                    vector_a_test=New_complex(complex_Ring, xc, yc, zc,Errors_list);
                    
                    fread(&xc, sizeof(complex_float), 1, input);
                    fread(&yc, sizeof(complex_float), 1, input);
                    fread(&zc, sizeof(complex_float), 1, input);
                    vector_b_test=New_complex(complex_Ring, xc, yc, zc,Errors_list);
                    
                    fread(&xc, sizeof(complex_float), 1, input);
                    fread(&yc, sizeof(complex_float), 1, input);
                    fread(&zc, sizeof(complex_float), 1, input);
                    vector_sum_test=New_complex(complex_Ring, xc, yc, zc,Errors_list);
                    
                    fread(&xc, sizeof(complex_float), 1, input);
                    fread(&yc, sizeof(complex_float), 1, input);
                    fread(&zc, sizeof(complex_float), 1, input);
                    vector_mult_test=New_complex(complex_Ring, xc, yc, zc,Errors_list);
                    
                    fread(scalar_complex_mult_test,sizeof(complex_float),1, input);
                    
                    vector_sum=Sum_Vectors(vector_a_test, vector_b_test,Errors_list);
                    
                    vector_mult=Vector_Mult_Vectors2(vector_a_test, vector_b_test,Errors_list);
                    
                    scalar_complex_mult=Scalar_Mult_Vectors2(vector_a_test, vector_b_test,Errors_list);
                    
                    Print_Sum_Vector3_test(vector_a_test, vector_b_test, vector_sum, vector_sum_test);
                    Print_Vector_Mult_Vector3_test(vector_a_test, vector_b_test, vector_mult, vector_mult_test);
                    Print_Scalar_Mult_Vector3_test(vector_a_test, vector_b_test, scalar_complex_mult, scalar_complex_mult_test);
                    
                    //1 проверка на корректность
                    vector_test = Dif_Vectors(vector_sum, vector_sum_test,Errors_list);
                    complex_test = Scalar_Mult_Vectors2(vector_test, vector_test,Errors_list);
                    test_complex1 = (*complex_test);
                    Free_Vector3(vector_test);
                    complex_Ring->Free_item(complex_test);
                    
                    //2 проверка на корректность
                    vector_test = Dif_Vectors(vector_mult, vector_mult_test,Errors_list);
                    complex_test = Scalar_Mult_Vectors2(vector_test, vector_test,Errors_list);
                    test_complex2 = (*complex_test);
                    Free_Vector3(vector_test);
                    complex_Ring->Free_item(complex_test);
                    
                    //3 проверка на корректность
                    complex_test = real_Ring->Dif(scalar_complex_mult, scalar_complex_mult_test);
                    test_complex3 = (*complex_test);
                    complex_Ring->Free_item(complex_test);
                   
                    if ((test_complex1.real == zero_complex.real) &&
                        (test_complex1.imag == zero_complex.imag) &&
                        (test_complex2.real == zero_complex.real) &&
                        (test_complex2.imag == zero_complex.imag) &&
                        (test_complex3.real == zero_complex.real) &&
                        (test_complex3.imag == zero_complex.imag))
                        printf("тест № %d пройден корректно!\n", i+1);
                    else
                        printf("тест № %d не пройден-ОШИБКА!\n", i+1);
                    printf("----------------------------\n");
                    
                    Free_Vector3(vector_a_test);
                    Free_Vector3(vector_b_test);
                    Free_Vector3(vector_sum);
                    Free_Vector3(vector_sum_test);
                    Free_Vector3(vector_mult);
                    Free_Vector3(vector_mult_test);
                    real_Ring->Free_item(scalar_complex_mult);
                    
                }
                real_Ring->Free_item(scalar_complex_mult_test);
                fclose(input);
                break;
                
            case 5: //сформировать тесты и записать в файл для действительных чисел
                printf("########### СОЗДАЕМ ТЕСТЫ ###########\n");
                printf("-------------------------------------\n");
                printf("ВВЕДИТЕ КОЛИЧЕСТВО ТЕСТОВ:");
                col_test=Hand_input_int();
    
                output = fopen(file_name_test_r, "wb");
                    if (output == NULL)
                    {
                        printf("ошибка, невозможно открыть файл на запись\n");
                        break;
                    }
                fwrite(&col_test,sizeof(int),1,output);
                printf("########### ВВОДИМ ТЕСТЫ ДЛЯ ТЕСТИРОВАНИЯ ВЕКТОРНОЙ АРИФМЕТИКИ В ДЕЙСТВИТЕЛЬНЫХ ЧИСЛАХ ###########\n");
                printf("--------------------------------------------------------------------------------------------------\n");
                for (int i=0;i<col_test;i++)
                {
                    printf("ВЕКТОР <A>:\n");
                    vector_a_test=Hand_input_Vector3_real(real_Ring);
                    fwrite(vector_a_test->x, sizeof(float), 1, output);
                    fwrite(vector_a_test->y, sizeof(float), 1, output);
                    fwrite(vector_a_test->z, sizeof(float), 1, output);
                    
                    printf("-------------\n");
                    printf("ВЕКТОР <B>:\n");
                    vector_b_test=Hand_input_Vector3_real(real_Ring);
                    fwrite(vector_b_test->x, sizeof(float), 1, output);
                    fwrite(vector_b_test->y, sizeof(float), 1, output);
                    fwrite(vector_b_test->z, sizeof(float), 1, output);
                    
                    printf("-------------\n");
                    printf("СУММА ВЕКТОРОВ (А + В):\n");
                    vector_sum_test=Hand_input_Vector3_real(real_Ring);
                    fwrite(vector_sum_test->x, sizeof(float), 1, output);
                    fwrite(vector_sum_test->y, sizeof(float), 1, output);
                    fwrite(vector_sum_test->z, sizeof(float), 1, output);
                    
                    printf("-----------------------\n");
                    printf("ВЕКТОРНОЕ ПРОИЗВЕДЕНИЕ ВЕКТОРОВ (А X В):\n");
                    vector_mult_test=Hand_input_Vector3_real(real_Ring);
                    fwrite(vector_mult_test->x, sizeof(float), 1, output);
                    fwrite(vector_mult_test->y, sizeof(float), 1, output);
                    fwrite(vector_mult_test->z, sizeof(float), 1, output);
                    
                    printf("---------------------------------------:\n");
                    printf("СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ ВЕКТОРОВ (А * В):\n");
                    scalar_real_mult_test = (float*)malloc(sizeof(float));
                    *scalar_real_mult_test=Hand_input_real();
                    fwrite(scalar_real_mult_test, sizeof(float), 1, output);
                    
                    printf("----------------------------------------\n");
    
                    Free_Vector3(vector_a_test);
                    Free_Vector3(vector_b_test);
                    Free_Vector3(vector_sum_test);
                    Free_Vector3(vector_mult_test);
                    real_Ring->Free_item(scalar_real_mult_test);
                };
                fclose(output);
                printf("файл тестов в действительных числах записан (записано %d тестов)\n", col_test);
                break;
                
            case 6: //сформировать тесты и записать в файл для комплексных чисел
                printf("########### СОЗДАЕМ ТЕСТЫ ###########\n");
                printf("-------------------------------------\n");
                printf("ВВЕДИТЕ КОЛИЧЕСТВО ТЕСТОВ:");
                col_test=Hand_input_int();
    
                output = fopen(file_name_test_c,"wb");
                    if (output == NULL)
                    {
                        printf("ошибка, невозможно открыть файл на запись\n");
                        break;
                    }
                fwrite(&col_test,sizeof(int),1,output);
                printf("########### ВВОДИМ ТЕСТЫ ДЛЯ ТЕСТИРОВАНИЯ ВЕКТОРНОЙ АРИФМЕТИКИ В ДЕЙСТВИТЕЛЬНЫХ ЧИСЛАХ ###########\n");
                printf("--------------------------------------------------------------------------------------------------\n");
                for (int i=0;i<col_test;i++)
                {
                    printf("ВЕКТОР <A>:\n");
                    vector_a_test=Hand_input_Vector3_complex(complex_Ring);
                    fwrite(vector_a_test->x, sizeof(complex_float), 1, output);
                    fwrite(vector_a_test->y, sizeof(complex_float), 1, output);
                    fwrite(vector_a_test->z, sizeof(complex_float), 1, output);
                    
                    
                    printf("-------------\n");
                    printf("ВЕКТОР <B>:\n");
                    vector_b_test=Hand_input_Vector3_complex(complex_Ring);
                    fwrite(vector_b_test->x, sizeof(complex_float), 1, output);
                    fwrite(vector_b_test->y, sizeof(complex_float), 1, output);
                    fwrite(vector_b_test->z, sizeof(complex_float), 1, output);
                    
                    printf("-------------\n");
                    printf("СУММА ВЕКТОРОВ (А + В):\n");
                    vector_sum_test=Hand_input_Vector3_complex(complex_Ring);
                    fwrite(vector_sum_test->x, sizeof(complex_float), 1, output);
                    fwrite(vector_sum_test->y, sizeof(complex_float), 1, output);
                    fwrite(vector_sum_test->z, sizeof(complex_float), 1, output);
                    
                    printf("-----------------------\n");
                    
                    printf("ВЕКТОРНОЕ ПРОИЗВЕДЕНИЕ ВЕКТОРОВ (А X В):\n");
                    vector_mult_test=Hand_input_Vector3_complex(complex_Ring);
                    fwrite(vector_mult_test->x, sizeof(complex_float), 1, output);
                    fwrite(vector_mult_test->y, sizeof(complex_float), 1, output);
                    fwrite(vector_mult_test->z, sizeof(complex_float), 1, output);
                    
                    
                    printf("---------------------------------------:\n");
                    printf("СКАЛЯРНОЕ ПРОИЗВЕДЕНИЕ ВЕКТОРОВ (А * В):\n");
                    scalar_complex_mult_test = (complex_float*)malloc(sizeof(complex_float));
                    *scalar_complex_mult_test=Hand_input_complex();
                    fwrite(scalar_complex_mult_test, sizeof(complex_float), 1, output);
                    
                    printf("----------------------------------------\n");
                    
                    Free_Vector3(vector_a_test);
                    Free_Vector3(vector_b_test);
                    Free_Vector3(vector_sum_test);
                    Free_Vector3(vector_mult_test);
                    real_Ring->Free_item(scalar_complex_mult_test);
    
                };
                fclose(output);
                printf("файл тестов в действительных числах записан (записано %d тестов)\n", col_test);
                break;

        }
    }

    return 0;
}

