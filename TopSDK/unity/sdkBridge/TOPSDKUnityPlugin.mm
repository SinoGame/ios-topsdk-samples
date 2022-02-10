//
//  TOPSDKUnityPlugin.m
//  TopSDK
//
//  Created by lyj on 2021/3/18.
//

#import "TOPSDKUnityPlugin.h"
#import <TOPSDK/TopSDK.h>

@interface TOPSDKUnityPlugin()<TopSDKDelegate>

@end

@implementation TOPSDKUnityPlugin

+ (instancetype)shareInstance {
    static TOPSDKUnityPlugin *singleClass = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        singleClass = [[TOPSDKUnityPlugin alloc] init];
    });
    return singleClass;
}

+ (NSString *)getSDKVersion {
    return TopSDK.getSDKVersion;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        TopSDK.sharedInstance.delegate = self;
    }
    return self;
}

- (void)initWithAppId:(NSString *)appId {
    [TopSDK.sharedInstance initWithAppId:appId];
}

- (void)login {
    [TopSDK.sharedInstance login];
}

- (void)logout {
    [TopSDK.sharedInstance logout];
}

- (void)enterUserCenter {
    [TopSDK.sharedInstance enterUserCenter];
}

- (void)getUserInfo {
    [TopSDK.sharedInstance getUserInfo];
}

- (void)getUserBindInfo {
    [TopSDK.sharedInstance getUserBindInfo];
}

- (void)bindPlatform:(NSString *)platform {
    [TopSDK.sharedInstance bindPlatform:platform];
}

- (void)payWithPayment:(NSString *)paymentJson roleInfo:(NSString *)roleInfoJson {
    TOPPayment *payment = [TOPPayment new];
    TOPRoleInfo *roleInfo = [TOPRoleInfo new];
    if (paymentJson && [paymentJson isKindOfClass:NSString.class]) {
        NSDictionary *paymentDict = [self jsonDictOfData:[paymentJson dataUsingEncoding:NSUTF8StringEncoding]];
        NSString *productId = [paymentDict objectForKey:@"productId"];
        double amount = [[paymentDict objectForKey:@"amount"] doubleValue];
        NSString *productName = [paymentDict objectForKey:@"productName"];
        payment.productId = productId;
        payment.amount = amount;
        payment.productName = productName;
    }
    
    if (roleInfoJson && [roleInfoJson isKindOfClass:NSString.class]) {
        NSDictionary *roleInfoDict = [self jsonDictOfData:[roleInfoJson dataUsingEncoding:NSUTF8StringEncoding]];
        NSString *roleId = [roleInfoDict objectForKey:@"roleId"];
        NSString *roleName = [roleInfoDict objectForKey:@"roleName"];
        NSString *roleLevel = [roleInfoDict objectForKey:@"roleLevel"];
        NSString *serverName = [roleInfoDict objectForKey:@"serverName"];
        NSString *vipLevel = [roleInfoDict objectForKey:@"vipLevel"];
        
        roleInfo.roleId = roleId;
        roleInfo.roleName = roleName;
        roleInfo.roleLevel = roleLevel;
        roleInfo.serverName = serverName;
        roleInfo.vipLevel = vipLevel;
    }
    
    [TopSDK.sharedInstance payWithPayment:payment role:roleInfo];
}

- (nullable NSDictionary *)jsonDictOfData:(NSData *)data {
    if (data && [data isKindOfClass:NSDictionary.class]) {
        return (NSDictionary *)data;
    }
    if (!data || ![data isKindOfClass:NSData.class]) {
        return nil;
    }
    NSDictionary *result = nil;
    NSError *error = nil;
    id jsonData = [NSJSONSerialization JSONObjectWithData:data
                                                  options:0
                                                    error:&error];
    if (jsonData && [jsonData isKindOfClass:NSDictionary.class]) {
        result = jsonData;
    }
    return result;
}

#pragma mark - TopSDKDelegate

