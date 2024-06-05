//
//  SAPIDefine.h
//  SAPILib
//
//  Created by Vinson.D.Warm on 13-9-5.
//  Copyright (c) 2013年 baidu. All rights reserved.
//

#ifndef SAPILib_SAPIDefine_h
#define SAPILib_SAPIDefine_h

/**
运营商类型
*/
typedef NS_ENUM(NSInteger, PASSOperatorType) {
    PASSOperatorTypeUnknown,  // 未知
    PASSOperatorTypeCMCC,     // 运营商 移动
    PASSOperatorTypeCUCC,     // 运营商 联通
    PASSOperatorTypeCTCC      // 运营商 电信
};

// 预取号场景
typedef NS_ENUM(NSUInteger, SAPIPreGetPhoneScene) {
    SAPIPreGetPhoneSceneInit,      // 初始化阶段预取号
    SAPIPreGetPhoneSceneLogin,     // 登录阶段预取号
    SAPIPreGetPhoneSceneSapi,      // 外漏阶段预取号
    SAPIPreGetPhoneSceneProduct ,  // 产品线调用预取号
};

/**
 主题颜色
 */
typedef NS_ENUM(NSInteger, SAPIThemeStyle) {
    SAPIThemeStyleLight = 0, //亮色主题
    SAPIThemeStyleDark = 1   //暗色主题
};

/**
 部分页面支持不跟随全局设置的自定义样式设置
 9.2.6+版本
 目前支持的有：
 半弹层登录页面
 */
typedef NS_ENUM(NSUInteger, PASSThemeStyle) {
    PASSThemeStyleGlobal,       // 遵循全局配置
    PASSThemeStyleOnlyLight,    // 始终为亮色模式
    PASSThemeStyleOnlyDark,     // 始终为暗黑模式
};

/**
 快速登录选项
 */
typedef enum {
    SAPILoginOptionTSinaSSO = 0,  //notice: 由于新浪微博不支持迁移appid，目前产品线无法新接入新浪微博SSO登录。
    SAPILoginOptionQRCode,
    SAPILoginOptionDeviceLogin,
    SAPILoginOptionNuoMi,
    SAPILoginOptionVoicePrint,
    SAPILoginOptionWeiXinSSO,
    SAPILoginOptionQQSSO,     // QQ SSO 登录
    SAPILoginOptionAppleSSO,  // sign in with apple，百度网讯企业证书使用该方式，其他证书下的app使用SAPILoginOptionAppleWeb方式！！！
    SAPILoginOptionAppleWeb,  // sign in with apple H5方式，非百度网讯企业证书使用该方式
    SAPILoginOptionWXWork = 62,     // 企业微信，暂未开放使用
    SAPILoginOptionDingDing = 63,   // 钉钉
    SAPILoginOptionYYSSO = 100,     // YY SSO 登录
    SAPILoginOptionUnknow = 999
} SAPILoginOptionType;

/**
 第三方 SSO 登录类型

 - PASSThirdSSOTypeWeiXin: 微信登录
 - PASSThirdSSOTypeQQ: QQ登录
 - PASSThirdSSOTypeSina: 新浪微博登录
 - PASSThirdSSOTypeApple: Sign in with Apple
 */
typedef NS_ENUM(NSUInteger, PASSThirdSSOType) {
    PASSThirdSSOTypeWeiXin = 1,
    PASSThirdSSOTypeQQ,
    PASSThirdSSOTypeSina,
    PASSThirdSSOTypeApple,
    PASSThirdSSOTypeFacebook,
    PASSThirdSSOTwitter,
    PASSThirdSSOGoogle,
    PASSThirdSSOTypeWXWork = SAPILoginOptionWXWork,     // 企业微信，暂未开放使用
    PASSThirdSSOTypeDingDing = SAPILoginOptionDingDing, // 钉钉
    PASSThirdSSOTypeYY = SAPILoginOptionYYSSO, // 100
    PASSThirdSSOTypeUnknow = SAPILoginOptionUnknow // 999
};

/**
 互通模式
 */
typedef NS_ENUM(NSInteger, SAPILoginShareMode) {
    SAPINoShareLoginMode = 0,
    SAPIChoiceShareLoginMode = 3,
};

/**
 第三方帐号与百度帐号的绑定方式
 */
