//
//  SAPILoginService+PASSEnhancedLogin.h
//  PassEnhancedKit
//
//  Created by Sun,Chao(PPSD) on 2020/2/24.
//  Copyright © 2020 Baidu Passport. All rights reserved.
//

#import <PassportKit/PassportKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PASSFastLoginModel;

/**
 头像来源类型
 */
typedef NS_ENUM(NSUInteger, PASSPortraitSourceType) {
    PASSPortraitSourceTypeDefault,          // 用户自定义上传头像（默认）
    PASSPortraitSourceTypeProductDefine,    // 产品线自定义头像
    PASSPortraitSourceTypeCartoon           // 本地活动的动漫头像
};

@interface PASSPortraitConfig : NSObject
/**
头像来源类型
*/
@property (nonatomic, assign) PASSPortraitSourceType sourceType;

@end

@interface SAPILoginService (PASSEnhancedLogin)

/**
 *  修改头像
 *
 *  @important 由于某些原因（大部分是政府要求），上传头像需要禁止使用，请直接使用返回的文案。
 *
 *  @param imageData       头像图片NSData
 *  @param mimeType        mime类型
 *  @param model           登录模型, 如果传空，则用当前登录帐号
 *  @param completionBlock 完成后的回调
 *  @param errorBlock      失败后的回调
 */
- (BOOL)uploadPortrait:(NSData *)imageData
              mimeType:(NSString *)mimeType
            loginModel:(SAPILoginModel *)model
          onCompletion:(SAPIRequestCompletionBlock)completionBlock
               onError:(SAPIRequestErrorBlock)errorBlock DEPRECATED_MSG_ATTRIBUTE("use uploadPortrait:mimeType:loginModel:config:onCompletion:onError: instead");
/**
 *  修改头像
 *
 *  @important 由于某些原因（大部分是政府要求），上传头像需要禁止使用，请直接使用返回的文案。
 *
 *  @param imageData       头像图片NSData
 *  @param mimeType        mime类型
 *  @param model           登录模型, 如果传空，则用当前登录帐号
 *  @param config          头像类型配置
 *  @param completionBlock 完成后的回调
 *  @param errorBlock      失败后的回调
 */
- (BOOL)uploadPortrait:(NSData *)imageData
              mimeType:(NSString *)mimeType
            loginModel:(SAPILoginModel *)model
                config:(PASSPortraitConfig *)config
          onCompletion:(SAPIRequestCompletionBlock)completionBlock
               onError:(SAPIRequestErrorBlock)errorBlock;

/**
 *  获取头像
 *
 *  @param model           登录模型
 *  @param completionBlock 完成后的回调
 *  @param errorBlock      失败后的回调
 */
- (BOOL)getPortraitInfo:(SAPILoginModel *)model
           onCompletion:(SAPIRequestCompletionBlock)completionBlock
                onError:(SAPIRequestErrorBlock)errorBlock;

/**
 *  批量获取头像，最多获取5个,内部会根据 bduss 去重
 *
 *  @param modelList       登录模型数组
 *  @param completionBlock 完成后的回调
 *  @param errorBlock      网络请求失败后的回调
 */
- (BOOL)getPortraitListInfo:(NSArray<SAPILoginModel *> *)modelList
           onCompletion:(SAPIRequestCompletionBlock)completionBlock
                onError:(SAPIRequestErrorBlock)errorBlock;

/**
 *  获取热门推荐头像列表
 *
 *  v6.7.0新增
 *
 *  @param bduss           bduss
 *  @param completionBlock 获取成功时回调
 *  @param errorBlock      获取失败时回调
 */
- (void)getHotAvatarListWithBduss:(NSString *)bduss
                     onCompletion:(SAPIRequestCompletionBlock)completionBlock
                          onError:(SAPIRequestErrorBlock)errorBlock;

/**
 *  获取热门推荐头像列表
 *
 *  v9.1.9新增
 *
 *  @param bduss           bduss
 *  @param extraParams     扩展参数（目前有category=new）
 *  @param completionBlock 获取成功时回调
 *  @param errorBlock      获取失败时回调
 */
- (void)getHotAvatarListWithBduss:(NSString *)bduss params:(nullable NSDictionary *)extraParams
                     onCompletion:(SAPIRequestCompletionBlock)completionBlock
                          onError:(SAPIRequestErrorBlock)errorBlock;

/**
 *  设置用户头像为热门推荐头像的某个头像 (与用户自定义修改头像的接口不同，请注意区分)
 *
 *  v6.7.0新增
 *
 *  @param bduss           bduss
 *  @param serie           所选热门头像的系列
 *  @param number          所选热门头像的序号
 *  @param completionBlock 设置成功时的回调
 *  @param errorBlock      设置失败时的回调
 */
- (void)setHotAvatarWithBduss:(NSString *)bduss
                        serie:(NSString *)serie
                       number:(NSUInteger)number
                 onCompletion:(SAPIRequestCompletionBlock)completionBlock
                      onError:(SAPIRequestErrorBlock)errorBlock;

