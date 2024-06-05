//
//  SAPILogger.h
//  SecurityCenter
//
//  Created by zhoukeke on 14-3-13.
//  Copyright (c) 2014年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SAPILogVerbose(frmt, ...)  \
[SAPILogger logWithClass:[self class] function:__func__ line:__LINE__ format:(frmt), ## __VA_ARGS__]

#define SAPILogInfo(frmt, ...)  \
[SAPILogger logWithClass:[self class] function:__func__ line:__LINE__ format:(frmt), ## __VA_ARGS__]

#define SAPILogWarn(frmt, ...)  \
[SAPILogger logWithClass:[self class] function:__func__ line:__LINE__ format:(frmt), ## __VA_ARGS__]

#define SAPILogError(frmt, ...)  \
[SAPILogger logWithClass:[self class] function:__func__ line:__LINE__ format:(frmt), ## __VA_ARGS__]

#define SAPILog(frmt, ...) \
[SAPILogger logWithClass:[self class] function:__func__ line:__LINE__ format:(frmt), ## __VA_ARGS__]

@interface SAPILogger : NSObject

+ (void)logWithClass:(Class)cls
            function:(const char *)function
                line:(NSUInteger)line
              format:(NSObject *)format, ...;

@end
