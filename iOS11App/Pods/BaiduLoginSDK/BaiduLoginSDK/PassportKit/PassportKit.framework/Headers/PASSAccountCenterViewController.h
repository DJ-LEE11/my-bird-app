//
//  PASSAccountCenterViewController.h
//  PassportKit
//
//  Created by jiangzhenjie on 2017/3/31.
//  Copyright © 2017年 Baidu Passport. All rights reserved.
//

#import <PassportKit/PASSWebViewController.h>

typedef NS_OPTIONS(NSInteger, PASSAccountCenterOption) {
    PASSAccountCenterOptionShieldUname = 1 << 0,                    /// 用户名
    PASSAccountCenterOptionShieldPhone = 1 << 1,                    /// 绑定手机
    PASSAccountCenterOptionShieldCert = 1 << 2,                     /// 身份认证
    PASSAccountCenterOptionShieldPwd = 1 << 3,                      /// 登录密码
    PASSAccountCenterOptionShieldEmail = 1 << 4,                    /// 绑定邮箱
    PASSAccountCenterOptionShieldProtect = 1 << 5,                  /// 帐号保护
    PASSAccountCenterOptionShieldWay = 1 << 6,                      /// 登录方式
    PASSAccountCenterOptionShieldDevice = 1 << 7,                   /// 登录设备
    PASSAccountCenterOptionShieldAuth = 1 << 8,                     /// 授权管理
    PASSAccountCenterOptionShieldLoginRecords = 1 << 9,             /// 登录记录
    PASSAccountCenterOptionShieldSensitiveRecords = 1 << 10,        /// 敏感记录
    PASSAccountCenterOptionShieldRelated = 1 << 11,                 /// 关联帐号
    PASSAccountCenterOptionShieldAppeal = 1 << 12,                  /// 帐号申诉
    PASSAccountCenterOptionShieldFrost = 1 << 13,                   /// 帐号冻结
    PASSAccountCenterOptionShieldDestroy = 1 << 14,                 /// 帐号注销
    PASSAccountCenterOptionShieldDetection = 1 << 15,               /// 帐号检测
    PASSAccountCenterOptionShieldAvatar = 1 << 16,                  /// 帐号头像
    PASSAccountCenterOptionShieldCustomer = 1 << 17,                /// 我的客服
    PASSAccountCenterOptionShieldFeedback = 1 << 18,                /// 意见反馈
    PASSAccountCenterOptionShieldHelp = 1 << 19,                    /// 帮助中心
    PASSAccountCenterOptionShieldBottomArea =
                        PASSAccountCenterOptionShieldCustomer |
                        PASSAccountCenterOptionShieldFeedback |
                        PASSAccountCenterOptionShieldHelp,          /// 底部区域（我的客服|意见反馈|帮助中心）
};

/**
 帐号中心页面
 */
@interface PASSAccountCenterViewController : PASSWebViewController

@end
