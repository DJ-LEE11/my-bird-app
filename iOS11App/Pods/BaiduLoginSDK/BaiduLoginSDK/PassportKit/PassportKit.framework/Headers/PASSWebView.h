//
//  PASSWebView.h
//  popLogin
//
//  Created by Gang,Liu on 2018/7/30.
//  Copyright © 2018年 Gang,Liu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@class PASSWebView;
@protocol PASSWebViewDelegate <NSObject>

@optional
- (BOOL)passWebView:(PASSWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(WKNavigationType)navigationType;
- (void)passWebViewDidStartLoad:(PASSWebView *)webView;
- (void)passWebViewDidFinishLoad:(PASSWebView *)webView;
- (void)passWebView:(PASSWebView *)webView didFailLoadWithError:(NSError *)error;

@end


@interface PASSWebView : UIView

@property (nonatomic, weak) id <PASSWebViewDelegate> delegate;
/**
 当前内部使用的webView
 */
@property (nonatomic, readonly, strong) WKWebView *realWebView;

@property (nonatomic, readonly, weak) UIScrollView *scrollView;

@property (nonatomic, readonly, copy) NSURL *URL;

@property (nonatomic, readonly, strong) NSURLRequest *originRequest;
@property (nonatomic, readonly, strong) NSURLRequest *request;

@property (nonatomic, readonly, getter=isLoading) BOOL loading;
@property (nonatomic, readonly, assign) BOOL canGoBack;
@property (nonatomic, readonly, assign) BOOL canGoForward;
@property (nonatomic, assign) BOOL scalesPageToFit;

- (id)loadRequest:(NSURLRequest *)request;
- (id)loadHTMLString:(NSString *)string baseURL:(NSURL *)baseURL;

- (id)goBack;
- (id)goForward;

- (id)reload;
- (id)reloadFromOrigin;

- (void)stopLoading;

- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^)(id, NSError *))completionHandler;

@end
