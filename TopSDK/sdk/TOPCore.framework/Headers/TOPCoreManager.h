//
//  TOPCoreManager.h
//  TOPCore
//
//  Created by lyj on 2021/11/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPCoreManager : NSObject

+ (NSString *)sdkVersion;
+ (void)initManager;
+ (void)initWithAppId:(NSString *)appid;

+ (void)updateUid:(NSString * __nullable)uid;
+ (NSString *)getUid;

@end

NS_ASSUME_NONNULL_END
