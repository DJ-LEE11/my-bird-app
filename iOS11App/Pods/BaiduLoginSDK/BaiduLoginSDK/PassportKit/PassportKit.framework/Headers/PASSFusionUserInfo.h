//
//  PASSFusionUserInfo.h
//  PassportKit
//
//  Created by sunchao19 on 2022/11/25.
//  Copyright © 2022 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * PASSFusionField;

FOUNDATION_EXTERN PASSFusionField const PASSFusionFieldUsername;        /// 无论是否设置均返回
FOUNDATION_EXTERN PASSFusionField const PASSFusionFieldDisplayname;     /// 无论是否设置均返回
FOUNDATION_EXTERN PASSFusionField const PASSFusionFieldNickname;
FOUNDATION_EXTERN PASSFusionField const PASSFusionFieldSign;
FOUNDATION_EXTERN PASSFusionField const PASSFusionFieldAvatarMember;
FOUNDATION_EXTERN PASSFusionField const PASSFusionFieldAvatar;
FOUNDATION_EXTERN PASSFusionField const PASSFusionFieldType;
FOUNDATION_EXTERN PASSFusionField const PASSFusionFieldBirth;
FOUNDATION_EXTERN PASSFusionField const PASSFusionFieldCitycode;

@interface PASSFusionUserInfoRequest : NSObject

/// 是否强制从服务端获取（谨慎调用，非必要情况禁止调用，为了减轻服务端QPS）默认为NO
@property (nonatomic, assign) BOOL force;

@property (nonatomic, copy) NSString *appName;

/// 请求所需信息数组
@property (nonatomic, copy, nullable) NSArray <PASSFusionField>*fields;

/// 扩展信息数组
@property (nonatomic, copy, nullable) NSDictionary *extraFields;

@end

@interface PASSFusionUserInfoResponse : NSObject

/// 来源于缓存
@property (nonatomic, assign, readonly) BOOL cached;

@property (nonatomic, copy, readonly) NSString *nickname;           /// 昵称
@property (nonatomic, copy, readonly, nullable) NSString *sign;               /// 签名
@property (nonatomic, copy, readonly) NSString *displayname;
@property (nonatomic, copy, readonly, nullable) NSString *username;
@property (nonatomic, copy, readonly, nullable) NSString *avatarMember;      /// 会员头像字段
@property (nonatomic, copy, readonly, nullable) NSString *avatar;             /// BC融合头像，B账号B头像，C账号PASS头像
@property (nonatomic, copy, readonly, nullable) NSString *birth;              /// 生日
@property (nonatomic, copy, readonly) NSString *citycode;
@property (nonatomic, copy, readonly) NSString *type;               /// 帐号类型（"0" //普通用户（ugc）"1" //百家号（media）"2" //明星号（celebrity））
@property (nonatomic, copy, readonly, nullable) NSDictionary *extFields;      /// 扩展
@end
NS_ASSUME_NONNULL_END
