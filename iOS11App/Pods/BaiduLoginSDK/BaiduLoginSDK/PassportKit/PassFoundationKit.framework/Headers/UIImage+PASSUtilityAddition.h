//
//  UIImage+PASSUtilityAddition.h
//  PassportKit
//
//  Created by jiangzhenjie on 2018/7/9.
//  Copyright © 2018年 Baidu Passport. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (PASSUtilityAddition)

+ (UIImage *)pass_imageWithColor:(UIColor *)color;

+ (UIImage *)pass_imageWithColor:(UIColor *)color rect:(CGRect)rect;

- (NSString *)pass_base64EncodedString;

- (UIImage *)pass_imageWithTintColor:(UIColor *)tintColor;

- (UIImage *)pass_imageWithGradientTintColor:(UIColor *)tintColor;

- (UIImage *)pass_imageWithScale:(CGFloat)scale blendMode:(CGBlendMode)blendMode;

- (UIImage *)pass_imageWithTintColor:(UIColor *)tintColor scale:(CGFloat)scale blendMode:(CGBlendMode)blendMode;

- (UIImage *)croppedImageWithFrame:(CGRect)frame;

+ (UIImage*)scaledWithImage:(UIImage*)image toSize:(CGSize)size;

- (UIImage *)pass_imageRotatedByRadians:(CGFloat)radians;

+ (UIImage *)resizableImageWithColor:(UIColor *)color cornerRadius:(CGFloat)cornerRadius;
@end
