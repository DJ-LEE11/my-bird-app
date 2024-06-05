//
//  PASSError.h
//  PassportKit
//
//  Created by jiangzhenjie on 2018/4/8.
//  Copyright © 2018年 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 PASS SDK 本地错误码

 - SAPIErrorCodeSucceed: 成功
 - SAPIErrorCodeNetworkException: 网络异常
 - SAPIErrorCodeUnknowError: 未知错误
 - SAPIErrorCodeParamsInvalid: 参数错误
 - SAPIErrorCodeResponseInvalid: 服务异常
 - SAPIErrorCodeUserCancel: 用户取消
 - SAPIErrorCodeLowVersion: pass sdk版本太低，无法处理
 - SAPIErrorCodeAbilityUnavailable: 端能力不可用
 - SAPIErrorCodeUserNotLogin: 用户未登录
 - SAPIErrorCodeSecureIssue: 安全问题
 - SAPIErrorCodeNetTimeout: 网络超时
 */
typedef NS_ENUM(NSInteger, SAPIErrorCode) {
    SAPIErrorCodeSucceed = 0,
    SAPIErrorCodeNetworkException = -201,
    SAPIErrorCodeUnknowError = -202,
    SAPIErrorCodeParamsInvalid = -205,
    SAPIErrorCodeResponseInvalid = -206,
    SAPIErrorCodeUserCancel = -207,
    SAPIErrorCodeLowVersion = -208,
    SAPIErrorCodeAbilityUnavailable = -301,
    SAPIErrorCodeUserNotLogin = -302,
    SAPIErrorCodeSecureIssue = -310,
    SAPIErrorCodeNetTimeout = -705,
    
    /// 便捷登录组件
    SAPIErrorCodeFastLoginFail = 35001,             /// 登录失败
    SAPIErrorCodeFastLoginNotAgreePolicy = 35002,   /// 未勾选隐私协议
    SAPIErrorCodeFastLoginSignInvalid = 35003,      /// 一键登录签名错误
};

FOUNDATION_EXPORT NSString * const PASSErrorDomain;

/**
 Domain 固定为 PASSErrorDomain，以区分是 PASS 抛出的错误。
 localizedDescription 属性可以直接用于前端展示
 underlyingError 为细分错误
 */
@interface PASSError : NSError

- (instancetype)initWithCode:(NSInteger)code localizedDescription:(NSString *)localizedDescription;

- (instancetype)initWithCode:(NSInteger)code localizedDescription:(NSString *)localizedDescription underlyingError:(NSError *)error userInfo:(NSDictionary<NSErrorUserInfoKey, id> *)userInfo;

// code 必须为 SAPIErrorCode 枚举
+ (instancetype)errorWithCode:(SAPIErrorCode)code;

+ (instancetype)errorWithCode:(NSInteger)code localizedDescription:(NSString *)localizedDescription;

+ (instancetype)errorWithCode:(NSInteger)code localizedDescription:(NSString *)localizedDescription underlyingError:(NSError *)error userInfo:(NSDictionary<NSErrorUserInfoKey, id> *)userInfo;

// error 为老版本接口抛出的 NSError
+ (instancetype)compatibleErrorWithError:(NSError *)error;

@end
