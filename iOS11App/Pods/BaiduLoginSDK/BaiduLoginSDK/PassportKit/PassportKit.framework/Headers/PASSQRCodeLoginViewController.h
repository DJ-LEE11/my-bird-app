//
//  PASSQRCodeLoginViewController.h
//  PassportKit
//
//  Created by jiangzhenjie on 2018/1/17.
//  Copyright © 2018年 Baidu Passport. All rights reserved.
//

#import <PassportKit/PassportKit.h>

@class PASSSourceAppInfo;
@interface PASSQRCodeLoginViewController : PASSAccountWebViewController

@property (nonatomic, strong) PASSSourceAppInfo *sourceAppInfo;

@end
