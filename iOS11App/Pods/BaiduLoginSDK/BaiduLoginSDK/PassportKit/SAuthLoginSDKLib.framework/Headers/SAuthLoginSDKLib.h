//
//  SAuthLoginSDKLib.h
//  v1.4.5
//
//  Created by Gong,Jialiang on 2020/1/6.
//  Copyright © 2020年 Gong,Jialiang. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SALoginCarrierType) {
    SALoginCarrierTypeDefault = 0,
    SALoginCarrierTypeChinaMobile = 1, // 中国移动
    SALoginCarrierTypeChinaUnicom = 2, // 中国联通
    SALoginCarrierTypeChinaTelecom = 3, //中国电信
};


@interface SAuthLoginSDKLib : NSObject

/**
 * SDK初始化接口
 @param appKey     初始化SDK需要的参数，需要提前申请
 @param secretKey     初始化SDK需要的参数，需要提前申请
 @param userInfo     初始化SDK需要的参数，用户的自定义参数
 */
+ (void)startSDKWithAppKey:(NSString *)appKey secretKey:(NSString *)secretKey userInfo:(NSDictionary *)userInfo;

/**
 预登录接口

 @param timeout 接口响应超时时间
 @param completion 回调结果
 */
+ (void)preAuthLoginWithTimeout:(NSTimeInterval)timeout completion:(void(^)(NSString *resultString))completion;


/**
 登录接口

 @param timeout 接口响应超时时间
 @param jsonString 登录透传参数
 @param completion 回调结果
 */
+ (void)authLoginWithTimeout:(NSTimeInterval)timeout parameters:(NSString *)jsonString completion:(void(^)(NSString *resultString))completion;

/**
本机号码验证，预登录接口

@param timeout 接口响应超时时间
@param completion 回调结果
*/
+ (void)preMobileAuthWithTimeout:(NSTimeInterval)timeout completion:(void(^)(NSString *resultString))completion;

/**
本机号码验证，验证接口

@param timeout 接口响应超时时间
@param completion 回调结果
*/
+ (void)mobileAuthWithTimeout:(NSTimeInterval)timeout parameters:(NSString *)jsonString completion:(void(^)(NSString *resultString))completion;

/**
弹出登录页面

*/
+ (void)showLoginView;

/**
获取运营商信息

@return SALoginCarrierType
*/
+ (SALoginCarrierType)carrierType;

@end