/// SDK初始化结果回调
/// @param success 是否初始化成功
- (void)initSDKWithResult:(BOOL)success {
    if (success) {
        [self callbackWithMethod:@"EmitInitSuccessEvent" params:nil];
    } else {
        [self callbackWithMethod:@"EmiInitFailedEvent" params:nil];
    }
}

/// 登录成功回调
/// @param user 登录用户对象
- (void)didLoginSuccessWithUser:(TOPUser *)user {
    NSDictionary *userInfo = @{
        @"id" : user.userId ?: @"",
        @"name" : user.name ?: @"",
        @"isGuest" : @(user.isGuest),
        @"token" : user.token ?: @""
    };
    
    [self callbackWithMethod:@"EmitLoginSuccessEvent" params:userInfo];
}

/// 登录失败回调
/// @param error 错误信息
- (void)didLoginFailureWithError:(NSError *)error {
    NSDictionary *errorInfo = @{
        @"code" : @(error.code),
        @"message" : error.localizedDescription ?: @"",
    };
    
    [self callbackWithMethod:@"EmitLoginFailedEvent" params:errorInfo];
}

/// 支付成功回调
/// @param payment 支付信息
- (void)didPaySuccessWithPayment:(TOPPayment *)payment {
    NSDictionary *errorInfo = @{
        @"productId" : payment.productId ?: @"",
        @"orderNo" : payment.orderNo ?: @"",
        @"payPlatformOrderNo" : @""
    };
    
    [self callbackWithMethod:@"EmitPaySuccessEvent" params:errorInfo];
}

/// 支付失败回调
/// @param payment 支付信息
/// @param error 错误信息
- (void)didPayFailureWithPayment:(TOPPayment *)payment
                           error:(NSError *)error {
    NSDictionary *errorInfo = @{
        @"code" : @(error.code),
        @"message" : error.localizedDescription ?: @"",
    };
    
    [self callbackWithMethod:@"EmitPayFailedEvent" params:errorInfo];
}

/// 登出成功回调
- (void)didLogoutSuccess {
    [self callbackWithMethod:@"EmitLogoutSuccessEvent" params:nil];
}

/// 登出失败回调
/// @param error 错误信息
- (void)didLogoutFailureWithError:(NSError *)error {
    
}

/// 获取用户信息成功回调
/// @param user 用户信息
- (void)didGetUserInfoSuccessWithUser:(TOPUser *)user {
    NSDictionary *userInfo = @{
        @"id" : user.userId ?: @"",
        @"name" : user.name ?: @"",
        @"isGuest" : @(user.isGuest),
        @"token" : user.token ?: @""
    };
    
    [self callbackWithMethod:@"EmitUserInfoSuccessEvent" params:userInfo];
}

/// 获取用户信息失败回调
/// @param error 错误信息
- (void)didGetUserInfoFailureWithError:(NSError *)error {
    NSDictionary *errorInfo = @{
        @"code" : @(error.code),
        @"message" : error.localizedDescription ?: @"",
    };
    
    [self callbackWithMethod:@"EmitUserInfoFailedEvent" params:errorInfo];
}

/// 获取用户账号绑定信息成功回调
/// @param platforms 账号绑定的平台列表
- (void)didGetUserBindInfoSuccessWithPlatforms:(NSArray *)platforms {
    [self callbackWithMethod:@"EmitUserBindInfoSuccessEvent" params:platforms];
}

/// 获取用户账号绑定信息失败回调
/// @param error 错误信息
- (void)didGetUserBindInfoFailureWithError:(NSError *)error {
    NSDictionary *errorInfo = @{
        @"code" : @(error.code),
        @"message" : error.localizedDescription ?: @"",
    };
    
    [self callbackWithMethod:@"EmitUserBindInfoFailedEvent" params:errorInfo];
}

/// 绑定账号成功回调
/// @param platform 绑定的平台
- (void)didBindSuccessWithPlatform:(NSString *)platform {
    NSDictionary *result = @{
        @"platform" : platform ?: @"",
        @"bindStatus" : @(1)
    };
    
    [self callbackWithMethod:@"EmitBindSuccessEvent" params:result];
}

