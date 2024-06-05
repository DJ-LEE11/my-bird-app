//
//  SAPIMainManager.h
//  SAPIDemo
//
//  Created by Vinson.D.Warm on 13-9-5.
//  Copyright (c) 2013年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PassportKit/PassportKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SAPIMainManager;
@class PASSFaceIDService;
@class PASSEvent;

@protocol SAPIMainManagerDelegate <NSObject>

@required
/**
 *  登录成功回调
 *
 *  @param sapiManager SAPIMainManager实例
 *  @param loginModel  登录成功的帐号信息
 *  @param extraInfo   额外的信息，目前包含字段：
 *                          SAPILoginExtraInfoIncompleteUserKey: 用户帐号类型，为SAPIUserCompleteType类型(这个字段值可能会变，建议只在登录成功时使用)
 *                          SAPILoginExtraInfoSourceKey：目前仅在通过H5登录时返回该字段，value固定为SAPILoginExtraInfoSourceFromH5LoginValue
 *                          SAPILoginExtraInfoActionTypeKey：表示当前登录类型，value 为 SAPILoginExtraInfoActionTypeXXX
 *                          SAPILoginExtraInfoFirstLoginKey：表示是否首次登录（一键登录、短信登录、首次注册后的自动登录）
 *                          SAPILoginExtraInfoFromFastLoginKey: 表示是否来自半屏登录组件 值为登录类型，详见PASSFastLoginActionType
 */
- (void)sapiManager:(SAPIMainManager *)sapiManager
    didLoginSucceed:(SAPILoginModel *)loginModel
          extraInfo:(nullable NSDictionary *)extraInfo;

/**
 *  登录失败时回调
 *
 *  @param sapiManager sapiManager实例
 *  @param model       登录模型
 */
- (void)sapiManager:(SAPIMainManager *)sapiManager didLoginFail:(SAPILoginModel *)model;

/**
 *  登录失败时回调
 *  注意：如该方法和 sapiManager:didLoginFail: 同时存在，则只会调用该方法
 *
 *  @param sapiManager sapiManager实例
 *  @param model       登录模型
 *  @param error       错误信息
 */
- (void)sapiManager:(SAPIMainManager *)sapiManager didLoginFail:(nullable SAPILoginModel *)model error:(nullable NSError *)error;

/**
 *  退出成功时回调
 *
 *  @param sapiManager sapiManager实例
 *  @param model       登录模型
 */
- (void)sapiManager:(SAPIMainManager *)sapiManager didLogOut:(SAPILoginModel *)model;

/**
 * 仅用于产品线统计失败信息。error code详见PASSError
 * 9.5.1 版本增加
 *
 * 注意：该代理仅用于业务线统计
 * 注意：该代理仅用于业务线统计
 * 注意：该代理仅用于业务线统计
 *
 * info说明：
 * {
 *  code:  NSNumber 服务端或者网络错误码（可能为空）
 *  msg：NSString 服务端或者网络错误信息（可能为空）
 *  SAPILoginExtraInfoFromFastLoginKey: PASSFastLoginActionType 有值则说明来自便捷登录组件，值内容为账号类型（可能为空）
 *}
 */
- (void)sapiManager:(SAPIMainManager *)sapiManager error:(NSError *)error info:(nullable NSDictionary *)info;

@optional

/**
 *  在成功登录一个帐号前会回调此方法
 *
 *  @param sapiManager SAPIMainManage
 *  @param freshModel  将要登录成功的帐号信息
 */
- (void)sapiManager:(SAPIMainManager *)sapiManager beforeLoginSucceed:(SAPILoginModel *)freshModel;

/**
 *  补填用户名成功时回调
 *
 *  @param sapiManager sapiManager实例
 *  @param model       登录模型
 */
- (void)sapiManager:(SAPIMainManager *)sapiManager didFillUnameSucceed:(SAPILoginModel *)model;

