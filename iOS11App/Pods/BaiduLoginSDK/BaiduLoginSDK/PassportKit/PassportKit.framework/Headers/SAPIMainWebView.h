//
//  SAPIMainWebView.h
//  SAPILib
//
//  Created by Vinson.D.Warm on 12/27/13.
//  Copyright (c) 2013 baidu. All rights reserved.
//

#import <PassportKit/SAPIWebView.h>
#import <PassportKit/SAPIDefine.h>

@class SAPIInvokeCommand;

@protocol SAPIMainWebViewDelegate <NSObject>

@optional
- (BOOL)sapiWebView:(SAPIWebView *)webView mainViewShouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(WKNavigationType)navigationType;
- (void)sapiWebViewDidStartLoadFromNetwork:(SAPIWebView *)webView;
- (void)sapiWebViewDidStartLoadFromCache:(SAPIWebView *)webView;
- (void)sapiWebViewDidFinishLoadFromNetwork:(SAPIWebView *)webView;
- (void)sapiWebViewDidFinishLoadFromCache:(SAPIWebView *)webView;
- (void)sapiWebView:(SAPIWebView *)webView didFailLoadFromNetWorkWithError:(NSError *)error;
- (void)sapiWebView:(SAPIWebView *)webView didFailLoadFromCacheWithError:(NSError *)error;

@end

@interface SAPIMainWebView : SAPIWebView

@property (nonatomic, assign) BOOL viewLoaded;

@property (nonatomic, weak) id<SAPIMainWebViewDelegate> mainWebViewDelegate;

/**
 *  第三方登录是否成功
 */
@property (nonatomic, assign, getter = isThirdLoginSucceeded) BOOL thirdLoginSucceeded;

/**
 *  保存页面包含导航栏的url列表
 *
 *  @param whiteList url列表
 */
- (void)saveNavWhiteInfo:(NSDictionary *)whiteList;

/**
 *  检查url是否在“页面包含导航栏的url列表”里
 *
 *  @param url url
 *
 *  @return url在“页面包含导航栏的url列表”里时返回YES，其他返回NO
 */
- (BOOL)checkInWhiteList:(NSURL *)url;

/**
 *  根据URL 获取title
 *
 *  @param url url
 *
 *  @return title
 */
- (NSString *)titleForWhiteListURL:(NSURL *)url;

/**
 *  取消所有网络请求
 */
- (void)cancelAllRequest;

/**
 *  加载选择互通列表
 *  如果有可选择互通的帐号，则会加载选择互通列表；否则webview会自动隐藏。
 */
- (void)loadSharedLoginAccountsIfPossible;

/**
 *  在从微信App获取到code后调用，通过webview传递该参数去换取access_token后获取微信帐号信息，及与之对应的百度帐号信息
 *
 *  @param authInfo 微信App返回字段，需要包含code
 */
- (void)loadWeiXinBindURLWithAuthInfo:(NSDictionary *)authInfo;

/**
*  在从微信App获取到code后调用，通过webview传递该参数去换取access_token后获取微信帐号信息，及与之对应的百度帐号信息
*
*  @param authInfo 微信App返回字段，需要包含code，用于换取access_token
*  @param extra 透传字段
*/
- (void)loadWeiXinBindURLWithAuthInfo:(NSDictionary *)authInfo extraParams:(NSDictionary *)extra;

/**
 从QQ App授权完成，拿到授权信息后，通过加载webview进行绑定操作，获取与之对应的百度帐号信息

 @param authInfo 授权信息，需要包含 accessToken、openId、unionId，一般从 Wrapper 中获取即可。
 */
- (void)loadQQBindURLWithAuthInfo:(NSDictionary *)authInfo;

/**
 从QQ App授权完成，拿到授权信息后，通过加载webview进行绑定操作，获取与之对应的百度帐号信息
 
 @param authInfo 授权信息，需要包含 accessToken、openId、unionId，一般从 Wrapper 中获取即可。
 @param extra 透传字段
 */
- (void)loadQQBindURLWithAuthInfo:(NSDictionary *)authInfo extraParams:(NSDictionary *)extra;

/**
 从新浪微博 App授权完成，拿到授权信息后，SAPILoginModel通过加载webview进行绑定操作，获取与之对应的百度帐号信息
 @param authInfo 授权信息，需要包含 accessToken、userID、refreshToken，一般从 Wrapper 中获取即可。
 */
- (void)loadSinaWeiboBindURLWithAuthInfo:(NSDictionary *)authInfo;

/**
 从新浪微博 App授权完成，拿到授权信息后，通过加载webview进行绑定操作，获取与之对应的百度帐号信息
 
 @param authInfo 授权信息，需要包含 accessToken、userID、refreshToken，一般从 Wrapper 中获取即可。
 @param extra 透传字段
 */
- (void)loadSinaWeiboBindURLWithAuthInfo:(NSDictionary *)authInfo extraParams:(NSDictionary *)extra;

/**
 从sign in with apple授权完成，拿到授权信息后，通过加载webview进行绑定操作，获取与之对应的百度帐号信息
 
 @param authInfo 授权信息，需要包含 idToken、userID、code，一般从 Wrapper 中获取即可。
 @param extra 透传字段
 */
- (void)loadAppleBindURLWithAuthInfo:(NSDictionary *)authInfo extraParams:(NSDictionary *)extra;

- (void)loadYYBindURLWithAuthInfo:(NSDictionary *)authInfo extraParams:(NSDictionary *)extra;
- (void)loadDingDingBindURLWithAuthInfo:(NSDictionary *)authInfo extraParams:(NSDictionary *)extra;
- (void)loadWXWorkBindURLWithAuthInfo:(NSDictionary *)authInfo extraParams:(NSDictionary *)extra;
- (BOOL)loginThirdModelIfExists;

@end
