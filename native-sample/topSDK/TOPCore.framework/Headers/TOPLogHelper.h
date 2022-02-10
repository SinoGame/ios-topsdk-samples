//
//  TOPLogHelper.h
//  TOPCore
//
//  Created by lyj on 2021/4/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPLogHelper : NSObject

+ (instancetype)sharedInstance;

- (void)reportAction:(NSString *)actionName
              params:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