/**
 * 当前登录方式为苹果登录且苹果认证状态为revoked时，会调用该代理方法，业务线可以返回YES，SDK会执行logout方法，业务线也可以返回NO，自行调用logout方法。如不实现该代理方法，PASS SDK默认会执行logout方法退出登录。建议业务线实现该方法，可以在该方法内部弹出登录框，引导用户重新授权登录
 *
 * @param sapiManager shareManager
 * @param info 扩展字段，当前为nil
 */
- (BOOL)sapiManager:(SAPIMainManager *)sapiManager appleAuthRevoked:(nullable NSDictionary *)info;

#pragma mark - 普通事件统计
/**
 普通统计事件

 @param actionId 统计action Id
 @param dictionary 统计字典
 */
- (void)eventWithActionId:(NSString *)actionId dictionary:(NSDictionary *)dictionary;

/**
 普通统计事件

 @param actionId 统计action Id
 @param dictionary 统计字典
 @param eventDate 事件发生时间
 */
- (void)eventWithActionId:(NSString *)actionId dictionary:(NSDictionary *)dictionary eventDate:(NSDate *)eventDate;

@end

typedef NSString *PASSInfoForAPPKey NS_EXTENSIBLE_STRING_ENUM;

// 用户是否同意获取隐私信息 默认为同意 9.1.10+版本支持
FOUNDATION_EXPORT PASSInfoForAPPKey const PASSUserAgreeStateForAPP;
// App当前是否是浏览模式，默认为正常模式（用户已授权隐私协议）
FOUNDATION_EXPORT PASSInfoForAPPKey const PASSBrowseModeStateForAPP;

// 双清单项目（需要外部传入cuid和隐私服务平台注册的appname）
// 双清单项目（业务线CUID）
FOUNDATION_EXPORT PASSInfoForAPPKey const PASSProfessionCUIDForAPP;
// 双清单项目（业务线隐私服务appname）
FOUNDATION_EXPORT PASSInfoForAPPKey const PASSPrivacyMappingNameForAPP;


@interface SAPIMainManager : NSObject

// ======== 基础必配参数 ========
// 从6.17.18版本起，请通过-[SAPIMainManager setupTpl:appKey:appId:environmentType:]方法设置这四个基础参数。
@property (nonatomic, assign, readonly) SapiEnvironmentType environmentType;
@property (nonatomic, copy, readonly) NSString *appid;
@property (nonatomic, copy, readonly) NSString *tpl;
@property (nonatomic, copy, readonly) NSString *appkey;
// ============================

/**
 * 重要：如非必要请勿设置该属性。不设置默认依次取CFBundleDisplayName或CFBundleName值返回。如需设置需要保障名称正确
 *
 * 互通显示名称
 * 应用场景：对于百度极速版、百度大字版等矩阵app在iOS上展示的名称均为百度情况，其他app互通没办法区分是来自极速版还是大字版
 *         因此可以通过设置该属性来区分展示
 * v9.3.14
 */
@property (nonatomic, copy, nullable) NSString *sharedName;

@property (nonatomic, readonly) NSString* version;
// 是否测试包，默认 NO
@property (nonatomic, assign, getter=isDebug) BOOL debug;
@property (nonatomic, readonly) NSString* voiceProductId;
@property (nonatomic, assign) SAPIShareBindMode shareBindMode;

@property (nonatomic, assign) SAPILoginShareMode loginShareMode;
@property (nonatomic, assign) BOOL cacheEnabled;
@property (nonatomic, assign) BOOL loginOptionHidden;
@property (nonatomic, assign) BOOL showFastRegLink;

// 游客登录，游客帐号不支持互通
@property (nonatomic, assign) BOOL supportGuestLogin;

// 快推登录，开启快推登录的帐号不支持互通
@property (nonatomic, assign) BOOL quickUserLogin;

@property (nonatomic, copy) NSString* fastRegText;
@property (nonatomic, assign) BOOL showRegLink;
@property (nonatomic, assign) BOOL showIPlayout;

