//
//  TOPTimerUtils.h
//  TopSDK
//
//  Created by lyj on 2021/1/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPTimerUtils : NSObject

+ (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)ti
                                     target:(id)aTarget
                                   selector:(SEL)aSelector
                                   userInfo:(nullable id)userInfo
                                     repeat:(BOOL)repeat;

@end

NS_ASSUME_NONNULL_END
