//
//  PassportKit.h
//  PassportKit
//
//  Created by jiangzhenjie on 2017/3/31.
//  Copyright © 2017年 Baidu Passport. All rights reserved.
/**
 Passport版本：9.6.9.101
*/

#import <UIKit/UIKit.h>

FOUNDATION_EXPORT double PassportKitVersionNumber;

FOUNDATION_EXPORT const unsigned char PassportKitVersionString[];

// 工具 & 框架
#import <PassportKit/SAPIWebView.h>
#import <PassportKit/SAPIMainWebView.h>
#import <PassportKit/PASSWebView.h>

// SAPI基本类型定义
#import <PassportKit/SAPIDefine.h>
#import <PassportKit/PASSError.h>

// SAPI通用模型
#import <PassportKit/SAPILoginModel.h>
#import <PassportKit/SAPIOAuthInfo.h>
#import <PassportKit/PASSOneKeyCheckResult.h>
#import <PassportKit/PASSCertInfo.h>
#import <PassportKit/PASSOpenBdussModel.h>
#import <PassportKit/PASSFusionUserInfo.h>

// WKWebView Cookie 同步
#import <PassportKit/WKUserContentController+SAPIH5LoginSyncAddition.h>
#import <PassportKit/SAPIWebView+SAPIConstantAddition.h>

// Utility
#import <PassportKit/PASSViewControllerTerminator.h>
#import <PassportKit/PASSMethodCallTransfer.h>

// Controller
#import <PassportKit/PASSBaseViewController.h>
#import <PassportKit/PASSWebViewController.h>
#import <PassportKit/PASSLoginViewController.h>
#import <PassportKit/PASSAccountCenterViewController.h>
#import <PassportKit/PASSAccountSecurityCenterViewController.h>
#import <PassportKit/UIViewController+PASSConvenient.h>
#import <PassportKit/UINavigationController+PASSConvenient.h>
#import <PassportKit/PASSThirdLoginViewController.h>
#import <PassportKit/PASSAccountRealNameViewController.h>
#import <PassportKit/PASSAccountWebViewController.h>
#import <PassportKit/PASSQRCodeLoginViewController.h>
#import <PassportKit/PASSControllerFactory.h>

#import <PassportKit/PASSRouter.h>
#import <PassportKit/PASSLoginConfig.h>

// SAPI管理组件
#import <PassportKit/SAPILoginService.h>
#import <PassportKit/SAPIMainManager.h>
#import <PassportKit/SAPILogService.h>
#import <PassportKit/SAPILoginService+PASSThirdLoginService.h>
#import <PassportKit/SAPILoginService+PASSEnhancedLogin.h>
#import <PassportKit/PASSOneKeySDKManager.h>

// FaceID
#import <PassportKit/PASSFaceIDService.h>

// PASS OpenURL Handler
#import <PassportKit/PASSOpenURLHandler.h>

