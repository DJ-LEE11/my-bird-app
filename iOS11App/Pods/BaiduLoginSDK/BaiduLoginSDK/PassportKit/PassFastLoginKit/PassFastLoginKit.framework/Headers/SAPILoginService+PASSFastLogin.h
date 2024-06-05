//
//  SAPILoginService+PASSFastLogin.h
//  PassFastLoginKit
//
//  Created by sunchao19 on 2022/8/9.
//  Copyright © 2022 Baidu Passport. All rights reserved.
//

#import <PassFastLoginKit/PassFastLoginDefine.h>
#import <PassportKit/SAPILoginService.h>

NS_ASSUME_NONNULL_BEGIN

@interface SAPILoginService (PASSFastLogin)

- (void)getFastLoginAccountsWithExtra:(nullable NSDictionary *)extraParams
                          displayType:(PASSLoginDisplayAccountType)type
                              timeout:(NSTimeInterval)timeout
                           completion:(void (^)(NSArray <__kindof PASSFastLoginModel *>* models, BOOL sync))completion;

@end

NS_ASSUME_NONNULL_END
