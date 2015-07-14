//
//  DLSHuman.h
//  DSHomeWork
//
//  Created by Denis Surzhan on 06.07.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

/*
 Задание 1.
 Условие:
 Есть существо, у существа есть typedef пола, есть строка имени, есть масса, есть возраст, есть массив детей.
 Существо умеет воевать и рожать детей. При родах существо не добавляет к себе ребенка автоматом.
 Существо умеет добавит к себе детей и удалить. Существо умеет говорить "Привет!", причем, когда существо говорит
 привет, то сначала говорит оно, а потом все его дети (значит и дети детей, и т.д.).
 Задание:
 1. Написать класс существа;
 2. Создать несколько существ и положить их в массив, каждому из существ добавить детей;
 3. В цикле пройти по массиву существ и проверить их пол. Если мужик, то надо отправить существо воевать, если баба,
 то рожать детей;
 4. У существа наружу должен быть немутабельный массив детей через динамическое проперти с копи+авторелиз, а внутри -
 еще и мутабельное свойство.
 
 Задание 2.
 Условие:
 Дано существо из задания 1.
 Задание:
 1. Убрать переменную пол из существа, а также умение воевать и рожать детей;
 2. Вместо нее создать наследников существа: мужское и женское существо;
 3. Мужское существо умеет воевать, женское - рожать детей;
 4. Создать метод performGenderSpecificOperation у родительского существа, который ничего не делает, мужское существо по вызову этого метода идет воевать, женское рожает детей;
 5. Создать массив существ, в котором бы лежали только мужчины и женщины, пройтись по нему через for
 (Creature *creature in creatures) и вызвать метод performGenderSpecificOperation, которой, в зависимости от пола
 существа приведет либо к войне, либо к родам -> Подчеркнуть, что это - полиморфизм, значит, охуенно.
 6. Заменить alloc init autorelease на NSOBject категорию с методом object
 */

#import <Foundation/Foundation.h>

typedef enum DLSHumanGender {
    kDLSHumanMale,
    kDLSHumanFemale,
} DLSHumanGender;

@interface DLSHuman : NSObject

@property (nonatomic, copy)                 NSString        *name;
@property (nonatomic, copy, readonly)       NSArray         *children;
@property (nonatomic, assign)               DLSHumanGender  gender;
@property (nonatomic, assign)               NSUInteger        age;
@property (nonatomic, assign)               float           weight;

- (instancetype)initWithName:(NSString *)name
                         age:(NSUInteger)age;
- (void)sayHello;
- (void)addChild:(DLSHuman *)child;
- (void)removeChild:(DLSHuman *)child;
- (id)performGenderSpecificOperation;


@end
