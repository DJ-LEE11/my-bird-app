//
//  NSObject+PASSRuntime.h
//  PassportKit
//
//  Created by jiangzhenjie on 2017/4/1.
//  Copyright © 2017年 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (PASSRuntime)

- (void)pass_performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2 withObject:(id)object3;

+ (NSString*)getPropertyType:(NSString*)property;

@end
