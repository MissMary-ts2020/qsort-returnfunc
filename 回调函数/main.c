#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>



int compare_double(const void* p1, const void* p2) {//为了迎合库函数的参数列表
    //void*类型的指针不能直接进行解引用，必须首先进行强制类型转换
    if (*(double*)p1 > *(double*)p2) {//但是实际上还要强制转换成正确的样子
        return -1;
    }
    if (*(double*)p1 == *(double*)p2) {
        return 0;
    }
    if (*(double*)p1 < *(double*)p2) {
        return 1;
    }
    //return (int)(*(double*)p1 - *(double*)p2);//这样写成做差也可以，不拘是多少
}//需要自己设计一个比较函数,通过这个函数>,<的条件还可以调整从大到小或从小到大


typedef struct stu {
    char name[20];
    int age;
}stu;


int compare_studentage(const void* p1, const void* p2) {//为了迎合库函数的参数列表
    //if (((stu*)p1)->age <  ((stu*)p2)->age) {//但是实际上还要强制转换成正确的样子
    //    return -2;
    //}
    //if (((stu*)p1)->age == ((stu*)p2)->age) {
    //    return 0;
    //}
    //if (((stu*)p1)->age > ((stu*)p2)->age) {
    //    return 2;
    //}
    //return 2;
    //其实也可以作差
    return (((stu*)p1)->age - ((stu*)p2)->age);
}



int main(void) {
    
    double arr1[10] = {
        1.0,3.0,5.0,2.2345246,4.0,6.0,9.0,5.6,5.3,8.2
    };
    qsort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(double), compare_double);
    int i = 0;
    for (; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
        printf("%lf\n", arr1[i]);
    }

    stu arr_stu[3] = {
        {"张三",24},{"李斯",10},{"王五",13}
    };

    qsort(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]), sizeof(stu), compare_studentage);
    for (i = 0; i < sizeof(arr_stu) / sizeof(arr_stu[0]); i++) {
        printf("第%d位，姓名%s，年龄%d\n", i, arr_stu[i].name, arr_stu[i].age);
    }
    
    
    return 0;
}