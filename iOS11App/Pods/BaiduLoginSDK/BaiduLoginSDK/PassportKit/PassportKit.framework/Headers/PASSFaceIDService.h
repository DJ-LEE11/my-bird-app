//
//  PASSFaceIDService.h
//  PassportKit
//
//  Created by jiangzhenjie on 2018/6/7.
//  Copyright © 2018年 Baidu Passport. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 人脸状态

 - PASSFaceIDStatusUnknown: 未知
 - PASSFaceIDStatusAvailable: 人脸可用，可直接调起刷脸验证
 - PASSFaceIDStatusUnregister: 未注册人脸，需调注册接口
 - PASSFaceIDStatusUnBindMobile: 未绑定手机
 */
typedef NS_ENUM(NSInteger, PASSFaceIDStatus) {
    PASSFaceIDStatusUnknown,
    PASSFaceIDStatusAvailable,
    PASSFaceIDStatusUnregister,
    PASSFaceIDStatusUnBindMobile,
};

typedef NS_ENUM(NSUInteger, PASSRealNameStatus) {
    PASSRealNameStatusNot,      // 未实名
    PASSRealNameStatusJunior,   // 初级实名
    PASSRealNameStatusSenior,   // 高级实名
};

// 网盘二级密码
FOUNDATION_EXPORT NSString * const PASSFaceIDSceneNetdisk2Pwd;
// 通用刷脸开关
FOUNDATION_EXPORT NSString * const PASSFaceIDSceneLoginSwitch;
// 人脸验证
FOUNDATION_EXPORT NSString * const PASSFaceIDSceneFaceVerify;
// 百度Xp
FOUNDATION_EXPORT NSString * const PASSFaceIDSceneXp;

/**
 刷脸配置参数
 */
@interface PASSFaceRecognConfig : NSObject

/**
 调起刷脸的源ViewController，一般为当前Controller。不可为空
 */
@property (nonatomic, strong) UIViewController *sourceViewController;

/**
 是否显示默认的刷脸引导页，默认为不显示
 */
@property (nonatomic, assign) BOOL showGuidePage;

/**
 场景参数，不能为空
 */
@property (nonatomic, copy) NSString *scene;

/**
 子产品线标识，没有时传空即可
 */
@property (nonatomic, copy, nullable) NSString *subpro;

/**
 透传参数，可空，透传参数会放入名为sp_params的key中
 */
@property (nonatomic, copy, nullable) NSDictionary *transParams;

/**
 活体检测返回结果图片压缩比，默认为不压缩
 */
@property (nonatomic, assign) CGFloat compressRatio;

/**
 proportionalCompression
 按比例压缩，压缩宽高，默认为不压缩
 */
@property (nonatomic, assign) CGFloat propCompression;

// 透传参数，本参数会直接透传如活体SDK内
@property (nonatomic, copy) NSDictionary *extraParams;

//使用身份证号、姓名信息进行刷脸前，是否需要用户先同意《个人信息处理授权书》协议并授权。默认为 NO
@property (nonatomic, assign, getter=isNeedAuthorizeCertInfo) BOOL needAuthorizeCertInfo;
@end

/**
 人脸检查接口结果
 */
@interface PASSFaceIDCheckResult : NSObject

/**
 人脸状态
 */
@property (nonatomic, assign, readonly) PASSFaceIDStatus status;

/**
 提示信息
 */
@property (nonatomic, copy, nullable, readonly) NSString *errMsg;

/**
 人脸帐号ID（加密的UID）
 */
@property (nonatomic, copy, nullable, readonly) NSString *livingUname;

/**
 授权凭证
 */
@property (nonatomic, copy, nullable, readonly) NSString *authsid;

/**
 验证控件地址
 */
@property (nonatomic, copy, nullable, readonly) NSString *authWidgetURL;

/**
 实名状态
 */
@property (nonatomic, assign, readonly) PASSRealNameStatus realNameStatus;

@end

@interface PASSFaceLoginStatus : PASSFaceIDCheckResult

/**
 刷脸开关是否开启
 */
@property (nonatomic, assign, readonly) BOOL faceLoginEnabled;

@end

@interface PASSUseCertInfo : NSObject
/// 姓名
@property (nonatomic, copy) NSString *realName;
/// 身份证号
@property (nonatomic, copy) NSString *idCardNo;
@end

@interface PASSFaceIDService : NSObject

/**
 检测当前用户人脸状态

 @param loginModel 登录模型，不可为空，如果传空，则用当前登录帐号
 @param success 成功时回调
 @param failure 失败时回调
 */
- (void)checkUserFaceIDWithLoginModel:(SAPILoginModel *)loginModel
                              success:(void(^)(PASSFaceIDCheckResult *result))success
                              failure:(void(^)(PASSError *error))failure;

