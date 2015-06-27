//
//  DSHumanStructure.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 18.05.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#ifndef __DSHomeWork__DSHumanStructure__
#define __DSHomeWork__DSHumanStructure__

#include <stdio.h>
#include <stdbool.h>

#include "DSObject.h"
#include "DSArray.h"
#include "DSString.h"
#include "DSMacros.h"

/*
 1. Создать объектную структуру данных человек, имеющую поля имя, возраст, пол, количество детей, женат или нет, 
 указатель на партнера, на родителей и на массив с детьми, где могло бы быть, максимум, 20 детей.
 Требования:
 - каждая из сущностей, будь то строка или массив, должны быть обернуты в свой объект, который, как минимум, умел бы выполнять подсчет ссылок и имел базовые аксессоры и тесты;
 - реализовать подсчет ссылок, геттеры и сеттеры для полей;
 - реализовать метод жениться, который бы устанавливал поле женат в true и указатель на партнера, с которым был брак;
 - реализовать метод развестись, который бы устанавливал поле женат и указатель на партнера;
 - реализовать метод произвести потомство, который бы создавал ребенка, устанавливал ему родителей, а у родителей
 добавлял бы ребенка;
 - создать тесты на все поведение человека;
 
 2. Добавить в человека универсальное управление памятью;
 
 3. Переделать объект массива детей, который бы с помощью realloc мог расширяться или сужаться.
 Требования:
 - подсчет ссылок;
 - расширение или сужение на любое количество элементов с сохранением текущих данных/их усечением;
 - покрытие тестами.
 4. Написать описательную часть BDD-тестов для всех значимых поведений всех объектов (хуман, строка, массив)
 
 */

typedef struct DSHuman DSHuman;
typedef enum DSHumanGender DSHumanGender;

extern const uint kDSMinAgeForMarriage;

enum DSHumanGender {
    kDSHumanUndefined,
    kDSHumanMale,
    kDSHumanFemale,
};

struct DSHuman {
    DSObject _super;
    
    char *_name;
    DSHuman *_father;
    DSHuman *_mother;
    DSHuman *_partner;
    DSArray *_children;
    DSHumanGender _gender;
    uint8_t _age;
};

extern
DSHuman *DSHumanCreateWithParameters(DSHumanGender DSHumanGender);

extern
void DSHumanAddChild(DSHuman *human, DSHuman *child);

extern
void DSHumanRemoveChild(DSHuman *human, DSHuman *child);

extern
uint64_t DSHumanGetChildrenCount(DSHuman *human);

extern
void DSHumanSetName(DSHuman *human, char *name);

extern
char *DSHumanGetName(DSHuman *human);

extern
void DSHumanSetAge(DSHuman *human, uint8_t newAge);

extern
uint8_t DSHumanGetAge(DSHuman *human);

extern
void DSHumanSetGender(DSHuman *human, DSHumanGender gender);

extern
DSHumanGender DSHumanGetGender(DSHuman *human);
                         
extern
DSHuman *DSHumanGetPartner(DSHuman *human);

extern
DSHuman *DSHumanGetMother(DSHuman *human);

extern
DSHuman *DSHumanGetFather(DSHuman *human);

extern
void DSHumanMarried(DSHuman *human, DSHuman *partner);

extern
void DSHumanDivorce(DSHuman *human);

extern
bool DSHumanIsMarried(DSHuman *human);


#endif /* defined(__DSHomeWork__DSHumanStructure__) */
