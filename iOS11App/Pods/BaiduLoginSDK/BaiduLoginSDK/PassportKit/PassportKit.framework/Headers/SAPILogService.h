//
//  SAPILogService.h
//  SAPILib
//
//  Created by Vinson.D.Warm on 11/26/13.
//  Copyright (c) 2013 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString * const SAPILogCommonKeyErrno;
FOUNDATION_EXPORT NSString * const SAPILogCommonKeyExtraJson;

@interface SAPILogService : NSObject

+ (SAPILogService *)sharedInstance;

- (void)sendAutoStatisticLogWithName:(NSString *)name;

- (void)sendAutoStatisticLogWithName:(NSString *)name extraParams:(NSDictionary *)extraParams;

- (void)sendAutoStatisticLogWithName:(NSString *)name extraParams:(NSDictionary *)extraParams urlEncodeExtraParams:(NSDictionary *)urlEncodeExtraParams;

- (void)sendAutoStatisticLog:(NSString *)autoStatistic extraParams:(NSDictionary *)extraParams urlEncodeExtraParams:(NSDictionary *)urlEncodeExtraParams;


// AS - Automated Atatistical 能自动化的统计、分析采集的数据

// DimensionInfo 会添加拼接到 auto_statistic 字段的内容体内，auto_statistic 是整个 Get 请求 Query 中的参数之一
- (void)collectASDataForEventType:(NSString *)eType withDimensionInfo:(NSDictionary *)dInfo;

// BaseParams 会添加拼接到整个 Get 请求的 Query 里，BaseParams 通常统一添加，这里主要用于兼容历史 log 参数设置
- (void)collectASDataForEventType:(NSString *)eType withDimensionInfo:(NSDictionary *)dInfo andBaseParams:(NSDictionary *)bParams;

@end
