//
//  TOPJsonUtils.h
//  TopSDK
//
//  Created by lyj on 2021/1/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPJsonUtils : NSObject

+ (nullable id)jsonObjOfString:(NSString *)str;
+ (nullable NSDictionary *)jsonDictOfData:(NSData *)data;
+ (nullable NSArray *)jsonArrayOfData:(NSData *)data;

+ (nullable NSString *)jsonStringWithObj:(id)obj;
+ (nullable NSData *)jsonDataWithObj:(id)obj;

@end

NS_ASSUME_NONNULL_END
