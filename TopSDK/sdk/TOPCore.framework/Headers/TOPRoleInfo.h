//
//  TOPRoleInfo.h
//  TOPCore
//
//  Created by lyj on 2021/3/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPRoleInfo : NSObject

/// 游戏角色id
@property (nonatomic, copy) NSString *roleId;

/// 游戏角色名
@property (nonatomic, copy) NSString *roleName;

/// 游戏角色等级
@property (nonatomic, copy) NSString *roleLevel;

/// 游戏服务器名
@property (nonatomic, copy) NSString *serverName;

/// 游戏用户Vip等级
@property (nonatomic, copy) NSString *vipLevel;

@end

NS_ASSUME_NONNULL_END
