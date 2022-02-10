//
//  AppDelegate.m
//  native-sample
//
//  Created by lyj on 2021/8/19.
//

#import "AppDelegate.h"
#import <TOPSDK/TopSDK.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [TopSDK.sharedInstance application:application didFinishLaunchingWithOptions:launchOptions];
    TopSDK.sharedInstance.delegate = self;
    [TopSDK.sharedInstance initWithAppId:@"132168550394630144"];
    return YES;
}

#pragma mark - UISceneSession lifecycle

- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options  API_AVAILABLE(ios(13.0)){
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions  API_AVAILABLE(ios(13.0)){
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    return [TopSDK.sharedInstance application:app openURL:url options:options];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [TopSDK.sharedInstance applicationDidEnterBackground:application];
    
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    [TopSDK.sharedInstance applicationWillEnterForeground:application];
    
}

- (void)showAlertWithTitle:(NSString *)title content:(NSString *)content {
    UIAlertController *alertVC = [UIAlertController alertControllerWithTitle:title message:content preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
    }];
    
    [alertVC addAction:cancelAction];
    UIWindow *currentWindow = UIApplication.sharedApplication.keyWindow;
    if (!currentWindow) {
        currentWindow = UIApplication.sharedApplication.windows.lastObject;
    }
    
    if (currentWindow) {
        [currentWindow.rootViewController presentViewController:alertVC animated:YES completion:nil];
    }
}

#pragma mark - GamePlusDelegate

- (void)initSDKWithResult:(BOOL)success {
    [self showAlertWithTitle:@"初始化结果" content:[NSString stringWithFormat:@"初始化%@",success?@"成功":@"失败"]];
}

- (void)didLoginSuccessWithUser:(TOPUser *)user {
    [self showAlertWithTitle:@"登录成功" content:[NSString stringWithFormat:@"uid:%@\nname:%@",user.userId,user.name]];
}

- (void)didLoginFailureWithError:(NSError *)error {
    [self showAlertWithTitle:@"登录失败" content:[NSString stringWithFormat:@"errorCode:%ld \nerrorMessgae：%@",(long)error.code,error.localizedDescription]];
}

- (void)didLogoutSuccess {
    [self showAlertWithTitle:@"登出成功" content:@"已登出"];
}

- (void)didLogoutFailureWithError:(NSError *)error {
    [self showAlertWithTitle:@"登出失败" content:[NSString stringWithFormat:@"errorCode:%ld \nerrorMessgae：%@",(long)error.code,error.localizedDescription]];
}

- (void)didPaySuccessWithPayment:(TOPPayment *)payment {
    [self showAlertWithTitle:@"支付成功" content:[NSString stringWithFormat:@"producId:%@\norderNo:%@",payment.productId,payment.orderNo]];
}

- (void)didPayFailureWithPayment:(TOPPayment *)payment
                           error:(NSError *)error {
    [self showAlertWithTitle:@"支付失败" content:[NSString stringWithFormat:@"errorCode:%ld \nerrorMessgae：%@",(long)error.code,error.localizedDescription]];
}

- (void)didGetUserInfoSuccessWithUser:(TOPUser *)user {
    [self showAlertWithTitle:@"获取用户信息成功" content:[NSString stringWithFormat:@"uid:%@\nname:%@\nisGuest:%@",user.userId,user.name,user.isGuest?@"是":@"否"]];
}

- (void)didGetUserInfoFailureWithError:(NSError *)error {
    [self showAlertWithTitle:@"获取用户信息失败" content:[NSString stringWithFormat:@"errorCode:%ld \nerrorMessgae：%@",(long)error.code,error.localizedDescription]];
}

- (void)didGetUserBindInfoSuccessWithPlatforms:(NSArray *)platforms {
    [self showAlertWithTitle:@"获取用户绑定信息成功" content:[NSString stringWithFormat:@"%@",platforms]];
}

- (void)didGetUserBindInfoFailureWithError:(NSError *)error {
    [self showAlertWithTitle:@"获取用户绑定信息失败" content:[NSString stringWithFormat:@"errorCode:%ld \nerrorMessgae：%@",(long)error.code,error.localizedDescription]];
}

- (void)didBindSuccessWithPlatform:(NSString *)platform {
    [self showAlertWithTitle:@"绑定结果" content:[NSString stringWithFormat:@"%@平台绑定成功",platform]];
}

- (void)didBindFailureWithPlatform:(NSString *)platform error:(NSError *)error {
    [self showAlertWithTitle:@"绑定结果" content:[NSString stringWithFormat:@"%@平台绑定失败,errorCode:%ld,message:%@",platform,(long)error.code, error.localizedDescription]];
}

@end
