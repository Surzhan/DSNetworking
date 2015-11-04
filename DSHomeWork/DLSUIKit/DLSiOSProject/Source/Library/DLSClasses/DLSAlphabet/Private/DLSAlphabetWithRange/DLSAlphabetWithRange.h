//
//  DLSAlphabetWithRange.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 28.10.15.
//  Copyright © 2015 IDAPGroupCollege. All rights reserved.
//

#import "DLSAlphabet.h"

@interface DLSAlphabetWithRange : DLSAlphabet

- (id)initWithUnicodeRange:(NSRange)range;

@end
