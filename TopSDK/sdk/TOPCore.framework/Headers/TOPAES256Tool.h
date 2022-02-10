//
//  TOPAES256Tool.h
//  TOPCore
//
//  Created by lyj on 2022/1/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPAES256Tool : NSObject

+ (NSString *)encryptWithPlainText:(NSString *)plainText;

@end

NS_ASSUME_NONNULL_END
