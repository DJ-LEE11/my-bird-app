//
//  PASSNormalizeGuestViewController.h
//  PassportKit
//
//  Created by Gang,Liu on 2018/6/5.
//  Copyright © 2018年 Baidu Passport. All rights reserved.
//

#import <PassportKit/PassportKit.h>

typedef NS_ENUM(NSInteger, PASSGuestNormalizeWay) {
    PASSGuestNormalizeWayNone = 0,     //未完成正常化
    PASSGuestNormalizeWaySMS,          //短信方式升级
    PASSGuestNormalizeWaySMSExist,     //短信方式绑至已有帐号
    PASSGuestNormalizeWayPWD,          //帐号密码方式绑至已有帐号
};

typedef NS_ENUM(NSInteger, PASSGuestNormalizeResult) {
    PASSGuestNormalizeResultSuccess = 0, //正常化成功
    PASSGuestNormalizeResultMerge,       //合并帐号
    PASSGuestNormalizeResultFailed,      //正常化失败
};

@interface PASSGuestNormalizeResponse : NSObject

/**
 正常化成功 / 合并帐号 后返回的 SAPILoginModel 实例
 */
@property (nonatomic, strong) SAPILoginModel *model;

/**
 游客帐号正常化结果
 */
@property (nonatomic, assign) PASSGuestNormalizeResult result;

/**
 游客帐号正常化的方式
 */
@property (nonatomic, assign) PASSGuestNormalizeWay normalWay;

@end

@interface PASSGuestNormalizeViewController : PASSAccountWebViewController

/**
 正常化以后的回调, 使用者需在此回调内自己关闭 PASSGuestNormalizeViewController 页面。
 response: 正常化结果 PASSGuestNormalizeResponse 类型, 失败为nil,
 error   : 失败时会回传一个PASSError实例,成功为nil
 */
@property (nonatomic, copy) void(^normalizeCompolition)(PASSGuestNormalizeResponse *response, PASSError *error);

/**
 设置游客帐号正常化文案，title、subtitle
 */
@property (nonatomic, copy) NSDictionary *normalizeTips;

@end
