//
//  BDRimSDKMainManager.h
//  BDFSGRIM-SDK
//
//  Created by shuang on 2017/4/28.
//  Copyright © 2017年 shuang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

extern NSString *const kPASSBio_Method_Name;

//=======活体初始化======
extern NSString *const kPASSBioFace_Appid;
extern NSString *const kPASSBioFace_AppKey;
extern NSString *const kPASSBioFace_AppTpl;
extern NSString *const kPASSBioFace_SapiCuid;
//=======安全SDK初始化======
extern NSString *const KPASSBioSecuritySDK_AppKey;
extern NSString *const KPASSBioSecuritySDK_Secret;
//=======method name start======
extern NSString *const kPASSBio_MethodName_Liveness;
extern NSString *const kPASSBio_MethodName_OCR;
extern NSString *const kPASSBio_MethodName_RiskInfo;
extern NSString *const kPASSBio_MethodName_RiskToken;
extern NSString *const kPASSBio_MethodName_SecuritySDK;
extern NSString *const kPASSBio_MethodName_OCRBankCard;
extern NSString *const kPASSBio_MethodName_LbsCheck;
//=======method name end =====

// 进入SDK返回的错误类型
typedef enum _EPASSBioSDK_Error_Type {
    PASSBioSDK_Error_Spno = -32,          //sp_no错误
    PASSBioSDK_Error_None              = 0,// 无错
    PASSBioSDK_Error_Net               = 1,// 网络异常
    PASSBioSDK_Error_InvalidParameters = 3,// 无效参数
    PASSBioSDK_Error_InvalidLicense    = 4,// 无效授权
   
}PASSBioSDKErrorType;

typedef void (^PASSBioServiceFinish)(id finishObject);


@interface PASSBioSDKMainManager : NSObject

@property (nonatomic, copy, readonly) NSString *tpl;
@property (nonatomic, copy, readonly) NSString *appid;
@property (nonatomic, copy, readonly) NSString *appkey;
@property (nonatomic, copy, readonly) NSString *sapiCuid;

/**
 *  PASSBioSDKMainManager单例
 */
+ (PASSBioSDKMainManager *)shareInstance;

/**
 *  初始配置接口
 *  @param params 入口参数
 */

- (PASSBioSDKErrorType)configWithParams:(NSMutableDictionary*)params;

/**
 *  对外统一入口
 *  @param params 统一入口参数 {"method":"methodName",}
 *  @param finishBlock 回调
 *  @param rootVC 外部传入的VC
 */
- (void)accessPASSBioServiceWithParams:(NSDictionary*)params
                          withRootVC:(UIViewController *)rootVC
                         finishBlock:(PASSBioServiceFinish)finishBlock;

@end
