//
//  PASSDesignMacro.h
//  PassFoundationKit
//
//  Created by Sun,Chao(PPSD) on 2020/8/3.
//  Copyright © 2020 Gang,Liu. All rights reserved.
//

#ifndef PASSDesignMacro_h
#define PASSDesignMacro_h

#define LayoutLeft          NSLayoutAttributeLeft
#define LayoutRight         NSLayoutAttributeRight
#define LayoutTop           NSLayoutAttributeTop
#define LayoutBottom        NSLayoutAttributeBottom
#define LayoutWidth         NSLayoutAttributeWidth
#define LayoutHeight        NSLayoutAttributeHeight

#define PASSLayoutEqual(from, to, attr) [NSLayoutConstraint constraintWithItem:from attribute:attr relatedBy:NSLayoutRelationEqual toItem:to attribute:attr multiplier:1 constant:0]

#define PASSLayoutEqualWithConstant(from, to, attr, cons) [NSLayoutConstraint constraintWithItem:from attribute:attr relatedBy:NSLayoutRelationEqual toItem:to attribute:attr multiplier:1 constant:cons]

#define PASSLayoutCenterX(from, to) [NSLayoutConstraint constraintWithItem:from attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:to attribute:NSLayoutAttributeCenterX multiplier:1 constant:0]

#define PASSLayoutCenterY(from, to) [NSLayoutConstraint constraintWithItem:from attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:to attribute:NSLayoutAttributeCenterY multiplier:1 constant:0]

#define PASSLayoutCenterXWithConstant(from, to, cons) [NSLayoutConstraint constraintWithItem:from attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:to attribute:NSLayoutAttributeCenterX multiplier:1 constant:cons]

#define PASSLayoutCenterYWithConstant(from, to, cons) [NSLayoutConstraint constraintWithItem:from attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:to attribute:NSLayoutAttributeCenterY multiplier:1 constant:cons]

#define PASSLayoutConstraint(from, attr1, rel, to, attr2, mult, cons) [NSLayoutConstraint constraintWithItem:from attribute:attr1 relatedBy:rel toItem:to attribute:attr2 multiplier:mult constant:cons]

#define PASSDesignWidth(w) ((w) / 414.0 * ([UIScreen mainScreen].bounds.size.width < [UIScreen mainScreen].bounds.size.height ? [UIScreen mainScreen].bounds.size.width : [UIScreen mainScreen].bounds.size.height))

#define PASSDesignHeight(h) ((h) / 896.0 * ([UIScreen mainScreen].bounds.size.width < [UIScreen mainScreen].bounds.size.height ? [UIScreen mainScreen].bounds.size.height : [UIScreen mainScreen].bounds.size.width))

#define PASSScreenWidth [UIScreen mainScreen].bounds.size.width
#define PASSScreenHeight [UIScreen mainScreen].bounds.size.height

#endif /* PASSDesignMacro_h */
