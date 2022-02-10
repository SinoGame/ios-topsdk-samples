//
//  TOPErrorUtils.h
//  TopSDK
//
//  Created by lyj on 2021/1/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPErrorUtils : NSObject

+ (NSString *)configPath;

+ (void)saveErrorConfig:(NSData *)configData;

+ (NSError *)errorWithCode:(NSInteger)code message:(NSString *)message;

+ (NSError *)errorWithCode:(NSInteger)code message:(NSString *)message extra:(NSString *)extra;

@end

NS_ASSUME_NONNULL_END
