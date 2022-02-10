//
//  TOPEventHelper.h
//  TOPCore
//
//  Created by lyj on 2021/4/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPEventHelper : NSObject

+ (instancetype)sharedInstance;

- (void)reportEventName:(NSString *)eventName
                 params:(nullable NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
