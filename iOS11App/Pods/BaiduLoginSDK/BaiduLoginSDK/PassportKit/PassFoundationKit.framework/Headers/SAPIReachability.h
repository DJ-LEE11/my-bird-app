//
//  SAPIReachability.h
//  SAPILib
//
//  Created by jiangzhenjie on 2016/11/29.
//  Copyright © 2016年 jiangzhenjie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <netinet/in.h>

extern NSString * const SAPIReachabilityChangedNotification;

typedef NS_ENUM(NSUInteger, SAPIReachabilityNetworkStatus) {
    SAPIReachabilityNetworkStatusNotReachable,
    SAPIReachabilityNetworkStatusViaWiFi,
    SAPIReachabilityNetworkStatusViaWWAN,
};

@interface SAPIReachability : NSObject

+ (instancetype)reachabilityWithHostName:(NSString *)hostName;

+ (instancetype)reachabilityWithAddress:(const struct sockaddr *)hostAddress;

+ (instancetype)reachabilityForInternetConnection;

+ (BOOL)networkAvailable;

- (BOOL)startNotifier;

- (void)stopNotifier;

- (SAPIReachabilityNetworkStatus)currentReachabilityStatus;

@end
