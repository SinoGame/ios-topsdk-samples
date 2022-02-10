//
//  TOPUserManager.h
//  TOPCore
//
//  Created by lyj on 2021/3/3.
//

#import <Foundation/Foundation.h>
#import <TOPSDK/TOPUser.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPUserManager : NSObject

+ (TOPUser *)currentUser;
+ (TOPUser *)cacheUser;
+ (void)updateUser:(TOPUser *)user;
+ (void)clean;

@end

NS_ASSUME_NONNULL_END
