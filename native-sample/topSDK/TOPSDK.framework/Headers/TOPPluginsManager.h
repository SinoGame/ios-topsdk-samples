//
//  TOPPluginsManager.h
//  TOPCore
//
//  Created by lyj on 2021/3/2.
//

#import <UIKit/UIKit.h>
#import <TOPSDK/TOPUI.h>
#import <TOPSDK/TOPPay.h>
#import <TOPSDK/TOPSignin.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TOPPluginType) {
    TOPPluginTypeLogin = 0,  // 登录插件
    TOPPluginTypePay,        // 支付插件
    TOPPluginTypeUI          // UI插件
};

@protocol TOPPluginProtocol <NSObject>

- (void)initWithParams:(NSDictionary *)params;

- (TOPPluginType)pluginType;

@optional

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

- (void)sceneWillEnterForeground:(id)scene;

- (void)sceneDidEnterBackground:(id)scene;

- (void)scene:(id)scene openURLContexts:(NSSet *)URLContexts;

@end

@interface TOPPluginsManager : NSObject

+ (instancetype)sharedInstance;

- (void)loadPlugins;

/// 获取UI插件(唯一)
- (id<TOPUIProtocol, TOPPluginProtocol>)getUIPlugin;

/// 获取支付插件（唯一）
- (id<TOPPayProtocol, TOPPluginProtocol>)getPayPlugin;

/// 获取登录插件
- (NSMutableDictionary<NSString *, id<TOPSigninProtocol, TOPPluginProtocol>> *)getLoginPlugins;

#pragma mark - ApplicationLife

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

- (void)sceneWillEnterForeground:(id)scene;

- (void)sceneDidEnterBackground:(id)scene;

- (void)scene:(id)scene openURLContexts:(NSSet *)URLContexts;

@end

NS_ASSUME_NONNULL_END