/**
 检测当前用户人脸状态

 @param loginModel 登录模型，不可为空，如果传空，则用当前登录帐号
 @param extraParams 透传参数
 @param success 成功时回调
 @param failure 失败时回调
 */
- (void)checkUserFaceIDWithLoginModel:(SAPILoginModel *)loginModel
                          extraParams:(nullable NSDictionary *)extraParams
                              success:(void(^)(PASSFaceIDCheckResult *result))success
                              failure:(void(^)(PASSError *error))failure;

/**
 人脸录入接口

 @param loginModel 登录模型，不可为空，如果传空，则用当前登录帐号
 @param config 刷脸配置参数，不可为空
 @param result 人脸状态检测结果，不可为空
 @param success 人脸录入成功时回调
 @param failure 人脸录入失败时回调
 */
- (void)registerUserFaceIDWithLoginModel:(SAPILoginModel *)loginModel
                        faceRecognConfig:(PASSFaceRecognConfig *)config
                             checkResult:(PASSFaceIDCheckResult *)result
                                 success:(void(^)(NSDictionary *info))success
                                 failure:(void(^)(PASSError *error))failure;

/**
 人脸验证接口

 @param loginModel 登录模型（对于实名刷脸验证，不可为空，如果传空，则用当前登录帐号；对于非实名刷脸验证，可为空）
 @param config 刷脸配置参数，不可为空
 @param livingUname 人脸帐号ID（加密的UID）（对于实名刷脸验证，可空；对于非实名刷脸验证，不可为空）
 @param success 人脸验证通过时，回调成功
 @param failure 人脸验证失败或者发生其他错误时，回调失败
 */
- (void)verifyUserFaceIDWithLoginModel:(nullable SAPILoginModel *)loginModel
                      faceRecognConfig:(PASSFaceRecognConfig *)config
                           livingUname:(nullable NSString *)livingUname
                               success:(void(^)(NSDictionary *info))success
                               failure:(void(^)(PASSError *error))failure;


/// 身份证三要素刷脸接口
/// @param certInfo 身份证三要素，不可为空
/// @param config 刷脸配置参数，不可为空
/// @param success 脸验证通过时，回调成功
/// @param failure 人脸验证失败或者发生其他错误时，回调失败
- (void)verifyUserFaceIDWithCertInfo:(PASSUseCertInfo *)certInfo
                    faceRecognConfig:(PASSFaceRecognConfig *)config
                             success:(void(^)(NSDictionary *info))success
                             failure:(void(^)(PASSError *error))failure;
/**
 刷脸开关接口

 @param model        登录模型，不可为空，如果传空，则用当前登录帐号
 @param callbackKey  人脸验证接口中返回，关闭时不用传
 @param open         打开/关闭 刷脸开关
 @param success      打开/关闭 刷脸开关，成功时回调
 @param failure      打开/关闭 刷脸开关，失败时回调
 */
- (void)switchFaceloginWithModel:(SAPILoginModel *)model
                     callbackKey:(nullable NSString *)callbackKey
                            open:(BOOL)open
                         success:(void(^)(NSDictionary *info))success
                         failure:(void(^)(PASSError *error))failure;


/**
 查询人脸登录开关状态
 
 @param loginModel 登录模型，不可为空，如果传空，则用当前登录帐号
 @param extraParams 透传参数
 @param success 成功时回调
 @param failure 失败时回调
 */
- (void)faceLoginStatusWithLoginModel:(SAPILoginModel *)loginModel
                          extraParams:(nullable NSDictionary *)extraParams
                              success:(void(^)(PASSFaceLoginStatus *result))success
                              failure:(void(^)(PASSError *error))failure;
/**
 用于APP检测是否授权刷脸

 @param appid           (必须) 开放平台应用ID
 @param appkey          (必须) 开放平台应用apikey
 @param extraParams     (可选) 透传参数
 @param completionBlock 完成时回调，error有值时失败
 */
- (void)appFaceCheckWithAppid:(NSString *)appid
                       appKey:(NSString *)appkey
                  extraParams:(nullable NSDictionary *)extraParams
                   completion:(void (^)(PASSError *error))completionBlock;

/**
 活体检测接口

 @param loginModel 如果传空，则用当前登录帐号
 @param config 刷脸配置参数，不可为空
 @param success 活体识别通过时回调
 @param failure 活体识别未通过时回调
 */
- (void)faceLiveDetactionWithLoginModel:(nullable SAPILoginModel *)loginModel
                        faceRecognConfig:(PASSFaceRecognConfig *)config
                                 success:(void(^)(NSDictionary *info))success
                                 failure:(void(^)(PASSError *error))failure;
@end

NS_ASSUME_NONNULL_END
