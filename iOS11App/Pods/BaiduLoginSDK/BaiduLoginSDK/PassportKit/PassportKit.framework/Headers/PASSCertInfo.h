//
//  PASSCertInfo.h
//  PassportKit
//
//  Created by sunchao19 on 2022/6/7.
//  Copyright © 2022 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 实名状态
typedef NS_ENUM(NSUInteger, PASSCertRealNameState) {
    PASSCertRealNameStateNone,       /// 未实名
    PASSCertRealNameStateJunior,     /// 初级实名
    PASSCertRealNameStateSenior,     /// 高级实名
};

/// 认证类型
typedef NS_ENUM(NSUInteger, PASSCertType) {
    PASSCertTypeNone,       /// 未认证
    PASSCertTypeFace,       /// 刷脸认证
    PASSCertTypePhone,      /// 手机号认证
};

@interface PASSCertInfo : NSObject

@property (nonatomic, assign, readonly) BOOL isChild;                       /// 当前账号是否是未成年人（<=14 true)
@property (nonatomic, assign, readonly) PASSCertRealNameState realName;     /// 当前账号实名状态
@property (nonatomic, copy, nullable) NSString *idName;                     /// 打码用户真实姓名（若有）
@property (nonatomic, copy, nullable) NSString *idNum;                      /// 打码用户身份证号（若有）


@property (nonatomic, assign, readonly) PASSCertRealNameState guarderRealName;  /// 监护人实名状态
@property (nonatomic, copy, nullable) NSString *guarderIdName;                  /// 监护人打码真实姓名（若有）
@property (nonatomic, copy, nullable) NSString *guarderIdNum;                   /// 监护人打码身份证号（若有）
@property (nonatomic, assign, readonly) PASSCertType guarderCertType;           /// 监护人认证类型

- (instancetype)initWithDictionary:(NSDictionary *)info;

@end

NS_ASSUME_NONNULL_END
