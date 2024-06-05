//
//  SSWbaesLib.h
//  SSWbaesLib
//
//  Created by Gong,Jialiang on 2021/9/16.
//  Copyright © 2021 bang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

__attribute__((visibility("default")))
@interface SSWbaesLib : NSObject

/**
 返回单例对象
 */
+ (instancetype)sharedInstance;

/**
 加密模块初始化，初始化成功后才可进行文件加密

 @param keyBytes 加密Key指针
 @return 加密是否成功
 */
- (BOOL)encryptInitWithKeyBytes:(const char *)keyBytes;

/**
 加密文件

 @param originBytes 文件的数据指针
 @param length 数据长度
 @return 加密后的数据
 */
- (NSData*)encryptWithOriginBytes:(const char *)originBytes length:(NSUInteger)length;

/**
 图片变换加密

 @param originImageData 原始图片数据
 @return 加密后的二进制图片
 */
- (NSData *)safeTransformImage:(NSData *)originImageData;

@end