@property (nonatomic, strong) NSMutableArray<NSNumber *> *fastLoginOptionList;
@property (nonatomic, copy, nullable) NSString* skinUrl;

/**
 *  新浪微博、人人等通过oauth认证的第三方登录，每次登录都强制用户输入帐号密码来登录
 */
@property (nonatomic, assign) BOOL isOauthForceLogin;

@property (nonatomic, strong, readonly) NSURL *enhancedShareLoginURL;

/**
 *  新浪微博SSO登录URL
 */
@property (nonatomic, readonly) NSString *sinaSSOLoginUrl;

/**
 *  忘记密码URL
 */
@property (nonatomic, readonly) NSString *forgetPwdUrl;

/**
 *  强制绑定相关参数
 */
@property (nonatomic, assign) BOOL connect;

/**
 *   执行绑定、解绑、换绑等功能成功后，是否跳过提示页面
 */
@property (nonatomic, assign) BOOL quickCallbackAfterExecuteBind;

@property (nonatomic, strong) SAPILoginService *loginService;

@property (nonatomic, weak) id<SAPIMainManagerDelegate> delegate;

@property (nonatomic, copy) NSString *fastRegSMSChannel;

/**
 *  v6.8.4  新增
 *
 *  短信登录界面是否显示第三方登录入口
 */
@property (nonatomic, assign) BOOL showThirdLoginOnSMSLogin;

/**
 *  v6.8.4  新增
 *
 *  绑定手机时，如果手机号已经被绑定，是否跳转到短信登录界面
 *  如果设置为YES，则在绑定手机冲突时，如果用户点击了手机号登录则会回调SAPIControlPlugin的action_bind_widget_phone_number_exist:方法
 */
@property (nonatomic, assign) BOOL handleBindMobileConflict;

@property (nonatomic, strong, readonly) NSString *SAPICUID;

/**
 *  是否支持海外手机号登录。默认为NO，不支持。
 */
@property (nonatomic, assign) BOOL supportForeignMobile;

/**
 *  短信登录是否支持通过语音验证码登录。默认为YES
 */
@property (nonatomic, assign) BOOL supportVoiceVerifyOnSMSLogin;

/**
 *  支持横竖屏
 *  当控制器调用系统supportedInterfaceOrientations方法时，如果实现该回调，则会调用该回调
 *  不实现则默认以下策略：iPad上，支持横竖屏，iphone上仅支持竖屏
 */
@property (nonatomic, copy) UIInterfaceOrientationMask (^supportOrientation)(void);

/**
 *  是否开启H5登录状态同步，默认为NO。
 * 
 *  @discussion 开启此字段后，将使用如下策略同步Native和H5登录态：
     1. NA为空，H5为空 —— 帐号已同步，不处理
     2. NA为空，H5不为空 —— H5已登录，需要同步到NA，请求getUserInfo，成功H5->NA，失败不处理
     3. NA不为空，H5为空 —— H5退出或Cookie被清空，将NA登录态写回Cookie（如果是H5退出登录，BDUSS失效，需要产品线调logout接口。为方便产品线处理这种情况，SDK 会在这种情况下发送 SAPICookieSyncH5CookieClearedNotification 通知，产品线可监听该通知来触发查询 BDUSS 是否失效，查询 BDUSS 是否有效请用产品线业务接口）
     4. NA不为空，H5不为空
         4.1 NA == H5 —— 帐号已同步，不处理，即同1
         4.2 NA != H5，帐号不同步（可认为H5换号登录），根据策略决定最终状态。若使用NA优先策略，则直接使用NA登录态覆盖H5，若使用H5优先策略，则用H5 BDUSS请求getUserInfo，成功H5->NA，BDUSS失效NA->H5，其他不处理
 *
 */
@property (nonatomic, assign) BOOL enableSyncH5LoginStatus;

/**
 *  NA与H5登录态同步策略
 * 
 *  @see SAPINativeH5SyncStrategy
 */
@property (nonatomic, assign) SAPINativeH5SyncStrategy naH5SyncStrategy;

