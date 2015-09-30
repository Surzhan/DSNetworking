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

#define DLSEmptyMacro

#define DLSStrongifyAndReturnResultIfNil(object, result) \
    DLSStrongify(object); \
    if (!object) { \
        return result; \
    }

#define DLSStrongifyAndReturnIfNil(object) \
    DLSStrongifyAndReturnResultIfNil(object, DLSEmptyMacro)

#define DLSStrongifyAndReturnNilIfNil(object) \
    DLSStrongifyAndReturnResultIfNil(object, nil)

#define DLSWeakify(object) \
    __weak __typeof(object) __DLSWeak_##object = object

#define DLSStrongify(object) \
    __strong __typeof(object) object = __DLSWeak_##object
