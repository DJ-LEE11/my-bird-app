//
//  PASSFastLoginDefine.h
//  PassportKit
//
//  Created by sunchao19 on 2022/1/7.
//  Copyright © 2022 Baidu Passport. All rights reserved.
//

#ifndef PASSFastLoginDefine_h
#define PASSFastLoginDefine_h

#import <UIKit/UIKit.h>
#import <PassportKit/SAPIDefine.h>

NS_ASSUME_NONNULL_BEGIN

@class PASSFastLoginViewController;

/// 面板类型
typedef NS_ENUM(NSUInteger, PASSFastLoginPanelType) {
    PASSFastLoginPanelTypeLoading,     // 加载态
    PASSFastLoginPanelTypeShare,       // 互通登录
    PASSFastLoginPanelTypeOnekey,      // 一键登录
    PASSFastLoginPanelTypeHistory,     // 历史登录
    PASSFastLoginPanelTypeSMS          // 短信登录
};

/// 第三方登录方式配置类
@interface PASSFastLoginThirdButtonConfig : NSObject

@property (nonatomic, strong) UIImage *defalutImage;
@property (nonatomic, nullable, strong) UIImage *darkImage;
@property (nonatomic, assign) PASSThirdSSOType type;

/// 是否强制勾选同意协议才可进行下一步（注意：仅 type = PASSThirdSSOTypeUnknow 生效），默认强制
@property (nonatomic, assign, getter=isMandatoryAgreement) BOOL mandatoryAgreement;
@property (nonatomic, copy) void(^tapped)(PASSFastLoginThirdButtonConfig *, PASSFastLoginPanelType panelType);

@end

typedef NSString * PASSFastLoginActionType NS_STRING_ENUM;

FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeWechat;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeQQ;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeSina;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeYY;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeFacebook;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeGoogle;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeTwitter;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeApple;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeDingDing;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeWXWork;      // 暂未开放使用
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeHistory;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeShare;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeCM;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeCU;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeCT;
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeReg;             /// 注册登录
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeClose;           /// 点击了关闭按钮
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeMaskClose;       /// 点击mask视图
FOUNDATION_EXPORT PASSFastLoginActionType const PASSFastLoginActionTypeSMS;             /// 短信登录

/// 面板主题配置
@interface PASSFastLoginThemeConfig : NSObject

/**
 * 面板标题（适用：所有）
 * 默认文案为 登录百度账号，精彩永相随
 * 标题颜色 默认为 亮色 0x1F1F1F 透明度1 暗色 0xFFFFFF 透明度 0.8
 */
@property (nonatomic, copy, nullable) NSAttributedString *panelTitleAttrString;

/// 登录按钮文案，默认为 一键登录（适用：历史、互通、一键）
@property (nonatomic, copy, nullable) NSString *loginBtnTitle;

/// 登录按钮正常状态颜色 默认为 0x4E6EF2 （适用：历史、互通、一键）
@property (nonatomic, strong, nullable) UIColor *loginBtnNormalColor;

/// 登录按钮高亮状态颜色 默认为 0x4E6EF2 透明度 0.2 （适用：历史、互通、一键）
@property (nonatomic, strong, nullable) UIColor *loginBtnHighlightedColor;

/// 账号框渐变颜色开始颜色设置 默认为 亮色 0xF5F5F5 透明度 1 暗色 0x333333 透明度1（适用：历史、互通）
@property (nonatomic, strong, nullable) UIColor *gradientLayerStartColor;

/// 账号框渐变颜色结束颜色设置 默认为 亮色 0xF5F5F5 透明度 0 暗色 0x333333 透明度0（适用：历史、互通）
@property (nonatomic, strong, nullable) UIColor *gradientLayerEndColor;

/// 用户名颜色，默认为  亮色 0x1F1F1F 透明度1 暗色 0xFFFFFF 透明度 0.8（适用：历史、互通）
@property (nonatomic, strong, nullable) UIColor *displaynameColor;

/// 打码手机号颜色 默认为 亮色 0x1F1F1F  透明度1 暗色  0xFFFFFF 透明度 0.8（适用：一键）
@property (nonatomic, strong, nullable) UIColor *maskPhoneColor;

