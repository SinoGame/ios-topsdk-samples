//
//  TOPUser.h
//  TOPCore
//
//  Created by lyj on 2021/3/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPUser : NSObject

/// 用户id
@property (nonatomic, copy) NSString *userId;

/// 用户名
@property (nonatomic, copy) NSString *name;

/// 登录token
@property (nonatomic, copy) NSString *token;

/// 是否是游客
@property (nonatomic, assign) BOOL isGuest;

- (instancetype)initWithDict:(NSDictionary *)dict;
- (NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
