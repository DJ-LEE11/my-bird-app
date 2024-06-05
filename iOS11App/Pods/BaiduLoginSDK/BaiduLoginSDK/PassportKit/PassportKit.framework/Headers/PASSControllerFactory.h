//
//  PASSControllerFactory.h
//  PassportKit
//
//  Created by Sun,Chao(PPSD) on 2020/6/15.
//  Copyright © 2020 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PASSWebViewController;

typedef NS_ENUM(NSUInteger, PASSCtrlType) {
    PASSCtrlTypeUserAgreement, // 用户协议
    PASSCtrlTypeAppeal,        // 帐号申诉
    PASSCtrlTypeHelpCenter,    // 帮助中心
    PASSCtrlTypeFaceAgreement, // 刷脸用户协议
    PASSCtrlTypeFrostAccount,  // 帐号冻结
    PASSCtrlTypeFindAccount,   // 找回帐号
    PASSCtrlTypeChildVerify,   // 青少年模式认证
    PASSCtrlTypeTrustedDevice, // 登录设备管理
    PASSCtrlTypeAuthWidget,    // 验证控件
    PASSCtrlTypeChildGuarder,  // 儿童监护人
    PASSCtrlTypeBindPhone,     // 修改手机号（注意：已绑定手机才可以使用该页面，该页面较PASSBindWidgetViewController多了前置关闭/开启手机号页面）
    PASSCtrlTypeBindEmail,     // 修改邮箱（注意：已绑定邮箱才可以使用该页面，该页面较PASSBindWidgetViewController多了前置更换/解绑页面）
    PASSCtrlTypeChangeUserName,// 修改用户名
    PASSCtrlTypePrivateList,    // 双清单
    PASSCtrlTypePrivateDownload,    // 个人信息导出
};

typedef NSString *const PASSCtrlParamKey;
/*
 * PASSCtrlParamsCloseCurCtrlIfLoginSuccess
 * 接收值类型：bool
 * 使用类型：PASSCtrlTypeFindAccount
 * 说明：在找回帐号场景下，如果用户选择了登录，则会登录成功，默认pass会关闭找回
 *      帐号页面，但对于部分产品线如果设置为YES（在登录成功代理内调用了
 *      [PASSViewControllerTerminator closePASSViewController]
 *      或执行了关闭pass所有页面）可能会造成关闭多次的问题。因此，该属性需要设置
 *      为NO
 */
FOUNDATION_EXTERN PASSCtrlParamKey PASSCtrlParamsCloseCurCtrlIfLoginSuccess;

/**
 * PASSCtrlParamsAuthWidgetID
 * 接受值类型：string
 * 使用类型：PASSCtrlTypeAuthWidget
 * 说明：调起验证控件时传递id参数，验证结果根据id来pass服务端查询结果
 */
FOUNDATION_EXTERN PASSCtrlParamKey PASSCtrlParamsAuthWidgetID;

@interface PASSControllerFactory : NSObject

+ (nullable __kindof PASSWebViewController *)controllerWithType:(PASSCtrlType)type;
+ (nullable __kindof PASSWebViewController *)controllerWithType:(PASSCtrlType)type params:(nullable NSDictionary *)params;
@end

NS_ASSUME_NONNULL_END
