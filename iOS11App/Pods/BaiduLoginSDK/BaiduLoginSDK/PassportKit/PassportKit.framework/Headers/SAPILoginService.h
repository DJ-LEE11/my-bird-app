//
//  SAPILoginService.h
//  SAPILib
//
//  Created by Vinson.D.Warm on 13-9-8.
//  Copyright (c) 2013年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PASSOneKeyCheckResult;
@class SAPILoginModel;
@class PASSError;
@class PASSCertInfo;
@class PASSFusionUserInfoRequest;
@class PASSFusionUserInfoResponse;

typedef NSString * const PASSFederatedLoginKey;
typedef NSString * const PASSFederatedLoginValue;

FOUNDATION_EXPORT PASSFederatedLoginKey PASSFederatedLoginHost;

// 爱奇艺
FOUNDATION_EXPORT PASSFederatedLoginKey PASSFederatedLoginIQIYIToken;
FOUNDATION_EXPORT PASSFederatedLoginKey PASSFederatedLoginIQIYIMobile;
FOUNDATION_EXPORT PASSFederatedLoginValue PASSFederatedLoginIQIYIHost;

@interface SAPILoginService : NSObject

/**
 *  根据BDUSS、tpl列表查询本地是否已存在所有对应的stoken
 *
 *  @param bduss         bduss
 *  @param targetTPLList 业务线tpl列表
 *
 *  @return 传入参数正确时，如果本地已有全部的与传入参数对应的stoken时返回YES，其他情况返回NO。
 */
- (BOOL)isStokenExistedForBduss:(NSString *)bduss targetTPLList:(NSArray *)targetTPLList;

/**
 *  根据BDUSS获取传入tpl列表对应的stoken列表
 *
 *  @param bduss         bduss
 *  @param targetTPLList 业务线tpl列表，用于获取tpl对应的stoken
 *  @param success       获取成功时的回调。返回一个键值对，其中key为传入的某一tpl，value为对应的stoken。
 *  @param failure       获取失败时的回调，返回一个NSError实例。若返回NSError code为8，产品线需要引导用户重新登录。返回错误码为8的原因有几种：1. 本地PTOKEN缺失；2. BDUSS失效；3. PTOKEN和BDUSS不对应。从NSError的userInfo中取SAPIBdussPtokenInvalidReasonKey对应的值可以区分具体的原因，上述三种原因对应的值分别为SAPIBdussPtokenInvalidReasonMissingPtoken，SAPIBdussPtokenInvalidReasonUserNotOnline，SAPIBdussPtokenInvalidReasonBdussPtokenNotMatch。
 *
 *  @return 本地有与传入参数对应的缓存数据时，返回相应缓存数据；否则发起网络请求。
 *
 */
- (nullable NSDictionary *)getStokenForBduss:(NSString *)bduss
                      targetTPLList:(NSArray *)targetTPLList
                            success:(void (^)(NSDictionary *tplStokenPairs))success
                            failure:(void (^)(NSError *error))failure;

/**
 *  根据BDUSS+TPLList，删除本地对应的stoken
 *
 *  @param bduss bduss
 *  @param targetTPLList   业务线tpl列表
 *
 *  @return 参数不为空时，删除成功返回YES，否则返回失败。
 *
 */
- (BOOL)deleteStokenForBduss:(NSString *)bduss targetTPLList:(NSArray *)targetTPLList;

- (void)getOpenBdussWithConfig:(PASSOpenBdussConfig *)config
                       success:(void (^)(PASSOpenBdussModel *model))success
                       failure:(void (^)(NSError *error))failure;

/**
 *  用现有模型登录(含互通)

 @param model model 构造的model中如果uid、bduss、displayname任一参数为nil或空串，则会回调登录失败，其他情况会回调登录成功
 @param userInfo 透传参数，该参数将透传至 didLoginSuccess 方法的 extraInfo 字段中，Key 为 userInfo
 */
- (void)loginWithLoginModel:(SAPILoginModel *)model userInfo:(NSDictionary *)userInfo DEPRECATED_MSG_ATTRIBUTE("Use SAPIMainManager instance's loginWithLoginModel: instead, this property will be removed in a future release and should be avoided");

/**
 * UC 帐号登录
 * 错误码：2（uc帐号不在线）3（uc帐号没有对应的百度帐号）
 */
- (void)loginWithUCAccount:(NSDictionary *)params completion:(void(^)(NSError * _Nullable error, NSDictionary * _Nullable info))completion;

