//
//  TopSDK.h
//  TOPCore
//
//  Created by lyj on 2021/3/2.
//

#import <UIKit/UIKit.h>
#import <TOPCore/TOPPayment.h>
#import <TOPCore/TOPRoleInfo.h>
#import <TOPCore/TOPUser.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TopSDKDelegate <NSObject>

@required

/// SDK初始化结果回调
/// @param success 是否初始化成功
- (void)initSDKWithResult:(BOOL)success;

/// 登录成功回调
/// @param user 登录用户对象
- (void)didLoginSuccessWithUser:(TOPUser *)user;

/// 登录失败回调
/// @param error 错误信息
- (void)didLoginFailureWithError:(NSError *)error;

/// 支付成功回调
/// @param payment 支付信息
- (void)didPaySuccessWithPayment:(TOPPayment *)payment;

/// 支付失败回调
/// @param payment 支付信息
/// @param error 错误信息
- (void)didPayFailureWithPayment:(TOPPayment *)payment
                           error:(NSError *)error;

/// 登出成功回调
- (void)didLogoutSuccess;

/// 登出失败回调
/// @param error 错误信息
- (void)didLogoutFailureWithError:(NSError *)error;

@optional

/// 获取用户信息成功回调
/// @param user 用户信息
- (void)didGetUserInfoSuccessWithUser:(TOPUser *)user;

/// 获取用户信息失败回调
/// @param error 错误信息
- (void)didGetUserInfoFailureWithError:(NSError *)error;

/// 获取用户账号绑定信息成功回调
/// @param platforms 账号绑定的平台列表
- (void)didGetUserBindInfoSuccessWithPlatforms:(NSArray *)platforms;

/// 获取用户账号绑定信息失败回调
/// @param error 错误信息
- (void)didGetUserBindInfoFailureWithError:(NSError *)error;

/// 绑定账号成功回调
/// @param platform 绑定的平台
- (void)didBindSuccessWithPlatform:(NSString *)platform;

/// 绑定账号失败回调
/// @param platform 绑定的平台
/// @param error 错误信息
- (void)didBindFailureWithPlatform:(NSString *)platform error:(NSError *)error;

@end

@interface TopSDK : NSObject

/// 获取全局SDK单例
+ (instancetype)sharedInstance;

/// 获取当前SDK的版本号
+ (NSString *)getSDKVersion;

/// 代理
@property (nonatomic, weak) id<TopSDKDelegate> delegate;

/// 初始化方法（务必尽早调用）
/// @param appId 分配的应用id
- (void)initWithAppId:(NSString *)appId;

/// 登录方法
- (void)login;

/// 登出方法
- (void)logout;

/// 主动唤起用户中心
- (void)enterUserCenter;

/// 获取用户信息
- (void)getUserInfo;

/// 获取账号绑定信息
- (void)getUserBindInfo;

/// 绑定账号
/// @param platform 需要绑定的第三方平台，如：TOPLoginPlatformGoogle，见TOPConstants.h
- (void)bindPlatform:(NSString *)platform;

/// 调起支付
/// @param payment 支付商品信息
/// @param roleInfo 支付角色信息
- (void)payWithPayment:(TOPPayment *)payment role:(TOPRoleInfo *)roleInfo;

#pragma mark - AppDelegate

- (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation;

- (BOOL)application:(UIApplication *)app
            openURL:(NSURL *)url
            options:(NSDictionary *)options;

- (void)applicationDidEnterBackground:(UIApplication *)application;

- (void)applicationWillEnterForeground:(UIApplication *)application;

#pragma mark - SceneDelegate

- (void)sceneWillEnterForeground:(id)scene;

- (void)sceneDidEnterBackground:(id)scene;

- (void)scene:(id)scene openURLContexts:(NSSet *)URLContexts;

@end

NS_ASSUME_NONNULL_END
