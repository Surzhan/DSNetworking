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

enum DSHumanGender {
    kDSHumanUndefined,
    kDSHumanMale,
    kDSHumanFemale,
};

struct DSHuman {
    char *_name;
    DSHuman *_father;
    DSHuman *_mother;
    DSHuman *_partner;
    DSHuman *_children[20];
    DSHumanGender _sex;
    uint8_t _age;
    int _childrenCount;
    bool _isMarried;
};

extern
DSHuman DSHumanCreate (char *name, DSHumanGender DSHumanGender, uint8_t age);

extern
void DSHumanSetAge (DSHuman *human, int newAge);

extern
DSHuman DSHumanGetAge (DSHuman *human);

extern
void DSHumanSetMarried(DSHuman *human, bool married);

extern
bool DSHumanGetMarried(DSHuman *human);

extern
void DSHumanSetMother (DSHuman *human, DSHuman *mother);

extern
DSHuman DSHumanGetMother (DSHuman *human);

extern
void DSHumanSetFather (DSHuman *human, DSHuman *father);

extern
DSHuman DSHumanGetFather (DSHuman *human);





#endif /* defined(__DSHomeWork__DSHumanStructure__) */