/**
 *  @brief NA和H5登录态同步成功回调策略
 *
 *  NA和H5登录态同步成功后，按策略回调登录成功。
 *
 *  @see SAPINativeH5SyncCallbackStrategy
 *
 *  @since 6.15.15
 */
@property (nonatomic, assign) SAPINativeH5SyncCallbackStrategy naH5SyncCallbackStrategy;

/**
 *  @brief 国际化配置项，默认为中文
 */
@property (nonatomic, assign) SAPII18NType i18nType;

/**
 支持生物认证类型，默认为包含 SAPIBiometricOptionLivenessRecog
 */
@property (nonatomic, assign) SAPIBiometricOptions biometricOptions;

/**
 百度地图CUID，用于数据打通
 */
@property (nonatomic, copy, nullable) NSString *baiduMapCuid;

/**
 App Group，给该字段赋值时，会将本地登录帐号与Widget共享。使用SAPIWidget库从Widget中读取当前登录帐号。
 */
@property (nonatomic, copy) NSString *appGroupID;

/**
 微信AppId
 使用微信登录或者帐号中心使用微信关联时需要赋值
 */
@property (nonatomic, copy, nullable) NSString *wxAppId;

@property (nonatomic, copy, nullable) NSString *twitterApiKey;
@property (nonatomic, copy, nullable) NSString *googleClientID;
@property (nonatomic, copy, nullable) NSString *googleReversedClientID;

/**
 微信 UniversalLink，在openSDK1.8.6版本之后
 微信支持 UniversalLink 方式跳转
 */
@property (nonatomic, copy, nullable) NSString *wxUniversalLink;

/**
 安全SDK APPKey，申请请到 http://dev.passport.baidu.com/authorize/safesdk
 */
@property (nonatomic, copy, readonly) NSString *ssdkAppKey;

/**
 安全SDK APPSecretKey，申请请到 http://dev.passport.baidu.com/authorize/safesdk
 */
@property (nonatomic, copy, readonly) NSString *ssdkSecretKey;

/**
 安全SDK初始化完成后回调，会固定在主线程中回调，error不为空说明ssdk初始化失败
 */
@property (nonatomic, copy) void(^ssdkInitializeCompletion)(NSError *error);

/**
 安全SDK 初始化参数 hostAppCUID（由宿主产品线提供的CUID）
 产品线如在自己业务中用到安全 SDK，务必传递该参数
 */
@property (nonatomic, copy) NSString *hostAppCUID;

/**
 *  是否校验APP是否是备份恢复安装，若是备份恢复将清除登录信息，用户需要从新登录。默认为NO（不校验）。
 *  注：请在初始化 PASS SDK统一入口之前设置，否则无效
 */
@property (nonatomic, assign) BOOL shouldCheckAppRestored;

/**
 是否支持刷脸登录，默认YES。请参考文档：http://wiki.baidu.com/pages/viewpage.action?pageId=369625380
 */
@property (nonatomic, assign) BOOL supportFaceLogin;

/**
 是否支持指纹登录，默认YES。
 */
@property (nonatomic, assign) BOOL supportTouchLogin;

/**
 是否支持系统记住密码登录，默认NO。
 */
@property (nonatomic, assign) BOOL supportSysPwdLogin;

/**
 QQ 登录 AppId，接入 QQ SSO 登录时需要赋值
 */
@property (nonatomic, copy, nullable) NSString *qqAppId;

/**
 QQ UniversalLink
 */
@property (nonatomic, copy, nullable) NSString *qqUniversalLink;

/**
 新浪微博 登录 AppKey，接入 新浪微博 SSO 登录时需要赋值
 */
@property (nonatomic, copy, nullable) NSString *sinaWeiboAppKey;

/**
 新浪微博 登录 redirectURI，默认设置为 https://passport.baidu.com，若与申请时填写的不一样请重新赋值，否则会报 redirect_uri_mismatch 错误
 */
