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
typedef struct DSStructureOptimized DSStructureOptimized;

struct DSStructureRandom {
    bool _random1;
    long long _random9;
    bool _random3;
    double _random14;
    bool _random4;
    short _random11;
    bool _random6;
    float _random7;
    int _random8;
    char *_random15;
    short _random10;
    bool _random5;
    short _random12;
    bool _random2;
    short _random13;
    
    
};

struct DSStructureOptimized {
    double _random14;
    long long _random9;
    char *_random15;
    int _random8;
    float _random7;
    short _random10;
    short _random11;
    short _random12;
    short _random13;
    union {
        struct {
            bool _random1:1;
            bool _random2:1;
            bool _random3:1;
            bool _random4:1;
            bool _random5:1;
            bool _random6:1;
        } flags;
        uint16_t bitFields;
    };
    
};


#endif /* defined(__DSHomeWork__DSCreateStructure__) */