/**
 *  补填用户名
 *
 *  @important 由于某些原因（大部分是政府要求），补填用户名需要禁止使用，请直接使用返回的文案。
 *
 *  @param uname           用户名
 *  @param model           登录模型
 *  @param completionBlock 完成后的回调
 *  @param errorBlock      失败后的回调
 */
- (BOOL)fillUname:(NSString *)uname
       loginModel:(SAPILoginModel *)model
     onCompletion:(SAPIRequestCompletionBlock)completionBlock
          onError:(SAPIRequestErrorBlock)errorBlock;

/**
 *  根据bduss同步loginModel到sdk（此接口同步的帐号不会互通），需网络请求
 *  如果是将Cookie中的BDUSS同步到SDK，请使用-[SAPILoginService web2NativeLoginSuccess:failure:]接口
 *
 *  @param bduss           bduss，不能为nil或空字符串
 *  @param ptoken          ptoken，没有时传入nil
 *  @param app             帐号来源app名字，不能为nil或空字符串
 *  @param completionBlock 同步成功时的回调
 *  @param errorBlock      同步失败时的回调
 *
 *  @return 传入参数格式是否正确，返回NO表示传入参数不合法
 */
- (BOOL)syncLoginModelWithBduss:(NSString *)bduss
                         ptoken:(NSString *)ptoken
                            app:(NSString *)app
                   onCompletion:(SAPIRequestCompletionBlock)completionBlock
                        onError:(SAPIRequestErrorBlock)errorBlock;

/**
 *  通过手机号获取动态密码，然后根据手机号、动态密码登录。
 *  如果命中反作弊策略，需要输入验证码，验证码为数字字母组合。
 *
 *  @param mobile  手机号
 *  @param captcha 验证码，没有时传nil
 *  @param success 获取成功时的回调，返回一个内容格式如@{ @"errCode": @"0", @"errMsg": @"" }的键值对
 *  @param failure 获取失败时的回调，返回一个NSError实例,其中domain为错误文案，code为错误码；
 *                                  如果需要输入验证码，则返回一个UIImage实例，否则返回nil。
 */
- (void)getDpassWithMobile:(NSString *)mobile
                   captcha:(nullable NSString *)captcha
                   success:(void (^)(NSDictionary *info))success
                   failure:(void (^)(UIImage * _Nullable captchaImage, NSError *error))failure;

- (void)getDpassWithMobile:(NSString *)mobile
                   captcha:(nullable NSString *)captcha
               extraParams:(nullable NSDictionary *)extraParams
                   success:(void (^)(NSDictionary *info))success
                   failure:(void (^)(UIImage * _Nullable captchaImage, NSError *error, NSDictionary * _Nullable errorInfo))failure;

/**
 *  短信登录获取动态密码需要输入验证码时，可通过此方法刷新验证码
 *
 *  @param completion 完成时回调
 */
- (void)refreshCaptchaForSMSLoginOnCompletion:(void (^)(UIImage *captchaImage))completion;

/**
 *  根据手机号、动态密码登录
 *  先调用getDpassWithMobile:success:failure:接口获取动态密码
 *
 *  v6.7.8新增
 *
 *  @param mobile  手机号
 *  @param dpass   动态密码，通过getDpassWithMobile:success:failure:获取
 *  @param success 登录成功时的回调，返回一个SAPILoginModel实例
 *  @param failure 登录失败时的回调，返回一个NSError实例,其中domain为错误文案，code为错误码
 */
- (void)loginWithMobile:(NSString *)mobile
                  dpass:(NSString *)dpass
                success:(void (^)(SAPILoginModel *loginModel))success
                failure:(void (^)(NSError *error))failure;

- (void)loginWithMobile:(NSString *)mobile
                  dpass:(NSString *)dpass
            extraParams:(nullable NSDictionary *)extraParams
                success:(void (^)(SAPILoginModel *loginModel))success
                failure:(void (^)(NSError *error, NSDictionary * _Nullable errorInfo))failure;

/**
 *  生成短信内容，用于上行短信注册、登录等操作
 *
 *  v6.7.8新增
 *
 *  @return 生成的短信内容
 */
- (NSString *)getUpwardSMSContentForRegister DEPRECATED_MSG_ATTRIBUTE("this method will be removed in a future release and should be avoided");

/**
 *  通过上行短信注册并登录帐号
 *  需先调用getUpwardSMSContentForRegister接口获取短信内容并成功发送该短信后再调用本接口
 *
 *  v6.7.8新增
 *
 *  @param sms     上行短信的内容，通过getUpwardSMSContentForRegister接口获取
 *  @param timeout 本次注册、登录操作的超时时间
 *  @param success 注册并登录成功时的回调，返回一个SAPILoginModel实例
 *  @param failure 注册、登录失败时的回调，返回一个NSError实例
 */
- (void)registerBySendSMS:(NSString *)sms
                  timeout:(NSTimeInterval)timeout
                  success:(void (^)(SAPILoginModel *loginModel))success
                  failure:(void (^)(NSError *error))failure DEPRECATED_MSG_ATTRIBUTE("this method will be removed in a future release and should be avoided");

@end

NS_ASSUME_NONNULL_END
