//
//  PASSAccountRealNameViewController.h
//  PassportKit
//
//  Created by jiangzhenjie on 2017/11/1.
//  Copyright © 2017年 Baidu Passport. All rights reserved.
//

#import <PassportKit/PassportKit.h>

typedef NS_OPTIONS(NSInteger, PASSAccountRealNameResult) {
    PASSAccountRealNameResultCancel = 0,        //取消操作
    PASSAccountRealNameResultJunior = 1 << 0,   //初级实名
    PASSAccountRealNameResultSenior = 1 << 1    //高级实名
};

typedef NS_ENUM(NSInteger, PASSAccountRealNameStatus) {
    PASSAccountRealNameStatusSeniorFailed = -2,           // 高级实名时失败
    PASSAccountRealNameStatusJuniorFailed = -1,           // 初级实名时失败
    PASSAccountRealNameStatusCanceled = 0,                // 未触发任何实名操作返回或实名时放弃返回
    PASSAccountRealNameStatusJunior = 1,                  // 此次完成了初级实名认证
    PASSAccountRealNameStatusSenior = 2,                  // 此次完成了高级实名认证
    PASSAccountRealNameStatusJuniorAndSenior = 3          // 一次同时完成了初级和高级实名认证
};

// 实名返回结果文档：https://ku.baidu-int.com/knowledge/HFVrC7hq1Q/pKzJfZczuc/zjSPXAlMno/wXYfi2idRMon-G

@interface PASSRealNameResponse : NSObject
// 完成高级实名后的刷脸凭证，其他情况 callbackkey 为空
@property (nonatomic, copy) NSString *callbackkey;
/**
 帐号实名操作结果
 
 result 仅表示用户是否有实名操作，并不一定是用户当前的实名状态。
 判断是否做初级实名操作：result & PASSAccountRealNameResultJunior
 result 无法细分出实名错误时的信息，请用 status 替换升级
 */
@property (nonatomic, assign) PASSAccountRealNameResult result DEPRECATED_MSG_ATTRIBUTE("replaced by property:status");

// 关闭实名页面时，返回的此次实名认证状态
@property (nonatomic, assign, readonly) PASSAccountRealNameStatus status;
// 实名错误码
@property (nonatomic, assign, readonly) NSInteger code;
// 错误信息
@property (nonatomic, readonly) NSString *message;
// 该对象所有属性及其值对应的 Dictionary 形式，key 名称同属性名一致（不包含 mappedProperties 自己，result已过期，不包含）
// 需要对外透传对象，而又不能暴露对象定义、引用时可以使用
@property (nonatomic, readonly) NSDictionary<NSString*, NSString*> *mappedProperties;
@end


@interface PASSAccountRealNameViewController : PASSWebViewController

/**
 登录态，如果传空，则用当前登录帐号
 */
@property (nonatomic, copy) NSString *bduss;

/**
 场景参数
 */
@property (nonatomic, copy) NSString *scene;

/**
 是否需要回传刷脸凭证 callbackkey，默认为NO
 */
@property (nonatomic, assign) BOOL needCallbackkey;
/**
 帐号实名操作结果回调
 
 result 仅表示用户是否有实名操作，并不一定是用户当前的实名状态。
 判断是否做初级实名操作：result & PASSAccountRealNameResultJunior
 */
@property (nonatomic, copy) void(^completion)(PASSAccountRealNameResult result) DEPRECATED_MSG_ATTRIBUTE("replaced by void(^realNameCompolition)(PASSRealNameResponse *response)");

/**
 帐号实名操作结果回调。设置needCallbackkey=YES，完成高级实名后，回传 callbackkey。
 */
@property (nonatomic, copy) void(^realNameCompolition)(PASSRealNameResponse *response);

/// 产品线传入的自定义实名url, 可在pass实名页面展示入口
@property (nonatomic, copy) NSString *customRealNameUrl;
@end
