//
//  TOPStringUtils.h
//  TopSDK
//
//  Created by lyj on 2021/1/5.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPStringUtils : NSObject

+ (nullable NSString *)md5hexOfString:(NSString *)plain;
+ (NSString *)urlEncodeWithString:(NSString *)str;
+ (NSString *)urlDecodeWithString:(NSString *)str;

+ (CGSize)sizeWithString:(NSString *)str maxSize:(CGSize)size font:(UIFont *)font;
+ (CGSize)sizeWithString:(NSString *)str noLimitInFont:(UIFont *)font;

+ (NSString *)randomStringWithLength:(NSInteger)length;

@end

NS_ASSUME_NONNULL_END
