//
//  PASSOpenURLHandler.h
//  PassportKit
//
//  Created by jiangzhenjie on 2018/7/10.
//  Copyright © 2018年 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PASSOpenURLHandleDelegate <NSObject>

@optional

- (void)passOpenURLHandlerDidHandleOpenURL:(nonnull NSURL *)openURL result:(nullable NSDictionary *)result error:(nullable PASSError *)error;

// Web调起App：是否能在 App 内打开 URL
- (BOOL)passOpenURLHandlerAPPCanHandleURL:(nonnull NSURL *)url sourceApp:(nullable NSString *)sourceApp;

// Web调起App：APP 处理 Web传入的 URL
- (BOOL)passOpenURLHandlerAPPHandleURL:(nonnull NSURL *)url sourceApp:(nullable NSString *)sourceApp;
@end

// 处理OpenURL基类，这是一个类簇
// 注意：该类不能处理第三方登录回调结果，只能处理PASS自身的OpenURL
@interface PASSOpenURLHandler : NSObject

// == Subclass must implement these methods ==
+ (BOOL)canHandleOpenURL:(nonnull NSURL *)openURL sourceApplication:(nonnull NSString *)sourceApplication
DEPRECATED_MSG_ATTRIBUTE("Use PASSRouter same function instead, this class will be removed in a future release and should be avoided");
+ (BOOL)handleOpenURL:(nonnull NSURL *)openURL sourceApplication:(nonnull NSString *)sourceApplication delegate:(nullable id<PASSOpenURLHandleDelegate>)delegate
DEPRECATED_MSG_ATTRIBUTE("Use PASSRouter same function instead, this class will be removed in a future release and should be avoided");

@end
