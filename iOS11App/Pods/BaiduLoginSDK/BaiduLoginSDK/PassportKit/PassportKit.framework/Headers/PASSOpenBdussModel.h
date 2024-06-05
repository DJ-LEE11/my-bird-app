//
//  PASSOpenBdussModel.h
//  PassportKit
//
//  Created by Gang,Liu on 2019/9/28.
//  Copyright © 2019 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PASSOpenBdussConfig : NSObject
@property (nonatomic, copy) NSString *clientid; //OAuth应用的标识client_id（也叫app_key）
@property (nonatomic, copy) NSArray *targetTPLList; //tpl列表，用于获取tpl对应的stoken
@end

@interface PASSOpenBdussModel : NSObject
@property (nonatomic, copy) NSString *openbduss; //基于unionid生成的度小满使用的bduss，需要作为cookie种在度小满域
@property (nonatomic, copy) NSString *unionid; //基于开发者uid生成的百度用户唯一标识
@property (nonatomic, copy) NSDictionary *stokenList; //返回一个键值对，其中key为传入的某一tpl，value为对应的stoken。
@property (nonatomic, copy) NSString *uid; //过渡期返回，后续直接从服务端降级不返回
@property (nonatomic, copy) NSString *bduss; //过渡期返回，后续直接从服务端降级不返回
@property (nonatomic, copy) NSString *displayname; //用于显示用途的显示用户名

/**
 *  根据传入参数生成PASSOpenBdussModel实例
 *
 *  @param info 传入参数
 *
 *  @return PASSOpenBdussModel实例
 */
- (instancetype)initWithDictionary:(NSDictionary *)info;

/**
 *  将PASSOpenBdussModel实例转换为键值对
 *
 *  @return 键值对
 */
- (NSDictionary *)toDictionary;
@end

NS_ASSUME_NONNULL_END