/**
 *  用现有模型登录(不含互通)
 *  建议以下情况使用：
 *  1. web端登录状态同步到sdk里
 *  2. 兼容历史版本登录状态
 *
 *  @param model 构造的model中如果uid、bduss、displayname任一参数为nil或空串，则会回调登录失败，其他情况会回调登录成功。
 */
- (void)unsharedLoginWithLoginModel:(SAPILoginModel *)model DEPRECATED_MSG_ATTRIBUTE("Set this property is unnecessary, this property will be removed in a future release");;

/// 退出帐号
/// @param model 用户登录模型
- (BOOL)logout:(SAPILoginModel *)model;

/// 退出当前帐号
- (BOOL)logoutCurrentModel;

/// 退出当前帐号
/// @param type 退出帐号类型
/// @param model 用户model，为空则默认当前用户
/// @param completion 退出结果回调
- (BOOL)logout:(PASSLogoutType)type model:(nullable SAPILoginModel *)model completion:(void (^_Nullable) (BOOL suc, NSDictionary * _Nullable info))completion;

/**
 *  获取登录行为信息
 *
 *  @param uid 用户uid
 *
 *  @return 用户登录行为信息
 */
- (NSDictionary *)readLoginActionInfoByUid:(NSString *)uid;

/**
 *  获取用户信息
 *
 *  @param bduss           用户的bduss
 *
 *
 *  @param completionBlock 获取成功时的回调。可能包含以下字段：
 *                          displayname：用户显示名称，用于产品线展示。
 *
 *                          have_psw：是否设置了密码。
 *
 *                          incomplete_user：是否为半帐号。为1时即为半帐号，半帐号需要绑定手机或者正常化后才能调用其他接口。
 *
 *                          portrait：头像地址拼接串。
 *                          portrait_tag：头像id的md5值，为 0 时表示用户尚未设置头像。
 *                          可根据portrait和portrait_tag拼接出头像地址：
 *                          NSString *portraitUrl = [NSString stringWithFormat:@"http://himg.bdimg.com/sys/portrait/item/%@.jpg?%@", [info objectForKey:@"portrait"], [info objectForKey:@"portrait_tag"]];
 *                          头像地址若也需HTTPS，可按如下方式拼接：
 *                          NSString *portraitUrl = [NSString stringWithFormat:@"https://himg.bdimg.com/sys/portrait/item/%@.jpg?%@", [info objectForKey:@"portrait"], [info objectForKey:@"portrait_tag"]];
 *
 *
 *                          secureemail：打码后的邮箱，用户已绑定邮箱时会返回此字段。
 *
 *                          securemobil：打码后的手机，用户已绑定手机时会返回此字段。
 *
 *                          userid：用户id。
 *
 *                          username：用户名（可能为空）。显示用户名请使用displayname字段。
 *
 *
 *  @param errorBlock      获取失败时的回调。最常见的错误情况为传入bduss已失效,此时返回errno:400021，errmsg: "user not
 *                          online, status = 2"
 *
 *  @return 传入bduss为空时返回NO，其他返回YES
 *
 */
- (BOOL)getUserInfo:(NSString *)bduss
       onCompletion:(SAPIRequestCompletionBlock)completionBlock
            onError:(SAPIRequestErrorBlock)errorBlock;

/**
 * 获取用户信息接口
 * 当前支持获取属性用户信息
 */
- (void)getUserInfoWithReq:(PASSFusionUserInfoRequest *)req completion:(void(^)(NSError * _Nullable, PASSFusionUserInfoResponse * _Nullable))completion;

/**
 * 获取是否是未成年以及实名状态
 */
- (void)getCertInfo:(nonnull NSString *)bduss completion:(void (^_Nonnull)(PASSCertInfo * _Nullable info, NSError * _Nullable error))completion;

- (void)getAccountCenterGuideMessageCompletion:(void (^_Nonnull)(BOOL guide, NSString * _Nullable message, NSError *_Nullable error))completion;

- (void)clearAllRequest;

#pragma mark - Native & H5 Share Login
/**
 *  H5登录态同步到Native
 *
 *  @discussion 该方法会自动从Cookie中获取bduss及其他信息，然后同步到Native。同步成功时，回调登录成功以及success；同步失败时，回调登录失败以及failure。同步策略请参考[SAPIMainManager sharedManager].naH5SyncStrategy配置项。
 *
 *  使用场景：H5登录完成，需要将H5登录态同步到Native端时调用
 *
 *  @param success 登录成功回调，若cookie中包含登录态，则返回一个loginModel，否则登录失败
 *  @param failure 登录失败回调
 */
- (void)web2NativeLoginSuccess:(void (^)(SAPILoginModel *loginModel))success
                       failure:(void (^)(NSError *error))failure;

