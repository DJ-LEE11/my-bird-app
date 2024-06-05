//
//  PASSLoginConfig.h
//  PassportKit
//
//  Created by jiangzhenjie on 2018/3/9.
//  Copyright © 2018年 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 帐号输入页样式
 */
typedef NS_ENUM(NSUInteger, PASSLoginEntryPageStyle) {
    PASSLoginEntryPageStyleDefault,          // 默认（用户名、邮箱、手机号）
    PASSLoginEntryPageStyleSMS,              // 手机号
};

/**
 展示错误样式
 */
typedef NS_ENUM(NSUInteger, PASSLoginErrorType) {
    PASSLoginErrorTypeOneKeyLoginFail = 1,     // 一键登录获取token失败
};

/**
 登录配置项
 */
@interface PASSLoginConfig: NSObject

/**
 登录方式，可选帐号密码登录、短信登录、注册
 默认为帐号密码登录
 */
@property (nonatomic, assign) PASSLoginWay loginWay;

// PASSLoginWay to SAPILoginType
@property (nonatomic, assign, readonly) SAPILoginType loginType DEPRECATED_MSG_ATTRIBUTE("Use loginWay instead, this property will be removed in a future release and should be avoided");

/**
 与 -[SAPIMainManager showLoginLink] 功能相同
 登录入口显示判断：短信登录页面是否显示普通登录入口 1 显示  0 隐藏
 默认与 -[SAPIMainManager showLoginLink] 相同
 */
@property (nonatomic, assign) BOOL showLoginLink;

/**
 与 -[SAPIMainManager showSMSLoginLink] 功能相同
 登录入口显示判断：普通登录界面是否显示短信登录入口 1 显示 0 隐藏
 默认与 -[SAPIMainManager showSMSLoginLink] 相同
 */
@property (nonatomic, assign) BOOL showSMSLoginLink;

/**
 与 -[SAPIMainManager showThirdLoginOnSMSLogin] 功能相同
 短信登录界面是否显示第三方登录入口
 默认与 -[SAPIMainManager showThirdLoginOnSMSLogin] 相同
 */
@property (nonatomic, assign) BOOL showThirdLoginOnSMSLogin;

/**
 支持的第三方登录
 数组元素为 SAPILoginOptionType 枚举值，数组为nil或者空数组时，表示不支持第三方登录
 
 默认与 -[SAPIMainManager addLoginOption:] 相同
 
 @code
 NSMutableArray *fastLoginOptions = [NSMutableArray array];
 [fastLoginOptions addObject:@(SAPILoginOptionWeiXinSSO)];
 [fastLoginOptions addObject:@(SAPILoginOptionQQSSO)];
 ...
 @endcode
 
 */
@property (nonatomic, copy) NSArray<NSNumber *> *supportFastLoginOptions;

/**
 当前登录页是否支持指纹引导，默认为YES
 */
@property (nonatomic, assign) BOOL supportTouchGuide;

/**
 联合登陆中需要用户同意的用户协议，格式：
 @[
  @{@"name":@"度秘协议",@"url":@"https://www.baidu.com"},
  @{@"name":@"苏宁协议",@"url":@"https://www.suning.com"}
 ]
 */
@property (nonatomic, copy) NSArray<NSDictionary<NSString *, NSString *> *> *joinLoginAgreements;
/**
 自定义登录页 css 样式文件的路径，默认为 mainBundle 下 sapi-custom-style.css 文件所在的路径
 
 注意：传的必须是 File URL，举例：
 
 @code
 NSString *path = [[NSBundle mainBundle] pathForResource:@"CssStyle.bundle/pass-custom-style-1" ofType:@"css"];
 NSURL *fileURL = [NSURL fileURLWithPath:path];
 @endcode
 */
@property (nonatomic, strong) NSURL *customCssStyleFileURL;

/**
 短信登录页面是否隐藏密码框下面的一排入口，默认为NO，不隐藏
 */
@property (nonatomic, assign) BOOL hideExtraEntry DEPRECATED_ATTRIBUTE;

/**
 关闭选择互通页面，仅对白名单产品线生效
 */
@property (nonatomic, assign) BOOL disableChoiceShareLogin DEPRECATED_MSG_ATTRIBUTE("Use displayAccountType instead, this property will be removed in a future release and should be avoided");

/**
 定向调起登录页参数，预置的加密 uid
 */
@property (nonatomic, copy) NSString *encryptedId;

/**
 定向调起登录页参数，预置的用户名，保证与设置的 PASSLoginWay 一致
 */
@property (nonatomic, copy) NSString *displayName;

/**
 用户 uid
 跨证书互通页改H5需求，在授权失败，弹登录时，需要加入direct参数给前端
 且需要在 sapi_action_directed_login 的方法内返回给H5 uid和displayname
 */
@property (nonatomic, copy) NSString *uid;

/**
 隐藏登录成功提示页，默认为 NO
 */
@property (nonatomic, assign) BOOL hideSuccessTip;

/**
 帐号输入页样式
 */
@property (nonatomic, assign) PASSLoginEntryPageStyle entryPageStyle;

/**
 发生错误时，跳转帐号输入页，展示错误提示，仅在 PASSLoginWayInsertAccount 类型下有效果
 */
@property (nonatomic, assign) PASSLoginErrorType errorType;

@property (nonatomic, assign) PASSLoginDisplayAccountType displayAccountType;

//青春版弹出页面样式使用UIModalPresentationPageSheet，因此需要在顶部展示该样式关闭按钮
@property (nonatomic, assign) BOOL showTopCloseButton;

/// 预设用户名（注意，仅 loginway 为 PASSLoginWayPreLogin 时有效）
@property (nonatomic, copy) NSString *preLoginName;

/**
 9.3.18+版本
 用户在登录页面录屏/截屏时，是否展示安全提示弹窗（合规需要，目前仅金融场景-度小满，需要提示弹窗）
 默认 NO
 */
@property (nonatomic, assign) BOOL showScreenCapturedTip;

/**
 创建 PASSLoginConfig 实例

 @return PASSLoginConfig 实例
 */
+ (instancetype)config;

@end
