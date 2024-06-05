//
//  PassFoundationKit.h
//  PassFoundationKit
//
//  Created by Gang,Liu on 2019/11/25.
//  Copyright © 2019 Gang,Liu. All rights reserved.

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT double PassFoundationKitVersionNumber;

FOUNDATION_EXPORT const unsigned char PassFoundationKitVersionString[];


//Utility
#import <PassFoundationKit/SAPIReachability.h>
#import <PassFoundationKit/SAPIHTTPClient.h>
#import <PassFoundationKit/SAPILogger.h>
#import <PassFoundationKit/PASSDesignMacro.h>
#import <PassFoundationKit/SAPIJSONUtility.h>

//Category
#import <PassFoundationKit/NSObject+PASSRuntime.h>
#import <PassFoundationKit/NSString+SAPIBase64Additions.h>
#import <PassFoundationKit/NSDictionary+SAPIDictionaryAddition.h>
#import <PassFoundationKit/UIImage+PASSUtilityAddition.h>
#import <PassFoundationKit/UIColor+PASSConvenientAddition.h>
#import <PassFoundationKit/NSURL+SAPIURLAdditions.h>
#import <PassFoundationKit/NSString+SAPIStringAdditions.h>