typedef enum {
    SAPIShareBindMobileBindMode, // 强制绑定手机号 - 在注册（首次登录）时，强制绑定手机号，推荐产品线使用该方式
    SAPIShareExplicitBindMode, // 明绑
    SAPIShareSMSBindMode, // 明绑且只支持通过手机号绑定
} SAPIShareBindMode;

/**
 环境配置
 
 - SapiEnvironment_Online: 线上环境
 - SapiEnvironment_QA: QA联调环境
 
 由于 QA 环境 HTTPS 使用的是自签名证书，需要安装根证书，步骤如下：
 1. 手机或者模拟器用 Safari 打开 http://10.94.19.13:8235/cer/passportqa.cer
 2. 点击安装证书
 3. iOS 10.3开始默认不信任自签名根证书，需要到 设置-通用-关于本机-证书信任设置 中勾选
 
 （如上面地址不可用，请尝试http://gitlab.baidu.com/jiangzhenjie/passport-https/raw/master/passportqa.cer）
 
 */
typedef enum ESapiEnvironmentType
{
    SapiEnvironment_Online = 1,
    SapiEnvironment_QA,
} SapiEnvironmentType;

/**
 登录类型
 
 - SAPILoginTypeDefault: 普通登录
 - SAPILoginTypeSMS: 短信登录
 - SAPILoginTypeReg: 短信注册
 - SAPILoginTypeJoinWithAccount: AI联合登录，第三方拥有帐号系统
 - SAPILoginTypeJoinWithoutAccount: AI联合登录，第三方没有帐号系统
 - SAPILoginWayInsertAccount: 切换帐号，不展示登录历史
 */
typedef NS_ENUM(NSInteger, SAPILoginType){
    SAPILoginTypeDefault,
    SAPILoginTypeSMS,
    SAPILoginTypeReg,
    SAPILoginTypeJoinWithAccount,
    SAPILoginTypeJoinWithoutAccount,
    SAPILoginWayInsertAccount,
    SAPILoginWayPreLogin,
};

/// 上次用户成功登录方式
/// 注意：修改改属性双端需保持一致
typedef NS_ENUM(NSInteger, PASSLastLoginType){
    PASSLastLoginTypeNone = 0,                      // 无
    PASSLastLoginTypePWD,                           // 帐号密码登录
    PASSLastLoginTypeSMS,                           // 帐号短信登录
    PASSLastLoginTypeFace,                          // 刷脸登录
    PASSLastLoginTypeWechat,                        // 微信登录
    PASSLastLoginTypeWeibo,                         // 微博登录
    PASSLastLoginTypeQQ,                            // QQ登录
//    PASSLastLoginTypeSilentShare,                   // 静默互通登录，已废弃！！！静默互通功能已下线
    PASSLastLoginTypeChoiceShare = 8,               // 选择互通登录
    
    PASSLastLoginTypeQRCodeAuthorized = 9,          // 二维码被扫描、授权登录
    PASSLastLoginTypeQRCodeJointAuthorized = 10,    // 二维码被扫描、联合授权登录
    
    PASSLastLoginTypeApple = 11,                    // Apple登录
    PASSLastLoginTypeTouch = 15,                    // 指纹登录
    PASSLastLoginTypeOneKeyCM = 16,                 // 移动一键登录
    PASSLastLoginTypeOneKeyCU = 17,                 // 联通一键登录
    PASSLastLoginTypeOneKeyCT = 18,                 // 电信一键登录
    
    PASSLastLoginTypeSwitch = 19,                   // 切换帐号
    PASSLastLoginTypeNaQrlogin = 20,                // 更换设备登录
    PASSLastLoginTypeHistory = 21,                  // 历史登录（20）
    PASSLastLoginTypeFederatedLoginIQIYI = 22,      // 爱奇艺联合登录
    PASSLastLoginTypeOneKey = 40,                   // 一键登录，已废弃！！！请使用下面具体的运营商类型
    PASSLastLoginTypeYY = PASSThirdSSOTypeYY,       // YY登录（100）
    PASSLastLoginTypeWXWork = PASSThirdSSOTypeWXWork,           // 企业微信
    PASSLastLoginTypeDingDing = PASSThirdSSOTypeDingDing,       // 钉钉
    PASSLastLoginTypeGoogle = 110,                  // Google登录
    PASSLastLoginTypeFacebook = 111,                // Facebook登录
    PASSLastLoginTypeTwitter = 112,                 // Twitter登录
};