@end

/// 可便捷登录的账号Model（外部切记只能使用，不可修改该Model）
@interface PASSFastLoginModel : NSObject

@property (nonatomic, strong) id originData;
@property (nonatomic, assign) PASSFastLoginPanelType panelType;

@end

/// 历史、互通登录的账号Model（外部切记只能使用，不可修改该Model）
@interface PASSFastLoginShareModel : PASSFastLoginModel

@property (nonatomic, copy) NSString *headImgUrlString;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subTitle;

@end

/// 一键登录的账号Model（外部切记只能使用，不可修改该Model）
@interface PASSFastLoginOneKeyModel : PASSFastLoginModel

@property (nonatomic, copy) NSString *maskPhone;

@end

typedef NSString * PASSProtocolString NS_STRING_ENUM;
FOUNDATION_EXPORT PASSProtocolString const PASSProtocolStringForUser;
FOUNDATION_EXPORT PASSProtocolString const PASSProtocolStringForPrivacy;
FOUNDATION_EXPORT PASSProtocolString const PASSProtocolStringForCMCC;
FOUNDATION_EXPORT PASSProtocolString const PASSProtocolStringForCUCC;
FOUNDATION_EXPORT PASSProtocolString const PASSProtocolStringForCTCC;
FOUNDATION_EXPORT PASSProtocolString const PASSProtocolStringForChild;

typedef NSString * PASSFastLoginProtocolURL NS_STRING_ENUM;
FOUNDATION_EXPORT PASSFastLoginProtocolURL const PASSFastLoginProtocolURLForUser;           /// 百度用户协议
FOUNDATION_EXPORT PASSFastLoginProtocolURL const PASSFastLoginProtocolURLForPrivacy;        /// 隐私政策
FOUNDATION_EXPORT PASSFastLoginProtocolURL const PASSFastLoginProtocolURLForCMCC;           /// 中国移动认证服务条款
FOUNDATION_EXPORT PASSFastLoginProtocolURL const PASSFastLoginProtocolURLForCUCC;           /// 中国联通认证服务协议
FOUNDATION_EXPORT PASSFastLoginProtocolURL const PASSFastLoginProtocolURLForCTCC;           /// 中国电信天翼账号服务条款
FOUNDATION_EXPORT PASSFastLoginProtocolURL const PASSFastLoginProtocolURLForChild;          /// 

/// 便捷组件自定义隐私协议内容
@interface PASSFastLoginProtocolConfig : NSObject

@property (nonatomic, copy) NSAttributedString *attributedText;                               /// 协议内容
@property (nullable, nonatomic, copy) NSDictionary<NSAttributedStringKey,id> *linkTextAttributes;

@property (nullable, nonatomic, strong) NSArray <NSValue *>*linkTextRanges;

/// 如果 selectedImg或notSelectedImg 均为空，则不展示勾选按钮
@property (nullable, nonatomic, strong) UIImage *selectedImg;             /// 选中样式图片
@property (nullable, nonatomic, strong) UIImage *notSelectedImg;          /// 未选中样式图片

/// 默认选中状态（默认为NO）
@property (nonatomic, assign) BOOL defaultSelected;

/// 点击协议内的链接
@property (nullable, nonatomic, copy) void (^actionForUrl)(NSURL *url);

@end

/// 面板关闭对象
@interface PASSFastLoginPanelClosedModel : NSObject

@property (nonatomic, assign) PASSFastLoginPanelType panelType;

/// 注意：面板关闭原因可能为空
@property (nullable, nonatomic, copy) PASSFastLoginActionType reason;

@end

@protocol PASSFastLoginViewControllerDelegate <NSObject>

@required
/**
 * 半弹层组件弹出toast提示（自动消失）
 * 受包大小及app样式影响，toast使用app样式弹出
 */
- (void)fastLoginController:(PASSFastLoginViewController *)ctrl panelType:(PASSFastLoginPanelType)type toastMsg:(NSString *)msg;

/**
 * 半弹层组件弹出toast提示（不自动消失，直到调用 hideProgressToastWith:panelType: 才应该消失提示）
 */