@property (nonatomic, copy, nullable) NSString *sinaRedirectURI;
@property (nonatomic, copy, nullable) NSString *sinaUniversalLink;

/**
 宿主App的Scheme
 */
@property (nonatomic, copy) NSString *appScheme;

@property (nonatomic, strong, nullable) PASSFaceIDService *faceIDService;

/**
 上次用户成功登录方式
 */
@property (nonatomic, assign, readonly) PASSLastLoginType lastLoginType;

/**
 当前是否登录
 */
@property (nonatomic, assign, readonly) BOOL isLogin;

/**
 接入 oauth 功能的 百度系APP 需要设置该属性
 */
@property (nonatomic, copy, nullable) NSString *oauthApiKey;

/**
 使用 rim 刷脸SDK, 默认为 NO
 */
@property (nonatomic, assign) BOOL rimSDKEnable DEPRECATED_MSG_ATTRIBUTE("Set this property is unnecessary, this property will be removed in a future release");
/**
 Pass侧会将可延时任务通过该回调传递给产品线
 产品线可在冷启动完成后执行Pass侧的可延时任务
 
 @param identify 任务标识
 @param task 任务
 */
@property (nonatomic, copy) void (^launchTaskBlock)(NSString *identify, void (^task)(void));

/**
主题模式
*/
@property (nonatomic, assign) SAPIThemeStyle themeStyle;

@property (nonatomic, copy) NSString *oneKeyLoginAppKey;
@property (nonatomic, copy) NSString *oneKeyLoginAppSecret;

/**
 初始化时调用运营商预取号，默认为YES
 */
@property (nonatomic, assign) BOOL syncOneKeyLoginInfo;

/**
 是否支持多帐号登录，默认YES
 登录的多个帐号通过 localLoginModelList 获取
*/
@property (nonatomic, assign) BOOL supportMultipleAccounts;

/**
 tid转换sid的Block，在初始化之前设置实现，pass在初始化后调用获取sid
 
 @param tidArry 实验tid数组
 @return 拼接后的sid字符串
 */
@property (nonatomic, copy) NSString* (^tidConvertSidBlock)(NSArray<NSString *> *tidArry);

/**
 限手百使用，其他业务线禁止使用
 
 修复第三方验证方式bug：https://console.cloud.baidu-int.com/devops/icafe/issue/BAIDUSEARCHIOS-225835/show
 */
@property (nonatomic, copy) void (^ _Nullable startThirdSSOAuthForBdbox)(PASSThirdSSOType type, void(^_Nonnull authed)(NSDictionary * _Nullable authInfo, NSError * _Nullable error));

/**
 9.2.0+版本
 PASS SDK依赖产品线相关参数
 该方法可能会调用多次，可支持参数详见 PASSInfoFromAPPKey
 */
@property (nonatomic, copy) NSDictionary <PASSInfoForAPPKey, id> *(^infoForAPP)(void);

/**
 YY 第三方登录appid
 */
@property (nonatomic, copy) NSString *YYAppID;

/**
 9.2.3+版本
 为大字版产品线提供的全局配置，默认100，如想设置1.26倍字体则需传入126
 */
@property (nonatomic, assign) NSUInteger textZoom;

/**
 初始化 PASS SDK 统一入口

 申请TPL，APPKEY，APPID参数请到 http://dev.passport.baidu.com/authorize/index
 
 @param tpl 产品线标识
 @param appKey APPKey
 @param appId APPID
 @param environmentType 环境类型
 */
- (void)setupTpl:(NSString *)tpl appKey:(NSString *)appKey appId:(NSString *)appId environmentType:(SapiEnvironmentType)environmentType ssdkAppKey:(NSString *)ssdkAppKey ssdkSecretKey:(NSString *)ssdkSecretKey;

/**
 *  当前登录Model
 *
 *  @return 如果为nil，则当前没有登录帐号
 */
- (nullable SAPILoginModel *)currentLoginModel;

/**
 *  登录帐号列表
 *
 *  @return 帐号列表
 */
- (nullable NSArray *)localLoginModelList;

