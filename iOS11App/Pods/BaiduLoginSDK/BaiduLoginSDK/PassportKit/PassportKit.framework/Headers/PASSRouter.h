//
//  PASSRouter.h
//  PassportKit
//
//  Created by jiangzhenjie on 2017/7/20.
//  Copyright © 2017年 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PASSOpenURLHandleDelegate;

typedef NS_ENUM(NSUInteger, PASSAbilityType) {
    PASSAbilityTypeUnknown,
    PASSAbilityTypeLivenessBduss,
    PASSAbilityTypeLivenessCertInfo,
    PASSAbilityTypeLivenessAuthToken,
    PASSAbilityTypeLivenessUID,
    PASSAbilityTypeNewWebView,
    PASSAbilityTypeGetDI,
};


@protocol PASSRouterQRDelegate <NSObject>

@required

// SDK打开页面前会调用该代理，业务方如有特殊需求，可拦截该代理实现，如注销回调
- (void)passOpenURLHandlerWillOpenCtrl:(__kindof PASSWebViewController *_Nonnull)ctrl;

// SDK在打开页面的过程中，发现登录态失效会调用该代理方法，业务方应在该代理方法内实现打开登录页
// 如业务方需自行弹出页面，则返回yes，否则pass将会弹出相关页面
- (void)passOpenURLHandlerWillOpenLoginCtrl:(PASSLoginViewController *_Nonnull)ctrl;

@end


/**
 PASS路由器，主要用于处理PASS相关功能跳转
 */
@interface PASSRouter : NSObject

+ (BOOL)canHandleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication;
+ (BOOL)handleOpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication delegate:(id<PASSOpenURLHandleDelegate>)delegate;

/**
 8.9.5（不含）版本后增加
 建立下述两个方法原因有二：
 一方面Facebook SDK需要代理里的全部参数；
 另外一方面便于Pass管理内部的逻辑。
 */
+ (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options delegate:(id<PASSOpenURLHandleDelegate>)delegate;

+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotations delegate:(id<PASSOpenURLHandleDelegate>)delegate;
@end

/**
 处理二维码扫码结果
 */
@interface PASSRouter (PASSQRCode)

/**
 是否能处理二维码内容
 
 @param content 二维码内容
 @return 能处理时返回YES，其他情况返回NO
 */
+ (BOOL)canHandleQRCodeContent:(nonnull NSString *)content;
+ (void)handleQRCodeContent:(nonnull NSString *)content delegate:(id<PASSRouterQRDelegate>_Nonnull)delegate;

/**
 处理二维码内容，打开相应页面
 
 @param content 二维码内容
 @param nav 导航栏控制器，内部固定使用 push 打开页面
 @param handler 需要打开登录页回调
 */
+ (void)handleQRCodeContent:(nonnull NSString *)content rootVC:(nonnull UINavigationController *)nav presentLoginVCHandler:(void(^_Nonnull)(NSDictionary * _Nullable params))handler;

/**
 处理二维码内容，打开相应页面
 
 @param content 二维码内容
 @param nav 导航栏控制器，内部固定使用 push 打开页面
 @param handler 需要打开登录页回调。 自定义登录页时，请取出params[@"statExtra"] 拼接到 statExtra 参数上，
 @param completion 处理完成回调（目前只有二维码登录会回调）
 */
+ (void)handleQRCodeContent:(nonnull NSString *)content rootVC:(nonnull UINavigationController *)nav presentLoginVCHandler:(void(^_Nonnull)(NSDictionary * _Nullable params))handler completionHandler:(void(^_Nullable)(NSDictionary * _Nullable info))completion;

@end

/**
 处理PASS SDK端能力调用
 */
@interface PASSRouter (PASSAbility)

/**
 调起PASS SDK端能力

 @param context 上下文
 @param params 参数, 参数中需传入 open_appid、open_apikey（@since 8.7.14）, 该参数在 开放平台（https://developer.baidu.com/newwiki/dev-wiki/zhu-ce-bai-du-kai-fa-zhe.html?t=1518338594397）申请，
 @param completion 回调
 */
+ (void)callAbilityWithContext:(UIViewController *)context params:(NSDictionary *)params completion:(void(^)(NSDictionary *result))completion;

@end