- (void)showProgressToastWith:(PASSFastLoginViewController *)ctrl panelType:(PASSFastLoginPanelType)type toastMsg:(nullable NSString *)msg;
- (void)hideProgressToastWith:(PASSFastLoginViewController *)ctrl panelType:(PASSFastLoginPanelType)type;

@optional

#pragma mark 面板类型相关
/**
 * 主题设置相关
 */
- (PASSFastLoginThemeConfig *)fastLoginController:(PASSFastLoginViewController *)ctrl themeConfigForPanelType:(PASSFastLoginPanelType)type theme:(SAPIThemeStyle)themeStyle;

/**
 * 获取第三方登录方式
 */
- (NSArray <PASSFastLoginThirdButtonConfig *> *)thirdButtonsWithFastController:(PASSFastLoginViewController *)ctrl panelType:(PASSFastLoginPanelType)type;

/**
 * 换个登录方式按钮点击代理
 */
- (void)showMoreLoginWayControllerWithPanelType:(PASSFastLoginPanelType)type info:(nullable NSDictionary *)info;

/**
 * 自定义头图
 *
 * 注意，产品线必须要约束头图高度，头图高度一旦固定，则不会修改，产品线需注意各场景下自定义头图高度保持一致
 */
- (void)headViewWithContent:(UIView *)content panelType:(PASSFastLoginPanelType)type theme:(SAPIThemeStyle)themeStyle;

#pragma mark 面板类型不相关
/**
 * 面板支持的主题
 */
- (PASSThemeStyle)supportThemeForFastLoginController:(PASSFastLoginViewController *)ctrl;

/**
 * 背景颜色
 * 由于有loading页面存在，因此背景颜色为了美观，不区分面板类型，要设置则所有页面背景都一致
 */
- (UIColor *)panelBackgroundColorWithTheme:(SAPIThemeStyle)themeStyle;

#pragma mark 短信验证码面板相关

/// 获取短信验证码成功
- (void)fastLoginController:(PASSFastLoginViewController *)ctrl getSmsCodeSuccess:(NSDictionary *)info;

/// 获取短信验证码失败
- (void)fastLoginController:(PASSFastLoginViewController *)ctrl getSmsCodeFailed:(NSError *)err info:(NSDictionary *)info;

/// 短信登录需要回退
- (void)fastloginController:(PASSFastLoginViewController *)ctrl needBack:(NSString *)phoneNumber;

#pragma mark 隐私协议相关

/**
 * 自定义隐私协议
 *
 * 优先级：最高
 * 注意：如果实现该协议，以下隐私相关协议将不会调用
 *      protocolView:defaultSelectedForPanelType:
 *      protocolView:shouldShowForPanelType:
 *      protocolView:hideSelectedImgForPanelType:
 *
 * 实现该协议，需要将所有类型协议均定义实现，如果不展示返回nil即可
 * 如果不实现该协议，则走默认协议
 */
- (nullable PASSFastLoginProtocolConfig *)protocolView:(PASSFastLoginViewController *)ctrl panelType:(PASSFastLoginPanelType)type;

/**
 * 控制协议是否默认选择（仅控制默认协议的选择）
 * 优先级：pass云控 > 代理方法返回 >  不勾选
 */
- (BOOL)protocolView:(PASSFastLoginViewController *)ctrl defaultSelectedForPanelType:(PASSFastLoginPanelType)type;

/**
 * 控制协议是否展示（仅控制默认协议的展示）
 * 默认展示
 */
- (BOOL)protocolView:(PASSFastLoginViewController *)ctrl shouldShowForPanelType:(PASSFastLoginPanelType)type;

/**
 * 控制协议选择按钮是否展示（仅控制默认协议的展示）
 * 默认展示
 */
- (BOOL)protocolView:(PASSFastLoginViewController *)ctrl hideSelectedImgForPanelType:(PASSFastLoginPanelType)type;

/**
 * 面板关闭回调
 */
- (void)fastLoginController:(PASSFastLoginViewController *)ctrl panelClosed:(PASSFastLoginPanelClosedModel *)model;

@end

NS_ASSUME_NONNULL_END

#endif /* PASSFastLoginDefine_h */
