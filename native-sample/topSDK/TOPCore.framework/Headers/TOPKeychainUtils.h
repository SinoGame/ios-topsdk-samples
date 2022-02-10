//
//  TOPKeychainUtils.h
//  TopSDK
//
//  Created by lyj on 2021/1/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TOPKeychainUtils : NSObject

/// 保存字典到钥匙串
/// @param dict 需要保存的字典
+ (void)saveKeychainDict:(NSMutableDictionary *)dict;

/// 获取存储在钥匙串的字典数据
+ (NSMutableDictionary *)keychainDict;

/// 获取钥匙串对应key的值
/// @param key 想要获取的值的key
+ (nullable NSString *)valueInKeyChainForKey:(NSString *)key;

/// 保存键值到钥匙串
/// @param value 值
/// @param key 键
+ (void)saveValueToKeyChain:(NSString *)value forKey:(NSString *)key;

//+ (void)deleteAllInfoInKeyChain;

@end

NS_ASSUME_NONNULL_END
