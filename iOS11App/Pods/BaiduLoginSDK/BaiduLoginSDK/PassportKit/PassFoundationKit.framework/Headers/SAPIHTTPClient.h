//
//  SAPIHTTPClient.h
//  SAPILib
//
//  Created by jinsong on 5/18/15.
//  Copyright (c) 2015 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SAPIHTTPClient : NSObject

@property (nonatomic, strong, nullable) NSURLSession *session;
@property (nonatomic, copy) NSString *userAgent;

/* GET */
- (void)getPath:(NSString *)path
     parameters:(NSDictionary *)parameters
        success:(void (^ __nullable)(id responseObject))success
        failure:(void (^ __nullable)(NSError *responseError))failure;

- (void)getPath:(NSString *)path
     parameters:(NSDictionary *)parameters
        timeout:(NSTimeInterval)interval
        success:(void (^ __nullable)(id responseObject))success
        failure:(void (^ __nullable)(NSError *responseError))failure;

- (NSURLSessionDataTask *)getWithRequest:(NSURLRequest *)request completionHandler:(void (^ __nullable)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/* POST */
- (void)postPath:(NSString *)path
      parameters:(NSDictionary *)parameters
         success:(void (^ __nullable)(id responseObject))success
         failure:(void (^ __nullable)(NSError *responseError))failure;

- (NSURLSessionDataTask *)postWithRequest:(NSURLRequest *)request success:(void (^ __nullable)(id responseObject))success failure:(void (^ __nullable)(NSError *responseError))failure;

- (NSURLSessionDataTask *)postWithRequest:(NSURLRequest *)request completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/* HEAD */
- (NSURLSessionDataTask *)headWithURL:(NSURL *)url completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/* CANCEL */
- (void)cancelAllRequests;

@end

@interface SAPIHTTPRequest : NSObject

+ (NSMutableURLRequest *)requestWithMethod:(NSString *)method
                                      path:(NSString *)path
                                parameters:(NSDictionary *)parameters;

+ (NSMutableURLRequest *)requestWithMethod:(NSString *)method
                                      path:(NSString *)path
                                   timeout:(NSTimeInterval)interval
                                parameters:(NSDictionary *)parameters;
@end

NS_ASSUME_NONNULL_END
