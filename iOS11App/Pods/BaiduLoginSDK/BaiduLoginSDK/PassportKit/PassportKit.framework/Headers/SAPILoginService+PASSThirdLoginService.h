//
//  SAPILoginService+PASSThirdLoginService.h
//  PassportKit
//
//  Created by Gang,Liu on 2019/10/25.
//  Copyright © 2019 Baidu Passport. All rights reserved.
//
#import <PassportKit/PassportKit.h>

NS_ASSUME_NONNULL_BEGIN
@class PASSThirdLoginViewController;
@interface SAPILoginService (PASSThirdLoginService)

#pragma mark - Third Login
- (void)startSsologinWithType:(PASSThirdSSOType)type
                     authInfo:(NSDictionary *)authInfo
                  extraParams:(nullable NSDictionary *)extraParams
                   completion:(void (^)(PASSThirdLoginViewController * _Nullable showVC))completion;
@end

NS_ASSUME_NONNULL_END
