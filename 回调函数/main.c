#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>



int compare_double(const void* p1, const void* p2) {//Ϊ��ӭ�Ͽ⺯���Ĳ����б�
    //void*���͵�ָ�벻��ֱ�ӽ��н����ã��������Ƚ���ǿ������ת��
    if (*(double*)p1 > *(double*)p2) {//����ʵ���ϻ�Ҫǿ��ת������ȷ������
        return -1;
    }
    if (*(double*)p1 == *(double*)p2) {
        return 0;
    }
    if (*(double*)p1 < *(double*)p2) {
        return 1;
    }
    //return (int)(*(double*)p1 - *(double*)p2);//����д������У���Ϊdouble->int�������
}//��Ҫ�Լ����һ���ȽϺ���,ͨ���������>,<�����������Ե����Ӵ�С���С����


typedef struct stu {
    char name[20];
    int age;
}stu;



int compare_studentage(const void* p1, const void* p2) {//Ϊ��ӭ�Ͽ⺯���Ĳ����б�
    //if (((stu*)p1)->age <  ((stu*)p2)->age) {//����ʵ���ϻ�Ҫǿ��ת������ȷ������
    //    return -2;
    //}
    //if (((stu*)p1)->age == ((stu*)p2)->age) {
    //    return 0;
    //}
    //if (((stu*)p1)->age > ((stu*)p2)->age) {
    //    return 2;
    //}
    //return 2;
    //��ʵҲ��������
    return (((stu*)p1)->age - ((stu*)p2)->age);//��������û����
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
                //void����ֱ��ʹ��(0���ֽ�)����ǿ�Ƹ�char*���������һ���ֽڣ�Ȼ��+i*width����λ�����Ƚ϶���Ŀ�ʼ��ַ
                //����
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
        {"����",24},{"��˹",10},{"����",13}
    };

    bubble(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]), sizeof(stu), compare_studentage);
    for (i = 0; i < sizeof(arr_stu) / sizeof(arr_stu[0]); i++) {
        printf("��%dλ������%s������%d\n", i, arr_stu[i].name, arr_stu[i].age);
    }
    
    
    return 0;
}