/**
 *  H5登录态同步到Native
 *
 *  @discussion 该方法会自动从Cookie中获取bduss及其他信息，然后同步到Native。同步成功时，回调登录成功以及success；同步失败时，回调登录失败以及failure。同步策略请参考[SAPIMainManager sharedManager].naH5SyncStrategy配置项。
 *
 *  使用场景：H5登录完成，需要将H5登录态同步到Native端时调用
 *
 *  @param source  登录来源，该字段会透传到登录成功回调中，以 SAPILoginExtraInfoSourceKey 作为 Key
 *  @param oauthType 第三方登录类型
 *  @param success 登录成功回调，若cookie中包含登录态，则返回一个loginModel，否则登录失败
 *  @param failure 登录失败回调
 */
- (void)web2NativeLoginWithSource:(NSString *)source
              loginModelOauthType:(NSString *)oauthType
                            success:(void (^)(SAPILoginModel *loginModel))success
                            failure:(void (^)(NSError *error))failure;

/**
 *  H5登录态同步到Native
 *
 *  @discussion 该方法会将传入的登录模型同步到Native。同步成功时，回调登录成功；同步失败时，回调登录失败。同步策略请参考[SAPIMainManager sharedManager].naH5SyncStrategy配置项。
 *
 *  使用场景：H5登录完成且产品线已获取到完整的登录模型（uid，displayname，bduss不能为nil或空字符串），需要将H5登录态同步到Native端时调用。若产品线没有获取完整的登录模型，可调用-[SAPILoginService web2NativeLoginSuccess:failure:]方法同步H5登录态到Native。
 *
 *  @param loginModel 登录模型。uid，displayname，bduss不能为nil或空字符串
 */
- (void)web2NativeLoginWithLoginModel:(SAPILoginModel *)loginModel;

/**
 *  Native登录态同步到H5
 *
 *  使用场景：需要主动将Native登录状态同步到H5时调用。SAPI在登录完成时会自动同步Native登录态到H5。
 *
 *  @discussion 当前未登录时，会删除cookie中的bduss；当前已登录时，会将当前登录态写到cookie中。
 */
- (void)native2WebLogin;

/**
 *  将bduss写入cookie
 *  <li>所有白名单域名都写(如 .baidu.com, .nuomi.com, .hao123.com)</li>
 *  <li>非SessionOnly，过期时间8年</li>
 *  <li>非Secure</li>
 *
 *  @param bduss bduss
 */
- (void)setBdussToCookie:(NSString *)bduss;

/**
*  将 currentLoginModel 的bduss写入cookie
*  <li>所有白名单域名都写(如 .baidu.com, .nuomi.com, .hao123.com)</li>
*  <li>非SessionOnly，过期时间8年</li>
*  <li>非Secure</li>
*/
- (void)setCurrentModelBdussToCookie;

/**
 *  获取cookie中的bduss
 *
 *  @return 如果存在返回baidu域下的bduss，否则返回nil
 */
- (nullable NSString *)getBdussFromCookie;

#pragma mark - 二维码联合登录
/**
 获取二维码联合登录授权文案

 @param text 扫码后得到的百度侧二维码文本
 @return 授权文案。如果二维码合法，则返回相应的文案；否则将返回 nil。
 */
- (nullable NSString *)qrcodeAuthCopywritingWithQRCodeText:(NSString *)text;

/**
 二维码登录，将App登录态同步到其他设备端。注意：该接口仅提供外部厂商联合登录百度帐号使用，内部产品线不可使用
 
 @param text 扫码后得到的百度侧二维码文本
 @param success 成功时回调
 @param failure 失败时回调
 */
- (void)qrcodeLoginWithQRCodeText:(NSString *)text
                   successHandler:(void(^)(NSDictionary *info))success
                   failureHandler:(void(^)(PASSError *error))failure;

@end

@class SAPIOAuthInfo;
@interface SAPILoginService (PASSAIJoinLogin)

/**
 *  通过openPlatformId换取百度开放平台accesstoken
 *
 *  @param openPlatformId  调用时传入，不能为空。
 *  @param success 成功回调，返回一个SAPIOAuthInfo实例。
 *  @param failure 失败回调，返回一个NSError实例。
 */
- (void)getAccessTokenWithOpenPlatformId:(NSString *)openPlatformId
                                 success:(void (^)(SAPIOAuthInfo *oauthInfo))success
                                 failure:(void (^)(NSError *error))failure;

/**
 *  通过openPlatformId换取百度开放平台accesstoken
 *
 *  @param openPlatformId  调用时传入，不能为空。
 *  @param success 成功回调，返回一个SAPIOAuthInfo实例。
 *  @param failure 失败回调，返回一个NSError实例。
 */
