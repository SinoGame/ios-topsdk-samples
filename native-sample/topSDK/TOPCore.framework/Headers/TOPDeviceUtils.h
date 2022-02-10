//
//  TOPDeviceUtils.h
//  TopSDK
//
//  Created by lyj on 2021/1/6.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TOPNetworkType) {
    TOPNetworkTypeUnknown = -1,
    TOPNetworkType2G = 0,
    TOPNetworkType3G,
    TOPNetworkType4G,
    TOPNetworkType5G,
    TOPNetworkTypeWifi,
};

@interface TOPDeviceUtils : NSObject

+ (NSString *)idfa;

+ (NSString *)encryptIdfa;

+ (BOOL)checkAppSyncExist;

+ (NSString *)appVersion;

+ (NSString *)appName;

+ (NSString*)bundleId;

+ (NSString *)machineModel;

+ (NSString *)osVersion;

+ (NSString *)simCountryCode;

+ (NSString *)carrierCode;

+ (TOPNetworkType)networkType;

+ (NSString *)networkTypeStr;

@end

NS_ASSUME_NONNULL_END
