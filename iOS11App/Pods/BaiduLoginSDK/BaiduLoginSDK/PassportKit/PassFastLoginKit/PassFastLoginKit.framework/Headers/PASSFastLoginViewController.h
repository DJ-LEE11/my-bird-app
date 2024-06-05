//
//  PASSFastLoginViewController.h
//  PassEnhancedKit
//
//  Created by sunchao19 on 2021/12/22.
//  Copyright © 2021 Baidu Passport. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PASSFastLoginViewControllerDelegate;

@interface PASSFastLoginViewController : UIViewController

@property (nonatomic, weak) id <PASSFastLoginViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END

