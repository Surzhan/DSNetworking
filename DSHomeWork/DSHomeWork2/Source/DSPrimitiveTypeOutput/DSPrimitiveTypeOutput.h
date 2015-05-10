//
//  DSPrimitiveTypeOutput.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 10.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef DSHomeWork_DSPrimitiveTypeOutput_h
#define DSHomeWork_DSPrimitiveTypeOutput_h

#include <stdio.h>


/*
 1. Создать макрос, который бы генерировал метод для вывода в консоль значения любого примитивного типа. У макроса 
 должно быть 2 параметра: тип, спецификатор вывода. При препроцессинге макрос должен создавать метод output_type, 
 где вместо type должен быть подставлен тип, который мы выводим данным сгенерированным методом. Создать второй макрос,
 который бы занимался вызовом сгенерированного первым макросом метода, на вход должен получать тип метода и величину.
 Требования:
 - создать тестовые методы для проверки того, как работает генерация на всех примитивных типах.
 */

#define DSValueOutput(type, specifier) \
    void DSOutput_##type(type value) { \
    printf(#type " value = " #specifier "\n", value); \
}

#define DSTypeOutput(type, value) \
    DSOutput_##type(value)

#endif