/**
 *  互通帐号列表
 *
 *  @return 帐号列表
 */
- (nullable NSArray *)sharedLoginModelList;

/**
 * 异步获取互通账号列表（内部会发起网络请求，返回登录态有效的账号）
 * 注意：网络请求失败、超时、SDK降级情况返回结果和sharedLoginModelList方法返回结果一致
 * @param completion 完成回调（如果verified为YES为校验成功，否则为未校验）
 */
- (void)sharedLoginModelList:(void (^)(BOOL verified, NSArray * _Nullable list))completion;

/**
 *  用现有模型登录(含互通)， 若需要保存本次登录类型，请使用 loginWithLoginModel:loginType:
 *
 *  @param model 构造的model中如果uid、bduss、displayname任一参数为nil或空串，则会回调登录失败，其他情况会回调登录成功。
 */
- (void)loginWithLoginModel:(SAPILoginModel *)model;

/**
 用现有模型登录(含互通)，若不需要保存本次登录类型，请使用 loginWithLoginModel:

 @param model     构造的model中如果uid、bduss、displayname任一参数为nil或空串，则会回调登录失败，其他情况会回调登录成功。
 @param Type      需要保存的本次登录类型
 @param userInfo  透传参数，该参数将透传至 didLoginSuccess 方法的 extraInfo 字段中，Key 为 userInfo
 */
- (void)loginWithLoginModel:(SAPILoginModel *)model loginType:(PASSLastLoginType)Type userInfo:(NSDictionary *)userInfo
DEPRECATED_MSG_ATTRIBUTE("Use SAPIMainManager instance's loginWithLoginModel:userInfo:completion: instead, this property will be removed in a future release and should be avoided");

/**
 用现有模型登录(含互通)

 @param model     构造的model中如果uid、bduss、displayname任一参数为nil或空串，则会回调登录失败，其他情况会回调登录成功。
 @param update      登录成功后是否调用getuserinfo接口更新信息，默认是
 */
- (void)loginWithLoginModel:(SAPILoginModel *)model needUpdateUserInfo:(BOOL)update
DEPRECATED_MSG_ATTRIBUTE("Use SAPIMainManager instance's loginWithLoginModel:userInfo:completion: instead, this property will be removed in a future release and should be avoided");

/**
 用现有模型登录(含互通)
 内部会校验bduss是否有效，无效则登录失败

 @param model     构造的model中如果uid、bduss、displayname任一参数为nil或空串，则会回调登录失败，其他情况会回调登录成功。
 @param userInfo  透传参数，该参数将透传至 didLoginSuccess 方法的 extraInfo 字段中，Key 为 userInfo
 @param completion 登录结果回调（登录成功和失败均会回调统一代理和该方法，业务方如有打点需求，应避免重复）
 */
- (void)loginWithLoginModel:(SAPILoginModel *)model userInfo:(nullable NSDictionary *)userInfo completion:(void(^)(NSError * _Nullable error))completion;

/**
 *  清除所用快捷登录选项
 */
- (void)clearLoginOptions;

/**
 *  添加快捷登录选项
 *
 *  @param optionType 快捷登录选项
 */
- (void)addLoginOption:(SAPILoginOptionType)optionType;

/**
 *  取消当前SAPI所有网络请求
 */
- (void)clearAllRequest;

/**
 *  pass cookies可信任domain
 */
- (NSArray *)getCookiesAuthorizedDomainList;

/**
 *  SAPIMainManger单例
 */
+ (SAPIMainManager *)sharedManager;

/**
 获取安全 SDK ZID
 该接口返回一个字典，Key 为 @"0" 表示 ZID，ZID 可能会变，产品线不应该缓存 ZID，而是每次需要时调用接口获取
 
 @param eventID 事件ID，由安全SDK分配
 若不涉及到安全性操作，仅期望简单获取zid时，eventID 传@"0"
 
 @important 从8.5.0版本起，产品线自身业务如需接入安全SDK，强烈建议直接调用安全SDK相关接口，无需通过PASS SDK调用，具体接入方式参考SSDKLib.h。该接口在未来可能会被废弃，建议尽量避免使用。
 
 return 返回数据
 
 */
