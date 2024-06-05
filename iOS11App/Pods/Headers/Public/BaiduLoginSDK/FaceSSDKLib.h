//
//  FaceSSDKLib.h
//  FaceSSDKLib v1.1.0
//
//  Created by Gong,Jialiang on 2018/2/26.
//  Copyright © 2018年 Gong,Jialiang. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger, DeployModeType) {
    DeployModeTypeOffline, // 离线模式
    DeployModeTypeOnline // 在线模式
};

__attribute__((visibility("default")))
@interface FaceSSDKLib : NSObject

/**
 返回单例对象
 */
+ (instancetype)sharedInstance;


/**
 启动FaceSDK，需要传入已经申请好的appKey和secretKey

 @param appKey
 @param secretKey 
 */
- (void)startSDKWithAppKey:(NSString *)appKey secretKey:(NSString *)secretKey deployMode:(DeployModeType)deployModeType;

/**
 返回FaceSDK运行环境信息

 @return 包含FaceID和ztoken两个字段，{ @“0”: (NSString*)ztoken, @“1”:(NSString*)faceID}
 */
- (NSDictionary *)getFaceInfo;


- (void)setFaceLicenseId:(NSString *)faceLicenseId;

@end
