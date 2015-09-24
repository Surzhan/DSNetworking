//
//  DLSMacros.h
//  DLSiOSProject
//
//  Created by Denis Surzhan on 15.09.15.
//  Copyright (c) 2015 IDAPGroupCollege. All rights reserved.
//

#define DLSDefineBaseViewProperty(propertyName, viewClass) \
    @property (nonatomic, readonly) viewClass   *propertyName;

#define DLSViewGetterSynthesize(selector, viewClass) \
    - (viewClass *)selector { \
        if ([self isViewLoaded] && [self.view isKindOfClass:[viewClass class]]) { \
            return (viewClass *)self.view; \
        } \
        \
        return nil; \
    }

#define DLSViewControllerBaseViewProperty(viewControllerClass, propertyName, viewClass) \
    @interface viewControllerClass (__##viewClass_##propertyName) \
    DLSDefineBaseViewProperty(propertyName, viewClass) \
    \
    @end \
    \
    @implementation viewControllerClass (__##viewClass_##propertyName) \
    \
    @dynamic propertyName; \
    \
    DLSViewGetterSynthesize(propertyName, viewClass) \
    \
    @end

#define DLSWeakify(var) \
    __weak __typeof(var) __DLSWeak_##var = var

#define DLSStrongify(var) \
    __strong __typeof(var) var = __DLSWeak_##var

#define DLSStrongifyAndReturnIfNil(var) \
    DLSStrongify(var); \
    if (!var) { \
        return; \
    }
