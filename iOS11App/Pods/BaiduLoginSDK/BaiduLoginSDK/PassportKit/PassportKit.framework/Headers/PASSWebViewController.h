//
//  PASSWebViewController.h
//  PassportKit
//
//  Created by jiangzhenjie on 2017/3/31.
//  Copyright © 2017年 Baidu Passport. All rights reserved.
//

#import <PassportKit/PASSBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class PASSWebViewController;
@protocol PASSWebViewControllerNavigationDelegate <NSObject>

@optional
- (void)webViewController:(PASSWebViewController *)webViewController didReceivedParams:(NSDictionary *)params;

@end

/**
 加载动画代理
 */
@protocol PASSWebViewControllerLoadingDelegate <NSObject>

@optional

/**
 显示 Loading，需要在回调中创建或者显示 loading 视图，并且启动 loading 动画

 @param webViewController controller实例
 @param view loadingView 的父视图，一般回传为 controller 的 root view
 */
- (void)passWebViewController:(PASSWebViewController *)webViewController startLoadingInView:(UIView *)view;

/**
 隐藏 Loading，需要在回调中停止 loading 动画，并且移除或者隐藏 loading 视图

 @param webViewController controller实例
 */
- (void)passWebViewController:(PASSWebViewController *)webViewController endLoadingInView:(UIView *)view;

@end

typedef NSString *const PASSWebExtraQueryKey;

// 接入方可以使用该Tag标记LoadingView，防止Tag重复
FOUNDATION_EXPORT NSInteger const kPASSWebViewControllerLoadingViewTag;
FOUNDATION_EXPORT PASSWebExtraQueryKey PASSWebExtraQuerySelectedAgreement;
FOUNDATION_EXPORT PASSWebExtraQueryKey PASSWebExtraQueryOnlyJunior;
FOUNDATION_EXPORT PASSWebExtraQueryKey PASSWebExtraQueryCashierOrder; // 支付实名传入订单id

typedef NSString *const PASSCommissionActionKey;

//FOUNDATION_EXPORT PASSCommissionActionKey PASSCommissionActionClearTraces;          // 清除痕迹回调
FOUNDATION_EXPORT PASSCommissionActionKey PASSCommissionActionAuthWidget;           // 验证控件回调
FOUNDATION_EXPORT PASSCommissionActionKey PASSCommissionActionDuVip;           // 验证控件回调
FOUNDATION_EXPORT PASSCommissionActionKey PASSCommissionActionCustomerService;           // 客服

/**
 WebView控制器基类
 */
@interface PASSWebViewController : PASSBaseViewController <SAPIMainWebViewDelegate>

/**
 控制器持有的WebView实例
 */
@property (nonatomic, strong, readonly) SAPIMainWebView *webView;

/**
 页面加载路径
 */
@property (nonatomic, strong) NSURL *url;

/**
 是否显示进度条，默认为YES
 */
@property (nonatomic, assign) BOOL showProgress;

/**
 是否允许在WebView加载完成后动态更新标题，默认为YES
 自9.0.0版本起登录页和三方登录页面该属性将失效（登录视觉改版需求）
 */
@property (nonatomic, assign) BOOL enableUpdateTitle;

/**
 额外的查询字符串参数，这些参数将直接拼接在URL后面
 key可参考 SAPIDefine 中定义的 PASSWebViewExtraQueryKey 类型值
 注意：key 和 value 如果是非 URL 允许字符，需要 URL Encode 后传入
 
 PASSWebExtraQuerySelectedAgreement  // 如果值为true则默认勾选隐私协议弹窗
 PASSWebExtraQueryOnlyJunior //如果值为@(YES) 只进行初级实名认证, 不传或@(NO) 为初级+高级实名认
 */
@property (nonatomic, strong, nullable) NSDictionary *extraQueryParams;

/**
 导航代理
 */
@property (nonatomic, weak, nullable) id<PASSWebViewControllerNavigationDelegate> navigationDelegate;

/**
 打开登录页回调，产品线在该回调中调起自己的登录页面。
 <p>
 某些流程可能触发登录，建议产品线实现该回调。
 注意，如不实现该回调，将打开默认的登录页。
 </p>
 */
@property (nonatomic, copy) void(^presentLoginVCHandler)(NSDictionary *userInfo);

@property (nonatomic, copy) void(^jumpToUrl)(PASSWebViewController *ctrl, NSString *urlString);

/**
 加载动画代理
 */
@property (nonatomic, weak, nullable) id<PASSWebViewControllerLoadingDelegate> loadingDelegate;

/**
 页面当前URL Request
 */
@property (nonatomic, strong, readonly) NSURLRequest *currentRequest;

/**
 * 登录成功是否关闭该页面
 * 如果产品线在登录成功的代理里未调用
 * [PASSViewControllerTerminator closePASSViewController]或
 * 未关闭pass的所有页面，则closeCtrlIfLoginSuccess应该设置为YES，如果
 * 产品线关闭了所有的pass页面，则设置为NO，否则会出现动画不连贯，影响体验
 * 默认值为NO
 */
@property (nonatomic, assign) BOOL closeCtrlIfLoginSuccess;

/**
 日志打点透传字段
 
 字段规范：
 1. 字段格式为 json，需要 URL Encode 后传入；
 2. URL Encode 后的长度不能超过 100 字节。
 */
@property (nonatomic, copy, nullable) NSString *statExtra;

/**
*  标识帐号切换里的三方登录场景
*/
@property (nonatomic, copy, nullable) NSString *sceneFrom;


/**
 初始化页面

 @param url 路径
 @return WebView 控制器实例
 */
- (instancetype)initWithURL:(NSURL *)url;

/**
 初始化页面
 
 @param urlString 路径字符串
 @return WebView 控制器实例
 */
- (instancetype)initWithURLString:(NSString *)urlString;

/**
 加载WebView，子类可重写该方法自定义加载行为
 */
- (void)loadWebView;

/**
 重新加载当前URL
 */
- (void)reloadWebView;

/**
 是否支持侧滑返回
 
 @return YES 表示支持，NO 表示不支持
 */
- (BOOL)supportInteractivePopGesture;

/**
 页面是否可以回退

 @return YES 表示可以回退，NO表示不可以
 */
- (BOOL)pageCanGoBack;

/**
 * 在SDK的Webview页面内某些事件需要业务线自行处理的场景
 * action返回值表示是否关闭页面或是否处理成功
 */
- (void)registerCommissionAction:(PASSCommissionActionKey)key action:(BOOL(^_Nonnull)(NSDictionary * _Nullable))action;
- (void)asynNoticeCommissionAction:(PASSCommissionActionKey)key info:(NSDictionary * _Nullable)info completion:(void(^ _Nullable)(NSDictionary *resp))completion;

@end

NS_ASSUME_NONNULL_END