- (void)getAccessTokenWithOpenPlatformId:(NSString *)openPlatformId
                                  extParams:(nullable NSDictionary *)extParams
                                 success:(void (^)(SAPIOAuthInfo *oauthInfo))success
                                 failure:(void (^)(NSError *error))failure;
@end

@interface SAPILoginService (PASSOneKeyLogin)

/// 获取该设备是否能使用运营商一键登录。回调均在主线程
/// v8.8.10 新增
/// @param interval 接口超时时间，应 >0，内部最多会有两个网络请求，为提高成功率建议不要设置太小。<=0 时默认设置为 15s
/// @param success  接口成功时的回调
/// @param failure  接口失败时的回调
- (void)oneKeyAbilityWithTimeout:(NSTimeInterval)interval
                         success:(void(^)(PASSOneKeyCheckResult *result))success
                         failure:(void (^)(NSError *error))failure;

/**
*  调用运营商一键登录，回调均在主线程
*  先调用oneKeyAbilityCheck:failure:接口获取 checkResult
*
*  v8.8.10 新增
*
*  @param sign      oneKeyAbilityCheck接口返回的result.sign，转换后传入，
                    将40位result.sign切割为8+32的string，转换成[string(8)+[string(32)+大写的passCuid取md5] 取md5]传入。
*  @param result      oneKeyAbilityCheck接口返回的 result
*  @param success     登录成功时的回调，调用success后会回调 sapiManager:didLoginSucceed:extraInfo:代理方法
*  @param verify      登录过程中，需要强制验证、二次卡验证的回调，产品线需打开回传的verifyVC，若使用present打开必须包装Nav控制器！！！
                      或者使用 pass_present 方法打开。
*  @param failure     登录失败时的回调，不会回调 sapiManager:didLoginFail:代理方法
*                     当code为400801时，通过NSLocalizedDescriptionKey可以获取到手机号（限YY使用）9.2.9+版本支持
*/
- (void)oneKeyloginWithSign:(NSString *)sign
                checkResult:(PASSOneKeyCheckResult *)result
                    success:(void (^)(SAPILoginModel *loginModel))success
                     verify:(void (^)(PASSWebViewController *verifyVC))verify
                    failure:(void (^)(NSError *error))failure;

/// 调用运营商一键登录，回调均在主线程
///
/// @param sign      oneKeyAbilityCheck接口返回的result.sign，转换后传入，将40位result.sign切割为8+32的string，转换成[string(8)+[string(32)+大写的passCuid取md5] 取md5]传入。
/// @param result oneKeyAbilityCheck接口返回的 result
/// @param token  oneKeyLoginToken:completion:接口返回的info中op_token字段对应值
/// @param success 成功回调，调用success后会回调 sapiManager:didLoginSucceed:extraInfo:代理方法
/// @param verify 登录过程中，需要强制验证、二次卡验证的回调，产品线需打开回传的verifyVC，若使用present打开必须包装Nav控制器！！！或者使用 pass_present 方法打开。
/// @param failure 登录失败时的回调，不会回调 sapiManager:didLoginFail:代理方法
///
- (void)oneKeyloginWithSign:(NSString *)sign
                checkResult:(PASSOneKeyCheckResult *)result
                      token:(NSString *)token
                    success:(void (^)(SAPILoginModel *loginModel))success
                     verify:(void (^)(PASSWebViewController *verifyVC))verify
                    failure:(void (^)(NSError *error))failure;

/// 退出登录时调用，预取本机手机号，用于PASS登录页面内部展示，请勿并行调用！！！
/// v8.9.3 新增
/// @param interval   接口超时时间，应 >0，内部最多会有两个网络请求，为提高成功率建议不要设置太小。<=0 时默认设置为 15s
/// @param completion 接口回调，回调在主线程
- (void)preGetPhoneTimeout:(NSTimeInterval)interval
                completion:(void(^)(PASSError *error))completion;

/// 获取运营商token
/// v9.3.14
/// @param interval 超时时间，默认为15s，传0即默认
/// @param completion 结果回调info中包含token及pass服务端所需的必要参数，业务先应该通过业务线服务端传递info到pass服务端
///
- (void)oneKeyLoginToken:(NSTimeInterval)interval completion:(void(^)(NSDictionary * _Nullable info, PASSError * _Nullable error))completion;
@end

@interface SAPILoginService (PASSHistoryLogin)

- (void)getHistoryLoginItems:(void (^)(NSArray <SAPILoginModel *>*items))completion;
@end

NS_ASSUME_NONNULL_END
