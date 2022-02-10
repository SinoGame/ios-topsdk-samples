//
//  TOPLocalizedUtils.h
//  TopSDK
//
//  Created by lyj on 2021/1/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPLocalizedUtils : NSObject

+ (NSString *)getLanguage;

+ (NSString *)localize:(NSString *)key;

+ (NSString *)localize:(NSString *)key defaultValue:(NSString *)defaultValue;

@end

NS_ASSUME_NONNULL_END