/**
 *  绑定控件类型
 */
typedef NS_ENUM(NSUInteger, SAPIBindWidgetType){
    /**
     *  绑定手机
     */
    SAPIBindWidgetTypeBindMobile,
    /**
     *  换绑手机
     */
    SAPIBindWidgetTypeRebindMobile,
    /**
     *  绑定邮箱
     */
    SAPIBindWidgetTypeBindEmail,
    /**
     *  换绑邮箱
     */
    SAPIBindWidgetTypeRebindEmail,
    /**
     *  解绑邮箱
     */
    SAPIBindWidgetTypeUnbindEmail,
};

/**
 *  用户帐号类型
 */
typedef NS_ENUM(NSUInteger, SAPIUserCompleteType) {
    /**
     *  完整帐号
     */
    SAPIUserCompleteTypeNormalUser,
    /**
     *  半帐号
     */
    SAPIUserCompleteTypeIncompleteUser,
    /**
     *  未知类型，产品线需要自行查询
     */
    SAPIUserCompleteTypeUnknown,
};

/**
 *  NA与H5登录态同步策略
 *  当NA Bduss和H5 Bduss出现不一致时，根据以下策略决定最终登录状态<br/>
 *  1.SAPINativeH5SyncStrategyNativePriority —— NA优先，直接使用NA登录态覆盖H5登录态<br/>
 *  2.SAPINativeH5SyncStrategyH5Priority —— H5优先，亦即最后一次登录的帐号优先，将H5登录状态同步到NA<br/>
 */
typedef NS_ENUM(NSUInteger, SAPINativeH5SyncStrategy) {
    SAPINativeH5SyncStrategyNativePriority,
    SAPINativeH5SyncStrategyH5Priority,
};

typedef NS_OPTIONS(NSUInteger, PASSLoginDisplayAccountType) {
    PASSLoginDisplayAccountTypeALL = 1 << 0,            // 默认展示全部（supportFaceLogin和supportTouchLogin设置优先）
    PASSLoginDisplayAccountTypeExceptShare = 1 << 1,    // 不展示互通
    PASSLoginDisplayAccountTypeExceptOneKey = 1 << 2,   // 不展示一键登录
    PASSLoginDisplayAccountTypeExceptHistory = 1 << 3,  // 不展示历史登录
    PASSLoginDisplayAccountTypeExceptFace = 1 << 4,     // 不展示刷脸（如果已设置全局supportFaceLogin属性，则该属性自动生效）
    PASSLoginDisplayAccountTypeExceptFinger = 1 << 5,   // 不展示指纹及指纹引导（如果已设置全局supportTouchLogin属性，则该属性自动生效）
};

/**
 *  @brief NA和H5登录态同步成功回调策略
 *
 *  @since 6.15.15
 */
typedef NS_ENUM(NSUInteger, SAPINativeH5SyncCallbackStrategy) {
    /**
     *  登录态同步成功后立刻回调
     *
     *  @since 6.15.15
     */
    SAPINativeH5SyncCallbackStrategyImmediately,
    /**
     *  登录态同步成功后，先对STOKEN进行预取，预取成功后回调；预取失败回调同步失败。
     *
     *  @since 6.15.15
     */
    SAPINativeH5SyncCallbackStrategyAfterStokenRetrieved,
};

/**
 *  @brief 国际化
 */
typedef NS_ENUM(NSUInteger, SAPII18NType) {
    /**
     *  中文
     */
    SAPII18NZh_Cn,
    /**
     *  英文
     */
    SAPII18NEng,
    /**
     *  繁体
     */
    SAPII18NZh_HK,
};

typedef NS_OPTIONS(NSUInteger, SAPIBiometricOptions) {
    SAPIBiometricOptionLivenessRecog = 1 << 0,
    SAPIBiometricOptionVoiceVerify = 1 << 1,
};

typedef NS_ENUM(NSUInteger, SAPINativeURLType) {
    SAPINativeURLTypeNone,
    SAPINativeURLTypeAppeal,
    SAPINativeURLTypeLiveness,
    // 通过扫码同步登录状态出去(SAPINativeURLTypeQRCodeLoginStatusOut)
    SAPINativeURLTypeQRCodeLogin,
    // 通过扫码同步登录状态进来
    SAPINativeURLTypeQRCodeLoginStatusIn,
};

