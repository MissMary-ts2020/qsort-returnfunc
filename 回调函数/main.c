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
    //return (int)(*(double*)p1 - *(double*)p2);//这样写成做差不行，因为double->int会出问题
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
    return (((stu*)p1)->age - ((stu*)p2)->age);//整数做差没问题
}
typedef int(*compare_func)(const void*, const void*);

void Swap(char* buf1, char* buf2,int width) {
    int i = 0;
    for (; i < width; i++) {
        char tmp = *(buf1+i);
        *(buf1+i) = *(buf2+i);
        *(buf2 + i) = tmp;
    }
    return;
}

void bubble(void* base, int size, int width,compare_func compare_func) {
    int flag = 1,i=0;
    while (flag) {
        flag = 0;
        for (i = 0; i < size; i++) {
            if (compare_func(((char*)base + i * width), ((char*)base + (i + 1) * width))>0) {
                //void不能直接使用(0个字节)，先强制赋char*，让它变成一个字节；然后+i*width来定位到待比较对象的开始地址
                //交换
                flag = 1;
                Swap((char*)base + i * width, (char*)base + (i + 1) * width, width);
            
            }
        }
    }
}

int main(void) {
    int i = 0;
    /*double arr1[10] = {
        1.0,3.0,5.0,2.2345246,4.0,6.0,9.0,5.6,5.3,8.2
    };
    qsort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(double), compare_double);
    
    for (; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
        printf("%lf\n", arr1[i]);
    }*/

    stu arr_stu[3] = {
        {"张三",24},{"李斯",10},{"王五",13}
    };

    bubble(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]), sizeof(stu), compare_studentage);
    for (i = 0; i < sizeof(arr_stu) / sizeof(arr_stu[0]); i++) {
        printf("第%d位，姓名%s，年龄%d\n", i, arr_stu[i].name, arr_stu[i].age);
    }
    
    
    return 0;
}