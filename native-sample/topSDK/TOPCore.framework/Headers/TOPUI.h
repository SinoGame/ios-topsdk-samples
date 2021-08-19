//
//  TOPUI.h
//  TopSDKCore
//
//  Created by lyj on 2021/3/3.
//

#import <UIKit/UIKit.h>
#import <TOPCore/TOPUser.h>
#import <TOPCore/TOPAgreement.h>

#ifndef TOPUI_h
#define TOPUI_h

// UI界面事件
typedef NS_ENUM(NSInteger, TOPUIAction) {
    TOPLoginViewClickClose,
    TOPLoginViewClickMore,
    TOPLoginViewClickLogin,
    
    TOPMoreViewClickClose,
    TOPMoreViewClickBack,
    TOPMoreViewClickLogin,
    
    TOPAgreementOpen,
    TOPAgreementAlertClickClose,
    TOPAgreementAlertClickCancel,
    TOPAgreementAlertClickSubmit,
    
    TOPSuccessViewClickSwitch,
    
    TOPUserCenterClickClose,
    TOPUserCenterClickBack,
    TOPUserCenterClickLogout,
    TOPUserCenterRefreshUserInfo,
    TOPUserCenterRefreshBindInfo,
    TOPUserCenterRefreshAgreements,
    TOPUserCenterClickBind,
    
    TOPGuestPayAlertClickClose,
    TOPGuestPayAlertClickCancel,
    TOPGuestPayAlertClickBind,
    
    TOPGuestLogoutAlertClickClose,
    TOPGuestLogoutAlertClickSubmit,
    TOPGuestLogoutAlertClickBind,
};

@protocol TOPUIActionProtocol <NSObject>

- (void)showLoading;
- (void)hideLoading;

- (void)showToast:(NSString *)toast;
- (void)hideToast;

- (void)handlerUIAction:(TOPUIAction)action params:(NSDictionary *)params;
- (void)handlerUIAction:(TOPUIAction)action params:(NSDictionary *)params callback:(void(^)(NSError *error, id result))callback;

@end

@protocol TOPUIProtocol <NSObject>

- (void)setActionHandler:(id<TOPUIActionProtocol>)handler;

/// 登录界面
- (UIView *)getLoginViewWithTypes:(NSArray<NSString *> *)types;

/// 其他登录方式界面
- (UIView *)getOtherLoginViewWithTypes:(NSArray<NSString *> *)types;

/// 协议弹窗界面
- (UIView *)getAgreementAlertWithAgreements:(NSArray<TOPAgreement *> *)agreements;

/// 登录成功提示
- (UIView *)getLoginSuccessViewWithSwitchBtn:(BOOL)showSwitch;

/// 用户中心页面
- (UIView *)getUserCenterViewPlatforms:(NSArray *)platforms
                            agreements:(NSArray<TOPAgreement *> *)agreements;

/// 游客登出提示弹窗
- (UIView *)getGuestLogoutAlertView;

/// 游客支付提示弹窗
- (UIView *)getGuestPayAlertView;

@end

#endif /* TOPUI_h */
