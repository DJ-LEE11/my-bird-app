//
//  UIColor+PASSConvenientAddition.h
//  PassportKit
//
//  Created by jiangzhenjie on 2017/3/31.
//  Copyright © 2017年 Baidu Passport. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (PASSConvenientAddition)

+ (UIColor *)pass_colorWithHex:(NSUInteger)hexValue;

+ (UIColor *)pass_colorWithHex:(NSUInteger)hexValue alpha:(CGFloat)alpha;

@end