typedef NS_ENUM(NSUInteger, SAPIWebURLType) {
    //未知类型
    SAPIWebURLTypeNone,
    //通过oauth将登录态同步出去到其它设备，需使用 PASSWebViewController 打开该类型的 url
    //（https://openauth.baidu.com/doc/doc.html 对应文档 2.0 部分url）
    SAPIWebURLTypeOauthLoginStatusOut
};

typedef NS_ENUM(NSUInteger, PASSLogoutType) {
    PASSLogoutTypeDefault = 0,      /// 默认
    PASSLogoutTypeUserOperation,    /// 用户操作
    PASSLogoutTypeNotOnline,        /// 用户登录态失效
    PASSLogoutTypeError,            /// 用户登录态报错
    PASSLogoutTypeDestroyed,        /// 用户注销账号
    PASSLogoutTypeFrozen,           /// 用户冻结账号
};

//Service方法回调
typedef void (^SAPIRequestCompletionBlock)(NSDictionary *info);
typedef void (^SAPIRequestErrorBlock)(NSDictionary *errorInfo);

//登录相关Notification
// SAPI中相关行为所产生的Notification

/**
 *  支持互通帐号登陆成功消息 notification中的userInfo中会有登录成功后的json字典
 */
#define kLoginSucceedNotification        @"kLoginSucceedNotification"

/**
 *  不支持互通帐号登陆成功消息 notification中的userInfo中会有登录成功后的json字典
 */
#define kUnsharedLoginSucceedNotification @"kUnsharedLoginSucceedNotification"

/**
 *  登陆失败消息
 */
#define kLoginFailNotification           @"kLoginFailNotification"

/**
 *  补填用户名成功消息 notification中的userInfo中会有注册成功后的json字典
 */
#define kFillUnameSucceedNotification    @"kFillUnameSucceedNotification"

/**
 *  退出返回信息
 */
#define kLogOutNotification              @"kLogOutNotification"

/**
 *  更新主题
 */
#define kPASSUpdateThemeNotification              @"kPASSUpdateThemeNotification"

// ==== Login Extra Info Key ====
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoIncompleteUserKey;
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoSourceKey;
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoActionTypeKey;
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoUserInfoKey;
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoKey;
// 标识从帐号切换场景完成登录
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoSceneFromKey;
// 是否首次登录
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoFirstLoginKey;
// 是否是来源半屏登录组件 值详见 PASSFastLoginActionType
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoFromFastLoginKey;

// ==== Login Extra Info Value ====
// 登录来源：H5登录
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoSourceFromH5LoginValue;
// 登录类型：登录
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoActionTypeLogin;
// 登录类型：注册
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoActionTypePhoneReg;
// 登录类型：命中风控登录
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoActionTypeLoginProtect;
// 登录类型：选择互通
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoActionTypeChoiceShareLogin;

FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoFirstLogin;
FOUNDATION_EXPORT NSString * const SAPILoginExtraInfoNotFirstLogin;

// ==== SceneFrom Value ====
// 标识从帐号切换场景完成登录
FOUNDATION_EXPORT NSString * const SAPILoginSceneFromSwitchAccount;


// ==== SAPI NSError UserInfo Keys and Values ====
FOUNDATION_EXPORT NSString * const SAPIBdussPtokenInvalidReasonKey;
/**
 *  @brief 本地PTOKEN缺失
 */
FOUNDATION_EXPORT NSString * const SAPIBdussPtokenInvalidReasonMissingPtoken;
/**
 *  @brief BDUSS无效
 */
FOUNDATION_EXPORT NSString * const SAPIBdussPtokenInvalidReasonUserNotOnline;
/**
 *  @brief PTOKEN和BDUSS不匹配
 */
FOUNDATION_EXPORT NSString * const SAPIBdussPtokenInvalidReasonBdussPtokenNotMatch;

// ==== Cookie Synchronization Notification ====
FOUNDATION_EXPORT NSString * const SAPICookieSyncH5CookieClearedNotification;

// 打开PASS WKWebView的通知，宿主需关闭网络接管，否则会导致 WKWebView 内 Post 请求丢失Body，
// 详见：http://wiki.baidu.com/pages/viewpage.action?pageId=883727274
FOUNDATION_EXPORT NSString * const HSLockWKNetworkHandleNotification;
// 关闭PASS WKWebView的通知，宿主可开启网络接管
FOUNDATION_EXPORT NSString * const HSUnlockWKNetworkHandleNotification;

