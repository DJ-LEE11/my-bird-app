//
//  PASSOneKeyCheckResult.h
//  PassportKit
//
//  Created by Gang,Liu on 2019/12/12.
//  Copyright © 2019 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PASSOneKeyCheckResult : NSObject

/**
 是否可以使用一键登录
*/
@property (nonatomic, assign) BOOL enable;

/**
 是否存在该帐号一键登录历史
*/
@property (nonatomic, assign) BOOL hasHistory;

/**
 预取的打码手机号
 */
@property (nonatomic, copy) NSString *securityPhoneNum;

/**
 运营商类型
 */
@property (nonatomic, assign) PASSOperatorType operatorType;

/**
 下发的接口校验参数，40位字符串，切割为8+32，转换成[string(8)+[string(32)+大写的passCuid取md5] 取md5]传入
*/
@property (nonatomic, copy) NSString *sign;

/**
 js、md5、url，产品线无需关心，把 checkResult 在下一接口整体传入
*/
@property (nonatomic, copy) NSString *js;
@property (nonatomic, copy) NSString *md5;
@property (nonatomic, copy) NSString *url;

/**
 *  根据传入参数生成PASSOneKeyCheckResult实例
 *
 *  @param info 传入参数
 *
 *  @return PASSOneKeyCheckResult实例
 */
- (instancetype)initWithDictionary:(NSDictionary *)info;

/**
 *  将PASSOneKeyCheckResult实例转换为键值对
 *
 *  @return 键值对
 */
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
