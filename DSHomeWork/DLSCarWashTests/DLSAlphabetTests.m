//
//  DLSAlphabetTests.m
//  DSHomeWork
//
//  Created by Denis Surzhan on 02.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "NSString+DLSStringExtensions.h"

#import "DLSAlphabet.h"
#import "DLSClusterAlphabet.h"
#import "DLSRangeAlphabet.h"
#import "DLSStringAlphabet.h"

@interface DLSAlphabetTests : XCTestCase

@end

@implementation DLSAlphabetTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)performAlphabetTest {
    NSArray *alphabetStrings = [[[NSArray alloc] initWithObjects:@"string1", @"string2", nil] autorelease];
    DLSAlphabet *alphabet = [DLSAlphabet alphabetWithStrings:alphabetStrings];
    
    DLSAlphabet *uppercaseAlphabet = [DLSAlphabet alphabetWithRange:NSMakeRange('A', 'Z' - 'A' + 1)];
    DLSAlphabet *lowercaseAlphabet = [DLSAlphabet alphabetWithRange:NSMakeRange('a', 'z' - 'a' + 1)];
    DLSAlphabet *numericAlphabet = [DLSAlphabet alphabetWithRange:NSMakeRange('0', '9' - '0' + 1)];
    
    NSArray *alphabetCluster = [[[NSArray alloc] initWithObjects:uppercaseAlphabet,
                                 lowercaseAlphabet,
                                 numericAlphabet,
                                 nil] autorelease];
    alphabet = [DLSAlphabet alphabetWithAlphabets:alphabetCluster];
    NSLog(@"%@", alphabet);
    NSLog(@"%lu", [alphabet count]);
    NSLog(@"%@", [alphabet string]);
    
    alphabet = nil;
                                   
    XCTAssert(YES, @"Pass");
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