- (NSDictionary *)activeSSDKWithEventID:(NSInteger)eventID;

/**
 产品线自定义网络请求session
 SDK内部会强引用session，如果产品线需要销毁调用该方法传入nil即可
 建议在初始化SDK前进行设置，如在初始化之后设置，会有部分请求使用系统默认的session处理
 */
- (void)setSession:(NSURLSession *)session;

/**
刷脸 sdk 版本号
@return 如果接入了刷脸SDK，返回版本号，否则返回 ""
*/
- (NSString *)biometricSDKVersion;

// ====== SAPIMainManager Deprecated Properties ======

// those properties will be removed in a future release.

@property (nonatomic, assign) BOOL webNavigationBarHidden DEPRECATED_MSG_ATTRIBUTE("this property will be removed in a future release and should be avoided");

@property (nonatomic, readonly) NSURL *bindMobileUrl DEPRECATED_MSG_ATTRIBUTE("Use -[SAPIWebView loadBindWidgetURLWithType:bduss:callback:] instead, this property will be removed in a future release and should be avoided");

@property (nonatomic, readonly) NSURL *bindEmailUrl DEPRECATED_MSG_ATTRIBUTE("Use -[SAPIWebView loadBindWidgetURLWithType:bduss:callback:] instead, this property will be removed in a future release and should be avoided");

@property (nonatomic, readonly) NSURL *rebindMobileUrl DEPRECATED_MSG_ATTRIBUTE("Use -[SAPIWebView loadBindWidgetURLWithType:bduss:callback:] instead, this property will be removed in a future release and should be avoided");

@property (nonatomic, readonly) NSURL *rebindEmailUrl DEPRECATED_MSG_ATTRIBUTE("Use -[SAPIWebView loadBindWidgetURLWithType:bduss:callback:] instead, this property will be removed in a future release and should be avoided");

@property (nonatomic, readonly) NSURL *unbindEmailUrl DEPRECATED_MSG_ATTRIBUTE("Use -[SAPIWebView loadBindWidgetURLWithType:bduss:callback:] instead, this property will be removed in a future release and should be avoided");

@property (nonatomic, readonly) NSURL *accountRecordIndexUrl DEPRECATED_MSG_ATTRIBUTE("Use -[SAPIWebView loadRecordIndexURLWithBduss:] instead, this property will be removed in a future release and should be avoided");

@property (nonatomic, readonly) NSURL *changePasswordUrl DEPRECATED_MSG_ATTRIBUTE("Use -[SAPIWebView loadModifyPasswordURLWithBduss:callback:] instead, this property will be removed in a future release and should be avoided");

@property (nonatomic, readonly) NSString *weixinLoginURLString DEPRECATED_MSG_ATTRIBUTE("Use -[SAPIMainWebView loadWeiXinBindURLWithCode:] instead, this property will be removed in a future release and should be avoided");

// 关于声纹登录
@property (nonatomic, assign) BOOL showQuickLogin DEPRECATED_MSG_ATTRIBUTE("this property will be removed in a future release and should be avoided");
@property (nonatomic, copy) NSString *quickLoginUserName DEPRECATED_MSG_ATTRIBUTE("this property will be removed in a future release and should be avoided");

/**
 * 该属性get方法返回值默认依次取CFBundleDisplayName或CFBundleName值返回，业务线在9.3.13（不含）版本前设置该属性无效
 * 9.3.13版本设置该属性会导致互通显示异常
 * 9.3.13版本后该属性废弃，如需设置app互通显示名称，请使用sharedName
 */
@property (nonatomic, copy) NSString *appName DEPRECATED_MSG_ATTRIBUTE("this property will be removed in a future release and should be avoided");

