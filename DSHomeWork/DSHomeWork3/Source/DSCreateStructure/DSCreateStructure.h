//
//  DSCreateStructure.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 10.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSCreateStructure__
#define __DSHomeWork__DSCreateStructure__

#include <stdio.h>
#include <stdbool.h>

/*
 1. Создать структуру, данных, хранящую в себе расположенные в случайном порядке 6 bool, 1 float, 1 int, 1 long long, 3 short, 1 double, 1 указатель на строку.
 Примечание:
 - Дополнитель должны быть объявлены и протестированы еще 2 варианта оригинальной структуры:
 1) все поля перекомпонованы так, чтобы структура имела минимальный размер (sizeof);
 2) вариант 2 с union для переменных типа bool (поместить bool значения в битовое поле и создать union);
 Требования:
 - создать тестовый метод, который бы с помощью offsetof выводил расположение каждого из элементов структуры;
 - создать тестовый метод, который бы выводил размер всей структуры;
 2. Создать универсальный метод для вывода битов числа (различных типов) в консоль.
 */

typedef struct DSStructureRandom DSStructureRandom;
typedef struct DSStructureOptimize DSStructureOptimize;
typedef struct DSStructureOptimizedWithUnion DSStructureOptimizedWithUnion;

struct DSStructureRandom {
    bool _bool1;
    long long _longlong1;
    bool _bool2;
    double _double1;
    bool _bool3;
    short _short1;
    bool _bool4;
    float _float1;
    int _int1;
    char *_char1;
    short _shot2;
    bool _bool5;
    short _short3;
    bool _bool6;
    
};

struct DSStructureOptimize {
    double _double1;
    long long _longlong1;
    char *_char1;
    int _int1;
    float _float1;
    short _short1;
    short _short2;
    short _short3;
    bool _bool1;
    bool _bool2;
    bool _bool3;
    bool _bool4;
    bool _bool5;
    bool _bool6;
       
    };

struct DSStructureOptimizedWithUnion {
    double _double1;
    long long _longlong1;
    char *_char1;
    int _int1;
    float _float1;
    short _short1;
    short _short2;
    short _short3;
    union {
        struct {
            bool _bool1:1;
            bool _bool2:1;
            bool _bool3:1;
            bool _bool4:1;
            bool _bool5:1;
            bool _bool6:1;
        } flags;
        char bitFields;
    };
    
};


#endif /* defined(__DSHomeWork__DSCreateStructure__) */
