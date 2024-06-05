//
//  PASSMethodCallTransfer.h
//  PassportKit
//
//  Created by Gang,Liu on 2019/9/26.
//  Copyright © 2019 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const PASSParamValueTypeBduss;
FOUNDATION_EXPORT NSString * const PASSParamValueTypeUid;

@interface PASSParamAppendModel : NSObject
/*
 原始参数，如果是NSDictionary、自定义object，内部会使用setValue:forKey:赋值，
 NSString类型，覆盖处理
 其他类型,如NSArray、BOOL、int等不处理
  */
@property (nullable, nonatomic, strong) id originParam;
/*
 { @"bduss":PASSParamValueTypeBduss,
   @"uid":PASSParamValueTypeUid }
 */
@property (nullable, nonatomic, strong) NSDictionary <NSString *, NSString *> *extraParams;

@end

@interface PASSMethodCallTransfer : NSObject

typedef NS_ENUM(NSInteger, PASSDynamicErrorType) {
    PASSDynamicErrorTypeUnknown = -1000,    //未知错误
    PASSDynamicErrorTypeNotLogin = -1001,   //用户未登录
    PASSDynamicErrorTypeNoMethod = -1002,   //找不到要调用的方法
    PASSDynamicErrorTypeParamError = -1003  //参数有误
};

/**
 *  pass封装动态方法调用者，用于在调用方法时动态插入uid、bduss值
 *
 * @param executorObj  方法执行对象
 * @param methodName   需要执行的方法名称
 * @param params       方法执行参数，如果需要插入uid、bduss，请包装成PASSParamAppendModel
 * @param failure      方法动态执行过程中出现的错误
 * @return 返回值，返回值如果为基本数据类型，会包装成NSValue
*/
+ (id)dynamicCall:(id)executorObj method:(SEL)methodName params:(NSArray *)params failure:(void (^)(NSError *))failure;

@end

NS_ASSUME_NONNULL_END
