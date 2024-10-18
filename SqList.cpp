//
//  顺序表的实现 - 复数计算器 - C0RE算法
//  SqList
//  Created by Leo Zhang on 9/6/24.
//

#include <iostream>

#define MAXSIZE 100010
using namespace std;

typedef struct Exponential {
    float real;
    float imag;
} Exponential;

typedef struct SqList {
    Exponential *elem;   // 只有声明了*指针变量才能创建并操作数组！！
    int length;
} SqList;

// 初始化线性表
bool initList(SqList &lst) {
    lst.elem = new Exponential[MAXSIZE];
    lst.length = 0;
    return lst.elem != nullptr;
}

// 添加多项式
void addExp(SqList &lst, const Exponential &exp) {
    if (lst.length >= MAXSIZE) {
        cout << "SqList is full!" << endl;
        return;
    }
    lst.elem[lst.length] = exp;
    lst.length++;
}

// 获得顺序表内容
int getExp(const SqList &lst, int i) {
    if (i < 1 || i > lst.length) {
        return 1;
    }
    cout << "Exp No." << i << ": " << lst.elem[i - 1].real << "+" << lst.elem[i - 1].imag << "i" << endl;
    return 0;
}

// 销毁与清空顺序表
void destroyList(SqList &lst) {
    if (lst.elem != nullptr) {
        delete[] lst.elem;
        lst.elem = nullptr;
    }
    lst.length = 0;
}

int getLength(SqList &lst) {
    return lst.length;
}

bool isEmpty(const SqList &lst) {
    return lst.length == 0;
}

// 查找元素
int locateExp(const SqList lst, const Exponential exp) {
    for (int i = 0; i < lst.length; i++) {
        if (lst.elem[i].real == exp.real && lst.elem[i].imag == exp.imag) {
            return i + 1;
        }
    }
    return 0;
}

// 插入元素
int listInsert(SqList &lst, int i, const Exponential Exp) {
    if (i < 1 || i > lst.length + 1)
        return -1;
    if (lst.length >= MAXSIZE)
        return -1;
    for (int j = lst.length - 1; j >= i - 1; j--)
        lst.elem[j + 1] = lst.elem[j];

    lst.elem[i - 1] = Exp;
    lst.length++;
    return 0;
}

// 删除元素
Exponential listDelete(SqList &lst, int i) {
    if (i < 1 || i > lst.length)
        return Exponential{0, 0}; // Return a default Exponential if index is OOB
    Exponential deleteElem = lst.elem[i - 1]; // Corrected index to i - 1
    for (int j = i - 1; j < lst.length - 1; j++)
        lst.elem[j] = lst.elem[j + 1];
    lst.elem[lst.length - 1] = Exponential{0, 0};
    lst.length--;
    return deleteElem;
}

// 复数相加
void addExpLst(const SqList &lst, SqList &result) {
    if (lst.length==0) return;
    Exponential newExp = lst.elem[0];
    for (int i = 1; i < lst.length; ++i) {
        newExp.real += lst.elem[i].real;
        newExp.imag += lst.elem[i].imag;
    }
    addExp(result, newExp);
}

// 复数减法
void subExpLst(const SqList &lst, SqList &result) {
    if (lst.length==0) return;
    Exponential newExp = lst.elem[0];
    for (int i = 1; i < lst.length; ++i) {
        newExp.real -= lst.elem[i].real;
        newExp.imag -= lst.elem[i].imag;
    }
    addExp(result, newExp);
}

// 复数乘法
void mulExpLst(const SqList &lst, SqList &result) {
    if (lst.length==0) return;
    Exponential newExp = lst.elem[0];
    for (int i = 1; i < lst.length; ++i) {
        float newReal = newExp.real * lst.elem[i].real - newExp.imag * lst.elem[i].imag;
        float newImag = newExp.real * lst.elem[i].imag + newExp.imag * lst.elem[i].real;
        newExp.real = newReal, newExp.imag = newImag;
    }
    addExp(result, newExp);
}

// 复数除法
void divExpLst(const SqList &lst, SqList &result) {
    if (lst.length==0) return;
    Exponential newExp = lst.elem[0];
    for (int i = 1; i < lst.length; ++i) {
        float denominator = lst.elem[i].real * lst.elem[i].real + lst.elem[i].imag * lst.elem[i].imag;
        if (denominator == 0) { //分母为0
            cout << "Division by zero!" << endl;
            return;
        }
        float real = (newExp.real * lst.elem[i].real + newExp.imag * lst.elem[i].imag) / denominator;
        float imag = (newExp.imag * lst.elem[i].real - newExp.real * lst.elem[i].imag) / denominator;
        newExp.real = real;
        newExp.imag = imag;
    }
    addExp(result, newExp);
}

int main() {
    SqList exp, result;
    initList(exp);
    initList(result);

    float real, imag;
    printf("------compNum Calculator------\nplease input 1st number's real part and image part(use space to separate):");
    scanf("%f %f", &real, &imag);
    addExp(exp, Exponential{real, imag});
    printf("input 2nd number's real part and image part:");
    scanf("%f %f", &real, &imag);
    addExp(exp, Exponential{real, imag});

    printf("\ntwo numbers're:\n");
    for (int i = 1; i <= exp.length; i++) {
        getExp(exp, i);
    }

    char flag;
    printf("input operator(+-*/):");
    scanf(" %c", &flag);
    if (flag == '+') addExpLst(exp, result);
    if (flag == '-') subExpLst(exp, result);
    if (flag == '*') mulExpLst(exp, result);
    if (flag == '/') divExpLst(exp, result);

    getExp(result, 1);

    destroyList(exp);
    destroyList(result);
    return 0;
}
