//
//  AppDelegate.m
//  iOS11App
//
//  Created by Lidongjie on 2023/10/13.
//

#import "AppDelegate.h"
#import "ViewController.h"

@interface AppDelegate ()
@end

@implementation AppDelegate
@synthesize window = _window;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    self.window = [UIWindow new];
    self.window.frame = UIScreen.mainScreen.bounds;
    self.window.rootViewController = [ViewController new];
    return YES;
}


@end
