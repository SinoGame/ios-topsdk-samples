//
//  TOPBase64Utils.h
//  TopSDK
//
//  Created by lyj on 2021/1/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPBase64Utils : NSObject

+ (NSString *)base64EncodedStringWithData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
