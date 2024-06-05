//
//  ViewController.m
//  iOS11App
//
//  Created by Lidongjie on 2023/10/13.
//

#import "ViewController.h"
#import <shared/shared.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.redColor;
    UIViewController *vc = [SharedMain_iosKt MainViewController];
    vc.view.accessibilityLabel = @"UITest_直播间关闭按钮1";
    [self addChildViewController:vc];
    [self.view addSubview:vc.view];
    vc.view.frame = self.view.bounds;
}


@end