/// 绑定账号失败回调
/// @param platform 绑定的平台
/// @param error 错误信息
- (void)didBindFailureWithPlatform:(NSString *)platform error:(NSError *)error {
    NSDictionary *errorInfo = @{
        @"code" : @(error.code),
        @"message" : error.localizedDescription ?: @"",
        @"platform" : platform ?: @""
    };
    
    [self callbackWithMethod:@"EmitBindFailedEvent" params:errorInfo];
}

#pragma mark - Utils

- (nullable NSString *)jsonStringWithObject:(id)obj {
    BOOL isValidJSON = [NSJSONSerialization isValidJSONObject:obj];
    if (!isValidJSON) {
        return @"";
    }
    NSError *error;
    NSData *jsonData =
    [NSJSONSerialization dataWithJSONObject:obj
                                    options:0
                                      error:&error];
    
    if (!jsonData) {
        return @"";
    } else {
        return [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
}

- (void)callbackWithMethod:(NSString *)method params:(id)params {
    if (!method || method.length == 0) {
        return;
    }
    
    NSString *jsonStr = @"";
    if (params) {
        jsonStr = [self jsonStringWithObject:params];
    }
    
    UnitySendMessage("TopSDKManager", method.UTF8String, jsonStr.UTF8String);
}

@end

#pragma mark - 接口

extern "C" {
    void _init(const char *appId) {
        TOPSDKUnityPlugin *plugin = [TOPSDKUnityPlugin shareInstance];
        @synchronized (plugin) {
            [plugin initWithAppId:[NSString stringWithUTF8String:appId]];
        }
    }

    char * _getSDKVersion() {
        NSString *versionStr = [TOPSDKUnityPlugin getSDKVersion];
        char *buffer = (char *)malloc(sizeof(char) * (versionStr.length + 1));
        memcpy(buffer, versionStr.UTF8String, versionStr.length);
        return buffer;
    }
    
    void _login() {
        TOPSDKUnityPlugin *plugin = [TOPSDKUnityPlugin shareInstance];
        @synchronized (plugin) {
            [plugin login];
        }
    }
    
    void _logout() {
        TOPSDKUnityPlugin *plugin = [TOPSDKUnityPlugin shareInstance];
        @synchronized (plugin) {
            [plugin logout];
        }
    }
    
    void _enterUserCenter() {
        TOPSDKUnityPlugin *plugin = [TOPSDKUnityPlugin shareInstance];
        @synchronized (plugin) {
            [plugin enterUserCenter];
        }
    }
    
    void _getUserInfo() {
        TOPSDKUnityPlugin *plugin = [TOPSDKUnityPlugin shareInstance];
        @synchronized (plugin) {
            [plugin getUserInfo];
        }
    }
    
    void _getUserBindInfo() {
        TOPSDKUnityPlugin *plugin = [TOPSDKUnityPlugin shareInstance];
        @synchronized (plugin) {
            [plugin getUserBindInfo];
        }
    }
    
    void _pay(const char *paymentJson, const char *roleInfoJson) {
        TOPSDKUnityPlugin *plugin = [TOPSDKUnityPlugin shareInstance];
        @synchronized (plugin) {
            NSString *paymentStr = nil;
            NSString *roleInfoStr = nil;
            if (paymentJson != NULL) {
                paymentStr = [NSString stringWithUTF8String:paymentJson];
            }
            if (roleInfoJson != NULL) {
                roleInfoStr = [NSString stringWithUTF8String:roleInfoJson];
            }
            [plugin payWithPayment:paymentStr
                          roleInfo:roleInfoStr];
        }
    }
    
    void _bindPlatform(char *platform) {
        TOPSDKUnityPlugin *plugin = [TOPSDKUnityPlugin shareInstance];
        @synchronized (plugin) {
            [plugin bindPlatform:[NSString stringWithUTF8String:platform]];
        }
    }
}