// 短信登录输入框默认手机号
@property (nonatomic, copy) NSString* inputPlaceholderPhoneNumber DEPRECATED_MSG_ATTRIBUTE("Use PASSLoginViewController instance's presetUsername instead, this property will be removed in a future release and should be avoided");

/**
 *  登录入口显示判断：短信登录页面是否显示普通登录入口 1 显示  0 隐藏
 */
@property (nonatomic, assign) BOOL showLoginLink DEPRECATED_MSG_ATTRIBUTE("this property will be removed in a future release and should be avoided");

/**
 *  登录入口显示判断：普通登录界面是否显示短信登录入口 1 显示 0 隐藏
 */
@property (nonatomic, assign) BOOL showSMSLoginLink DEPRECATED_MSG_ATTRIBUTE("this property will be removed in a future release and should be avoided");

/**
 *  线下环境HTTPS开关，默认是YES。
 *  由于线下环境证书为自签名证书，请用Safari打开 http://10.94.19.13:8235/cer/passportqa.cer 安装QA环境根证书
 *
 */
@property (nonatomic, assign) BOOL enabledHTTPSOffline DEPRECATED_MSG_ATTRIBUTE("this property will be removed in a future release and should be avoided");

/**
 是否开启个性化登录，默认为YES
 个性化登录：登录方式展现层级：互通登录>用户自主设置刷脸方式（刷脸登录）>个性化登录（用户上次成功登录的方式）>默认登录方式
 */
@property (nonatomic, assign) BOOL supportPersonalizedLogin DEPRECATED_MSG_ATTRIBUTE("this property will be removed in a future release and should be avoided");

/**
 *  v6.7.6 新增
 *  是否支持无密码注册
 */
@property (nonatomic, assign) BOOL supportNoPwdRegister DEPRECATED_MSG_ATTRIBUTE("this property will be removed in a future release and should be avoided");

/**
 *  @brief Native与Webview的通信方式是否使用iframe，默认为NO。
 */
@property (nonatomic, assign) BOOL useIFrame DEPRECATED_MSG_ATTRIBUTE("this property will be removed in a future release and should be avoided");

/**
 *  清除内存中缓存的登录页
 */
- (void)clearCachePage DEPRECATED_MSG_ATTRIBUTE("this method will be removed in a future release");

/**
 *  获取糯米强制绑定地址
 */
- (NSURL *)enforceBindingURLWithToken:(NSString *)token
                               adtext:(NSString *)adtext
                               adhref:(NSString *)adhref
                            returnURL:(NSString *)returnURLStr DEPRECATED_MSG_ATTRIBUTE("this method will be removed in a future release");
/**
 *  获取强制绑定地址
 */
- (NSURL *)accountBindingURLWithToken:(NSString *)token
                               adtext:(NSString *)adtext
                               adhref:(NSString *)adhref
                            returnURL:(NSString *)returnURLStr DEPRECATED_MSG_ATTRIBUTE("this method will be removed in a future release");

/**
 *  安全验证url
 */
- (NSURL *)getAuthWidgetUrlWithToken:(NSString *)token
                           returnURL:(NSString *)returnUrl DEPRECATED_MSG_ATTRIBUTE("this method will be removed in a future release");

/**
 *  云端同步 (回调)
 *
 *  @param completion 完成时回调
 *  @param error      失败时回调
 */
- (void)syncCacheOnCompletion:(void (^)(void))completion error:(void (^)(void))error DEPRECATED_MSG_ATTRIBUTE("this method will be removed in a future release");

// ===================================================

@end

@interface SAPIMainManager (SAPIRedirect)

/**
 判断 PASSRouter 可以处理的 url 字符串类型

 @param urlString url字符串
 @return 类型
 */
- (SAPINativeURLType)checkNativeURLType:(NSString *)urlString;

/**
 判断需要在 WebView 中打开的 url 字符串类型

 @param urlString url字符串
 @return 类型
 */
- (SAPIWebURLType)checkWebURLType:(NSString *)urlString;

@end

NS_ASSUME_NONNULL_END