// ==== 第三方登录绑定授权信息Key ====
FOUNDATION_EXPORT NSString * const PASSThirdBindAccessTokenKey;
FOUNDATION_EXPORT NSString * const PASSThirdBindOpenIdKey;
FOUNDATION_EXPORT NSString * const PASSThirdBindUnionIdKey;
FOUNDATION_EXPORT NSString * const PASSThirdBindAuthCodeKey;
FOUNDATION_EXPORT NSString * const PASSThirdBindAppIdKey;
// 新浪微博
FOUNDATION_EXPORT NSString * const PASSThirdBindUserIDKey;
FOUNDATION_EXPORT NSString * const PASSThirdBindRefreshTokenKey;
//sign in with apple
FOUNDATION_EXPORT NSString * const PASSThirdBindIDTokenKey;
FOUNDATION_EXPORT NSString * const PASSThirdBindFullNameKey;
FOUNDATION_EXPORT NSString * const PASSThirdBindEmailKey;

// ==== PASSRouter Defines ====
FOUNDATION_EXPORT NSString * const PASSRouterResultKey;
FOUNDATION_EXPORT NSString * const PASSRouterSuccessKey;
FOUNDATION_EXPORT NSString * const PASSRouterCancelKey;

typedef NSString * const PASSControllerCloseKey;

FOUNDATION_EXPORT PASSControllerCloseKey PASSControllerCloseDestroyedKey;       /// 用户注销 isAccountDestroyed
FOUNDATION_EXPORT PASSControllerCloseKey PASSControllerCloseFrozenKey;          /// 用户状态冻结 isAccountFrozen
FOUNDATION_EXPORT PASSControllerCloseKey PASSControllerCloseUpdateKey;          /// 用户信息有更新（当前用户名）isAccountUpdate
FOUNDATION_EXPORT PASSControllerCloseKey PASSControllerCloseGuarderKey;         /// 监护人信息更新

typedef NSString * const PASSWebViewExtraQueryKey;

// ==== 账号中心页面隐藏修改头像入口 ====
FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSAccountCenterThirdKey;
FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSAccountCenterAvatarKey;
FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSAccountCenterUserChoiseGuideKey; /// 用户点击了飘红状态下的帐号管理入口时传递

// ==== 小程序二级、三级渠道标识 ====
FOUNDATION_EXPORT PASSWebViewExtraQueryKey  PASSChannelTPLSecondKey;
FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSChannelTPLThreeKey;

// ==== webview页面自定义样式url，产品需传入经encode的url ====
FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSCustomConfigStyleKey;

// ==== 游客帐号增加注销入口，符合苹果规范 ====
FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSErasureGuestAccountKey;  /// 展示游客账号注销入口，1为展示，0为不展示（仅PASSGuestNormalizeViewController生效）
FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSStoreCheckingKey;    /// 苹果商店审核状态，0为正常，否则为审核状态

// ==== App调起Pass页面Scheme ====
FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSAppSchemeKey;

// ==== 微信第三方登录透传pass需要请求openid ====
FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSRequestWeixinOpenidKey;          /// 是否在微信登录同时，获取微信openid
FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSRequestWeixinOpenidFromKey;      /// 业务线标识来源（如lite和手百共用tpl，导致无法使用tpl区分场景）

FOUNDATION_EXPORT PASSWebViewExtraQueryKey PASSAccountCenterShieldKey;          /// 帐号管理页屏蔽选项

/// 字体大小常量
typedef NSUInteger const PASSMeasureModeKey;

FOUNDATION_EXPORT PASSMeasureModeKey PASSMeasureModeKeySmall;           /// 86
FOUNDATION_EXPORT PASSMeasureModeKey PASSMeasureModeKeyNormal;          /// 100
FOUNDATION_EXPORT PASSMeasureModeKey PASSMeasureModeKeyLarge;           /// 106
FOUNDATION_EXPORT PASSMeasureModeKey PASSMeasureModeKeyExtraLarge;      /// 121
FOUNDATION_EXPORT PASSMeasureModeKey PASSMeasureModeKeySuperLarge;      /// 121

#endif
