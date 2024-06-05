//
//  PASSUMCOpenWrapper.h
//  SAPIStandardDemo
//
//  Created by Gang,Liu on 2019/1/28.
//  Copyright © 2019年 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PASSOneKeyError) {
    PASSOneKeyErrorSuccess = 0,
    PASSOnekeyErrorRetStringNull = 2000,        // 一键登录返回结果空
    PASSOnekeyErrorSerializationFail = 2001,    // 序列化一键登录结果失败
    PASSOneKeyErrorRiskDevice = 2002,           // 设备存在风险
    PASSOneKeyErrorCarrierFeatures = 2003,      // 运营商功能错误
    PASSOneKeyErrorCarrierSDK = 2004,           // 号码认证SDK错误
    PASSOneKeyErrorCarrierServer = 2005,        // 号码认证服务端错误
    PASSOneKeyErrorCMCCSDK = 2006,              // 移动SDK停用
    PASSOneKeyErrorCUCCSDK = 2007,              // 联通SDK停用
    PASSOneKeyErrorCTCCSDK = 2008,              // 电信SDK停用
    PASSOneKeyErrorALLCarrierSDK = 2009,        // 整体运营商SDK停用
    PASSOneKeyErrorCarrierLogining = 2010,      // 运营商正在登录中
    PASSOneKeyErrorCarrierSDKUnSupport = 2011,  // 未找到运营商方法名
    PASSOneKeyErrorServerReqFaild = 2012,       // 服务端登录验证请求失败
    PASSOneKeyErrorServerFaild = 2013,          // 服务端登录验证失败
    PASSOneKeyErrorCarrierNotMatchSIM = 2014,   // SIM卡和指定运营商不匹配
    PASSOneKeyErrorNotFoundRegInterface = 2015, // 注册接口未找到
    PASSOneKeyErrorNotOpenCarrier = 2016,       // 蜂窝数据未开启
    PASSOneKeyErrorCarrierUnSupport = 2017,     // 运营商未支持
    PASSOneKeyErrorCarrierNotFoundSIM = 2018,   // SIM卡未找到
    PASSOneKeyErrorCancelLogin = 2019,          // 取消登录
    PASSOneKeyErrorSDKNotReady = 2020,          // SDK未初始化
    PASSOneKeyErrorIntegrated = 2021,           // 集成错误
    PASSOneKeyErrorTimeOut = 2022,              // 超时
    PASSOneKeyErrorUnKnow = SAPIErrorCodeUnknowError, // 未知错误
};

@interface PASSOneKeyMarketingInfo : NSObject

@property (nonatomic, copy) NSString *appid;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, assign) PASSOperatorType type;

/**
 * 业务线需要注意：此参数需要最终传递给pass服务端，因此需要再业务线请求
 * 业务线服务端时携带，业务线服务端调用pass服务端时同样也需要携带
 */
@property (nonatomic, strong, nullable) NSDictionary <NSString *, NSString *>*needToServerParams;
@end

@interface PASSOneKeySDKManager : NSObject

+ (instancetype)sharedWrapper;
- (instancetype)init NS_UNAVAILABLE;

/**
 运营商类型
 */
@property (nonatomic, assign, readonly) PASSOperatorType operatorType;

/**
 预取的打码手机号
 */
@property (nullable, nonatomic, copy, readonly) NSString *securityPhoneNum;

/**
 * 营销场景下获取一键登录相关信息
 */
- (void)getOneKeyMarketingInfo:(void(^)(PASSOneKeyMarketingInfo *info, NSError *error))completion;
@end

NS_ASSUME_NONNULL_END
