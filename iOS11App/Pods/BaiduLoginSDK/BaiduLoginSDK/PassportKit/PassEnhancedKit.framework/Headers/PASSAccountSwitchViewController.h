//
//  PASSAccountSwitchViewController.h
//  PassportKit
//
//  Created by Gang,Liu on 2020/1/2.
//  Copyright © 2020 Baidu Passport. All rights reserved.
//

#import <PassportKit/PassportKit.h>

NS_ASSUME_NONNULL_BEGIN

// 通过 [SAPIMainManager sharedManager].supportMultipleAccounts配置是否支持多帐号登录

@interface PASSAccountSwitchViewController : PASSWebViewController
/**
 展示关联帐号查询，默认YES
*/
@property (nonatomic, assign) BOOL showLinkAccount;
@end

NS_ASSUME_NONNULL_END
